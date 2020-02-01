#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "IA.h"

int alea(int min, int max)
{
	static int rand_is_seeded = 0;
	if(!rand_is_seeded)
	{
			srand(time(NULL));
			rand_is_seeded = 1;
	}
	return rand()%(max-min+1) + min;
}


void IAlea(plateau grille){ // L'ia ne joue pas impérativement son coup avec l'algorithme
  int i = alea(0,5);
  int j = alea(0,5);
  if (alea(0,1)==1 && grille[(i*2+1)*(L) + (j*2)]==0)
        grille[(i*2+1)*(L) + (j*2)]=1;
  else if (alea(0,1)==0 && grille[(i*2)*(L) + (j*2+1)]==0)
        grille[(i*2)*(L) + (j*2+1)]=1;

}

void testcase(plateau grille, int joueur){
  int i, j;
  for (j=0; j<L; j++){
    for (i=0; i<L; i++){
      if (grille[(i*2+1)*(L) + (j*2+2)]==1 && grille[(i*2)*(L) + (j*2+1)]==1 && grille[(i*2+2)*(L) + (j*2+1)]==1 && grille[(i*2+1)*(L) + (j*2)] && joueur==IA && grille[(i*2+1)*(L)+(j*2+1)]==0)
      {
        grille[(i*2+1)*(L)+(j*2+1)]=2;
      }
    }
  }
}

int change(plateau grille){
  int i, j, compt = 0;
  for (j=0; j<5; j++){
    for (i=0; i<4; i++){
      if (grille[(i*2+1)*(L)+(j*2+1)]==IA)
      {
        compt++;
      }
    }
  }
  return compt;
}

int nbligne(plateau grille){
  int compt1 = 0;
  int i, j;
  for (j=0; j<L; j++){
    for (i=0; i<L; i++){
      if (grille(i, j)==1 || grille(i, j)==1)
      {
        compt1++;
      }
    }
  }
  return compt1;
}
