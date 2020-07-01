//Main files
#include "../../const/macros.h"
#include <iostream>
#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/gui.h"

using namespace std;

int QUIT = false;

Fl_Double_Window *janela_principal=(Fl_Double_Window *)0;
Fl_Return_Button *start=(Fl_Return_Button *)0;
Fl_Value_Input *fmg=(Fl_Value_Input *)0;
Fl_Value_Input *populacao=(Fl_Value_Input *)0;
Fl_Value_Input *mutacao_inicial=(Fl_Value_Input *)0;
Fl_JPEG_Image *jpg = (Fl_JPEG_Image *)0;
Fl_Box *background = (Fl_Box*)0;

static void start_listener(Fl_Return_Button*, void*){
  fmg->deactivate();
  populacao->deactivate();
  mutacao_inicial->deactivate();
  start->deactivate();
}

/**
 Funcao que instancia a GUI
*/
Fl_Double_Window* make_window() {
  { // Janela principal da GUI
    janela_principal = new Fl_Double_Window(870, 405, "LE_EVOLUTION");
    janela_principal->color((Fl_Color)237);
    janela_principal->labelfont(11);
    { // Imagem do cenario
      fl_register_images();
      background = new Fl_Box(10,10,screenWidth,screenHeight);
      jpg = new Fl_JPEG_Image("/var/tmp/foo.jpg");
      background->image(jpg);
    } // Fl_Box* image
    { // Comeca o ciclo de evolucao
      start = new Fl_Return_Button(185, 350, 115, 30, "INICIAR");
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
    janela_principal->end();
    janela_principal->show();
  } // Fl_Double_Window* janela_principal
  return janela_principal;
}

//Thread function to evolve A.G
void *evolve_routine(void*){
  //Instancing entities
  while(!QUIT){
    printf("Evolving...\n"); //TODO: Substituir evolucao aqui
  }
  pthread_exit(NULL);
}

int main(int argc, char **argv){

  fl_register_images(); 


  //##### Opening threads #####//
  pthread_t evolution;
  pthread_create(&evolution, NULL, evolve_routine, NULL);
  pthread_join(evolution, NULL);
  //###########################//

  return Fl::run();
}