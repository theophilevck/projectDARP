#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

//check capacity car
int CheckCapacity (Voiture car);

//check if the departure of client is before the arival
int CheckDeparturBeforeArival (LinkedList route,SingleLinkedListElem* arret);

//check if temp depos is in the time window
int CheckDeparturTime (Voiture car);

int CheckArivalTime (Voiture car);

int CheckWorckTime (Voiture car);

bool est_sup (Time time1, Time time2);

bool est_inf (Time time1, Time time2);