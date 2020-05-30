//Main file
#include "../../headers/gui.h"
#include "../../const/macros.h"
#include "pthread.h"

//Thread function to instantiate the GUI
void *inst_gui(void*){
  gui_instantiate();
  pthread_exit(NULL);
}

//Thread function to evolve A.G
void *evolve_routine(void*){
  while(1){
    printf("Evolving...\n"); //TODO: Substituir evolucao aqui
  }
  pthread_exit(NULL);
}

int main(int argc, char *argv[]){

  //##### Abrindo threads #####//
  pthread_t gui, evolution;
  //thread_create(&evolution, NULL, evolve_routine ,NULL);
  pthread_create(&gui, NULL, inst_gui, NULL);
  pthread_join(gui,NULL);
  //###########################//

  return EXIT_SUCCESS;
}
