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
	LinkedList* liste;
	liste = lecture_fichier("a4-40.txt");
	liste = Initialisation(liste);
	afficherListe(liste);

	LinkedList* copy;
	copy = CopyList(liste);


	printf("\n");
	printf("j affiche ici ma liste copy \n");
	afficherListe(copy);
	printf("\n");
	LinkedList* route;
	route = InsertDepot(copy);
	DeletCopy(copy, 0);


	afficherListe(route);
	printf("\n");

	int tampon;
	for (int i = 0; i < 2; i++)
	{
		tampon = aleatoire(40,0);
	}
	route = InsertElementAleatoire(tampon, copy, route);
	route=InitFirstElement(route);
	afficherListe(route);
	printf("\n");
	afficherListeHeure(route);
	printf("\n affichage de copy : ");

	afficherListe(copy);
	printf("\n");

	LinkedList* rout;
	SingleLinkedListElem* tmpo;
	tmpo = GetElementAt(copy, 1);
	rout = IntersecClusters(copy, tmpo,1);
	printf("\n interssection cluster: ");

	afficherListe(rout);
	

	for (int i = 0; i < 3; i++)
	{
		tampon = aleatoire(route->size , 1);
	}
	rout = IntersecClusters(copy, tmpo, 1);
	int i = 0;
	i=InsertGoodSpot(copy,route,rout,tampon);
	afficherListe(route);
	afficherListe(copy);
	for (int i = 0; i < 3; i++)
	{
		tampon = aleatoire(route->size, 1);
	}
	rout = IntersecClusters(copy, tmpo, 1);
	i = InsertGoodSpot(copy, route, rout, tampon);
	printf("\n afficherListe ");
	afficherListe(route);
	afficherListeIstaken(route);
	printf("\n affichercopy ");


	system("pause");
	return (EXIT_SUCCESS);
}

