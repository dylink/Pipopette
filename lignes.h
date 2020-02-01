#define Haut grille[(p.x*2)*(L) + (p.y*2+1)] //Ligne du haut
#define Bas grille[(p.x*2+2)*(L) + (p.y*2+1)] //Ligne du bas
#define Gauche grille[(p.x*2+1)*(L) + (p.y*2)] //Ligne de gauche
#define Droite grille[(p.x*2+1)*(L) + (p.y*2+2)] //Ligne de droite
#define Carre grille[(p.x*2+1)*(L)+(p.y*2+1)] //Case du carré
//Certaines arrêtes du carré étant communes avec celles d'un autre, il est nécessaire de tester
//si elle appartient au bon côté
#define CarreYm grille[(p.x*2+1)*(L)+((p.y-1)*2+1)]
#define CarreYp grille[(p.x*2+1)*(L)+((p.y+1)*2+1)]
#define CarreXm grille[((p.x-1)*2+1)*(L)+(p.y*2+1)]
#define CarreXp grille[((p.x+1)*2+1)*(L)+(p.y*2+1)]
#define HautYp grille[(p.x*2)*(L) + ((p.y+1)*2+1)]
#define HautYm grille[(p.x*2)*(L) + ((p.y-1)*2+1)]
#define HautXp grille[((p.x+1)*2)*(L) + (p.y*2+1)]
#define HautXm grille[((p.x-1)*2)*(L) + (p.y*2+1)]
#define BasYp grille[(p.x*2+2)*(L) + ((p.y+1)*2+1)]
#define BasYm grille[(p.x*2+2)*(L) + ((p.y-1)*2+1)]
#define BasXp grille[((p.x+1)*2+2)*(L) + (p.y*2+1)]
#define BasXm grille[((p.x-1)*2+2)*(L) + (p.y*2+1)]
//Pareil pour le placement des lignes
#define GaucheYp grille[(p.x*2+1)*(L) + ((p.y+1)*2)]
#define GaucheYm grille[(p.x*2+1)*(L) + ((p.y-1)*2)]
#define GaucheXp grille[((p.x-1)*2+1)*(L) + (p.y*2)]
#define GaucheXm grille[((p.x-1)*2+1)*(L) + (p.y*2)]
#define DroiteYp grille[(p.x*2+1)*(L) + ((p.y+1)*2+2)]
#define DroiteYm grille[(p.x*2+1)*(L) + ((p.y-1)*2+2)]
#define DroiteXp grille[((p.x+1)*2+1)*(L) + (p.y*2+2)]
#define DroiteXm grille[((p.x-1)*2+1)*(L) + (p.y*2+2)]
