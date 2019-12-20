#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "structures.h"



typedef struct SingleLinkedListElem {
    ElementListe info;
	struct SingleLinkedListElem *next;//pointeur qui fait refernce a l elemnen qui suis dans la liste chainee
} SingleLinkedListElem;

typedef struct LinkedList {
	SingleLinkedListElem *head;//premier element de la liste chainee
	SingleLinkedListElem *tail;//dernier element de la liste chainee
	int size;//taille de la liste chainee
} LinkedList;

typedef struct voiture {
	int Id;
	int Cn;
	Depot depot;
	Time Edepart;
	Time Earrivee;
	Time dtravaille;
	LinkedList* Route;
}Voiture;

//Cree une voiture
Voiture NewCar(int Id, int Cn, Depot depot);

// Cree une liste chaînee unilatere vide et renvoie un pointeur sur celle-ci
LinkedList* NewLinkedList();

// Cree un nouveau maillon qui contient une nouvelle info et renvoie un pointeur sur ce maillon
SingleLinkedListElem* NewLinkedListElement(ElementListe info);

// Renvoie un pointeur sur le maillon qui se trouve en ieme position a partir de 1
SingleLinkedListElem* GetElementAt(LinkedList* liste, int i);

// Ajoute un nouvelle elemnt dans la liste chaînee en ieme position
int InsertElementAt(LinkedList* liste, int i, ElementListe info);

// Suppression et destruction d'un element de liste chainee
int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* Elem);

//affiche la liste element par element
void afficherListe(LinkedList *liste);

//affiche la liste element par element en specifiant si l element est un depart(1) ou une arriver(0)
void afficherListeIstaken(LinkedList *liste);

//affiche la liste element par element en specifiant la position du point ou l on se trouve
void afficherListePosition(LinkedList *liste);

//affiche la liste element par element en specifiant l heure a laquelle on se trouve a cette element
void afficherListHeure(LinkedList *liste);

//insertion des depot pour initialiser la route
LinkedList* InsertDepot(LinkedList* client);

//inserer les element aleatoire pour initialiser la chaine et cree 
LinkedList* InsertElementAleatoire(int aleatoire, LinkedList* client, LinkedList* route);

//initialisation de la LinkedList apres avoir lu le fichier file.txt
LinkedList* Initialisation(LinkedList* client);

//creation d une copy de la liste de client, on passe de n client a 2n+2 client au totale
LinkedList* CopyList(LinkedList* client);

//suprime les element qui on l id entrer dans la liste chainee
LinkedList* DeletCopy(LinkedList* client, int id);

//fonction qui insere et intilaise certaine valeur des elemnt
int InsertGoodSpot(LinkedList* copy, LinkedList* rout, LinkedList* IntersecClusters, int aleatoire);

//intialisation du premier client et des depot qui sont dans la liste chainee
LinkedList* InitFirstElement(LinkedList* client);

//fonction qui essaye d insere les element qui non pas pu etre inserer avant
int InsertLeftOver(LinkedList* copy, LinkedList* rout);

//calcule distance 
float distance(Pos p1, Pos p2);

//fonction qui permet de faire l addition de variable de temps
Time Horloge_addition(Time a, Time b);

//fonction qui permet de faire la sustraction de variable de temps
Time horloge_soustraction(Time a, Time b);

//calcule 
Time tempsparcours(SingleLinkedListElem* A, SingleLinkedListElem* B);

//fonction qui calcule le temps de parcour totale de la route
Time CalculeTimeItin(LinkedList* copy);

//fonction qui calcule le temps efectif qu il faut pour realiser la route
Time CalculeTimeTotalItin(LinkedList* copy);

//fonction qui teste si on peux insere les deux element qui constitue un client
int CheckinsertionFirstElement2(LinkedList* route, SingleLinkedListElem* cournat, SingleLinkedListElem* insertion);

//fonction qui teste ou on peux insere l element retour d un client
int CheckinsertionSecondElement2(LinkedList* route, SingleLinkedListElem* cournat, SingleLinkedListElem* insertion);

//fonction qui initialise la liste avec le depot et le premier client
LinkedList* InitList( LinkedList* copy);

//fonction qui parcour la liste chainee et qui rensseigne la capaciter a chaque maillont
LinkedList* InitCapa(LinkedList* route);

