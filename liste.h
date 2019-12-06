#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
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

void afficherListe(LinkedList *liste);

//inserer les element aleatoire pour initialiser la chaine
LinkedList* InsertElementAleatoire(int aleatoire, ElementListe listeclient[100], LinkedList* route);
