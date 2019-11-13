#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

// crée une nouvelle liste chainée unilataire vide et renvoie un pointeur sur cette liste
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
// crée un nouveau maillon qui contient l info passée en paramètre
SingleLinkedListElem* NewLinkedListElement(ElementListe info) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->info = info;
		tmp->next = NULL;
	}
	return(tmp);
}
// renvoie un pointeur sur l'élément en ième position dans la liste
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

// Ajoute une nouvelle info dans la liste chaînée en ième position
// Cette fonction fait appel à la fonction NewLinkedListElement(Enregistrement pers) pour créer un maillon
int InsertElementAt(LinkedList* Liste, int i, ElementListe info) {
	SingleLinkedListElem* CurrentElement, * NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'élément qui se trouve déjà en position i
	CurrentElement = GetElementAt(Liste, i);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on insère un nouvel élément
		NewElement = NewLinkedListElement(info);
		// son suivant est alors l'élément courant
		NewElement->next = CurrentElement;


int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* item) {
	if (list == NULL) return(0); // La liste n'existe pas
	if ((list->head == NULL) || (list->tail == NULL)) return(0); // liste vide ou anomalie
	if ((list->head == list->tail) && (list->size != 1)) return(0); // anomalie
	if ((list->size == 0) || (item == NULL)) return(0); // pas d'élément dans la liste ou item invalide

	// compléter code ici
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

int BrowseLinkedList(LinkedList* list);{
    int listSize;
    SingleLinkedListElem* courant = NULL;
    if (list == NULL) return(0); // La liste n'existe pas
	if ((list->head == NULL) || (list->tail == NULL)) return(0); // liste vide ou anomalie
	if ((list->head == list->tail) && (list->size != 1)) return(0); // anomalie
	if ((list->size == 0) || (item == NULL)) return(0); // pas d'élément dans la liste ou item invalide
    courant=list->head;
    listSize=list->size;

    
    
    





}


