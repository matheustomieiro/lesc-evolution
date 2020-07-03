#ifndef macros_h
#define macros_h

#define MATRIX_IMG "img/mapbase.png"

#define mapWidth 20
#define mapHeight 20
#define screenWidth 640
#define screenHeight 480
#define frames 0.008
#define vector_size 25600
#define end_x 18
#define end_y 18

#define initial_x 1
#define initial_y 1

typedef struct ent{
  bool dead;
  unsigned char x;
  unsigned char y;
  int passos_totais;
  char *movimentos;
}entity;

#endif