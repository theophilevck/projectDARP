#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

//create a new empty LinkedList
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
//create a new SingleLinkedListElem wich cointain the info in parametre
SingleLinkedListElem* NewLinkedListElement(ElementListe info) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->info = info;
		tmp->next = NULL;
	}
	return(tmp);
}
// Get the element of the LinkedList chosen in parameter
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

//add a new element in the LinkedList at the position chosen
int InsertElementAt(LinkedList *Liste, int i, ElementListe info) {
	SingleLinkedListElem *CurrentElement, *NewElement;
	if (Liste == NULL) return(0);
	CurrentElement = GetElementAt(Liste, i);
	if (CurrentElement != NULL) {
		NewElement = NewLinkedListElement(info);
		NewElement->next = CurrentElement;

		if (i == 0) {
			Liste->head = NewElement;
		}
		else {
			CurrentElement = GetElementAt(Liste, i - 1);
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { 
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
		if (Liste->size <= i) { 
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
	if (list == NULL) return(0); 
	if ((list->head == NULL) || (list->tail == NULL)) return(0);
	if ((list->head == list->tail) && (list->size != 1)) return(0);
	if ((list->size == 0) || (item == NULL)) return(0); 

	SingleLinkedListElem* courant = NULL;
	SingleLinkedListElem* effacer = NULL;
	if (item == list->head) {
	
		courant = list->head;
		list->head = courant->next;
		if (list->size == 1) {
			list->head = NULL;
			list->tail = NULL;
		}
		free(courant);
		list->size--;
		return(1);
	}
	if (item == list->tail) {
		
		courant = list->head;
		while (courant->next != item) {
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
		while (courant->next != item) {
			courant = courant->next;
		}
		effacer = courant->next;
		courant->next = courant->next->next;

		free(effacer);
		list->size--;
		return(1);
	}
}

void afficherListe(LinkedList *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SingleLinkedListElem* courant = liste->head;
	while (courant != NULL)
	{
//		if (courant->info.isDeparture == true) {
			printf("%d -> ", courant->info.order.ID);
//		}
		courant = courant->next;
	}
	printf("NULL\n");
}

LinkedList* InsertDepot(LinkedList* client ){
	LinkedList* route;
	route = NewLinkedList();
	SingleLinkedListElem* a;
	a = client->head;
	while (route->size<2) {
		if (a->info.order.ID == 0) {
			
			if (route->size == 1) {
				if (a->info.isDeparture == 1) {
					InsertElementAt(route, 0, a->info);
				}
				else
				{
					InsertElementAt(route, 1, a->info);
				}
			}
			else
			{
				InsertElementAt(route, 0, a->info);
			}
		}
			a = a->next;
		
	}
	return(route);
}


LinkedList* InsertElementAleatoire(int aleatoire, LinkedList* client, LinkedList* route) {
	SingleLinkedListElem* a;
	a = GetElementAt(client, aleatoire);
	int id = a->info.order.ID;
	int i = 0;
	
		while (a != client->tail) {
			if (a->info.order.ID == id) {
				if (route->size %2== 0) {
					InsertElementAt(route, 1, a->info);
					a = a->next;
				}
				else
				{
					if (a->info.isDeparture == 1) {
						InsertElementAt(route, 1, a->info);
						a = a->next;
						DeletCopy(client, id);
					}
					else
					{
						InsertElementAt(route, 2, a->info);
						a = a->next;
						DeletCopy(client, id);
					}
				}
			}
			else {
				a = a->next;
			}
		}
	return(route);
}

LinkedList* Initialisation(LinkedList* client) {

	LinkedList* listechaineclient_copy;
	listechaineclient_copy = NewLinkedList();

	SingleLinkedListElem* a;

	for (int k = 0; k < client->size; k++) {

		a = GetElementAt(client, k);
		a->info.priseencharge.heure = 0;
		a->info.priseencharge.minute = 0;
		a->info.order.dureemax.heure = 0;
		a->info.order.dureemax.minute = 30;
		a->info.order.nbrpersonne = 1;
		a->info.order.isTaken = true;

		//a->info.isDeparture = true;
		//InsertElementAt(listechaineclient_copy, k, a->info);

		//a->info.isDeparture = false;
		//InsertElementAt(listechaineclient_copy, k, a->info);
	}
	return(client);
}

LinkedList* CopyList(LinkedList* client) {
	LinkedList* listechaineclient_copy;
	listechaineclient_copy = NewLinkedList();

	SingleLinkedListElem* a;

	for (int k = 0; k < client->size; k++) {
		a = GetElementAt(client, k);
		 a->info.isDeparture = true;
		 InsertElementAt(listechaineclient_copy, k, a->info);
		 a->info.isDeparture = false;
		 InsertElementAt(listechaineclient_copy, k, a->info);
	}
	return(listechaineclient_copy);
}

LinkedList* DeletCopy(LinkedList* client, int id) {
	SingleLinkedListElem* a;
	int count = 0;
	a = client->head;
	
	while (a != client->tail) {
		if (a->info.order.ID == id) {
			count = count + 1;
			
			DeleteLinkedListElem(client, a);
			afficherListe(client);
			a = client->head;
		}
		else
		{
			a = a->next;
		}
	}
	if (a->info.order.ID == id) {
		count = count + 1;

		DeleteLinkedListElem(client, a);
		afficherListe(client);
		a = client->head;
	}
	return(client);
}





