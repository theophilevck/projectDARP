#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "liste.h"
#include "check.h"
#define TAILLE_MAX 1000 



LinkedList* lecture_fichier(char name[]) {

	FILE* fichier = NULL;

	LinkedList* listechaineclient;
	listechaineclient = NewLinkedList();


	fichier = fopen(name, "r");
	int nbdetaxi, nbdemande, dureetravail, capacite, dureemaxdemande;
	printf("on lit le fichier \n");
	int index;
	float abscisses;
	float ordonnees;
	int nbclient;
	int tempsdepart;
	int tempsarrivee;
	ElementListe listeclient[100];

	Voiture listevoiture[10];

	//on ouvre le fichier texte pour prélever toutes les informations
	if (fichier != NULL)
	{
		int lire;
		lire = fscanf(fichier, "%d %d %d %d %d", &nbdetaxi, &nbdemande, &dureetravail, &capacite, &dureemaxdemande);
		printf("je suis dans le fichier\n");
		printf("%d   %d   %d   %d   %d\n", nbdetaxi, nbdemande, dureetravail, capacite, dureemaxdemande);

		// on créé une liste de voiture

		for (int j = 0; j < nbdetaxi; j++) {

			listevoiture[j].Id = j + 1;
			//listevoiture[j].Cn = 5;
			listevoiture[j].dtravaille.heure = dureetravail / 60;
			listevoiture[j].dtravaille.minute = dureetravail % 60;
		}



		for (int k = 0; k < nbdemande + 1; k++) {


			int lecture1 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
				&tempsarrivee);

			// on initialise l'entrepot + 40 clients sur le départ

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

		for (int k = 1; k < nbdemande + 1; k++) {

			int lecture2 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
				&tempsarrivee);


			// on initialise les 40 clients sur l'arrivée + l'entrepot

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
			InsertElementAt(listechaineclient, k, listeclient[k]);

		}

		int lecture3 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
			&tempsarrivee);


		// on rajoute l'élément entrepot retour à la fin

		printf("%d     ", index);
		listeclient[0].order.arrivee.X = abscisses;
		printf("%f   ", listeclient[0].order.arrivee.X);
		listeclient[0].order.arrivee.Y = ordonnees;
		printf("%f   ", listeclient[0].order.arrivee.Y);
		listeclient[0].order.nbrpersonne = nbclient;
		printf("%d   ", listeclient[0].order.nbrpersonne);
		listeclient[0].order.intervallearrivee[0].heure = tempsdepart / 60;
		printf("%d:", listeclient[0].order.intervallearrivee[0].heure);
		listeclient[0].order.intervallearrivee[0].minute = tempsdepart % 60;
		printf("%d   ", listeclient[0].order.intervallearrivee[0].minute);
		listeclient[0].order.intervallearrivee[1].heure = tempsarrivee / 60;
		printf("%d:", listeclient[0].order.intervallearrivee[1].heure);
		listeclient[0].order.intervallearrivee[1].minute = tempsarrivee % 60;
		printf("%d\n", listeclient[0].order.intervallearrivee[0].minute);


		InsertElementAt(listechaineclient, 0, listeclient[0]);



		fclose(fichier); // On ferme le fichier qui a été ouvert


	}

	return(listechaineclient);

}
