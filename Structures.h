#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>
#include "liste.h"



typedef struct position {
	float X;
	float Y;
}Pos;


typedef struct  time { 
	int heure;
	int minute;
}Time;


typedef struct client
{
	bool isTaken;
	int ID;//id du client
	int nbrpersonne;//nombre de perssone pour la commande
	Pos depart;//position de depart du client
	Pos arrivee;//position d arriver du client
	Time intevalledepart[2];
	Time intervallearrivee[2];
	Time dureemax;//duree maximum d atente entre la prise en charge et le depot
}Client;




typedef struct elementListe {
	bool isDeparture;// departure or arival
	Client order;//contient les information de la demande du client
	Time priseencharge;//heure de prise en charge
	Time depot;//heure de depot
	int capaciter;//nombre de perssone qui sont dans le vehicule
}ElementListe;

typedef struct depot {
	Pos position;
	int nbVoiture;
}Depot;