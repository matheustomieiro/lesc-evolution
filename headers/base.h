#include "../const/macros.h"

void iniciaPop(entity **entities, int population);
void Transa(entity **entities, entity *thebest, entity *thebestofthebest, int population, float mutation, const unsigned char map[mapWidth][mapHeight]);
void Avalia(entity **entities, int population, entity *thebest, entity *thebestofthebest, float mutation);