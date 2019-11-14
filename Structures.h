#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include "liste.h"




typedef struct position {
	int X;
	int Y;
}Pos;


typedef struct  time { 
	int heure;
	int minute;
}Time;


typedef struct client
{
	bool isTaken;
	int ID;
	int nbrpersonne;
	Pos depart;
	Pos arrivee;
	Time intevalledepart[2];
	Time intervallearrivee[2];
	Time dureemax;
}Client;




typedef struct elementListe {
	bool isDeparture;// departure or arival
	Client order;
	Time priseencharge;
	Time depot;
}ElementListe;

typedef struct depot {
	Pos position;
	int nbVoiture;
}Depot;