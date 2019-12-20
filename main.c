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
FILE RouteDrawing(char NomDuFichierOuNomDuChemin[], LinkedList* MaRoute);


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


	LinkedList* save1=NewLinkedList();//sauvegarde de la meilleur route
	LinkedList* save2 = NewLinkedList();
	LinkedList* save3 = NewLinkedList();
	LinkedList* save4 = NewLinkedList();
	LinkedList* save5 = NewLinkedList();

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
	system("pause");
	
	for (int k = 0; k < 100; k++) {
		tampon9 = 0;
		copy = CopyList(liste);//creation de la copy que l on va utiliser
		if (copy != NULL) {
			route = InitList(copy);//initialisation des route avec le depot et un element aleatoire
			route1 = InitList(copy);
			route2 = InitList(copy);
			route3 = InitList(copy);
			DeletCopy(copy, 0);
			while ((tampon9 < 1000))
			{
				tampon = aleatoire(route->size, 0);//debut route

				tmpo = GetElementAt(route, tampon);
				rout = IntersecClusters(copy, tmpo);
				i = InsertGoodSpot(copy, route, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route

				tampon = aleatoire(route1->size, 0);//debut route1
				tampon4 = aleatoire(copy->size, 1);
				tmpo = GetElementAt(copy, tampon4);
				rout = IntersecClusters(copy, tmpo);
				afficherListe(copy);
				i = InsertGoodSpot(copy, route1, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route1

				tampon = aleatoire(route2->size, 0);//debut route2

				tmpo = GetElementAt(copy, tampon);
				rout = IntersecClusters(copy, tmpo);
				i = InsertGoodSpot(copy, route2, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route2

				tampon = aleatoire(route3->size, 0);//debut route3

				tmpo = GetElementAt(copy, tampon);
				rout = IntersecClusters(copy, tmpo);
				i = InsertGoodSpot(copy, route3, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
			}
			//fin route3

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
				i = InsertLeftOver(copy, route2);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				i = InsertLeftOver(copy, route3);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
			}
			//teste pour verifier si il n y a pas d erreur sur les horraire de passage
			j = 0;
			j = j + CheckTime(route);
			j = j + CheckTime(route1);
			j = j + CheckTime(route2);
			j = j + CheckTime(route3);
			//fin du teste

			printf("\n");
			afficherListHeure(route);
			printf("\n");
			afficherListHeure(route1);
			printf("\n");
			afficherListHeure(route2);
			printf("\n");
			afficherListHeure(route3);
			printf("\n");

			//test de verification de la solution et sauvegarde si elle est meilleure que la precedente
			if (j == 4) {
					if(save1!=NULL){
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
					else
					{
						save1 = route;
						save2 = route1;
						save3 = route2;
						save4 = route3;
						save5 = copy;

					}
			}
		}
	}

	//affichage de la solution sauvegarder
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
	//affichage des cleint qui non pas etes pris en charge
	afficherListe(save5);

	//afichage des solution sur graphiz
	RouteDrawing("demo.dot", save1);
	RouteDrawing("demo1.dot", save2);
	RouteDrawing("demo2.dot", save3);
	RouteDrawing("demo3.dot", save4);
	
	system("pause");
	return (EXIT_SUCCESS);
}



//fonction graphiz
FILE RouteDrawing(char NomDuFichierOuNomDuChemin[], LinkedList* MaRoute) {
	//Ouverture du fichier texte en veillant � pouvoir �crire dedans
	FILE* fichier = fopen(NomDuFichierOuNomDuChemin, "r+");
	//Verifions que le pointeur a bien pris le fichier
	if (fichier != NULL)
	{
		//OK
	}
	else
	{
		//On affiche un message d'erreur si on veut
		printf("Impossible d'ouvrir le fichier");
	}
	//Nous regardons les �l�ments de la liste chain�es et commen�ons � dessiner notre sch�ma graphviz
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentsuivant;
	current = GetElementAt(MaRoute, 0);
	currentsuivant = GetElementAt(MaRoute, 1);
	fprintf(fichier, "digraph G{");
	while (current != MaRoute->tail) {

		fprintf(fichier, "%d->%d ;\n", current->info.order.ID, currentsuivant->info.order.ID);

		current = currentsuivant;
		currentsuivant = currentsuivant->next;
	}
	fprintf(fichier, "}");
}

