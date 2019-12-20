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

//check capacity car
int CheckCapacity(LinkedList* route, int capa);

//check if the departure of client is before the arival
int CheckDeparturBeforeArival (Voiture car,SingleLinkedListElem* arret);

//check if temp depos is in the time window
int CheckDeparturTime (LinkedList* route);

int CheckArivalTime (LinkedList* route);

int CheckWorckTime (Voiture car);
//test si le premier est superieur au deuxieme
bool est_sup (Time time1, Time time2);

//test si le premier est inferieur au deuxieme
bool est_inf (Time time1, Time time2);

int CheckTime(LinkedList* route);