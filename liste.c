#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

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
// cr�e un nouveau maillon qui contient l info pass�e en param�tre
SingleLinkedListElem* NewLinkedListElement(ElementListe info) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->info = info;
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
int InsertElementAt(LinkedList* Liste, int i, ElementListe info) {
	SingleLinkedListElem* CurrentElement, * NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'�l�ment qui se trouve d�j� en position i
	CurrentElement = GetElementAt(Liste, i);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on ins�re un nouvel �l�ment
		NewElement = NewLinkedListElement(info);
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
			NewElement = NewLinkedListElement(info);
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
			NewElement = NewLinkedListElement(info);
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
		effacer = courant->next;
		courant->next = courant->next->next;
		free(effacer);
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

void afficherListe(LinkedList* liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}

	SingleLinkedListElem* courant = liste->head;

	while (courant != NULL)
	{
		printf("%d -> ", courant->info.order.ID);
		courant = courant->next;
	}
	printf("NULL\n");
}

LinkedList* InsertElementAleatoire(int aleatoire, ElementListe listeclient[100], LinkedList* route) {

	int id = listeclient[aleatoire].order.ID;
	int i = 0;
	if (route == NULL)
	{
		InsertElementAt(route, 0, listeclient[aleatoire]);
		while (listeclient[aleatoire + i].order.ID != NULL) {
			if (listeclient[aleatoire + i].order.ID == id) {
				InsertElementAt(route, 1, listeclient[aleatoire + i]);
			}
			i++;
		}
	}
	else {
		InsertElementAt(route, 1, listeclient[aleatoire]);
		while (listeclient[aleatoire + i].order.ID != NULL) {
			if (listeclient[aleatoire + i].order.ID == id) {
				InsertElementAt(route, 2, listeclient[aleatoire + i]);
			}
			i++;
		}
	}

	return(route);
}