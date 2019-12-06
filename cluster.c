#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"
#include "cluster.h"



LinkedList* clusterHeureAriver(ElementListe listeclient[], ElementListe test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();

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
	

	for (int i = 0; i < (sizeof(listeclient)); i++) {
			if ((est_sup(listeclient[i].order.intervallearrivee[0],intevallecluster[0]) == true) || (est_inf(listeclient[i].order.intervallearrivee[1], intevallecluster[1]) == true)) {
				if (listeclient[i].order.ID!= test.order.ID) {
				elementAdd = listeclient[i];
					InsertElementAt(listCluster, 1, elementAdd);
				}
			}
		}
	return(listCluster);
}

LinkedList* clusterHeureDepart(ElementListe listeclient[], ElementListe test) {
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


	for (int i = 0; i < (sizeof(listeclient)); i++) {
		if ((est_sup(listeclient[i].order.intevalledepart[0], intevallecluster[0]) == true) || (est_inf(listeclient[i].order.intevalledepart[1], intevallecluster[1]) == true)) {
			if (listeclient[i].order.ID != test.order.ID) {
				elementAdd = listeclient[i];
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
	}
	return(listCluster);
}

LinkedList* clusterCapaciter(ElementListe listeclient[100], ElementListe test, int capaActuel, int capMax) {
	LinkedList* listCluster = NewLinkedList();
	ElementListe elementAdd;
	elementAdd = test;
	InsertElementAt(listCluster, 0, elementAdd);
	int capaTest = capaActuel + elementAdd.order.nbrpersonne;
	int cap=0;
	for (int i = 0; i < (sizeof(listeclient)); i++) {
		int cap = 0;
		cap = capaTest + listeclient[i].order.nbrpersonne;

		if (cap < capMax) {
			if (listeclient[i].order.ID != test.order.ID) {
				elementAdd.order = listeclient[i].order;
				InsertElementAt(listCluster, 1, elementAdd);
			}
		}
	}
	return(listCluster);
}

LinkedList* clusterGeographique(ElementListe list[100], ElementListe client, int nbdemande, float dist) {

	LinkedList* cluster = NewLinkedList();
	InsertElementAt(cluster, 0, client);


	for (int k = 0; k < nbdemande + 1; k++) {
		if (distance(client.order.depart, list[k].order.depart) < dist) {
			if (list[k].order.ID != client.order.ID) {
				InsertElementAt(cluster, 1, list[k]);
			}
		}
	}
	printf("tous les clients proches a moins de %.2f metres du client %d sont :\n", dist, client.order.ID);
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