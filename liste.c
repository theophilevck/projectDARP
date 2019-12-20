
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include "liste.h"
#include "Structures.h"


Voiture NewCar(int id, int cn, Depot Depot) {
	Voiture car;
	car.Cn = cn;
	car.depot = Depot;
	car.Id = id;
	return(car);
}

//create a new empty LinkedList
LinkedList* NewLinkedList() {
	LinkedList* tmp;
	tmp = (LinkedList*)malloc(sizeof(LinkedList));
	if (tmp != NULL) {
		tmp->head = NULL;
		tmp->tail = NULL;
		tmp->size = 0;
	}
	return tmp;
}

//create a new SingleLinkedListElem wich cointain the info in parametre
SingleLinkedListElem* NewLinkedListElement(ElementListe info) {
	SingleLinkedListElem* tmp;
	tmp = (SingleLinkedListElem*)malloc(sizeof(SingleLinkedListElem));
	if (tmp != NULL) {
		tmp->info = info;
		tmp->next = NULL;
	}
	return(tmp);
}

// Get the element of the LinkedList chosen in parameter
SingleLinkedListElem* GetElementAt(LinkedList* Liste, int i) {
	int CurrentIndex = 0;
	SingleLinkedListElem* Element;
	if ((Liste == NULL) || (i < 0) || (i >= Liste->size)) return(NULL);
	if (i == 0) return(Liste->head);
	if (i == Liste->size - 1) return(Liste->tail);
	Element = Liste->head;
	while (CurrentIndex != i && Element != NULL) {
		Element = Element->next;
		CurrentIndex++;
	}
	return(Element);
}

//add a new element in the LinkedList at the position chosen
int InsertElementAt(LinkedList *Liste, int i, ElementListe info) {
	SingleLinkedListElem *CurrentElement, *NewElement;
	
	if (Liste == NULL) return(0);
	CurrentElement = GetElementAt(Liste, i);

	if (CurrentElement != NULL) {
		NewElement = NewLinkedListElement(info);
		if (NewElement == NULL) return(0);
		NewElement->next = CurrentElement;

		if (i == 0) {
			Liste->head = NewElement;
		}
		else {
			CurrentElement = GetElementAt(Liste, i - 1);
			CurrentElement->next = NewElement;
		}
		Liste->size++;
		return(1);
	}
	else {
		if (Liste->size == 0) { 
			NewElement = NewLinkedListElement(info);
			if (NewElement != NULL) {
				Liste->head = NewElement;
				Liste->size = 1;
				Liste->tail = NewElement;
				return(1);
			}
			else {
				return(0);
			}
		}
		if (Liste->size <= i) { 
			NewElement = NewLinkedListElement(info);
			if (NewElement != NULL) {
				Liste->tail->next = NewElement;
				Liste->tail = NewElement;
				Liste->size += 1;
				return(1);
			}
			else {
				return(0);
			}
		}
	}
	return(0);
}

int DeleteLinkedListElem(LinkedList* list, SingleLinkedListElem* item) {
	if (list == NULL) return(0); 
	if ((list->head == NULL) || (list->tail == NULL)) return(0);
	if ((list->head == list->tail) && (list->size != 1)) return(0);
	if ((list->size == 0) || (item == NULL)) return(0); 

	SingleLinkedListElem* courant = NULL;
	SingleLinkedListElem* effacer = NULL;
	if (item == list->head) {
	
		courant = list->head;
		list->head = courant->next;
		if (list->size == 1) {
			list->head = NULL;
			list->tail = NULL;
		}
		free(courant);
		list->size--;
		return(1);
	}
	if (item == list->tail) {
		
		courant = list->head;
		while (courant->next != item) {
			courant = courant->next;
		}
		list->tail = courant;
		effacer = courant->next;
		courant->next = courant->next->next;
		free(effacer);
		list->size--;
		return(1);
	}
	else
	{
		courant = list->head;
		while (courant->next != item) {
			courant = courant->next;
		}
		effacer = courant->next;
		courant->next = courant->next->next;

		free(effacer);
		list->size--;
		return(1);
	}
}


void afficherListe(LinkedList *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SingleLinkedListElem* courant = liste->head;
	while (courant != NULL)
	{
			printf("%d -> ", courant->info.order.ID);
		courant = courant->next;
	}
	printf("NULL\n");
}

void afficherListeIstaken(LinkedList *liste)
{
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SingleLinkedListElem* courant = liste->head;
	while (courant != NULL)
	{
		if (courant->info.isDeparture == true) {
			printf("%d %d -> ", courant->info.order.ID, courant->info.isDeparture);
		}
		else {
			printf("%d %d -> ", courant->info.order.ID, courant->info.isDeparture);
		}
		courant = courant->next;
	}
	printf("NULL\n");
}

void afficherListePosition(LinkedList *liste) {
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SingleLinkedListElem* courant = liste->head;
	while (courant != NULL)
	{
		if (courant->info.isDeparture == true) {
			printf("%d %f:%f -> ", courant->info.order.ID, courant->info.order.arrivee.X, courant->info.order.arrivee.Y);
		}
		else {
			printf("%d %f:%f -> ", courant->info.order.ID, courant->info.order.depart.X, courant->info.order.depart.Y);
		}
		courant = courant->next;
	}
	printf("NULL\n");
}

void afficherListHeure(LinkedList *liste) {
	if (liste == NULL)
	{
		exit(EXIT_FAILURE);
	}
	SingleLinkedListElem* courant = liste->head;
	while (courant != NULL)
	{
		if (courant->info.isDeparture == true) {
		printf("%d %d:%d  -> ", courant->info.order.ID, courant->info.priseencharge.heure, courant->info.priseencharge.minute);
		}
		if (courant->info.isDeparture == false)
		{
		printf("%d %d:%d  -> ", courant->info.order.ID, courant->info.depot.heure, courant->info.depot.minute);
		}
		courant = courant->next;
	}
	printf("NULL\n");
}

LinkedList* InsertDepot(LinkedList* client ){
	LinkedList* route;
	route = NewLinkedList();
	SingleLinkedListElem* a;
	a = client->head;
	while (route->size<2) {
		if (a->info.order.ID == 0) {
			if (route->size == 1) {
				if (a->info.isDeparture == 1) {
					InsertElementAt(route, 0, a->info);
				}
				else
				{
					InsertElementAt(route, 1, a->info);
				}
			}
			else
			{
				InsertElementAt(route, 0, a->info);
			}
		}
			a = a->next;
	}
	return(route);
}

LinkedList* InsertElementAleatoire(int aleatoire, LinkedList* client, LinkedList* route) {
	SingleLinkedListElem* a;
	a = GetElementAt(client, aleatoire);
	int id = a->info.order.ID;
	int i = 0;
		while (a != client->tail) {
			if (a->info.order.ID == id) {
				if (route->size %2== 0) {
					InsertElementAt(route, 1, a->info);//on insere l element selectioner entre les depo deja present
					a = a->next;
				}
				else
				{
					if (a->info.isDeparture == 1) {//si l element est un depart il est inserre avant l element que l on vient d insere
						InsertElementAt(route, 1, a->info);
						a = a->next;
						DeletCopy(client, id);
					}
					else
					{//sinon il est insere juste deriere
						InsertElementAt(route, 2, a->info);
						a = a->next;
						DeletCopy(client, id);
					}
				}
			}
			else {
				a = a->next;
			}
		}
	return(route);
}

LinkedList* Initialisation(LinkedList* client) {
	//on initialise les valeur des client qui non pas ete initialise a la lecture du fichier texte
	SingleLinkedListElem* a;

	for (int k = 0; k < client->size; k++) {

		a = GetElementAt(client, k);
		a->info.priseencharge.heure = 0;
		a->info.priseencharge.minute = 0;
		a->info.depot.heure = 0;
		a->info.depot.minute = 0;
		a->info.order.dureemax.heure = 0;
		a->info.order.dureemax.minute = 30;
		a->info.order.nbrpersonne = 1;
		a->info.order.isTaken = true;
		a->info.capaciter = 0;
	}
	return(client);
}

LinkedList* CopyList(LinkedList* client) {
	//cree une copy de la liet client 
	LinkedList* listechaineclient_copy;
	listechaineclient_copy = NewLinkedList();

	SingleLinkedListElem* a;
	SingleLinkedListElem* b;

	for (int k = 0; k < client->size; k++) {
		a = GetElementAt(client, k);
		b = GetElementAt(client, k);
		 a->info.isDeparture = true;//on ajoute un element depart 
		 InsertElementAt(listechaineclient_copy, k, a->info);
		 b->info.isDeparture = false;//et un element arriver pour chauqe client
		 InsertElementAt(listechaineclient_copy, k, b->info);
	}
	return(listechaineclient_copy);
}

LinkedList* DeletCopy(LinkedList* client, int id) {
	SingleLinkedListElem* a;
	int count = 0;
	a = client->head;
	
	while (a != client->tail) {
		if (a->info.order.ID == id) {
			count = count + 1;
			DeleteLinkedListElem(client, a);//on suprime le premier element qui a l id que l on cherche
			a = client->head;
		}
		else
		{
			a = a->next;
		}
	}
	if (a->info.order.ID == id) {
		count = count + 1;
		DeleteLinkedListElem(client, a);//on suprime le deuxieme element qui a l id que l on cherche
		a = client->head;
	}
	return(client);
}

LinkedList* InitFirstElement(LinkedList* client) {
	SingleLinkedListElem* first;
	SingleLinkedListElem* last;
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentNext;

	first = client->head;
	last = client->tail;
	current = client->head;
	current = current->next;
	currentNext= current->next;
	//on initialise d abord l heure darriver du client
	currentNext->info.depot.heure = (currentNext->info.order.intervallearrivee[0].heure + currentNext->info.order.intervallearrivee[1].heure)/2;
	currentNext->info.depot.minute = (currentNext->info.order.intervallearrivee[0].minute + currentNext->info.order.intervallearrivee[1].minute)/2;
	//on initialise enssuite l heure de depart 
	currentNext->info.priseencharge.heure = currentNext->info.depot.heure - 1;
	currentNext->info.priseencharge.minute = currentNext->info.depot.minute;

	current->info.depot = currentNext->info.depot;
	current->info.priseencharge = currentNext->info.priseencharge;

	//on initialise aussi les element depot 
	first->info.depot.heure = 24;
	first->info.depot.minute = 00;
	first->info.priseencharge.heure = 00;
	first->info.priseencharge.minute = 00;

	last->info.depot.heure = 24;
	last->info.depot.minute = 00;
	last->info.priseencharge.heure = 00;
	last->info.priseencharge.minute = 00;
	
	client = InitCapa(client);
	return(client);
}

int InsertGoodSpot(LinkedList* copy, LinkedList* rout, LinkedList* IntersecClusters, int elementbeforerandomnode) {
	SingleLinkedListElem* courant;//parcour la list rout
	SingleLinkedListElem* newCourant;//parcour la list IntersecClusters aleatoirement (element a inserer)
	Time time1;
	int tampon = 0;
	int tampon2 = 1;
	int test = 0;
	time1.heure = 0;
	time1.minute = 0;
	courant = rout->head;
	if (IntersecClusters!=NULL) {

		while (tampon2 != elementbeforerandomnode) {
			if (courant == rout->tail) {
				break;
			}
			courant = courant->next;
			tampon2 = tampon2 + 1;
		}

		tampon = aleatoire(IntersecClusters->size / 2, 0);
		newCourant = GetElementAt(IntersecClusters, tampon);//get a random elemeent we try to insert
		if (newCourant == NULL) {
			return 0;
		}

		while (CheckinsertionFirstElement2(rout, courant, newCourant) != 1) {
			DeletCopy(IntersecClusters, newCourant->info.order.ID);
			if (IntersecClusters->size == 0) {
				return(0);
			}
			tampon = aleatoire(IntersecClusters->size / 2, 0);
			newCourant = GetElementAt(IntersecClusters, tampon);//chose a new element we try to insert
		}

		//atribution de la valeur prise en charge avec le bon temps
		if (courant->info.order.ID != 0) {
			if (courant->info.isDeparture == true) {
				if (newCourant->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, newCourant));
					newCourant->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, newCourant));
					newCourant->info.depot = time1;
				}
			}
			else {
				if (newCourant->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, newCourant));
					newCourant->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, newCourant));
					newCourant->info.depot = time1;
				}
			}
			//fin de l atribution

			//insertion de l elemnt depart
			InsertElementAt(rout, elementbeforerandomnode, newCourant->info);
			afficherListHeure(rout);
			afficherListe(rout);
			
			SingleLinkedListElem* NewCurent;
			SingleLinkedListElem* Curent;
			NewCurent = newCourant;
			tampon2 = tampon2 + 1;
			if (NewCurent == NULL) {
				return(0);
			}
			Curent = courant->next;
			int tampon5 = 0;

			while ((NewCurent != IntersecClusters->tail) && (NewCurent != NULL)) {

				if ((NewCurent->info.order.ID == newCourant->info.order.ID) && (NewCurent->info.isDeparture == false)) {
					break;
				}
				else
				{
					NewCurent = NewCurent->next;
				}
			}
			int tmp = 0;
			while (Curent != rout->tail) {
				tmp = CheckinsertionSecondElement2(rout, Curent, NewCurent);
				if (tmp >= 1) {
					if (tmp == 1) {
						//atribution de la valeur depot avec le bon temps
						if (Curent->info.isDeparture == true) {
							if (NewCurent->info.isDeparture == true)
							{
								time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
								NewCurent->info.priseencharge = time1;
							}
							else
							{
								time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
								NewCurent->info.depot = time1;
							}
							afficherListHeure(rout);
						}
						else {
							Curent = GetElementAt(rout, tmp + 1);
							NewCurent = Curent->next;
							if (NewCurent->info.isDeparture == true)
							{
								time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
								NewCurent->info.priseencharge = time1;
							}
							else
							{
								time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
								NewCurent->info.depot = time1;
							}

						}
						InsertElementAt(rout, tampon2, NewCurent->info);
						afficherListHeure(rout);
						afficherListe(rout);
						Curent = Curent->next;
						tampon5 = 1;
						tampon2 = tampon2 + 1;
						Curent = rout->tail;
					}
					else {
						//atribution de la valeur depot avec le bon temps
						if (Curent->info.isDeparture == true) {
							if (NewCurent->info.isDeparture == true)
							{
								time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
								NewCurent->info.priseencharge = time1;
							}
							else
							{
								time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
								NewCurent->info.depot = time1;
							}
						}
						else {
							if (NewCurent->info.isDeparture == true)
							{
								time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
								NewCurent->info.priseencharge = time1;
							}
							else
							{
								time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
								NewCurent->info.depot = time1;
							}
						}
						//insertion de l element arriver 
						InsertElementAt(rout, tmp+1, NewCurent->info);

						afficherListHeure(rout);
						afficherListe(rout);
						Curent = Curent->next;

						tampon5 = 1;
						tampon2 = tampon2 + 1;
						Curent = rout->tail;
					}
				}
				else
				{
					Curent = Curent->next;
					tampon2 = tampon2 + 1;
				}
			}
			if (tampon5 == 0) {
				//atribution de la valeur depot avec le bon temps
				if (Curent->info.isDeparture == true) {
					if (NewCurent->info.isDeparture == true)
					{
						time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
						NewCurent->info.priseencharge = time1;
					}
					else
					{
						time1 = Horloge_addition(Curent->info.priseencharge, tempsparcours(Curent, NewCurent));
						NewCurent->info.depot = time1;
					}
				}
				else {
					if (NewCurent->info.isDeparture == false)
					{
						time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
						NewCurent->info.priseencharge = time1;
					}
					else
					{
						time1 = Horloge_addition(Curent->info.depot, tempsparcours(Curent, NewCurent));
						NewCurent->info.depot = time1;
					}
				}
				//insertion de l element arriver juste apres l element depart si on ne peux l insere nul par ailleur
				InsertElementAt(rout, elementbeforerandomnode + 1, NewCurent->info);
				afficherListHeure(rout);
			}
			DeletCopy(copy, newCourant->info.order.ID);
			rout = InitCapa(rout);
			return(1);
		}
		else
		{
			return 0;
		}
	}
	else
		{
		return 0;
		}
}

float distance(Pos p1, Pos p2) {
	float tampon1;
	float tampon2;
	tampon1 = (powf((p1.X - p2.X), 2) + powf((p1.Y - p2.Y), 2));
	tampon2 = sqrtf(tampon1);
	return(tampon2);
}

Time Horloge_addition(Time a, Time b) {

	Time resultat;
	resultat.minute = a.minute + b.minute;
	if ((resultat.minute) >= 59) {
		resultat.heure = a.heure + b.heure + resultat.minute/60;
		resultat.minute = resultat.minute % 60;
	}
	else {
		resultat.heure = a.heure + b.heure;
	}
	return(resultat);
}

Time horloge_soustraction(Time a, int minutes) {
	int delta = a.minute - minutes;
	if (delta < 0) {
		a.heure = a.heure - 1;
		a.minute = 60 + delta;
	}
	else {
		a.minute = a.minute - minutes;
	}
	return(a);
}

Time tempsparcours(SingleLinkedListElem* A, SingleLinkedListElem* B) {
	Pos pos1;
	Pos pos2;

	float dist;
	float temps;
	if (A->info.isDeparture == true) {
		pos1 = A->info.order.depart;
	}
	else
	{
		pos1 = A->info.order.arrivee;
	}
	if (B->info.isDeparture == true) {
		pos2 = B->info.order.depart;
	}
	else {
		pos2 = B->info.order.arrivee;
	}
	dist = distance(pos1, pos2);
	temps = 0.5 * dist;
	Time t;
	t.heure = 0;
	t.heure = temps / 60;
	t.minute = 0;
	t.minute = (int)temps % 60;
	return(t);
}

Time CalculeTimeItin(LinkedList* copy) {
	Time temps;
	temps.heure = 0;
	temps.minute = 0;
	if (copy != NULL) {
		SingleLinkedListElem* current;
		SingleLinkedListElem* currentnext;
		current = copy->head;
		currentnext = current->next;

		while (currentnext != copy->tail)
		{
			temps = Horloge_addition(temps, tempsparcours(current, currentnext));
			current = current->next;
			currentnext = currentnext->next;
		}
	}
	return(temps);
}

LinkedList* InitOtherElement(LinkedList* client) {
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentNext;

	current = client->head;
	currentNext = current->next;
	while (current->next != client->tail) {
		currentNext = current->next;
		while (currentNext != client->tail)
		{
			if (currentNext->info.order.ID == current->info.order.ID) {
				if (current->info.depot.heure != NULL) {
					currentNext->info.depot = current->info.depot;
				}
			}
			currentNext = currentNext->next;
		}
		current = current->next;
	}
	return(client);
}

int CheckinsertionFirstElement2(LinkedList* route, SingleLinkedListElem* cournat, SingleLinkedListElem* insertion) {
	if (cournat->next == NULL) {
		return 0;
	}
	if (insertion == NULL) {
		return 0;
	}
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentNext;
	Time tempscourse;
	//initialisation
	tempscourse.heure = 0;
	tempscourse.minute = 0;
	
	current =cournat;
	currentNext = current->next;

	Time temps1;
	if (currentNext->info.isDeparture == true) {

		temps1 = currentNext->info.priseencharge;
	}
	else {

		temps1 = currentNext->info.depot;
	}

	Time temps2;
	if (current->info.isDeparture == true) {

		temps2 = current->info.priseencharge;
	}
	else {

		temps2 = current->info.depot;
	}

	if (current->info.isDeparture == true)
	{
		tempscourse = Horloge_addition(tempscourse, current->info.priseencharge);
	}
	else
	{
		tempscourse = Horloge_addition(tempscourse, current->info.depot);
	}

	tempscourse = Horloge_addition(tempscourse, tempsparcours(current, insertion));
	tempscourse = Horloge_addition(tempscourse, tempsparcours(insertion, currentNext));
	/*printf("cournat %d\n", cournat->info.order.ID);
	printf("current %d %d:%d \n",current->info.order.ID, temps2.heure,temps2.minute);
	printf("currentnext %d:%d \n", temps1.heure, temps1.minute);
	printf("tempscourse %d:%d \n", tempscourse.heure, tempscourse.minute);*/
	
	if (!(est_inf(tempscourse, insertion->info.order.intevalledepart[1]) && (est_sup(tempscourse, insertion->info.order.intevalledepart[0])))) {
		return 0;
	}
		
	if (est_sup(tempscourse, temps1) )
	{
		return 0;
	}

	//initialisation
	tempscourse.heure = 0;
	tempscourse.minute = 0;

	SingleLinkedListElem* insertion2;
	insertion2 = &insertion;
	insertion2->info.isDeparture = false;
	insertion2->info.order.arrivee.X = insertion->info.order.arrivee.X;
	insertion2->info.order.arrivee.Y = insertion->info.order.arrivee.Y;

	//fin

	if (current->info.isDeparture == true)
	{
		tempscourse = Horloge_addition(tempscourse, current->info.priseencharge);
	}
	else
	{
		tempscourse = Horloge_addition(tempscourse, current->info.depot);
	}

	tempscourse = Horloge_addition(tempscourse, tempsparcours(current, insertion));
	tempscourse = Horloge_addition(tempscourse, tempsparcours(insertion, insertion2));
	tempscourse = Horloge_addition(tempscourse, tempsparcours(insertion2, currentNext));
	if (!(est_inf(tempscourse, insertion->info.order.intevalledepart[1]) && (est_sup(tempscourse, insertion->info.order.intevalledepart[0])))) {

		return 0;

	}

	if (est_sup(tempscourse, temps1))
	{
		return 0;
	}
	//printf(" 1 \n");
	//system("pause");
	return 1;

}


int CheckinsertionSecondElement2(LinkedList* route, SingleLinkedListElem* cournat, SingleLinkedListElem* insertion) {
	if (cournat->next == NULL) {
		return 0;
	}
	if (insertion == NULL) {
		return 0;
	}
	SingleLinkedListElem* current;
	SingleLinkedListElem* currentNext;
	Time tempscourse;
	int tampon2 = 0;
	int tampon = 0;

	tempscourse.heure = 0;
	tempscourse.minute = 0;
	current = route->head;
	while (tampon != 1)
	{
		if (current->info.order.ID != cournat->info.order.ID) {
			tampon = 1;
		}
		else
		{
			current = current->next;
			tampon2 = tampon2 + 1;
		}
	}
	current = cournat->next;
	tampon2 = tampon2 + 1;
		currentNext = current->next;
	
	while (current!=route->tail)
	{
		
		tampon2 = tampon2 + 1;
		Time temps1;
		if (currentNext->info.isDeparture == true) {

			temps1 = currentNext->info.priseencharge;
		}
		else {

			temps1 = currentNext->info.depot;
		}

		Time temps2;
		if (current->info.isDeparture == true) {

			temps2 = current->info.priseencharge;
		}
		else {

			temps2 = current->info.depot;
		}

		if (current->info.isDeparture == true)
		{
			tempscourse = Horloge_addition(tempscourse, current->info.priseencharge);
		}
		else
		{
			tempscourse = Horloge_addition(tempscourse, current->info.depot);
		}

		tempscourse = Horloge_addition(tempscourse, tempsparcours(current, insertion));
		tempscourse = Horloge_addition(tempscourse, tempsparcours(insertion, currentNext));
		
			if (est_inf(tempscourse, temps1))
			{
				if (est_sup(cournat->info.priseencharge.heure + 1, tempscourse))
				{
					return(tampon2);
				}
			}
		
		tempscourse.heure = 0;
		tempscourse.minute = 0;
		current = current->next;
		currentNext = current->next;

	}
	return 1;
}

LinkedList* InitList(LinkedList* copy) {
	LinkedList* client;
	int tampon;
	client = NewLinkedList();
	client = InsertDepot(copy);//initialisation des route avec le depot

	for (int i = 0; i < 3; i++)
	{
		tampon = aleatoire(39, 0)+1;
	}
	client = InsertElementAleatoire(tampon, copy, client);
	client = InitFirstElement(client);

	return(client);
}

int InsertLeftOver(LinkedList* copy, LinkedList* rout) {

	SingleLinkedListElem* courant;
	SingleLinkedListElem* courantnext;
	SingleLinkedListElem* insertion2;
	SingleLinkedListElem* insertion;
	int tampon=1;
	Time time1;
	time1.heure = 0;
	time1.minute = 0;
	insertion = copy->tail;
	if(copy->size==0)
	{
		return 0;
	}
	
	courant = rout->head->next;
	courantnext = courant->next;
	while (courant !=rout->tail)
	{
		if (CheckinsertionFirstElement2(rout, courant, insertion) == 1) {
			if (courant->info.isDeparture == true) {
				if (insertion->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, insertion));
					insertion->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, insertion));
					insertion->info.depot = time1;
				}
			}
			else {
				if (insertion->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, insertion));
					insertion->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, insertion));
					insertion->info.depot = time1;
				}

			}
			printf("%d:%d %d:%d %d:%d", time1.heure, time1.minute, courant->info.priseencharge.heure, courant->info.priseencharge.minute, courantnext->info.priseencharge.heure, courantnext->info.priseencharge.minute);
			InsertElementAt(rout,tampon, insertion->info );
			courant = courant->next;
			courantnext = courant->next;
			insertion2 = copy->head;
			

			if (courant->info.isDeparture == true) {
				if (insertion2->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, insertion2));
					insertion2->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.priseencharge, tempsparcours(courant, insertion2));
					insertion2->info.depot = time1;
				}
			}
			else {
				if (insertion2->info.isDeparture == true)
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, insertion2));
					insertion2->info.priseencharge = time1;
				}
				else
				{
					time1 = Horloge_addition(courant->info.depot, tempsparcours(courant, insertion2));
					insertion2->info.depot = time1;
				}
			}
			tampon = tampon + 1;
			InsertElementAt(rout, tampon , insertion2->info);
			DeletCopy(copy, insertion->info.order.ID);
			rout = InitCapa(rout);
			return(1);
		}
		else 
		{
			tampon = tampon + 1;
			courant = courant->next;
			courantnext = courant->next;
		}
	}
	return(0);
}

LinkedList* InitCapa(LinkedList* route) {
	SingleLinkedListElem* previousCourant;
	SingleLinkedListElem* courant;

	previousCourant = route->head;
	courant = previousCourant->next;
	while (courant != NULL) {
		if (courant->info.isDeparture == true) {
			courant->info.capaciter = previousCourant->info.capaciter + 1;

		}
		else
		{
			courant->info.capaciter = previousCourant->info.capaciter - 1;
		}
		previousCourant = previousCourant->next;
		courant=previousCourant->next;
	}
	return(route);
}






