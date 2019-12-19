#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "liste.h"
#include "check.h"
#include "cluster.h"
#include "Structures.h"


#define TAILLE_MAX 1000 // Tableau de taille 1000



FILE RouteDrawing(char NomDuFichierOuNomDuChemin[], LinkedList* MaRoute) {

	//Ouverture du fichier texte en veillant à pouvoir écrire dedans
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

	//Nous regardons les éléments de la liste chainées et commençons à dessiner notre schéma graphviz
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentsuivant;
	current = GetElementAt(MaRoute, 0);
	currentsuivant = GetElementAt(MaRoute, 1);
	fprintf(fichier, "digraph G{");
	while (current != MaRoute->tail) {

		fprintf(fichier, "%d->%d ;\n",current->info.order.ID,currentsuivant->info.order.ID);

		current = currentsuivant;
		currentsuivant = currentsuivant->next;
	}

	fprintf(fichier, "}");


}


int main() {
	LinkedList* liste;
	liste = lecture_fichier("a4-40.txt");
	liste = Initialisation(liste);
	afficherListe(liste);

	LinkedList* copy;
	copy = CopyList(liste);

	
	printf("is departure %d \n", copy->tail->info.isDeparture);



	float somme = 0;
	Pos x1;
	Pos x2;
	SingleLinkedListElem* a;
	for (int k=0; k< copy->size; k++){
		a = GetElementAt(copy, k);
		if (a->info.isDeparture == true) {
			x1 = a->info.order.depart;
			k++;
		}
		else {
			x1 = a->info.order.arrivee;
			k++;
		}
		if (a->next->info.isDeparture == true) {
			x2 = a->info.order.depart;
			
		}
		else {
			x2 = a->next->info.order.arrivee;
		
		}
		somme += distance(x1, x2);
	}
	
	printf(" voici la distance totale :  %f \n",somme);

	printf("\n");
	printf("j affiche ici ma liste copy \n");
	afficherListe(copy);
	printf("\n");

	RouteDrawing("demo.dot",copy );



	


	//LinkedList* route;

	//route = InsertDepot(copy);
	//DeletCopy(copy, 0);


	//afficherListe(route);
	//printf("\n");

	//int tampon;
	//for (int i = 0; i < 2; i++)
	//{
	//	tampon = aleatoire(40, 0);
	//}
	//route = InsertElementAleatoire(tampon, copy, route);
	//route = InitFirstElement(route);
	//afficherListe(route);
	//printf("\n");
	//afficherListeHeure(route);
	//printf("\n affichage de copy : ");

	//afficherListe(copy);
	//printf("\n");

	//LinkedList* rout;
	//SingleLinkedListElem* tmpo;
	//tmpo = GetElementAt(copy, 1);
	//rout = IntersecClusters(copy, tmpo, 1);
	//printf("\n interssection cluster: ");

	//afficherListe(rout);


	//for (int i = 0; i < 3; i++)
	//{
	//	tampon = aleatoire(route->size, 1);
	//}
	//rout = IntersecClusters(copy, tmpo, 1);
	//int i = 0;
	//i = InsertGoodSpot(copy, route, rout, tampon);
	//afficherListe(route);
	//afficherListe(copy);
	//for (int i = 0; i < 3; i++)
	//{
	//	tampon = aleatoire(route->size, 1);
	//}
	//rout = IntersecClusters(copy, tmpo, 1);
	//i = InsertGoodSpot(copy, route, rout, tampon);
	//printf("\n afficherListe ");
	//afficherListe(route);
	//afficherListeIstaken(route);
	//printf("\n affichercopy ");
	


	system("dot -Tpng demo.dot -o demo_dot.png");
	return (EXIT_SUCCESS);
}

