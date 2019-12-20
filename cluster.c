#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"
#include "cluster.h"


LinkedList* clusterHeureAriver(LinkedList* listeclient, ElementListe test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();
	SingleLinkedListElem* CurrentElement = listeclient->head;

	ElementListe elementAdd;
	elementAdd = test;
	


	InsertElementAt(listCluster, 0, elementAdd);
	int j = 1;
	int g = 0;
	int tampon = 0;
	intevallecluster[0] = test.order.intervallearrivee[0];
	intevallecluster[0].heure = intevallecluster[0].heure-1;
	intevallecluster[1] = test.order.intervallearrivee[1];
	intevallecluster[1].heure = intevallecluster[1].heure + 1;
	
	while (CurrentElement != listeclient->tail)
	{
		if ((est_sup(CurrentElement->info.order.intervallearrivee[0], intevallecluster[0]) == true) || (est_inf(CurrentElement->info.order.intervallearrivee[1], intevallecluster[1]) == true)) {
			if (CurrentElement->info.order.ID != test.order.ID) {
				elementAdd = CurrentElement->info;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
		CurrentElement = CurrentElement->next;
	}
	if ((est_sup(CurrentElement->info.order.intervallearrivee[0], intevallecluster[0]) == true) || (est_inf(CurrentElement->info.order.intervallearrivee[1], intevallecluster[1]) == true)) {
		if (CurrentElement->info.order.ID != test.order.ID) {
			elementAdd = CurrentElement->info;
			InsertElementAt(listCluster, 1, elementAdd);
		}
	}

	return(listCluster);
}

LinkedList* clusterHeureDepart(LinkedList* listeclient, ElementListe test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();
	SingleLinkedListElem* CurrentElement = listeclient->head;

	ElementListe elementAdd;
	elementAdd = test;

	InsertElementAt(listCluster, 0, elementAdd);
	int j = 1;
	int g = 0;
	int tampon = 0;
	intevallecluster[0] = test.order.intevalledepart[0];
	intevallecluster[0].heure = intevallecluster[0].heure - 1;
	intevallecluster[1] = test.order.intevalledepart[1];
	intevallecluster[1].heure = intevallecluster[1].heure + 1;

	while (CurrentElement != listeclient->tail)
	{
		if ((est_sup(CurrentElement->info.order.intevalledepart[0], intevallecluster[0]) == true) || (est_inf(CurrentElement->info.order.intevalledepart[1], intevallecluster[1]) == true)) {
			if (CurrentElement->info.order.ID != test.order.ID) {
				elementAdd = CurrentElement->info;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
		CurrentElement = CurrentElement->next;
	}

	if ((est_sup(CurrentElement->info.order.intevalledepart[0], intevallecluster[0]) == true) || (est_inf(CurrentElement->info.order.intevalledepart[1], intevallecluster[1]) == true)) {
		if (CurrentElement->info.order.ID != test.order.ID) {
			elementAdd = CurrentElement->info;
			InsertElementAt(listCluster, 1, elementAdd);
		}
	}
	return(listCluster);
}

LinkedList* clusterCapaciter(LinkedList* listeclient, ElementListe test, int capaActuel, int capMax) {
	LinkedList* listCluster = NewLinkedList();
	ElementListe elementAdd;
	SingleLinkedListElem* CurrentElement = listeclient->head;
	elementAdd = test;
	InsertElementAt(listCluster, 0, elementAdd);
	int capaTest = capaActuel + elementAdd.order.nbrpersonne;
	int cap=0;
	while (CurrentElement != listeclient->tail)
	{
		int cap = 0;
		cap = capaTest + CurrentElement->info.order.nbrpersonne;
		if (cap < capMax) {
			if (CurrentElement->info.order.ID != test.order.ID) {
				elementAdd = CurrentElement->info;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
		CurrentElement = CurrentElement->next;
	}
	cap = capaTest + CurrentElement->info.order.nbrpersonne;
	if (cap < capMax) {
		if (CurrentElement->info.order.ID != test.order.ID) {
			elementAdd = CurrentElement->info;
			InsertElementAt(listCluster, 1, elementAdd);
		}
	}
	return(listCluster);
}

LinkedList* clusterGeographique(LinkedList* listeclient, ElementListe client, float dist) {
	LinkedList* listCluster = NewLinkedList();
	ElementListe elementAdd;
	SingleLinkedListElem* CurrentElement = listeclient->head;
	LinkedList* cluster = NewLinkedList();
	InsertElementAt(cluster, 0, client);

	while (CurrentElement != listeclient->tail)
	{
		if (distance(client.order.depart, CurrentElement->info.order.depart) < dist) {
			if (CurrentElement->info.order.ID != client.order.ID) {
				InsertElementAt(cluster, 1, CurrentElement->info);
			}
		}
		CurrentElement = CurrentElement->next;
	}

	if (distance(client.order.depart, CurrentElement->info.order.depart) < dist) {
		if (CurrentElement->info.order.ID != client.order.ID) {
			InsertElementAt(cluster, 1, CurrentElement->info);
		}
	}
	return(cluster);
}

int aleatoire(int max, int min) {
		
		int valeur = (rand() * (max - min) / RAND_MAX);
		 return valeur;
}

int nbrePresenceClusters(SingleLinkedListElem* tmp, LinkedList* c1, LinkedList* c2, LinkedList* c3, LinkedList* c4) {
	int compteur = 0;
	SingleLinkedListElem* a;
	if (c1 != NULL) {
		if (c1->size > 1) {
			a = c1->head;
			a = a->next;
			while (a != NULL)
			{
				if ((a->info.order.ID == tmp->info.order.ID) && (a->info.isDeparture == tmp->info.isDeparture)) {

					compteur++;

				}
				a = a->next;
			}
		}
	}

	if (c2 != NULL) {
		if (c2->size > 1) {
			a = c2->head;
			a = a->next;
			while (a != NULL)
			{
				if ((a->info.order.ID == tmp->info.order.ID) && (a->info.isDeparture == tmp->info.isDeparture)) {
					compteur++;
				}
				a = a->next;
			}
		}
	}
	
	if (c3 != NULL) {
		if (c3->size > 1) {
			a = c3->head;
			a = a->next;
			while (a != NULL)
			{
				if ((a->info.order.ID == tmp->info.order.ID) && (a->info.isDeparture == tmp->info.isDeparture)) {
					compteur++;
				}
				a = a->next;
			}
		}
	}
	
	if (c4 != NULL) {
		if (c4->size > 1) {
			a = c4->head;
			a = a->next;
			while (a != NULL)
			{
				if ((a->info.order.ID == tmp->info.order.ID) && (a->info.isDeparture == tmp->info.isDeparture)) {
					compteur++;
				}
				a = a->next;
			}
		}
	}
	
	return(compteur);
}

LinkedList* IntersecClusters(LinkedList* list, SingleLinkedListElem* tmp) {

	int compteur = 0;
	LinkedList* tampon = NewLinkedList();
	LinkedList* tampon1 = NewLinkedList();
	LinkedList* tampon2 = NewLinkedList();
	LinkedList* tampon3 = NewLinkedList();
	LinkedList* Intersec = NewLinkedList();
	
	//cretaion des diferent cluster pour l element donnee
	tampon = clusterCapaciter(list, tmp->info, tmp->info.capaciter, 4);

	tampon1 = clusterGeographique(list, tmp->info, 3);

	tampon2 = clusterHeureAriver(list, tmp->info);

	tampon3 = clusterHeureDepart(list, tmp->info);
	//fin creation cluter

	//on ajoute les element qui sont present dans les 4 cluster a la liste
	tmp = list->head;
	while (tmp != list->tail)
	{
		if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 4) {
			InsertElementAt(Intersec, 0, tmp->info);
		}
		tmp = tmp->next;
	}
	if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 4) {
		InsertElementAt(Intersec, 0, tmp->info);
		
	}

	//si aucun n element n es ajoute on recomence le proceder 
	//mais avec on ajoute les elemnt qui sont present dans au moins 3 cluster
	if (Intersec != NULL) {
		if (Intersec->size == 0) {
			tmp = list->head;
			while (tmp != list->tail)
			{
				if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 3) {
					InsertElementAt(Intersec, 0, tmp->info);
				}
				tmp = tmp->next;
			}
			if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 3) {
				InsertElementAt(Intersec, 0, tmp->info);

			}

		}
		//identique a celui d haut dessu mais avec seulement 2 cluster
		if (Intersec->size == 0) {
			tmp = list->head;
			while (tmp != list->tail)
			{
				if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 2) {
					InsertElementAt(Intersec, 0, tmp->info);
				}
				tmp = tmp->next;
			}
			if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 2) {
				InsertElementAt(Intersec, 0, tmp->info);

			}

		}
		if (Intersec->size == 0) {
			tmp = list->head;
			while (tmp != list->tail)
			{
				if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 1) {
					InsertElementAt(Intersec, 0, tmp->info);
				}
				tmp = tmp->next;
			}
			if (nbrePresenceClusters(tmp, tampon, tampon1, tampon2, tampon3) == 1) {
				InsertElementAt(Intersec, 0, tmp->info);

			}

		}
	}
	
	return(Intersec);
}