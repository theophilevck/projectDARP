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

// Ajoute une nouvelle personne dans la liste chaînée en ième position
// Cette fonction fait appel à la fonction NewLinkedListElement(Enregistrement pers) pour créer un maillon
int InsertElementAt(LinkedList *Liste, int i, ElementListe info) {
	SingleLinkedListElem *CurrentElement, *NewElement;
	if (Liste == NULL) return(0);
	// recherche de l'élément qui se trouve déjà en position i
	CurrentElement = GetElementAt(Liste, i);
	// s'il y en a un
	if (CurrentElement != NULL) {
		// on insère un nouvel élément
		NewElement = NewLinkedListElement(info);
		// son suivant est alors l'élément courant
		NewElement->next = CurrentElement;

		if (i == 0) {
			// si l'insertion est en tête
			// le nouvel élément devient la tête
			Liste->head = NewElement;
		}
		else {
			// sinon il faut rétablir le chainage depuis l'élément précédent
			CurrentElement = GetElementAt(Liste, i - 1);
			// le sucesseur du précédent devient le nouvel élément
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { // insertion en tête de l'unique élément
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

void afficherListe(LinkedList *liste)
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
	
		while (a->info.order.ID != NULL) {
			if (a->info.order.ID == id) {
				if (route->size %2== 0) {
					InsertElementAt(route, 1, a->info);
				}
				else
				{

					if (a->info.isDeparture == 1) {
						InsertElementAt(route, 1, a->info);
					}
					else
					{
						InsertElementAt(route, 2, a->info);
					}
				}
			}
			a = a->next;
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






