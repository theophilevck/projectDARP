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
LinkedList* clusterGeographique(LinkedList* listeclient, ElementListe client, int nbdemande, float dist);

//calcule distance 
float distance(Pos p1, Pos p2);

//aleatoire
int aleatoire(int taille);