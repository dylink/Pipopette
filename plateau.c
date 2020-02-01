#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "jeu.h"

void initPlateau(plateau grille) {

	int i,j;
	for (i=0;i<C;i++){
		for(j=0;j<L;j++){
			if(!(i%2) && !(j%2)){
				grille(i,j) = -1;
			}
			else{
				grille(i,j) = 0;
			}
		}
	}
}

void affichePlateau(plateau grille){
	int i,j,d;
	printf("\n ");
	for(i=0;i<5;i++){
			printf("   %d",i);
	}
	for(i=0;i<C;i++) {
    d = (i-1)/2;
		if(i%2){
			printf("\n%d ",d);
		}
		else {
			printf("\n  ");
		}
		for(j=0;j<L;j++) {
				switch(grille(i,j)){
					case J1: printf("X"); break;
					case IA: printf("O"); break;
					case -1: printf("+"); break;
					case 0:  printf(" "); break;
					case 1:
						if(j%2){
							printf("-");
						}
						else{
							printf("|");
						}
						break;
				}
		printf(" ");
		}
	}
	printf("\n\n");
}
