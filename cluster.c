#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"
#include "cluster.h"






  



LinkedList* clusterHeureAriver(LinkedList* list, ElementListe test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();

	ElementListe elementAdd;
	elementAdd = test;



	InsertElementAt(listCluster, 0, elementAdd);
	int j = 1;
	int g = 0;
	int tampon = 0;
	intevallecluster[0] = test.order.intervallearrivee[0];
	intevallecluster[0].heure = intevallecluster[0].heure - 1;
	intevallecluster[1] = test.order.intervallearrivee[1];
	intevallecluster[1].heure = intevallecluster[1].heure + 1;

	SingleLinkedListElem* tmp;
	for (int i = 0; i < list->size; i++) {
		tmp = GetElementAt(list, i);
		if ((est_sup(tmp->info.order.intervallearrivee[0], intevallecluster[0]) == true) || (est_inf(tmp->info.order.intervallearrivee[1], intevallecluster[1]) == true)) {
			if (tmp->info.order.ID != test.order.ID) {
				elementAdd = tmp->info;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
	}
	printf("voici le cluster heure arrivee \n");
	afficherListe(listCluster);
	return(listCluster);
}

LinkedList* clusterHeureDepart(LinkedList* list, ElementListe test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();

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

	SingleLinkedListElem* tmp;
	for (int i = 0; i < list->size; i++) {
		tmp = GetElementAt(list, i);
		if ((est_sup(tmp->info.order.intevalledepart[0], intevallecluster[0]) == true) || (est_inf(tmp->info.order.intevalledepart[1], intevallecluster[1]) == true)) {
			if (tmp->info.order.ID != test.order.ID) {
				elementAdd = tmp->info;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
	}
	printf("voici le cluster heure depart \n");
	afficherListe(listCluster);
	return(listCluster);
}

LinkedList* clusterCapaciter(LinkedList* list, ElementListe test, int capaActuel, int capMax) {
	LinkedList* listCluster = NewLinkedList();
	ElementListe elementAdd;
	elementAdd = test;
	InsertElementAt(listCluster, 0, elementAdd);
	int capaTest = capaActuel + elementAdd.order.nbrpersonne;
	int cap = 0;
	SingleLinkedListElem* tmp;

	for (int i = 0; i < list->size; i++) {
		int cap = 0;
		tmp = GetElementAt(list, i);
		cap = capaTest + tmp->info.order.nbrpersonne;

		if (cap < capMax) {
			if (tmp->info.order.ID != test.order.ID) {
				elementAdd.order = tmp->info.order;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
	}
	printf("voici le cluster capaciter de l element %d pour une capaactuelle %d pour une capamax %d \n ", test.order.ID, capaActuel, capMax);
	afficherListe(listCluster);
	return(listCluster);
}

LinkedList* clusterGeographique(LinkedList* list, ElementListe client, float dist) {

	LinkedList* cluster = NewLinkedList();
	InsertElementAt(cluster, 0, client);

	 SingleLinkedListElem* tmp;
	
	for (int k = 0; k < list->size; k++) {
		tmp = GetElementAt(list, k);
		if (distance(client.order.depart, tmp->info.order.depart) < dist) {
			if (tmp->info.order.ID != client.order.ID) {
				InsertElementAt(cluster, k+1, tmp->info);
			}
		}
	}
	printf("tous les clients proches a moins de %.2f metres du client %d sont :\n", dist, client.order.ID);
	afficherListe(cluster);
	return(cluster);
}

float distance(Pos p1, Pos p2) {
	float tampon1;
	float tampon2;
	tampon1 = (powf((p1.X - p2.X), 2) + powf((p1.Y - p2.Y), 2));
	tampon2 = sqrtf(tampon1);
	return(tampon2);
}

int aleatoire(int taille) {

	int valeur = (rand() * (taille - 0) / RAND_MAX);
	return valeur;
}

int nbre_presence_cluster(SingleLinkedListElem* tmp, LinkedList* c1, LinkedList* c2, LinkedList* c3, LinkedList* c4) {
	// je compte le nombre de clusters contenant tmp
	int compteur = 0;
	SingleLinkedListElem* a;
	for (int k = 0; k < c1->size; k++) {
		a = GetElementAt(c1, k);
		if (a->info.order.ID == tmp->info.order.ID && tmp->info.isDeparture == true) {
			compteur++;
		}
	}
	for (int k = 0; k < c2->size; k++) {
		a = GetElementAt(c2, k);
		if (a->info.order.ID == tmp->info.order.ID && tmp->info.isDeparture== true) {
			compteur++;
		}
	}
	for (int k = 0; k < c3->size; k++) {
		a = GetElementAt(c3, k);
		if (a->info.order.ID == tmp->info.order.ID && tmp->info.isDeparture == true) {
			compteur++;
		}
	}
	for (int k = 0; k < c4->size; k++) {
		a = GetElementAt(c4, k);
		if (a->info.order.ID == tmp->info.order.ID && tmp->info.isDeparture == true) {
			compteur++;
		}
	}
	
	return(compteur);
}

LinkedList* IntersecCluster(LinkedList* list) {

	// je renvoie une linkedlist contenant les clients communs aux 4 clusters

	int compteur = 0;
	SingleLinkedListElem* tmp;
	tmp = GetElementAt(list, 2);
	
	LinkedList* tampon = NewLinkedList();
	LinkedList* tampon1 = NewLinkedList();
	LinkedList* tampon2 = NewLinkedList();
	LinkedList* tampon3 = NewLinkedList();
	LinkedList* Intersec = NewLinkedList();

	tampon = clusterCapaciter(list, tmp->info,0,3);
	tampon1 = clusterGeographique(list, tmp->info, 5);
	tampon2 = clusterHeureAriver(list, tmp->info);
	tampon3 = clusterHeureDepart(list, tmp->info);
	int emplacement = 0;
	for (int k = 0; k < list->size; k++) {
		tmp = GetElementAt(list, k);

		if ( nbre_presence_cluster(tmp,tampon,tampon1,tampon2,tampon3)== 4 ){
			InsertElementAt(Intersec, emplacement,tmp->info);
			emplacement++;
		}
	}
	printf("voici la liste de tous les clients contenus dans les 4 clusters \n");
	return(Intersec);
}
