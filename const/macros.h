#ifndef macros_h
#define macros_h

#include <vector>
#define mapWidth 20
#define mapHeight 20
#define screenWidth 640
#define screenHeight 480
#define frames 0.1
#define vector_size 100

#define initial_x 1
#define initial_y 1

typedef struct mov{
  char direcao;
  unsigned char passos;
}movimento;

typedef struct ent{
  bool dead;
  unsigned char x;
  unsigned char y;
  unsigned char passos_totais;
  movimento *movimentos;
}entity;

#endif