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
FILE RouteDrawing(char NomDuFichierOuNomDuChemin[], LinkedList* MaRoute1, LinkedList* MaRoute2, LinkedList* MaRoute3, LinkedList* MaRoute4, LinkedList* copy);

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
	
	for (int k = 0; k < 10; k++) {
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
				afficherListe(route);
				while (tmpo==NULL)
				{
				
					tampon = aleatoire(route->size, 0);
					tmpo = GetElementAt(route, tampon);
				}
				rout = IntersecClusters(copy, tmpo);

				i = InsertGoodSpot(copy, route, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route

				tampon = aleatoire(route1->size, 0);//debut route11

				tmpo = GetElementAt(route1, tampon);
				afficherListe(route1);
				while (tmpo == NULL)
				{
			
					tampon = aleatoire(route->size, 0);
					tmpo = GetElementAt(route1, tampon);
				}
				rout = IntersecClusters(copy, tmpo);

				i = InsertGoodSpot(copy, route, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route1

				tampon = aleatoire(route2->size, 0);//debut route2

				tmpo = GetElementAt(route2, tampon);
				afficherListe(route2);
				while (tmpo == NULL)
				{
			
					tampon = aleatoire(route->size, 0);
					tmpo = GetElementAt(route2, tampon);
				}
				rout = IntersecClusters(copy, tmpo);

				i = InsertGoodSpot(copy, route2, rout, tampon);
				if (i == 0) {
					tampon9 = tampon9 + 1;
				}
				//fin route2

				tampon = aleatoire(route3->size, 0);//debut route3

				tmpo = GetElementAt(route3, tampon);
				afficherListe(route3);
				while (tmpo == NULL)
				{
					tampon = aleatoire(route->size, 0);
					tmpo = GetElementAt(route3, tampon);
				}
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

			//test de verification de la solution et sauvegarde si elle est meilleure que la precedente
			if (j == 4) {
					if(save1!=NULL){
						if ((route->size + route1->size + route2->size + route3->size) > (save1->size + save2->size + save3->size + save4->size)) {
							save1 = route;//si on dans la nouvelle solution on prend plus de client que dans celle sauvegarder on sauvegarde la nouvelle
							save2 = route1;
							save3 = route2;
							save4 = route3;
							save5 = copy;
						}
						if ((route->size + route1->size + route2->size + route3->size) == (save1->size + save2->size + save3->size + save4->size)) {
							//choix de la fonction si on prefere le temps de la tourner reele ou si on veux le temps que ça va prendre de faire les chemin
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

							/*time1 = CalculeTimeTotalItin(route);
							time2 = CalculeTimeTotalItin(route1);
							time3 = CalculeTimeTotalItin(route2);
							time4 = CalculeTimeTotalItin(route3);
							timecompar1 = (Horloge_addition(time1, time2));
							timecompar1 = (Horloge_addition(timecompar1, time3));
							timecompar1 = (Horloge_addition(timecompar1, time4));
							time1 = CalculeTimeTotalItin(save1);
							time2 = CalculeTimeTotalItin(save2);
							time3 = CalculeTimeTotalItin(save3);
							time4 = CalculeTimeTotalItin(save4);
							timecompar2 = (Horloge_addition(time1, time2));
							timecompar2 = (Horloge_addition(timecompar1, time3));
							timecompar2 = (Horloge_addition(timecompar1, time4));*/
							
							
							if (est_sup(timecompar2, timecompar1)) {
								save1 = route;//si la nouvelle solutiion fait la meme taille que celle sauvegarder mais quelle est plus rapide on la sauvegarde
								save2 = route1;
								save3 = route2;
								save4 = route3;
								save5 = copy;
							}
						}
					}
					else
					{
						save1 = route;//si les sauvgarde sont vide on sauvegarde les routes que l on viens de cree
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

	copy = CopyList(liste);
	//afichage des solution sur graphiz
	RouteDrawing("demo.dot", save1, save2, save3, save4, copy);
	
	system("pause");
	return (EXIT_SUCCESS);
}



//fonction graphiz
FILE RouteDrawing(char NomDuFichierOuNomDuChemin[], LinkedList* MaRoute1, LinkedList* MaRoute2, LinkedList* MaRoute3, LinkedList* MaRoute4, LinkedList* copy) {

	//Ouverture du fichier texte en veillant � pouvoir �crire dedans
	FILE* fichier = fopen(NomDuFichierOuNomDuChemin, "w");
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
	current = copy->head;
	currentsuivant = current->next;
	fprintf(fichier, "digraph G{engine=\"neato\"\n");
	while (current != copy->tail) {
		if (current == copy->head) {
			fprintf(fichier, "Depot [shape=box , pos=\"%.3f,%.3f!\"] \n", 0, 0);
		}
		else
		{
			if (current->info.isDeparture == true) {
				fprintf(fichier, "%d.%d [pos=\"%.3f,%.3f!\"] \n", current->info.order.ID, current->info.isDeparture, current->info.order.depart.X, current->info.order.depart.Y);

			}
			else
			{
				fprintf(fichier, "%d.%d [pos=\"%.3f,%.3f!\"] \n", current->info.order.ID, current->info.isDeparture, current->info.order.arrivee.X, current->info.order.arrivee.Y);
			}
		}

		current = currentsuivant;
		currentsuivant = currentsuivant->next;

	}

	current = MaRoute1->head;
	currentsuivant = current->next;

	while (currentsuivant != MaRoute1->tail) {
		if (current == MaRoute1->head) {
			fprintf(fichier, "Depot->%d.%d [color=red,penwidth=3.0]  \n", currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
		}
		else {
			if (current->info.isDeparture == true) {
				fprintf(fichier, "%d.%d->%d.%d [color=red,penwidth=3.0]  \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
			else
			{
				fprintf(fichier, "%d.%d->%d.%d [color=red,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
		}
		current = currentsuivant;
		currentsuivant = currentsuivant->next;
	}
	fprintf(fichier, "%d.%d->Depot [color=red,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture);

	//route2

	current = MaRoute2->head;
	currentsuivant = current->next;

	while (currentsuivant != MaRoute2->tail) {
		if (current == MaRoute2->head) {
			fprintf(fichier, "Depot->%d.%d [color=limegreen,penwidth=3.0]  \n",  currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
		}
		else {
			if (current->info.isDeparture == true) {
				fprintf(fichier, "%d.%d->%d.%d [color=limegreen,penwidth=3.0]  \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
			else
			{
				fprintf(fichier, "%d.%d->%d.%d [color=limegreen,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
		}
		current = currentsuivant;
		currentsuivant = currentsuivant->next;


	}
	fprintf(fichier, "%d.%d->Depot [color=limegreen,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture);

	//route3

	current = MaRoute3->head;
	currentsuivant = current->next;

	while (currentsuivant != MaRoute3->tail) {
		if (current == MaRoute3->head) {
			fprintf(fichier, "Depot->%d.%d [color=blue,penwidth=3.0]  \n",  currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
		}
		else {
			if (current->info.isDeparture == true) {
				fprintf(fichier, "%d.%d->%d.%d [color= blue,penwidth=3.0]  \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
			else
			{
				fprintf(fichier, "%d.%d->%d.%d [color= blue,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
		}
		current = currentsuivant;
		currentsuivant = currentsuivant->next;
	}
	fprintf(fichier, "%d.%d->Depot [color= blue,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture);

	//route4

	current = MaRoute4->head;
	currentsuivant = current->next;

	while (currentsuivant != MaRoute4->tail) {
		if (current == MaRoute4->head) {
			fprintf(fichier, "Depot->%d.%d [color=yellow,penwidth=3.0]  \n", currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
		}
		else{
			if (current->info.isDeparture == true) {
				fprintf(fichier, "%d.%d->%d.%d [color=yellow,penwidth=3.0]  \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
			else
			{
				fprintf(fichier, "%d.%d->%d.%d [color=yellow,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture, currentsuivant->info.order.ID, currentsuivant->info.isDeparture);
			}
	}
	current = currentsuivant;
	currentsuivant = currentsuivant->next;
	}
	fprintf(fichier, "%d.%d->Depot [color=yellow,penwidth=3.0] \n", current->info.order.ID, current->info.isDeparture);
	
	fprintf(fichier, "}");
}
	

	


