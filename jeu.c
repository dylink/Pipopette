#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include "IA.h"
#include "lignes.h"


void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

int coup(plateau grille, position p, int joueur){
  int compt = 0;
	if(p.d==D){
		Droite = 1;

		if(Gauche == 1 && Bas == 1 && Haut == 1){
					Carre = joueur;
          compt++;
				}

		if(BasYp == 1 && DroiteYp == 1 && HautYp == 1){
					CarreYp = joueur;
          compt++;
				}

	}

	else if(p.d==Q){
		Gauche = 1;
		if(Droite == 1 && Bas==1 && Haut==1){
					Carre = joueur;
          compt++;
				}
		if(HautYm == 1 && BasYm == 1 && GaucheYm == 1){
					CarreYm = joueur;
          compt++;
				}
	}
	else if(p.d==S) {
		Bas = 1;
		if(Gauche == 1 && Droite == 1 && Haut == 1){
					Carre = joueur;
          compt++;
				}
		if(GaucheXp == 1 && DroiteXp == 1 && BasXp == 1){
					CarreXp = joueur;
          compt++;
				}
	}
	else if(p.d==Z){
		Haut = 1;

		if(Gauche == 1 && Bas == 1 && Droite == 1){
					Carre = joueur;
          compt++;
				}

		if(DroiteXm == 1 && GaucheXm == 1 && HautXm == 1){
					CarreXm = joueur;
          compt++;
				}
	}
  return compt;
}


void PvP(plateau grille,int nbLignes)
{
  int joueur=-2, fin = 0;
  int compt1=0, compt2=0;
  position p;
	char c;
  while(!fin)
  {
    affichePlateau(grille);
    while(nbLignes>0)
    {
      printf("\nJoueur 1 = %d, Joueur 2 = %d\n", compt1, compt2);
      if (joueur==-2){
        printf("\nAu tour du Joueur 1.\n");
      }
      else {
        printf("\nAu tour du Joueur 2.\n");
      }
        printf("Il reste %d lignes à placer:\n",nbLignes);
        printf("Ou voulez vous placez votre ligne?\n");
      do
      {
        printf("Choisissez la ligne:\n");
        scanf("%d",&p.x);
        if (p.x<0 || p.x>4){
          printf("Il n'y a pas de ligne %d.\n",p.x);
        }
      }while(p.x<0 || p.x>4);
      do
      {
        printf("Choisissez la colonne:\n");
        viderBuffer();
        scanf("%d", &p.y);
        if (p.y<0 || p.y>4){
          printf("Il n'y a pas de colonne %d.\n",p.y);
        }
      }while(p.y<0 || p.y>4);
      do {
        printf("Choisissez un côté avec Z, Q, S ou D:\n");
        viderBuffer();
        scanf("%c",&c);
        if (c!= 'Z' && c!= 'Q' && c!='S' && c!='D'){
          printf("Ce côté n'existe pas.\n");
        }
        else {
          switch(c) {
            case 'Z': p.d=Z; break;
            case 'Q': p.d=Q; break;
            case 'S': p.d=S; break;
            case 'D': p.d=D; break;
            default : p.d=null;
          }
        }
      } while(c!= 'Z' && c!= 'Q' && c!='S' && c!='D');
      if ((Gauche == 1 && c=='Q') || (Droite == 1 && c=='D') || (Haut == 1 && c=='Z') || (Bas == 1 && c=='S')){
        printf("Il y a déjà une ligne à cet emplacement.\n");
        joueur = (joueur == 2)? -2 : 2;
      }
      else {
        coup(grille,p,joueur);
        affichePlateau(grille);
        nbLignes--;
      }
      if (coup(grille,p,joueur)!=0){
        if (joueur==-2){
          compt1=compt1+coup(grille,p,joueur);
        }
        else {
          compt2=compt2+coup(grille,p,joueur);
        }
      }
      else {
        joueur = (joueur == 2)? -2 : 2;
      }
    }
    if (compt1>compt2){
      printf("Le Joueur 1 gagne %d à %d! Bravo!\n", compt1, compt2);
      fin=1;
    }
    else if (compt1<compt2){
      printf("Le Joueur 2 gagne %d à %d! Bravo!\n", compt2, compt1);
      fin=1;
    }
  }
}

void PvE(plateau grille,int nbLignes){
  int joueur=-2, fin = 0, a = 0, compt1 = 0;
  position p;
	char c;
  while(!fin)
  {
    affichePlateau(grille);
    while(nbLignes>0)
    {
      printf("\nJoueur 1 = %d, IA = %d\n", compt1, change(grille));
      printf("\nLignes = %d\n", nbligne(grille));
      if (joueur==-2){
        printf("\nA votre tour.\n");
        printf("Ou voulez vous placez votre ligne?\n"); // Dans ce mode de jeu, le test de fermeture de case peut être inexact.
        do
        {
          printf("Choisissez la ligne:\n");
          scanf("%d",&p.x);
          if (p.x<0 || p.x>4){
            printf("Il n'y a pas de ligne %d.\n",p.x);
          }
        }while(p.x<0 || p.x>4);
        do
        {
          printf("Choisissez la colonne:\n");
          viderBuffer();
          scanf("%d", &p.y);
          if (p.y<0 || p.y>4){
            printf("Il n'y a pas de colonne %d.\n",p.y);
          }
        }while(p.y<0 || p.y>4);
        do {
          printf("Choisissez un côté avec Z, Q, S ou D:\n");
          viderBuffer();
          scanf("%c",&c);
          if (c!= 'Z' && c!= 'Q' && c!='S' && c!='D'){
            printf("Ce côté n'existe pas.\n");
          }
          else {
            switch(c) {
              case 'Z': p.d=Z; break;
              case 'Q': p.d=Q; break;
              case 'S': p.d=S; break;
              case 'D': p.d=D; break;
              default : p.d=null;
            }
          }
        } while(c!= 'Z' && c!= 'Q' && c!='S' && c!='D');
        if ((Gauche == 1 && c=='Q') || (Droite == 1 && c=='D') || (Haut == 1 && c=='Z') || (Bas == 1 && c=='S')){
          printf("Il y a déjà une ligne à cet emplacement.\n");
        }
        else {
          coup(grille,p,joueur);
          affichePlateau(grille);
          nbLignes--;
          if (coup(grille,p,joueur)==0){
            joueur = (joueur == 2)? -2 : 2;
          }
          else {
            compt1=compt1+coup(grille,p,joueur);
          }

        }
      }
      else {
        printf("\nAu tour de l'IA.\n");
        sleep(1);
        IAlea(grille);
        testcase(grille, joueur);
        affichePlateau(grille);
        if(change(grille)!=a){
          a = change(grille);
        }
        else {
          joueur = (joueur == 2)? -2 : 2;
        }
        nbLignes--;
      }
      printf("Il reste %d lignes à placer:\n",nbLignes);
    }
    fin = 1;
  }
}

void modejeu (plateau grille){
  char c;
  printf("Veuillez choisir votre mode de jeu : \n\n");
  printf("H : Jouez avec un ami à vous!\n");
  printf("A : Jouez contre un ordinateur aléatoire.\n");
  do {
    viderBuffer();
    scanf("%c", &c);
    if (c!='H' && c!='A'){
      printf("Ce mode n'existe pas.\n");
    }
    else {
      switch(c){
        case 'H' : PvP(grille,nbCoups); break;
        case 'A' : PvE(grille,nbCoups); break;
        default : exit(1);
      }
    }
  }while(c!='H' && c!='A');

}
