#pragma once
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "Structures.h"

typedef struct SingleLinkedListElem {
	ElementListe info;
	struct SingleLinkedListElem* next;
} SingleLinkedListElem;

typedef struct LinkedList {
	SingleLinkedListElem* head;
	SingleLinkedListElem* tail;
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

void afficherListe(LinkedList* liste);

LinkedList* InsertElementAleatoire(int aleatoire, LinkedList * list, LinkedList* route);


//initialisation of LinkedList after the reading of the file.txt 
LinkedList* Initialisation(LinkedList* client);

//creation of a copy of the linkedList whitch we will use to work on 
LinkedList* CopyList(LinkedList* client);

Time tempsparcours(SingleLinkedListElem* A, SingleLinkedListElem* B);

LinkedList* InsertDepot(LinkedList* client);

LinkedList* insertion(LinkedList* list, Voiture taxi);

LinkedList* DeletCopy(LinkedList* client, int id);

Time horloge_soustraction(Time a, int minutes);

 

Time Horloge_addition(Time a, Time b);

int Checkinsertion(SingleLinkedListElem* current, SingleLinkedListElem* insertion);