#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

//check capacity car
int CheckCapacity(Voiture );

//check if the departure of client is before the arival
int CheckDeparturBeforeArival(LinkedList route,SingleLinkedListElem* arret);

//check if temp depos is in the time window
int CheckDeparturTime(LinkedList route);