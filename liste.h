#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "structures.h"


typedef struct SingleLinkedListElem {
    ElementListe info;
	struct SingleLinkedListElem *next;
} SingleLinkedListElem;

typedef struct LinkedList {
	SingleLinkedListElem *head;
	SingleLinkedListElem *tail;
	int size;
} LinkedList;

typedef struct voiture {
	int Id;
	int Cn;
	Depot depot;
	Time Edepart;
	Time Earrivee;
	Time dtravaille;
	LinkedList* Route;
}Voiture;

// Crée une liste chaînée unilatère vide et renvoie un pointeur sur celle-ci
LinkedList* NewLinkedList();

// Crée un nouveau maillon qui contient une nouvelle info et renvoie un pointeur sur ce maillon
SingleLinkedListElem* NewLinkedListElement(ElementListe info);

// Renvoie un pointeur sur le maillon qui se trouve en ième position à partir de 1
SingleLinkedListElem* GetElementAt(LinkedList* liste, int i);

// Ajoute une nouvelle personne dans la liste chaînée en ième position
// Cette fonction fait appel à la fonction NewLinkedListElement(Enregistrement pers) pour créer un maillon
int InsertElementAt(LinkedList* liste, int i, ElementListe info);

// Suppression et destruction d'un élément de liste chainée
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* Elem);

//print thebLinkedList element after element
void afficherListe(LinkedList *liste);

void afficherListeHeure(LinkedList *liste);

void afficherListeIstaken(LinkedList *liste);

//insertion of the depot in the LinkedList
LinkedList* InsertDepot(LinkedList* client);

//inserer les element aleatoire pour initialiser la chaine
LinkedList* InsertElementAleatoire(int aleatoire, LinkedList* client, LinkedList* route);

//initialisation of LinkedList after the reading of the file.txt
LinkedList* Initialisation(LinkedList* client);

//creation of a copy of the linkedList whitch we will use to work on
LinkedList* CopyList(LinkedList* client);

//delete the two element of the LinkedList
LinkedList* DeletCopy(LinkedList* client, int id);

//calculate the Time between two diferent point
Time tempsparcours(SingleLinkedListElem* A, SingleLinkedListElem* B);

//substract hours
Time horloge_soustraction(Time a, int minutes);

int InsertGoodSpot(LinkedList* copy, LinkedList* rout, LinkedList* IntersecClusters, int aleatoire);


//intialise the time of pick up of the first two element
LinkedList* InitFirstElement(LinkedList* client);

//intialise the time of pick up of the first two element
LinkedList* InitOtherElement(LinkedList* client);

//calcule distance 
float distance(Pos p1, Pos p2);

Time Horloge_addition(Time a, Time b);

int CheckinsertionFirstElement(SingleLinkedListElem* current, SingleLinkedListElem* insertion);

int CheckinsertionSecondElement(SingleLinkedListElem* current, SingleLinkedListElem* insertion);