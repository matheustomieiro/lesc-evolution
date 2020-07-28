# Lesc-Evolution
Este projeto desenvolvido na disciplina Sistemas Evolutivos Aplicados a Robotica-USP/ICMC, implementa o Labyrinth Escape Evolution, mas de um jeito inusitado, utilizando computação evolutiva. Temidas por muitos, as baratas são uma das especies mais antigas da terra - Evidências arqueológicas indicam que esta espécie está presente no planeta a cerca de 380 milhões de ano. Resistentes à variadas temperaturas e umidade, elas são simbolo de resistência e curiosamente sofreram pouca evolução genética. 

        ,--.     .--. 
      /     \. ./     \ 
	 /   /\ / " \ /\   \
      __/  {~~v~~}  \__  
          {   |   }      
       /\{    |    }/\    
    __/  {    |    }  \__   
         {    |    }      
        /{    |    }\     
       / {    |    } \    
      /  {    |    }  \   
      \  \    |    /  /   
       \  \   |   /  /    
        \  \  |  /  /     
        /   ~~~~~   \     

## Alunos
Felipe Oliveira

Matheus Tomieiro

Victor Vieira Custodio Reis

Yago Poletto

## Linguagem utilizada

 O algoritmo evolutivo foi escrito em C e C++ e utiliza FLTK como Interface Gráfica.

 ## Como executar
 Antes de tudo, instale as biblioteca utilizando o comando <code>make install_libs</code> na pasta raiz do projeto;
 
 - Para executar(em Linux ou MACOSX):
 ```shell
make
make run
 ```
 - Para Windows há um versão pré-compilada(Em desenvolvimento...).
 
## Funcionamento
As baratas precisam evoluir para superar os obstáculos do Maze e alcançar a saída. Para evoluir, inicialmente a barata considera a distancia euclídiana até o ponto de saída e as coordenadas vizinhas (x,y). A partir da barata melhor pontuada, filhas surgem e se movem nos eixos x e y e recalculam a distancia euclidiana. A cada iteração de evolução, o individuo filho compara se é superior ao melhor individuo da evolução até o momento, ou seja, caso o seu **x** e **y** for maior que melhor individuo e a distancia euclidiana menor, ele se torna o melhor individuo até ser substituído na evolução por outra barata melhor. Caso a barata fique presa em um canto, os pesos de pontuação mudarão e a barata comecerá a pontuar para outro lado do labirinto, sendo possível que ache outra rota.
