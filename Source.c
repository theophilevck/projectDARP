#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liste.h"
#include "check.h"
#define TAILLE_MAX 1000 // Tableau de taille 1000



// on compare toutes les distances, on ne retient que celles inf�rieures � 5



int main() {

	FILE* fichier = NULL;

	fichier = fopen("a4-40.txt", "r");
	int nbdetaxi, nbdemande, dureetravail, capacite, dureemaxdemande;
	printf("coucou \n");
	int index;
	float abscisses;
	float ordonnees;
	int capacit�;
	int nbclient;
	int tempsdepart;
	int tempsarrivee;
	ElementListe listeclient[100];



	//on ouvre le fichier texte pour pr�lever tous les documents
	if (fichier != NULL)
	{
		int lire;
		lire = fscanf(fichier, "%d %d %d %d %d", &nbdetaxi, &nbdemande, &dureetravail, &capacite, &dureemaxdemande);
		printf("je suis dans le fichier\n");
		printf("%d\n", nbdetaxi);





		for (int k = 0; k < nbdemande + 1; k++) { 

			
			int lecture1 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
				&tempsarrivee);



			listeclient[k].order.ID = index;
			printf("%d     ", listeclient[k].order.ID);
			listeclient[k].order.depart.X = abscisses;
			printf("%f   ", listeclient[k].order.depart.X);
			listeclient[k].order.depart.Y = ordonnees;
			printf("%f   ", listeclient[k].order.depart.Y);
			listeclient[k].order.nbrpersonne = nbclient;
			printf("%d   ", listeclient[k].order.nbrpersonne);
			listeclient[k].order.intevalledepart[0].heure = tempsdepart / 60;
			printf("%d:", listeclient[k].order.intevalledepart[0].heure);
			listeclient[k].order.intevalledepart[0].minute = tempsdepart % 60;
			printf("%d   ", listeclient[k].order.intevalledepart[0].minute);
			listeclient[k].order.intevalledepart[1].heure = tempsarrivee / 60;
			printf("%d:", listeclient[k].order.intevalledepart[1].heure);
			listeclient[k].order.intevalledepart[1].minute = tempsarrivee % 60;
			printf("%d\n", listeclient[k].order.intevalledepart[0].minute);
		}

		for (int k = 1; k <  nbdemande + 1; k++) { 

			int lecture2 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
				&tempsarrivee);

			printf("%d     ", index);
			listeclient[k].order.arrivee.X = abscisses;
			printf("%f   ", listeclient[k].order.arrivee.X);
			listeclient[k].order.arrivee.Y = ordonnees;
			printf("%f   ", listeclient[k].order.arrivee.Y);
			listeclient[k].order.nbrpersonne = nbclient;
			printf("%d   ", listeclient[k].order.nbrpersonne);
			listeclient[k].order.intervallearrivee[0].heure = tempsdepart / 60;
			printf("%d:", listeclient[k].order.intervallearrivee[0].heure);
			listeclient[k].order.intervallearrivee[0].minute = tempsdepart % 60;
			printf("%d   ", listeclient[k].order.intervallearrivee[0].minute);
			listeclient[k].order.intervallearrivee[1].heure = tempsarrivee / 60;
			printf("%d:", listeclient[k].order.intervallearrivee[1].heure);
			listeclient[k].order.intervallearrivee[1].minute = tempsarrivee % 60;
			printf("%d\n", listeclient[k].order.intervallearrivee[0].minute);

		}


		fclose(fichier); // On ferme le fichier qui a �t� ouvert


	}

	



	
	//on parcourt toutes les lignes pour connaitre chaque cluster
	// on doit inclure le code du cluster ici:




	LinkedList* tmp;
	tmp=clustergeographique(listeclient, listeclient[1], nbdemande,5);

	afficherListe(tmp);













	system("pause");
	return (0);



}






