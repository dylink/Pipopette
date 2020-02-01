#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "jeu.h"
#include "lignes.h"

bool test2(plateau grille);
void test(plateau grille, int joueur);
int alea(int a, int b);
void IAlea(plateau grille);
void cdispo(plateau grille, int tab[]);
int nbligne(plateau grille);
void testcase(plateau grille, int joueur);
int change(plateau grille);
int imp();
int pair();
