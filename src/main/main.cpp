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
entity e1 = {false, radius_entity, initial_x, initial_y, 1.56, 0.5f, 0.35f, 0.05f};
entity e2 = {false, radius_entity, initial_x, initial_y, 3.67, 0.5f, 0.35f, 0.05f};
entity e3 = {false, radius_entity, initial_x, initial_y, 4.6, 0.5f, 0.35f, 0.05f};
entity e4 = {false, radius_entity, initial_x, initial_y, 3.8, 0.5f, 0.35f, 0.05f};
entity e5 = {false, radius_entity, initial_x, initial_y, 2.99, 0.5f, 0.35f, 0.05f};


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
  draw_entity(e1);
  draw_entity(e2);
  draw_entity(e3);
  draw_entity(e4);
  draw_entity(e5);
  glutSwapBuffers();
}


void timer(int){
  move_entity(&e1, 0.005);
  rotate_entity(&e1, 0.001);
  move_entity(&e2, 0.005);
  rotate_entity(&e2, 0.001);
  move_entity(&e3, 0.005);
  rotate_entity(&e3, 0.001);
  move_entity(&e4, 0.005);
  rotate_entity(&e4, 0.001);
  move_entity(&e5, 0.005);
  rotate_entity(&e5, 0.001);
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