#include "../../headers/base.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <time.h>

using namespace std;

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
    
    num_direcao = (rand()+i)%4;

    switch (num_direcao){
      
      case 0:
        dir = 'u';
        break;
      case 1:
        dir = 'd';
        break;
      case 2:
        dir = 'l';
        break;
      case 3:
        dir = 'r';
        break;
    }
    entities[i]->movimentos = (char*)calloc(vector_size,sizeof(char));
    entities[i]->movimentos[entities[i]->passos_totais] = dir;
    entities[i]->passos_totais++;
  }
}

void Transa(entity **entities, entity *thebest, entity *thebestofthebest, int population, float mutation){

  for(int i = 0; i < population; i++){
    srand(time(NULL));
    rand();rand();rand();

    //ind_rand = (int) ((rand()%population + (rand()%430/1000.0 +  thebestofthebest->x*((rand()%388)/1000.0) + thebest->x*((rand()%588)/1000)))*(mutation))%(population-1);

  }
}

// Funcao que avalia uma populacao e define o melhor da geração e o melhor de todas as gerações
void Avalia(entity **entities, int population, entity *thebest, entity *thebestofthebest, float mutation){

  int melhor_dist = 0,dist;
  melhor_dist =  mapWidth*2;

  for(int i = 0; i < population; i++){
      dist = sqrt(pow(end_x - entities[i]->x,2) + pow(end_y - entities[i]->y,2));
      printf("DIST: %d\n",dist);    
      if(dist < melhor_dist){
        thebest->x = entities[i]->x;
        thebest->y = entities[i]->y;
        thebest->dead = entities[i]->dead;
        *(thebest->movimentos) = *(entities[i]->movimentos);
        melhor_dist = dist; 
      }
  }

  if(melhor_dist < sqrt(pow(abs(thebestofthebest->x - 18),2) + pow(abs(thebestofthebest->y - 18),2))){
    thebestofthebest->x = thebest->x;
    thebestofthebest->y = thebest->y;
    thebestofthebest->dead = thebest->dead;
    thebestofthebest->movimentos = thebest->movimentos;
  }

}

/*
void Transa(entity* entities, entity thebest){

  char mov_rand[2];

  for(int i = 0; i < population; i++){

    if(entities[i].r != thebest.r && entities[i].g != thebest.g && entities[i].b != thebest.b){
      srand(time(NULL));
      //revisar
      entities[i] = (entities[i].x + entities[floor(rand()%population)].x*((rand()%430)/1000.0) +  (thebest.x*(rand()%388)/1000.0) + (THEBESTOFTHEBEST[0]*(rand()%588)/1000))/(rand()%4);

      //POPULATION[math.floor(math.random(1,TAMPOPULATION))]*((math.random(0,429))/1000.0)) + (POPULATION[MELHOR]*((math.random(0,387))/1000.0)) + (THEBESTOFTHEBEST[1]*((math.random(0,587))/1000.0)))/math.floor(math.random(1, 3))   
    }

    double auxx = (entities[i].x + (rand()%(mapWidth - (-mapWidth)))*(initial_mutation));
    double auxy = (entities[i].y + (rand()%(mapHeight - (-mapHeight)))*(initial_mutation));

    if(auxy < mapHeight && auxx > 0){
      entities[i].y = auxy;
    }else{
      if(auxy > mapHeight){
        entities[i].y = (mapHeight-abs(auxx-mapWidth))%population;
      }
      else{
        entities[i].x = (abs(auxx-mapWidth))%population;
      }
    }
  

    if(auxx < mapWidth && auxx > 0){
      entities[i].x = auxx;
    }else{
      if(auxx > mapWidth){
        entities[i].x = (mapWidth-abs(auxx-mapWidth))%population;
      }
      else{
        entities[i].x = (abs(auxx-mapWidth))%population;
      }
    }

  }
}

*/
