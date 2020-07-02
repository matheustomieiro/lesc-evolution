#ifndef macros_h
#define macros_h

#include <vector>
#define mapWidth 20
#define mapHeight 20
#define screenWidth 640
#define screenHeight 480

#define radius_entity 2
#define initial_x 5.0
#define initial_y 5.0

typedef struct mov{
  char direcao;
  unsigned char passos;
}movimento;

typedef struct ent{
  bool dead;
  float x;
  float y;
  std::vector<movimento> *movimentos;
}entity;

#endif