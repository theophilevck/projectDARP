#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "liste.h"
#include "check.h"
#include "cluster.h"
#include "Structures.h"
#include "Calcul.h"

//check capacity car
int CheckCapacity (Voiture car);

//check if the departure of client is before the arival
int CheckDeparturBeforeArival (Voiture car,SingleLinkedListElem* arret);

//check if temp depos is in the time window
int CheckDeparturTime (Voiture car);

int CheckArivalTime (Voiture car);

int CheckWorckTime (Voiture car);
//test si le premier est superieur au deuxieme
bool est_sup (Time time1, Time time2);

//test si le premier est inferieur au deuxieme
bool est_inf (Time time1, Time time2);

int CheckInsertion(SingleLinkedListElem* InsertionAfter, SingleLinkedListElem* ElementTest);

int CheckTime(LinkedList* route);