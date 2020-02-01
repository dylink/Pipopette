#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define J1 -2
#define IA 2
#define grille(i,j) grille[i*(L)+j]
#define C 11
#define L 11
typedef int plateau[(C)*(L)];

typedef struct compteur {
  int compt1;
  int compt2;
} compteur;

void initPlateau(plateau grille);
void affichePlateau(plateau grille);
