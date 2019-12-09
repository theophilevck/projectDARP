#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "liste.h"
#include "Structures.h"

//cluster temp arriver
LinkedList* clusterHeureAriver(LinkedList* list, ElementListe test);

//cluster temp depart
LinkedList* clusterHeureDepart(LinkedList* list, ElementListe test);

//cluster capaciter
LinkedList* clusterCapaciter(LinkedList* list, ElementListe test, int capaActuel, int capMax);

//cluster de distance
LinkedList* clusterGeographique(LinkedList* list, ElementListe client, float dist);

//calcule distance 
float distance(Pos p1, Pos p2);

//aleatoire
int aleatoire(int taille);


LinkedList* IntersecCluster(LinkedList* list);

int nbre_presence_cluster(SingleLinkedListElem* tmp, LinkedList* c1, LinkedList* c2, LinkedList* c3, LinkedList* c4);
