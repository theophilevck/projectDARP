#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liste.h"
#include "check.h"
#include "cluster.h"
#include "Structures.h"

#define TAILLE_MAX 1000 // Tableau de taille 1000


int main() {



	FILE* fichier = NULL;

	fichier = fopen("a4-40.txt", "r");
	int nbdetaxi, nbdemande, dureetravail, capacite, dureemaxdemande;
	printf("coucou \n");
	int index;
	float abscisses;
	float ordonnees;
	int nbclient;
	int tempsdepart;
	int tempsarrivee;
	ElementListe listeclient[100];



	fichier = NULL;

	fichier = fopen("a4-40.txt", "r");


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

		for (int k = 1; k < nbdemande + 2; k++) {

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
	tmp = clusterGeographique(listeclient, listeclient[1], 40, 5.5);



	LinkedList* tmp1;
	tmp1 = clusterHeureDepart(listeclient, listeclient[1]);


	LinkedList* tmp2;
	tmp2 = clusterHeureAriver(listeclient, listeclient[1]);


	afficherListe(tmp);

	afficherListe(tmp1);

	afficherListe(tmp2);


	LinkedList* route;
	route = NewLinkedList();

	route = InsertElementAleatoire(0, listeclient, route);

	InsertElementAt(route, 0, listeclient[0]);
	

	afficherListe(route);
	int tampon;
	for (int i = 0; i < 2; i++)
	{
		tampon = aleatoire(nbdemande);
		printf("%d\n", tampon);
	}

	route= InsertElementAleatoire(tampon, listeclient , route);
	afficherListe(route);
	Voiture car;
	car.Route = route;
	car.Cn = 5;
	printf("%d %d \n", listeclient[22].order.intervallearrivee[0].heure, listeclient[22].order.intervallearrivee[1].heure);
	printf("%d %d \n", listeclient[22].order.intevalledepart[0].heure, listeclient[22].order.intevalledepart[1].heure);
	printf("%d \n",CheckCapacity(car));
	

	//ElementListe creation_client_depart(Client listeclient[], ElementListe listedepart) {
		// Lecture du fichier texte



		// Chargement de la liste des clients de d�parts dans un Element liste

	//}
	system("pause");
	return (0);



}
