#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "plateau.h"
#include "lignes.h"
#define nbCoups 60

typedef enum cote {null,Z,Q,S,D} cote;
typedef struct position{
	int x;
	int y;
	cote d;
} position;

void modejeu(plateau grille);
void jeu(plateau grille);
void PvP(plateau grille,int nbLignes);
int coup(plateau grille, position p, int joueur);
void viderBuffer();
