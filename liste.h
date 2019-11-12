#pragma once
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






// cr�e une nouvelle liste chain�e unilataire vide et renvoie un pointeur sur cette liste
LinkedList* NewLinkedList() {
	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
	return tmp;
}
// cr�e un nouveau maillon qui contient la personne pass�e en param�tre
SingleLinkedListElem* NewLinkedListElement(Pos pers) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->pers = pers;
		tmp->next = NULL;
	}
	return(tmp);
}
// renvoie un pointeur sur l'�l�ment en i�me position dans la liste
SingleLinkedListElem* GetElementAt(LinkedList* Liste, int i) {
	int CurrentIndex = 0;
	SingleLinkedListElem* Element;
	if ((Liste == NULL) || (i < 0) || (i >= Liste->size)) return(NULL);
	if (i == 0) return(Liste->head);
	if (i == Liste->size - 1) return(Liste->tail);
	Element = Liste->head;
	while (CurrentIndex != i && Element != NULL) {
		Element = Element->next;
		CurrentIndex++;
	}
	return(Element);
}

// Ajoute une nouvelle personne dans la liste cha�n�e en i�me position
// Cette fonction fait appel � la fonction NewLinkedListElement(Enregistrement pers) pour cr�er un maillon
int InsertElementAt(LinkedList* Liste, int i, Pos pers) {
	SingleLinkedListElem* CurrentElement, * NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'�l�ment qui se trouve d�j� en position i
	CurrentElement = GetElementAt(Liste, i);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on ins�re un nouvel �l�ment
		NewElement = NewLinkedListElement(pers);
		// son suivant est alors l'�l�ment courant
		NewElement->next = CurrentElement;

		if (i == 0) {
			// si l'insertion est en t�te
			// le nouvel �l�ment devient la t�te
			Liste->head = NewElement;
		}
		else {
			// sinon il faut r�tablir le chainage depuis l'�l�ment pr�c�dent
			CurrentElement = GetElementAt(Liste, i - 1);
			// le sucesseur du pr�c�dent devient le nouvel �l�ment
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { // insertion en t�te de l'unique �l�ment
			NewElement = NewLinkedListElement(pers);
			if (NewElement != NULL) {
				Liste->head = NewElement;
				Liste->size = 1;
				Liste->tail = NewElement;
				return(1);
			}
			else {
				return(0);
			}
		}
		if (Liste->size <= i) { // insertion en queue
			NewElement = NewLinkedListElement(pers);
			if (NewElement != NULL) {
				Liste->tail->next = NewElement;
				Liste->tail = NewElement;
				Liste->size += 1;
				return(1);
			}
			else {
				return(0);
			}
		}
	}
	return(0);
}

int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* item) {
	if (list == NULL) return(0); // La liste n'existe pas
	if ((list->head == NULL) || (list->tail == NULL)) return(0); // liste vide ou anomalie
	if ((list->head == list->tail) && (list->size != 1)) return(0); // anomalie
	if ((list->size == 0) || (item == NULL)) return(0); // pas d'�l�ment dans la liste ou item invalide

	// compl�ter code ici
	SingleLinkedListElem* courant = NULL;
	SingleLinkedListElem* effacer = NULL;
	if (item == list->head) {
		//suprimer le premier element
		//courant est un pointeur 
		//pointeur courant =head
		//head=courant +1
		//free courant
		courant = list->head;
		list->head = courant->next;
		if (list->size == 1) {// cas particulier si la taille egale a 1 on doit aussi changer la tail
			list->head = NULL;
			list->tail = NULL;
		}
		free(courant);//on suprime l element
		list->size--;
		return(1);
	}
	if (item == list->tail) {
		//suprimer le dernier element
		//courant est un pointeur 
		//pointeur courant =tail-1
		//tail=courant -1
		//free courant++
		courant = list->head;
		while (courant->next != item) {//on sarrete a l element d avant la queu
			courant = courant->next;
		}
		list->tail = courant;
		courant = courant->next;
		free(courant);
		list->size--;
		return(1);
	}
	else
	{

		courant = list->head;
		while (courant->next != item) {//on s arrete a l elelement avant celuis que l on souhaite suprimer
			courant = courant->next;
		}
		effacer = courant->next;
		courant->next = courant->next->next;//l element suivant devient l element apres celuit qu on souhaite suprimer

		free(effacer);
		list->size--;
		return(1);
	}
}
