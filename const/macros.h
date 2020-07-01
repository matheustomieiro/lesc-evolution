#include <vector>
#define mapWidth 20
#define mapHeight 20
#define screenWidth 640
#define screenHeight 480

#define speed 5
#define rotation 0.2
#define radius_entity 0.01
#define initial_x 0
#define initial_y 0

typedef struct mov{
  char direcao;
  unsigned char passos;
}movimento;

typedef struct ent{
  bool dead;
  float radius;
  float x;
  float y;
  float theta;
  float r,g,b;
  std::vector<movimento> movimentos;
}entity;
