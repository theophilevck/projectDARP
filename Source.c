#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "liste.h"
#include "cluster.h"
#include "check.h"
#include "Structures.h"
#include "lecture.h"
#include <stdbool.h>








int main(){
	
	// je lis mon fichier et je cree mes 2 listes chainees

	LinkedList* listechaineclient;
	LinkedList* listechaineclient_copy;
	listechaineclient = NewLinkedList();
	listechaineclient_copy = NewLinkedList();

	listechaineclient  =lecture_fichier("a4-40.txt");

	//afficherListe(listechaineclient);

	listechaineclient = Initialisation(listechaineclient);

	listechaineclient_copy = CopyList(listechaineclient);

	printf("j affiche la listecopie \n");


	afficherListe(listechaineclient_copy);



	// Je cree une voiture

	Voiture taxi;
	taxi.Id = 1;
	taxi.Cn = 5;
	taxi.depot.nbVoiture = 4;
	taxi.depot.position.X = 0;
	taxi.depot.position.Y = 0;
	taxi.dtravaille.heure = 10;
	taxi.dtravaille.minute = 0;
	taxi.Edepart.heure = 0;
	taxi.Edepart.minute = 0;
	taxi.Earrivee.heure = 24;
	taxi.Earrivee.minute = 0;
	taxi.Route = NewLinkedList();






	SingleLinkedListElem* tmp;

	ElementListe Listeclient[100];
	for (int i = 0; i < listechaineclient_copy->size; i++) {

		tmp = GetElementAt(listechaineclient_copy, i);
		Listeclient[i] = tmp->info;
		
	}

	printf("ici j affiche la route initialisee \n");

	taxi.Route = InsertDepot(listechaineclient_copy);
	taxi.Route = InsertElementAleatoire(5, listechaineclient_copy, taxi.Route);
	
	afficherListe(taxi.Route);



	
	
	LinkedList* clusteropt;
	clusteropt = NewLinkedList();



	clusteropt = IntersecCluster(listechaineclient_copy);
	afficherListe(clusteropt);
	/*
	LinkedList* clusdep;
	clusdep = NewLinkedList();

	LinkedList* clusarriv;
	clusarriv = NewLinkedList();

	LinkedList* clusgeo;
	clusgeo = NewLinkedList();

	capa=clusterCapaciter(listechaineclient_copy, Listeclient[0], 0, 3);
	clusdep = clusterHeureDepart(listechaineclient_copy, Listeclient[0]);
	clusarriv = clusterHeureAriver(listechaineclient_copy, Listeclient[0]);
	clusgeo = clusterGeographique(listechaineclient_copy, Listeclient[0],5);

	printf("clustercapa du premier element \n");

	afficherListe(capa);

	printf("clusterheurededepart du premier element \n");
	afficherListe(clusdep);

	printf("clusterheurearrivee du premier element \n");
	afficherListe(clusarriv);

	printf("clustergeographique du premier element \n");
	afficherListe(clusgeo);
	*/


	system("pause");
	return (0);



}












