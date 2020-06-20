#include "../../headers/base.h"
#include "../../const/macros.h"
#include "stdio.h"
#include "stdlib.h"

movimento aux;

movimento new_movement(char mov_type, unsigned char qtd){
  aux.direcao = mov_type;
  aux.passos = qtd;
  return aux;
}

