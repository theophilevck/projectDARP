#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"

//cluster temp arriver
LinkedList* clusterHeureAriver(Client listeclient[], Client test);

//cluster temp depart
LinkedList* clusterHeureDepart(Client listeclient[], Client test);

//cluster capaciter
LinkedList* clusterCapaciter(Client listeclient[], ElementListe test,int capa, int capMax);