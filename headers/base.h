#include "../const/macros.h"

void iniciaPop(entity **entities, int population);
void Transa(entity **entities, int *thebest, entity *thebestofthebest, int population, float mutation);
void Avalia(entity **entities, int population, int *thebest, entity *thebestofthebest, float mutation, const unsigned char map[mapWidth][mapHeight], int best_x, int best_y, char *melhor_movimento);