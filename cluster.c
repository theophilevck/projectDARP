#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"



Client clusterHeureDepart(Client listeclient[],Client test) {
	Time intevallecluster[2];
	Client listCluster[100] = { test };

	int j = 1;
	int g = 0;
	int tampon = 0;
	intevallecluster[0].heure = test.intervallearrivee->heure - 1;
	intevallecluster[1].heure = test.intervallearrivee->heure + 1;

	for (int i = 0; i < sizeof(listeclient); i++) {
		if ((est_sup(listeclient[i].intervallearrivee[0], intevallecluster[0]) && (est_inf(listeclient[i].intervallearrivee[1], intevallecluster[1]) {
			while (listCluster[g] != 0)
			{
				if (listeclient[i] == listCluster[g]) {
					tampon = 1;
				}
				g++;
			}
			if (tampon == 0) {
				listCluster[j] = listeclient[i];
				j++;
			}
		}
	}
}