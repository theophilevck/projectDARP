#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "liste.h"
#include "Structures.h"

//cluster temp arriver
LinkedList* clusterHeureAriver(LinkedList* listeclient, ElementListe test);

//cluster temp depart
LinkedList* clusterHeureDepart(LinkedList* listeclient, ElementListe test);

//cluster capaciter
LinkedList* clusterCapaciter(LinkedList* listeclient, ElementListe test, int capaActuel, int capMax);

//cluster de distance
LinkedList* clusterGeographique(LinkedList* listeclient, ElementListe client, float dist);

//aleatoire
int aleatoire(int max,int min);

//cre l interssection de chaque client 
LinkedList* IntersecClusters(LinkedList* list, SingleLinkedListElem* tmp);

//fonction qui compte le nombre de fois ou chaque client est present dans les cluster
int nbrePresenceClusters(SingleLinkedListElem* tmp, LinkedList* c1, LinkedList* c2, LinkedList* c3, LinkedList* c4);


