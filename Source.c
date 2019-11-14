#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#define TAILLE_MAX 1000 // Tableau de taille 1000



int main() {

	FILE* fichier = NULL;

	fichier = fopen( "a4-40.txt", "r");
	int nbdetaxi, nbdemande, dureetravail, capacite, dureemaxdemande;
	printf("coucou \n");
	int index;
	float abscisses;
	float ordonnees;
	int capacité;
	int nbclient;
	int tempsdepart;
	int tempsarrivee;
Client listeclient[100];




	if (fichier != NULL)
	{
		int lire;
		lire = fscanf(fichier, "%d %d %d %d %d", &nbdetaxi, &nbdemande, &dureetravail, &capacite, &dureemaxdemande);
		printf("je suis dans le fichier\n");
		printf("%d\n",nbdetaxi);


	


		for (int k = 0; k < nbdemande + 1; k++) { // +2 car 2 entrepots 2* car départ , arrivée

			int lecture1 = fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
				&tempsarrivee);



			listeclient[k].ID = index ;
			printf("%d     ", listeclient[k].ID);
			listeclient[k].depart.X = abscisses;
			printf("%f   ", listeclient[k].depart.X);
			listeclient[k].depart.Y = ordonnees;
			printf("%f   ", listeclient[k].depart.Y);
			listeclient[k].nbrpersonne = nbclient;
			printf("%d   ", listeclient[k].nbrpersonne);
			listeclient[k].intevalledepart[0].heure = tempsdepart / 60;
			printf("%d:", listeclient[k].intevalledepart[0].heure);
			listeclient[k].intevalledepart[0].minute = tempsdepart % 60;
			printf("%d   ", listeclient[k].intevalledepart[0].minute);
			listeclient[k].intevalledepart[1].heure = tempsarrivee / 60;
			printf("%d:", listeclient[k].intevalledepart[1].heure);
			listeclient[k].intevalledepart[1].minute = tempsarrivee % 60;
			printf("%d\n", listeclient[k].intevalledepart[0].minute);
		}

			for (int k = nbdemande + 1; k < 2 * nbdemande + 2; k++) { // +2 car 2 entrepots 2* car départ , arrivée
				Client listeclient[100];
				int lecture2=fscanf(fichier, "%d %f %f %d %d %d %d", &index, &abscisses, &ordonnees, &capacite, &nbclient, &tempsdepart,
					&tempsarrivee);
				listeclient[k].ID = index - 1;
				listeclient[k].depart.X = abscisses;
				listeclient[k].depart.Y = ordonnees;
				listeclient[k].nbrpersonne = nbclient;
				listeclient[k].intervallearrivee[0].heure = tempsdepart / 60;
				listeclient[k].intervallearrivee[0].minute = tempsdepart % 60;
				listeclient[k].intervallearrivee[1].heure = tempsarrivee / 60;
				listeclient[k].intervallearrivee[1].minute = tempsarrivee % 60;

			}

			

		
			fclose(fichier); // On ferme le fichier qui a été ouvert
}
	system("pause");
		return (0);

	
}