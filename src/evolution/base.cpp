#include "../../headers/base.h"
#include "../../const/macros.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>
#include <ctime>


movimento aux;

movimento new_movement(char mov_type, unsigned char qtd){
  aux.direcao = mov_type;
  aux.passos = qtd;
  return aux;
}

//Funcao que calcula uma funcao pre-definida
//args: (double) x
double PreFunction(double x){

  return (2*cos(0.39*x)) + (5*sin(0.5*x)) + (0.5*cos(0.1*x)) + (10*sin(0.7*x)) + (5*sin(1*x)) + (5*sin(0.35*x));  

}

// Funcao que avalia uma populacao e define o melhor e o pior
void Avaliar(){

  for(int x = 1; x <= TAMPOPULACAO; x++){

    if(f[x] > f[MELHOR]) MELHOR = x;
    if(f[x] < f[PIOR]) PIOR = x;
  }

  if(THEBESTOFTHEBEST[1] < f[MELHOR]){
    THEBESTOFTHEBEST[0] = POPULATION[MELHOR];
    THEBESTOFTHEBEST[1] = f[MELHOR];
  }       

}


void initialEvo(){

  srand(time(NULL));

  for(int i = 1; i <= TAMPOPULATION; i++){
  
    POPULATION[i] = -10;

  }

  for(int i = 1; i <= TAMPOPULATION; i++){

    f[i] = -10;

  }

}


void iniciaPop(){

  srand(time(NULL));

  for(int i = 1; i <= TAMPOPULATION; i++){
    POPULATION[i] = rand()%TAM_AMBIENTE;
  }

  for(int x = 1; x <= TAMPOPULATION; x++){
    f[x] = PreFunction(POPULATION[x]);
  }

}


void Transa(){

  for(int i = 1; i <= TAMPOPULATION; i++){

    if(i != MELHOR){
      srand(time(NULL));
      //revisar
      POPULATION[i] = (POPULATION[i] + POPULATION[floor(rand()%TAMPOPULATION)]*((rand()%430)/1000.0) +  (POPULATION[MELHOR]*(rand()%388)/1000.0) + (THEBESTOFTHEBEST[0]*(rand()%588)/1000))/(rand()%4);

      //POPULATION[math.floor(math.random(1,TAMPOPULATION))]*((math.random(0,429))/1000.0)) + (POPULATION[MELHOR]*((math.random(0,387))/1000.0)) + (THEBESTOFTHEBEST[1]*((math.random(0,587))/1000.0)))/math.floor(math.random(1, 3))   
    }

    double aux = (POPULATION[i] + (rand()%(TAM_AMBIENTE - (-TAM_AMBIENTE)))*(MUTACAO));

    if(aux < TAM_AMBIENTE && aux > 0){
      POPULATION[i] = aux;
    }else{
      if(aux > TAM_AMBIENTE){
         POPULATION[i] = (TAM_AMBIENTE-abs(aux-TAM_AMBIENTE))%TAMPOPULATION;
      }
      else{
         POPULATION[i] = (abs(aux-TAM_AMBIENTE))%TAMPOPULATION
      }
    }

    f[i] = PreFunction(POPULATION[i]);

  }

}