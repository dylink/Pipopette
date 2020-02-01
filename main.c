#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "lignes.h"
#include "IA.h"



int main(){
	plateau grille;
initPlateau(grille);
affichePlateau(grille);
modejeu(grille);
printf("\n");
return 0;
}
