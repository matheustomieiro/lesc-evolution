#include "../../headers/base.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <ctime>

using namespace std;

movimento aux;

movimento new_movement(char mov_type, unsigned char qtd){
  aux.direcao = mov_type;
  aux.passos = qtd;
  return aux;
}

void iniciaPop(entity **entities, int population){
  int num_direcao, num_passos;
  char dir;

  for(int i = 0; i < population; i++){
    
    entities[i]->dead = false;
    entities[i]->x = initial_x;
    entities[i]->y = initial_y;

    srand(time(NULL));
    num_direcao = rand()%4;
    num_passos = rand()%5 + 1;

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
    entities[i]->movimentos = new std::vector<movimento>;
    entities[i]->movimentos->push_back(new_movement(dir,num_passos));
  }
}

void Transa(entity **entities, entity *thebest, entity *thebestofthebest, int population, float mutation, const unsigned char map[mapWidth][mapHeight]){

  movimento moves[2];
  char chosen_mov, rand_dir[2];
  int ind_rand,chosen_passos, rand_passos;

  for(int i = 0; i < population; i++){
    srand(time(NULL));

    ind_rand = (int) ((rand()%population + (rand()%430/1000.0 +  thebestofthebest->x*((rand()%388)/1000.0) + thebest->x*((rand()%588)/1000)))*(mutation))%population;

    moves[0] = entities[ind_rand]->movimentos->at(entities[ind_rand]->movimentos->size() - 1);
    moves[1] = entities[i]->movimentos->at(entities[ind_rand]->movimentos->size() - 1);

    rand_dir[0] = moves[0].direcao;
    rand_dir[1] = moves[1].direcao;

    if(rand_dir[0] == rand_dir[1]) chosen_mov = rand_dir[0];
    else{
      chosen_mov = rand_dir[rand()%2];
    }

    if(moves[0].passos > moves[1].passos) chosen_passos = moves[0].passos;
    else{
      chosen_passos = moves[1].passos;
    } 
    //Problema aqui???
    //entities[i]->movimentos->push_back(new_movement(chosen_mov, chosen_passos));

    if(chosen_mov == 'u'){
      entities[i]->x = entities[i]->x + 1;
    }
    else if(chosen_mov == 'd'){
      entities[i]->x = entities[i]->x - 1;
    }
    else if(chosen_mov == 'l'){
      entities[i]->y = entities[i]->y - 1;
    }
    else if(chosen_mov == 'r'){
      entities[i]->y = entities[i]->y + 1;
    }
    if(map[mapWidth - entities[i]->x][mapHeight - entities[i]->y]) entities[i]->dead = true;
  }
}

// Funcao que avalia uma populacao e define o melhor da geração e o melhor de todas as gerações
void Avalia(entity **entities, int population, entity *thebest, entity *thebestofthebest, float mutation){

  double melhor_dist = 0,dist;
  melhor_dist =  mapWidth*2;

  for(int i = 0; i < population; i++){
    if(!entities[i]->dead){
      dist = sqrt(pow(abs(entities[i]->x - 18),2) + pow(abs(entities[i]->y - 18),2));      
      if(dist < melhor_dist){
        thebest->x =  entities[i]->x;
        thebest->y = entities[i]->y;
        thebest->dead = entities[i]->dead;
        thebest->movimentos = entities[i]->movimentos;
        melhor_dist = dist; 
      }
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
