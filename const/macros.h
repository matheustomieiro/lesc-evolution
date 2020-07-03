#ifndef macros_h
#define macros_h

#define mapWidth 20
#define mapHeight 20
#define screenWidth 640
#define screenHeight 480
#define frames 0.03
#define vector_size 100
#define end_x 18
#define end_y 18

#define initial_x 12
#define initial_y 7

typedef struct ent{
  bool dead;
  unsigned char x;
  unsigned char y;
  unsigned char passos_totais;
  char *movimentos;
}entity;

#endif