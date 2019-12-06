#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "liste.h"
#include "Structures.h"

//cluster temp arriver
LinkedList* clusterHeureAriver(ElementListe listeclient[], ElementListe test);

//cluster temp depart
LinkedList* clusterHeureDepart(ElementListe listeclient[], ElementListe test);

//cluster capaciter
LinkedList* clusterCapaciter(ElementListe listeclient[100], ElementListe test, int capaActuel, int capMax);

//cluster de distance
LinkedList* clusterGeographique(ElementListe list[100], ElementListe client, int nbdemande, float dist);

//calcule distance 
float distance(Pos p1, Pos p2);

//aleatoire
int aleatoire(int taille);