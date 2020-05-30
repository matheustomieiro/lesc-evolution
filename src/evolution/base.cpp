#include "../../headers/base.h"
#include "../../const/macros.h"
#include "stdio.h"
#include "stdlib.h"

movimento aux;

movimento new_movement(char mov_type, unsigned char ){
  aux.direcao = 'f';
  aux.passos = 5;
  return aux;
}

void printAlgo(){
  printf("HELLO?\n");
  //e[blabla]->movimentos.push_back(new_movement('f',10));
}