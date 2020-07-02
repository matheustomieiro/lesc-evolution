//Main files
#include "../../const/matrix.h"
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/gui.h"
#include "../../headers/base.h"
#include <unistd.h>

using namespace std;

int QUIT = false;
int population = 0;
int fmg_value = 0;
int initial_mutation = 0.00;

char auxx[128];

entity **cockroaches;
entity thebest, thebestofthebest;


class Entity_Shape: public Fl_Widget {
  void draw(){
    fl_push_clip(x(),y(),w(),h());
    fl_push_matrix();
    fl_translate(8,200);
    fl_color(FL_RED);
    for(int i=0; i<population; i++){
      fl_circle(fl_transform_x(cockroaches[i]->x*200, cockroaches[i]->x),490+(-fl_transform_x(cockroaches[i]->y*200, cockroaches[i]->y)), radius_entity);
    }
    fl_color(FL_YELLOW);
    fl_circle(fl_transform_x(thebestofthebest.x*200, thebestofthebest.x),490+(-fl_transform_y(thebestofthebest.y*200, thebestofthebest.y)),radius_entity);
    fl_pop_matrix();
    fl_pop_clip();
  }
public:
  Entity_Shape(int X,int Y,int W,int H) : Fl_Widget(X,Y,W,H) {}
};

Fl_Double_Window *janela_principal=(Fl_Double_Window *)0;
Fl_Return_Button *start=(Fl_Return_Button *)0;
Fl_Value_Input *fmg=(Fl_Value_Input *)0;
Fl_Value_Input *populacao=(Fl_Value_Input *)0;
Fl_Value_Input *mutacao_inicial=(Fl_Value_Input *)0;
Fl_PNG_Image *png = (Fl_PNG_Image *)0;
Fl_Box *background = (Fl_Box*)0;
Entity_Shape *entities_on_matrix = (Entity_Shape*)0;


static void start_listener(Fl_Return_Button*, void*){
  fmg->deactivate();
  fmg_value = fmg->value();
  populacao->deactivate();
  population = populacao->value();
  mutacao_inicial->deactivate();
  initial_mutation = mutacao_inicial->value();
  start->deactivate();

  cockroaches = (entity**)malloc(population*sizeof(entity*));
  for(int i=0; i<population; i++) cockroaches[i] = (entity*)malloc(sizeof(entity));
  
  iniciaPop(cockroaches,population);

  entities_on_matrix->redraw();
}

/**
 Funcao que instancia a GUI
*/
Fl_Double_Window* make_window() {
  { // Janela principal da GUI
    janela_principal = new Fl_Double_Window(800, 500, "LE_EVOLUTION");
    janela_principal->color((Fl_Color)237);
    janela_principal->labelfont(11);
    { // Imagem do cenario
      background = new Fl_Box(375,20,400,400);
      background->box(FL_SHADOW_BOX);
      png = new Fl_PNG_Image("img/map.png");
      background->image(png);
      entities_on_matrix = new Entity_Shape(375,20,400,400);
    } // Fl_Box* image
    { // Comeca o ciclo de evolucao
      start = new Fl_Return_Button(150, 180, 115, 30, "INICIAR");
      start->box(FL_RSHADOW_BOX);
      start->color((Fl_Color)215);
      start->labelfont(11);
      start->callback((Fl_Callback*)start_listener);
    } // Fl_Button* start
    { // Fator de mistura genetica
      fmg = new Fl_Value_Input(180, 35, 180, 25, "FMG:");
      fmg->box(FL_SHADOW_BOX);
      fmg->color((Fl_Color)215);
      fmg->labelfont(11);
      fmg->textfont(11);
    } // Fl_Value_Input* fmg
    { // Numero de individuos da populacao
      populacao = new Fl_Value_Input(180, 75, 180, 25, "INDIVIDUOS:");
      populacao->box(FL_SHADOW_BOX);
      populacao->color((Fl_Color)215);
      populacao->labelfont(11);
      populacao->textfont(11);
    } // Fl_Value_Input* populacao
    { // Taxa de mutacao inicial
      mutacao_inicial = new Fl_Value_Input(180, 120, 180, 25, "MUTACAO INICIAL:");
      mutacao_inicial->box(FL_SHADOW_BOX);
      mutacao_inicial->color((Fl_Color)215);
      mutacao_inicial->labelfont(11);
      mutacao_inicial->textfont(11);
    } // Fl_Value_Input* mutacao_inicial
    janela_principal->show();
    janela_principal->end();
  } // Fl_Double_Window* janela_principal
  return janela_principal;
}

//Thread function to evolve A.G
void *evolve_routine(void*){
  //Instancing entities
  while(!QUIT){
    //printf("Evolving...\n"); //TODO: Substituir evolucao aqui
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv){

  fl_register_images(); 
  make_window();

  //##### Opening threads #####//
  pthread_t evolution;
  pthread_create(&evolution, NULL, evolve_routine, NULL);
  //###########################//

  return Fl::run();
}