# Lesc-Evolution
Este projeto desenvolvido na disciplina Sistemas Evolutivos Aplicados a Robotica-USP/ICMC, implementa o Labyrinth Escape Evolution, mas de um jeito inusitado. Temidas por muitos, as baratas são uma das especies mais antigas da terra - Evidencias arqueológicas indicam que esta especie está presente no planeta a cerca de 380 milhões de ano. Resistentes à variadas temperaturas e umidade, elas são simbolo de resistência e sofreram pouca evolução genética. 

        ,--.     .--. 														  ,--.     .--. 
      /     \. ./     \ 												        /     \. ./     \ 
     /   /\ / " \ /\   \												       /   /\ / " \ /\   \
      __/  {~~v~~}  \__  												        __/  {~~v~~}  \__  
          {   |   }													            {   |   }      
       /\{    |    }/\													         /\{    |    }/\                    
    __/  {    |    }  \__												      __/  {    |    }  \__			
	 {    |    }	       	.__                                                   .__          __  .__               	   {    |    }
	/{    |    }\		|  |   ____   ______ ____             _______  ______ |  |  __ ___/  |_|__| ____   ____           /{    |    }\
       / {    |    } \		|  | _/ __ \ /  ___// ___\   ______ _/ __ \  \/ /  _ \|  | |  |  \   __\  |/  _ \ /    \         / {    |    } \
      /  {    |    }  \		|  |_\  ___/ \___ \\  \___  /_____/ \  ___/\   (  <_> )  |_|  |  /|  | |  (  <_> )   |  \       /  {    |    }  \
      \  \    |    /  /	 	|____/\___  >____  >\___  >          \___  >\_/ \____/|____/____/ |__| |__|\____/|___|  /       \  \    |    /  /
       \  \   |   /  /	    	          \/     \/     \/               \/                                           \/         \  \   |   /  /
        \  \  |  /  /    													  \  \  |  /  /
         \  \ | /  /   														   \  \ | /  /  
        /   ~~~~~   \  														  /   ~~~~~   \   

## Alunos
>Felipe Oliveira
>Matheus Tomieiro
>Victor Vieira Custodio Reis
>Yago Poletto

## Linguagem utilizada
 O algoritmo evolutivo foi escrito em C e C++.

## Como executar
Run Makefile
 
## Funcionamento
As baratas precisam evoluir para superar os obstáculos do Maze e alcançar a saída. Para evoluir, inicialmente a barata considera a distancia euclídia até o ponto de saída e as coordenadas vizinhas (x,y). A partir da primeira barata, filhas surgem e se movem nos eixos x e y e recalculam a distancia euclidiana. A cada iteração de evolução, o individuo filho compara se é superior ao melhor individuo da evolução até o momento, ou seja, caso o seu **x** e **y** for maior que melhor individuo e a distancia euclidiana menor, ele se torna o melhor individuo até ser substituído na evolução por outra barata melhor. 


Em andamento...
