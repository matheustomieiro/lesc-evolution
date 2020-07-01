//Main files
#ifdef __APPLE__
  #include <GLUT/glut.h>
#else
  #include <GL/glut.h>
#endif
#include "../../const/macros.h"
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int QUIT = false;
entity pop[population];


void setAtr(entity *e, bool dead, float radius, float x, float y, float theta, float r, float g, float b){
  e->dead = dead; e->radius = radius; e->x = x; e->y = y; e->theta = theta; e->r = r; e->g = g; e->b = b;
}

void rotate_entity(entity *e, float angle){
    e->theta+=angle;
}

void move_entity(entity *e, float d){
  e->x = e->x + d*speed*cos(e->theta);
  e->y = e->y + d*speed*sin(e->theta);
  if(e->x > 1) e->x = -0.9; if(e->x < -1) e->x = 0.9;//X nao passa de 1 nem -1
  if(e->y > 1) e->y = -0.9; if(e->y < -1) e->y = 0.9; //Y nao passa de 1 nem -1
}

void draw_entity(entity e){
  float x = e.x;
  float y = e.y;
  float theta = e.theta;
  float radius = e.radius;

  glBegin(GL_POLYGON);
  glColor3f(e.r, e.g, e.b);
  for (int i = 0; i < 360; i+=45) {
    glVertex2d(((radius*2)*cos(i/180.0*M_PI)+x), radius*sin(i/180.0*M_PI)+y);
  }
  glEnd();
  glBegin(GL_LINES);
  glColor3f(e.r, e.g, e.b);
  glVertex2d(x-(radius*6),y+(radius*3));
  glVertex2d(x-(radius*1.5),y);
  glVertex2d(x-(radius*6),y+(radius*-3));
  glVertex2d(x-(radius*1.5),y);
  glEnd();
}

void draw(){
  glClear(GL_COLOR_BUFFER_BIT);
  for(int i=0; i<population; i++){
    draw_entity(pop[i]);
  }
  glutSwapBuffers();
}


void timer(int){
  for(int i=0; i<population; i++){
    move_entity(&pop[i], 0.01 + i/10);
    rotate_entity(&pop[i], 0.15 + i/10);
  }
  //Redesenhando
  glutPostRedisplay();
  glutTimerFunc(1000/60, timer, 0);
}

//Thread function to evolve A.G
void *evolve_routine(void*){
  //Instancia entidades
  while(!QUIT){
    printf("Evolving...\n"); //TODO: Substituir evolucao aqui
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv){

  for(int i=0; i<population; i++){
    setAtr(&pop[i], false, radius_entity, initial_x, initial_y, i/156+0.56, 0.5f, 0.35f, 0.05f);
  }

  //Abrindo Gui
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(screenWidth, screenHeight);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("Labyrinth Escape Evolution");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glutDisplayFunc(draw);
  glutTimerFunc(0, timer, 0);// Define qual será a função de loop
  glutMainLoop();

  //##### Abrindo threads #####//
  pthread_t evolution;
  pthread_create(&evolution, NULL, evolve_routine, NULL);
  pthread_join(evolution, NULL);
  //###########################//

  return EXIT_SUCCESS;
}