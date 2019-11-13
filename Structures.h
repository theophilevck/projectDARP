#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <stdbool.h>


typedef struct Pos {
	int X;
	int Y;
}Pos;


typedef struct  Time { 
	int heure;
	int minute;
}Time;


typedef struct Client
{
	bool isTaken;
	int ID;
	int nbrpersonne;
	Pos depart;
	Pos arrivee;
	Time intevalledepart[2];
	Time intervallearrivee[2];
	Time priseencharge;
	Time depot;
	Time dureemax;
}Client;


typedef struct Voiture {
	int Id;
	int Cn;
	Pos depot;
	Time Edepart;
	Time Earrivee;
	Time dtravaille;
	LinkedList Route;
}Voiture;

typedef struct ElementListe {
	bool isDeparture;// departure or arival
	Client order
}ElementListe;

typedef struct Depot {
	Pos position;
	int nbVoiture;
}Depot;