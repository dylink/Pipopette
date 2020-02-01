
main: main.o plateau.o jeu.o IA.o
	gcc -Wall -o main main.o plateau.o jeu.o IA.o

main.o: main.c plateau.c plateau.h jeu.c jeu.h IA.c IA.h
	gcc -Wall -o main.o -c main.c

plateau.o: plateau.c plateau.h
	gcc -Wall -o plateau.o -c plateau.c

jeu.o: jeu.c jeu.h
	gcc -Wall -o jeu.o -c jeu.c

IA.o: IA.c IA.h
	gcc -Wall -o IA.o -c IA.c

clean:
	rm -rf *.o
