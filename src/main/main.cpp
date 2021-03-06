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
#include <math.h>
#include <time.h>
#include <X11/Xlib.h> 

using namespace std;

int QUIT = false;
bool start_pressed;
int population = 0;
int ge_value = 0;
float initial_mutation = 0.00;
int gen = 0;
struct timespec tim, tim2;
bool mut_var = true;
int FIM = 0;

entity **cockroaches;
entity *thebestofthebest;
int *thebest;

class Entity_Shape: public Fl_Widget {
  void draw(){
    fl_push_clip(x(),y(),w(),h());
    fl_push_matrix();
    fl_color(66,27,22);
    for(int i=0; i<population; i++){
      if(!cockroaches[i]->dead)
        fl_rectf(x()+(cockroaches[i]->x*mapWidth), y()+(380-(cockroaches[i]->y)*mapHeight), mapWidth, mapHeight);
    }
    fl_color(167,114,17);
    if(!thebestofthebest->dead){
      fl_rectf(x()+(thebestofthebest->x*mapWidth), y()+(380-(thebestofthebest->y)*mapHeight), mapWidth, mapHeight);
    }
    fl_pop_matrix();
    fl_pop_clip();
  }
public:
  Entity_Shape(int X,int Y,int W,int H) : Fl_Widget(X,Y,W,H) {}
};

Fl_Double_Window *janela_principal=(Fl_Double_Window *)0;
Fl_Return_Button *start=(Fl_Return_Button *)0;
Fl_Value_Input *ge=(Fl_Value_Input *)0;
Fl_Value_Input *populacao=(Fl_Value_Input *)0;
Fl_Value_Input *mutacao_inicial=(Fl_Value_Input *)0;
Fl_PNG_Image *png = (Fl_PNG_Image *)0;
Fl_Box *background = (Fl_Box*)0;
Fl_Box *generation = (Fl_Box*)0;
Fl_Box *mutation = (Fl_Box*)0;
Fl_Chart *fitness = (Fl_Chart*)0;
Fl_Chart *distancia_thebestofthebest = (Fl_Chart*)0;
Entity_Shape *entities_on_matrix = (Entity_Shape*)0;

static void update(void*){
  if(FIM == 1){
    FIM = 2;
    fl_alert("Chegou ao destino!");
    QUIT = 1;
  }
  entities_on_matrix->redraw();
  janela_principal->redraw();
  srand(time(NULL));rand();rand();rand();
  Fl::repeat_timeout(frames, update);
}


static void start_listener(Fl_Return_Button*, void*){
  ge->deactivate();
  ge_value = ge->value();
  populacao->deactivate();
  population = (int)floor(populacao->value());
  mutacao_inicial->deactivate();
  initial_mutation = (float)mutacao_inicial->value();
  start->deactivate();
  cockroaches = (entity**)malloc(population*sizeof(entity*));
  for(int i=0; i<population; i++) cockroaches[i] = (entity*)malloc(sizeof(entity));
  iniciaPop(cockroaches,population);
  entities_on_matrix->show();
  entities_on_matrix->redraw();
  janela_principal->redraw();
  start_pressed = true;
  Fl::add_timeout(0.01,update);
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
      //background->box(FL_SHADOW_BOX);
      png = new Fl_PNG_Image(MATRIX_IMG);
      background->image(png);
      entities_on_matrix = new Entity_Shape(375,20,400,400);
      entities_on_matrix->hide();
      generation = new Fl_Box(375,440,400,20);
      generation->label("GERACAO : 0");
      generation->box(FL_THIN_UP_BOX);
      generation->color((Fl_Color)238);
      //mutation = new Fl_Box(375,470,400,20);
      //mutation->label("MUTACAO : 0.0");
      //mutation->box(FL_THIN_UP_BOX);
      //mutation->color((Fl_Color)238);
    } // Fl_Box* image
    {
      fitness = new Fl_Chart(30, 235, 330, 97, "Fitness");
      fitness->type(2/*FL_LINE_CHART*/);
      distancia_thebestofthebest = new Fl_Chart(30,362,330,97,"Passos TheBest");
      distancia_thebestofthebest->type(2);
      distancia_thebestofthebest->bounds(-2,10);
      //distancia_thebestofthebest->autosize(1);
    }
    { // Comeca o ciclo de evolucao
      start = new Fl_Return_Button(150, 180, 115, 30, "INICIAR");
      //start->box(FL_RSHADOW_BOX);
      start->color((Fl_Color)215);
      start->labelfont(11);
      start->callback((Fl_Callback*)start_listener);
    } // Fl_Button* start
    { // Fator de mistura genetica
      ge = new Fl_Value_Input(180, 35, 180, 25, "GE:");
      //ge->box(FL_SHADOW_BOX);
      ge->value(23);
      ge->color((Fl_Color)215);
      ge->labelfont(11);
      ge->textfont(11);
    } // Fl_Value_Input* ge
    { // Numero de individuos da populacao
      populacao = new Fl_Value_Input(180, 75, 180, 25, "INDIVIDUOS:");
      //populacao->box(FL_SHADOW_BOX);
      populacao->value(800);
      populacao->color((Fl_Color)215);
      populacao->labelfont(11);
      populacao->textfont(11);
    } // Fl_Value_Input* populacao
    { // Taxa de mutacao inicial
      mutacao_inicial = new Fl_Value_Input(180, 120, 180, 25, "MUTACAO INICIAL:");
      mutacao_inicial->value(13);
      //mutacao_inicial->box(FL_SHADOW_BOX);
      mutacao_inicial->color((Fl_Color)215);
      mutacao_inicial->labelfont(11);
      mutacao_inicial->textfont(11);
    } // Fl_Value_Input* mutacao_inicial
    janela_principal->show();
    janela_principal->end();
  } // Fl_Double_Window* janela_principal
  return janela_principal;
}

bool all_dead(){
  bool is_all_dead = true;
  for(int i=0; i<population; i++){
    if(!cockroaches[i]->dead) is_all_dead = false; 
  }
  return is_all_dead;
}

void restart_pop(int x, int y){
  for(int i=0; i<population; i++){
    cockroaches[i]->x = x;
    cockroaches[i]->y = y;
    cockroaches[i]->dead = false;
    cockroaches[i]->passos_totais = 20;
  }
}


//Thread function to evolve A.G
void *evolve_routine(void*){
  int best_x = initial_x, best_y = initial_y, last_bx = best_x, last_by = best_y;
  char *melhor_movimento = (char*)malloc(sizeof(char)*vector_size);
  int fator = 1, fator2 = 1;
  int geracoes_trancado = 0;
  //Instancing entities
  while(FIM != 1){
    if(start_pressed){
        gen++;
        for(int j=0; j<vector_size; j++){
          if(all_dead()) break;
          for(int i=0; i<population; i++){
            if(j >= cockroaches[i]->passos_totais) cockroaches[i]->dead = true;
            if(!cockroaches[i]->dead && cockroaches[i]->movimentos[j] != 'n'){
              if(cockroaches[i]->movimentos[j] == 'd'){        //RIGHT
                cockroaches[i]->x += 1;
              }else if(cockroaches[i]->movimentos[j] == 'c'){  //LEFT
                cockroaches[i]->x -= 1;
              }else if(cockroaches[i]->movimentos[j] == 'b'){  //DOWN
                cockroaches[i]->y -= 1;
              }else if(cockroaches[i]->movimentos[j] == 'a'){  //UP
                cockroaches[i]->y += 1;
              }

              //Definicoes de como as baratas andam no labirinto
              if(map[mapWidth-1 - cockroaches[i]->y][cockroaches[i]->x] == 1) cockroaches[i]->dead =true; //Morre ao encostar numa parede
              if(map[mapWidth-1 - cockroaches[i]->y][cockroaches[i]->x] == 2){
                FIM = 1;
              }
              
              //Parte avaliativa quanto ao best_x e o best_y
              if(fator2*cockroaches[i]->x >= best_x && fator*cockroaches[i]->y >= fator*best_y && !cockroaches[i]->dead){
                best_x = cockroaches[i]->x;
                best_y = cockroaches[i]->y;
                for(int p=0; p<cockroaches[i]->passos_totais; p++){
                  melhor_movimento[p] = cockroaches[i]->movimentos[p];
                }
                mut_var = false;
                geracoes_trancado = 0;
              }

              //Distancia euclidiana modificada com os pesos
              if((sqrt(pow(end_x - cockroaches[i]->x,2) + pow(end_y - cockroaches[i]->y,2))) < fator*(sqrt(pow(end_x - thebestofthebest->x,2) + pow(end_y - thebestofthebest->y,2))) && !cockroaches[i]->dead){
                best_x = cockroaches[i]->x;
                best_y = cockroaches[i]->y;
                for(int p=0; p<cockroaches[i]->passos_totais; p++){
                  melhor_movimento[p] = cockroaches[i]->movimentos[p];
                }
                mut_var = false;
                geracoes_trancado = 0;
              }

              geracoes_trancado++;

              //Fim das definicoes
            }
          }
          nanosleep(&tim,&tim2);
        }
      nanosleep(&tim,&tim2);
      Avalia(cockroaches,population,thebest,thebestofthebest,initial_mutation,map,best_x, best_y, melhor_movimento);
      Transa(cockroaches,thebest,thebestofthebest,population,initial_mutation);
      restart_pop(best_x, best_y);
      //printf("\t%d\n%d\t\t%d\n\t%d\nVS:%d\n", map[mapWidth-1 - thebestofthebest->y-1][thebestofthebest->x], map[mapWidth-1 - thebestofthebest->y][thebestofthebest->x-1], map[mapWidth-1 - thebestofthebest->y][thebestofthebest->x+1], map[mapWidth-1 - thebestofthebest->y+1][thebestofthebest->x],cockroaches[0]->passos_totais);
      string aux_gen, aux_mutation;
      aux_gen.append("GERACAO : ");
      aux_gen.append(to_string(gen));
      generation->label(aux_gen.c_str());
      printf("Mutacao: %.4f\n",initial_mutation);

      if(geracoes_trancado >= (int)(ge_value*2)){
        geracoes_trancado = 0;
        fator2 = -fator2;
      }
     

      if(gen%ge_value == 0){
        fator = -fator;
      }

      if((gen%13) == 0 || (gen%57 == 0)){
        fator = -fator;
        fator2 = -fator2;
      }
      if(gen%13 == 0){
        if(true){
          if(initial_mutation > 10000) initial_mutation = mutacao_inicial->value();
          else initial_mutation *= 3;
          mut_var = true;
        }
      }

      fitness->add(-sqrt(pow(end_x - thebestofthebest->x,2) + pow(end_y - thebestofthebest->y,2)));
      distancia_thebestofthebest->add(sqrt(pow(best_x - last_bx,2) + pow(best_y - last_by,2)));
    }

    mut_var = true;
    last_bx = best_x; last_by = best_y;
  }
  free(melhor_movimento);
  pthread_exit(NULL);
}

static void setInitialTheBest(){
  thebestofthebest = (entity*)malloc(sizeof(entity));
  thebest = (int*)malloc(sizeof(int));
  *thebest = 0;
  thebestofthebest->dead = true;
  thebestofthebest->movimentos = (char*)malloc(sizeof(char)*vector_size);
  thebestofthebest->x = initial_x;
  thebestofthebest->y = initial_y;
}

int main(int argc, char **argv){

  XInitThreads();

  tim.tv_sec  = 0;
  tim.tv_nsec = SEC;

  setInitialTheBest();

  fl_register_images(); 
  make_window();

  //##### Opening threads #####//
  pthread_t evolution;
  pthread_create(&evolution, NULL, evolve_routine, NULL);
  //###########################//

  Fl::run();

  free(thebest);
  free(thebestofthebest->movimentos);
  free(thebestofthebest);
  for(int i=0; i<population; i++){
    free(cockroaches[i]->movimentos);
    free(cockroaches[i]);
  }
  free(cockroaches);
  
  return EXIT_SUCCESS;
}
