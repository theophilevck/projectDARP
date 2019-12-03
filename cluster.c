#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"
#include "cluster.h"



LinkedList* clusterHeureAriver(Client listeclient[], Client test) {
	Time intevallecluster[2];
	LinkedList* listCluster = NewLinkedList();

	ElementListe elementAdd;
	elementAdd.order = test;
	


	InsertElementAt(listCluster, 0, elementAdd);
	int j = 1;
	int g = 0;
	int tampon = 0;
	intevallecluster[0] = test.intervallearrivee[0];
	intevallecluster[0].heure = intevallecluster[0].heure-1;
	intevallecluster[1] = test.intervallearrivee[1];
	intevallecluster[1].heure = intevallecluster[1].heure + 1;
	

	for (int i = 0; i < (sizeof(listeclient)); i++) {
			if ((est_sup(listeclient[i].intervallearrivee[0],intevallecluster[0]) == true) && (est_inf(listeclient[i].intervallearrivee[1], intevallecluster[1]) == true)) {
				if (listeclient[i].ID!= test.ID) {
				elementAdd.order = listeclient[i];
					InsertElementAt(listCluster, 1, elementAdd);
				}
			}
		}
	return(listCluster);
}