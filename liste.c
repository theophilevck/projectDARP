#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
<<<<<<< Updated upstream
=======



typedef struct SingleLinkedListElem {
	Pos pers;
	struct SingleLinkedListElem* next;
} SingleLinkedListElem;

typedef struct LinkedList {
	SingleLinkedListElem* head;
	int size;
	SingleLinkedListElem* tail;
} LinkedList;
// Crée une liste chaînée unilatère vide et renvoie un pointeur sur celle-ci
LinkedList* NewLinkedList();

// Crée un nouveau maillon qui contient une nouvelle personne et renvoie un pointeur sur ce maillon
SingleLinkedListElem* NewLinkedListElement(Pos pers);

// Renvoie un pointeur sur le maillon qui se trouve en ième position à partir de 1
SingleLinkedListElem* GetElementAt(LinkedList* liste, int i);

// Ajoute une nouvelle personne dans la liste chaînée en ième position
// Cette fonction fait appel à la fonction NewLinkedListElement(Enregistrement pers) pour créer un maillon

int InsertElementAt(LinkedList* liste, int i, Pos pers);

// Suppression et destruction d'un élément de liste chainée
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* Elem);


>>>>>>> Stashed changes
