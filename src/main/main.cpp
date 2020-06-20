//Main files
#include "../../const/macros.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int QUIT = false;

//Thread function to instantiate the GUI
void *inst_gui(void*){
  //GUI
  QUIT = true;
  pthread_exit(NULL);
}

//Thread function to evolve A.G
void *evolve_routine(void*){
  //Instancia entidades
  while(!QUIT){
    printf("Evolving...\n"); //TODO: Substituir evolucao aqui
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){

  //##### Abrindo threads #####//
  pthread_t gui, evolution;
  pthread_create(&gui, NULL, inst_gui, NULL);
  pthread_create(&evolution, NULL, evolve_routine, NULL);
  pthread_join(gui, NULL);
  pthread_join(evolution, NULL);
  //###########################//

  return EXIT_SUCCESS;
}
