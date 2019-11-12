#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>


typedef struct Pos {

	int X; int Y;

}Pos;


typedef struct  Time { int heure; int minute; }Time;


typedef struct Client
{
	int ID; int nbrpersonne; Pos depart; Pos arrivee; Time intevalledepart[2]; Time intervallearrivee[2]; Time priseencharge; Time depot; Time dureemax;
}Client;








typedef struct Voiture {
	int Id; int Cn; Time Edepart; Time Earriv�e; Time dtravaille;
}Voiture;