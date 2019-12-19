#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "liste.h"
#include "check.h"
#include "cluster.h"
#include "Structures.h"
#include "Structures.h"


#define TAILLE_MAX 1000 // Tableau de taille 1000


int main() {
	srand(time(NULL)); // initialisation de rand

	int tampon9 = 1;
	int tampon4 = 0;
	int tampon;
	int i = 0;
	int j = 0;

	LinkedList* liste;//liste de client

	LinkedList* copy;//list de copy conteneant les client

	LinkedList* route;//route des different vehicule
	LinkedList* route1;
	LinkedList* route2;
	LinkedList* route3;


	LinkedList* save1;//sauvegarde de la meilleur route
	LinkedList* save2;
	LinkedList* save3;
	LinkedList* save4;
	LinkedList* save5;

	Time time1;
	Time time2;
	Time time3;
	Time time4;
	Time timecompar1;
	Time timecompar2;

	LinkedList* rout;
	SingleLinkedListElem* tmpo;
	
	liste = lecture_fichier("a4-40.txt");//lecture du fichier texte

	liste = Initialisation(liste);//initialisation de la liste
	afficherListe(liste);
	printf("\n");
	
	copy = CopyList(liste);//creation de la copy que l on va utiliser
	afficherListe(copy);
	printf("\n");
	
	route = InitList(copy);//initialisation des route avec le depot et un element aleatoire
	route1 = InitList(copy);
	route2 = InitList(copy);
	route3 = InitList(copy);

	afficherListeHeure(route);
	afficherListeHeure(route1);
	afficherListeHeure(route2);
	afficherListeHeure(route3);
	

	DeletCopy(copy, 0);
	afficherListe(copy);//fin intitialisation


	while ((tampon9<1000))
	{
		tampon = aleatoire(route->size, 0);//debut route
		tampon4 = aleatoire(copy->size / 2, 1);
		tmpo = GetElementAt(copy, tampon4);
		rout = IntersecClusters(copy, tmpo, 1);
		i = InsertGoodSpot(copy, route, rout, tampon);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
		
		
		tampon = aleatoire(route1->size, 0);//debut route1
		tampon4 = aleatoire(copy->size, 1);
		tmpo = GetElementAt(copy, tampon4);
		rout = IntersecClusters(copy, tmpo, 1);
		afficherListe(copy);
		i = InsertGoodSpot(copy, route1, rout, tampon);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}

		tampon = aleatoire(route2->size, 0);//debut route2
		tampon4 = aleatoire(copy->size / 2, 1);
		tmpo = GetElementAt(copy, tampon4);
		rout = IntersecClusters(copy, tmpo, 1);
		i = InsertGoodSpot(copy, route2, rout, tampon);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}

		tampon = aleatoire(route3->size, 0);//debut route3
		tampon4 = aleatoire(copy->size/2, 1);
		tmpo = GetElementAt(copy, tampon4);
		rout = IntersecClusters(copy, tmpo, 1);
		i = InsertGoodSpot(copy, route3, rout, tampon);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
	}
	
	tampon9 = 0;
	while ((tampon9<100)) {
		i=InsertLeftOver(copy,route);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
		i = InsertLeftOver(copy, route1);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
		tmpo = (GetElementAt(copy, 0));
		i = InsertLeftOver(copy, route2);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
		tmpo = (GetElementAt(copy, 0));
		i = InsertLeftOver(copy, route3);
		if (i == 0) {
			tampon9 = tampon9 + 1;
		}
	}
	
	save1=route;
	save2= route1;
	save3= route2;
	save4= route3;
	save5 = copy;

	afficherListHeure(save1);
	printf("\n");
	afficherListHeure(save2);
	printf("\n");
	afficherListHeure(save3);
	printf("\n");
	afficherListHeure(save4);
	printf("\n");

	afficherListe(save5);
	printf("on est ici");
	system("pause");

	for (int k = 0; k < 200; k++) {
		tampon9 = 0;
		copy = CopyList(liste);//creation de la copy que l on va utiliser

		route = InitList(copy);//initialisation des route avec le depot et un element aleatoire
		route1 = InitList(copy);
		route2 = InitList(copy);
		route3 = InitList(copy);
		DeletCopy(copy, 0);
		while ((tampon9 < 10000))
		{
			tampon = aleatoire(route->size, 0);//debut route
			tampon4 = aleatoire(copy->size, 1);
			tmpo = GetElementAt(copy, tampon4);
			rout = IntersecClusters(copy, tmpo, 1);
			i = InsertGoodSpot(copy, route, rout, tampon);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
			tampon = aleatoire(route1->size, 0);//debut route1
			tampon4 = aleatoire(copy->size, 1);
			tmpo = GetElementAt(copy, tampon4);
			rout = IntersecClusters(copy, tmpo, 1);
			afficherListe(copy);
			i = InsertGoodSpot(copy, route1, rout, tampon);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}

			tampon = aleatoire(route2->size, 0);//debut route2
			tampon4 = aleatoire(copy->size, 1);
			tmpo = GetElementAt(copy, tampon4);
			rout = IntersecClusters(copy, tmpo, 1);
			i = InsertGoodSpot(copy, route2, rout, tampon);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}

			tampon = aleatoire(route3->size, 0);//debut route3
			tampon4 = aleatoire(copy->size, 1);
			tmpo = GetElementAt(copy, tampon4);
			rout = IntersecClusters(copy, tmpo, 1);
			i = InsertGoodSpot(copy, route3, rout, tampon);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
		}

		tampon9 = 0;
		while ((tampon9 < 100)) {
			i = InsertLeftOver(copy, route);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
			i = InsertLeftOver(copy, route1);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
			tmpo = (GetElementAt(copy, 0));
			i = InsertLeftOver(copy, route2);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
			tmpo = (GetElementAt(copy, 0));
			i = InsertLeftOver(copy, route3);
			if (i == 0) {
				tampon9 = tampon9 + 1;
			}
		}
		j = 0;
		j = j + CheckTime(route);
		j = j + CheckTime(route1);
		j = j + CheckTime(route2);
		j = j + CheckTime(route3);


		if(j==4){
			if ((route->size + route1->size + route2->size + route3->size) > (save1->size + save2->size + save3->size + save4->size)) {
				
				save1 = route;
				save2 = route1;
				save3 = route2;
				save4 = route3;
				save5 = copy;
			}
			if ((route->size + route1->size + route2->size + route3->size) == (save1->size + save2->size + save3->size + save4->size)) {
				time1 = CalculeTimeItin(route);
				time2 = CalculeTimeItin(route1);
				time3 = CalculeTimeItin(route2);
				time4 = CalculeTimeItin(route3);
				timecompar1 = (Horloge_addition(time1, time2));
				timecompar1 = (Horloge_addition(timecompar1, time3));
				timecompar1 = (Horloge_addition(timecompar1, time4));
				time1 = CalculeTimeItin(save1);
				time2 = CalculeTimeItin(save2);
				time3 = CalculeTimeItin(save3);
				time4 = CalculeTimeItin(save4);
				timecompar2 = (Horloge_addition(time1, time2));
				timecompar2 = (Horloge_addition(timecompar1, time3));
				timecompar2 = (Horloge_addition(timecompar1, time4));
				if (est_sup(timecompar2, timecompar1)) {
					save1 = route;
					save2 = route1;
					save3 = route2;
					save4 = route3;
					save5 = copy;
				}
			}
		}
	}

	system("pause");
	
	time1 = CalculeTimeItin(save1);
	time2 = CalculeTimeItin(save2);
	time3 = CalculeTimeItin(save3);
	time4 = CalculeTimeItin(save4);

	printf("%d:%d %d:%d %d:%d %d:%d", time1.heure, time1.minute, time2.heure, time2.minute, time3.heure, time3.minute, time4.heure, time4.minute);
	printf("\n");
	afficherListHeure(save1);
	printf("\n");
	afficherListHeure(save2);
	printf("\n");
	afficherListHeure(save3);
	printf("\n");
	afficherListHeure(save4);
	printf("\n");

	afficherListe(save5);

	
	system("pause");
	return (EXIT_SUCCESS);
}

