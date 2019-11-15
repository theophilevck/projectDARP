#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include <math.h>



int main() {

	// le taxi part de l'entrepot donc la première valeur de la liste c'est la position de l'entrepot

	Pos entrepot;
	entrepot.X = 0;
	entrepot.Y = 0;

	
	// client1 initialisation
	Client client1;
	client1.depart.X = -5;
	client1.depart.Y = 1;
	client1.arrivee.X = 6;
	client1.arrivee.Y = 6;
	client1.dureemax.heure = 0;
	client1.dureemax.minute = 30;
	client1.ID = 1;
	client1.intervallearrivee[0].heure = 1;
	client1.intervallearrivee[0].minute = 0;
	client1.intervallearrivee[1].heure = 23;
	client1.intervallearrivee[1].minute = 0;
	client1.intevalledepart[0].heure = 3;
	client1.intevalledepart[0].minute = 33;
	client1.intevalledepart[1].heure = 3;
	client1.intevalledepart[1].minute = 48;
	client1.nbrpersonne = 1;

	Depot dep;
	dep.nbVoiture = 2;
	dep.position.X = 0;
	dep.position.Y = 0;

	Voiture car;
	car.Id = 1;
	car.Cn = 4;
	car.depot = dep;
	car.dtravaille.heure = 7;
	car.dtravaille.minute = 0;
	car.Route= NewLinkedList();

	Client depotc;
	depotc.depart.X = 0;
	depotc.depart.Y = 0;
	depotc.arrivee.X = 0;
	depotc.arrivee.Y = 0;
	depotc.dureemax.heure = 24;
	depotc.dureemax.minute = 0;
	depotc.ID = 0;
	depotc.intervallearrivee[0].heure = 12;
	depotc.intervallearrivee[0].minute = 0;
	depotc.intervallearrivee[1].heure = 24;
	depotc.intervallearrivee[1].minute = 0;
	depotc.intevalledepart[0].heure = 0;
	depotc.intevalledepart[0].minute = 0;
	depotc.intevalledepart[1].heure = 12;
	depotc.intevalledepart[1].minute = 0;
	depotc.nbrpersonne = 0;

	ElementListe depo0d;
	depo0d.order = depotc;
	depo0d.depot.heure = 11;
	depo0d.depot.minute = 0;
	depo0d.isDeparture = true;
	depo0d.depot.heure = 20;
	depo0d.depot.minute = 45;


	ElementListe depo0a;
	depo0a.order = depotc;
	depo0a.depot.heure = 11;
	depo0a.depot.minute = 0;
	depo0a.isDeparture = false;
	depo0a.depot.heure = 20;
	depo0a.depot.minute = 45;

	ElementListe cl1d;
	cl1d.order = client1;
	cl1d.priseencharge.heure = 12;
	cl1d.priseencharge.minute = 0;
	cl1d.isDeparture = true;
	cl1d.depot.heure = 12;
	cl1d.depot.minute = 45;

	ElementListe cl1a;
	cl1a.order = client1;
	cl1a.priseencharge.heure = 12;
	cl1a.priseencharge.minute = 0;
	cl1a.isDeparture = false;
	cl1a.depot.heure = 12;
	cl1a.depot.minute = 45;


	InsertElementAt(car.Route, 0, depo0d);
	InsertElementAt(car.Route, 1, depo0a);
	InsertElementAt(car.Route, 1, cl1a);
	InsertElementAt(car.Route, 1, cl1a);
	InsertElementAt(car.Route, 1, cl1d);
	afficherListe(car.Route);
	printf("\n");
	
	
	int test1 = CheckCapacity(car);
	int test3 = CheckDeparturTime(car);
	int test4 = CheckArivalTime(car);
	int test5 = CheckWorckTime(car);


	printf("CheckCapacity: ");
	printf("%d \n",test1);
	printf("CheckDeparturTime: ");
	printf("%d \n", test3);
	printf(" CheckArivalTime: ");
	printf("%d \n", test4);
	printf("CheckWorckTime: ");
	printf("%d \n", test5);
	system("pause");
	return(EXIT_SUCCESS);
}
