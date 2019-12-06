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



LinkedList* Initialisation(LinkedList* client) {

	LinkedList* listechaineclient_copy;
	listechaineclient_copy = NewLinkedList();

	SingleLinkedListElem* a;
	
	for (int k = 0; k < client->size; k++) {

		a=GetElementAt(client, k);
		a->info.isDeparture = true;
		a->info.priseencharge.heure = 0;
		a->info.priseencharge.minute = 0;
		a->info.order.dureemax.heure = 0;
		a->info.order.dureemax.minute = 30;
		a->info.order.nbrpersonne = 1;
		a->info.order.isTaken = true;

		InsertElementAt(listechaineclient_copy, k, a->info);

		a->info.isDeparture = false;
		InsertElementAt(listechaineclient_copy, k, a->info);
	}
	return(listechaineclient_copy);
}


int main(){
	
	// je lis mon fichier et je cree mes 2 listes chainees

	LinkedList* listechaineclient;
	LinkedList* listechaineclient_copy;
	listechaineclient = NewLinkedList();
	listechaineclient_copy = NewLinkedList();

	listechaineclient  =lecture_fichier("a4-40.txt");

	afficherListe(listechaineclient);

	listechaineclient_copy = Initialisation(listechaineclient);

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



	system("pause");
	return (0);



}












