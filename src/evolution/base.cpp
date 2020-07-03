#include "../../headers/base.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <time.h>

using namespace std;

char traduz_direcao(int num_direcao){
    switch (num_direcao){
      case 0:
        return 'a';
      case 1:
        return 'b';
      case 2:
        return 'c';
        break;
      case 3:
        return 'd';
    }
    return 'n';
}

int traduz_num_direcao(char direcao){
    switch (direcao){
      case 'a':
        return 0;
      case 'b':
        return 1;
      case 'c':
        return 2;
        break;
      case 'd':
        return 3;
    }
    return 4;
}


void iniciaPop(entity **entities, int population){
  int num_direcao;
  char dir;

  for(int i = 0; i < population; i++){
    entities[i]->dead = false;
    entities[i]->x = initial_x;
    entities[i]->y = initial_y;
    entities[i]->passos_totais = 0;

    srand(time(NULL));
    rand();rand();rand();
    
    num_direcao = traduz_direcao((rand()+i)%4);

    entities[i]->movimentos = (char*)malloc(vector_size*sizeof(char));
    for(int j=0; j<vector_size; j++){
      entities[i]->movimentos[j] = 'n';
    }
    entities[i]->movimentos[entities[i]->passos_totais] = dir;
    entities[i]->passos_totais++;
  }
}

void Transa(entity **entities, int *thebest, entity *thebestofthebest, int population, float mutation){

  for(int i = 0; i < population; i++){
    srand(time(NULL));
    rand();rand();rand();

    char dir = traduz_direcao((rand()+i)%4);

    if(entities[i]->passos_totais < vector_size){
      //Misturar genes para o individuo i
      
      for(int n=0; n<vector_size; n++){
        if(n > entities[i]->passos_totais || n > entities[*thebest]->passos_totais) break;
        entities[i]->movimentos[n] = traduz_direcao((int)(((traduz_num_direcao(entities[i]->movimentos[n]) + traduz_num_direcao(entities[*thebest]->movimentos[n])))/2));
        int aux_mut = traduz_num_direcao(entities[i]->movimentos[n]) + (((pow(-1,rand()%2+1))*(rand()%4)) * mutation);
        if(aux_mut < 0) entities[i]->movimentos[n] = traduz_direcao(-aux_mut);
        else if(aux_mut > 3) entities[i]->movimentos[n] = traduz_direcao(aux_mut-entities[i]->movimentos[n]);
        else entities[i]->movimentos[n] = traduz_direcao(aux_mut);
      }

      //Fim da mistura
      
      entities[i]->movimentos[entities[i]->passos_totais] = dir;
      entities[i]->passos_totais++;
    }

  }
}

// Funcao que avalia uma populacao e define o melhor da geração e o melhor de todas as gerações
void Avalia(entity **entities, int population, int *thebest, entity *thebestofthebest, float mutation, const unsigned char map[mapWidth][mapHeight]){
  thebestofthebest->dead = false;
  int melhor_dist = 0,dist;
  melhor_dist =  mapWidth*2;

  for(int i = 0; i < population; i++){
      dist = (sqrt(pow(end_x - entities[i]->x,2) + pow(end_y - entities[i]->y,2))*0.7) - (entities[i]->passos_totais*0.3);  
      if(dist < melhor_dist){
        *thebest = i;
        melhor_dist = dist; 
      }
  }
  
  if(melhor_dist < sqrt(pow((end_x - thebestofthebest->x),2) + pow(end_y - thebestofthebest->y,2)) && map[mapWidth-1 - entities[*thebest]->y][entities[*thebest]->x] != 1){
    thebestofthebest->x = entities[*thebest]->x;
    thebestofthebest->y = entities[*thebest]->y;
    for(int i=0; i<vector_size; i++){
      thebestofthebest->movimentos[i] = entities[*thebest]->movimentos[i];
    }
  }

}