#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"


int CheckCapacity (Voiture car){
	 SingleLinkedListElem* CurrentElement=car.Route->head;
    while (CurrentElement !=NULL)
    {
        if (CurrentElement->info.isDeparture==true){
			CurrentElement->info.capaciter = CurrentElement->info.capaciter + CurrentElement->info.order.nbrpersonne;
        }
        else{
			CurrentElement->info.capaciter = CurrentElement->info.capaciter - CurrentElement->info.order.nbrpersonne;
        }
        if (car.Cn< CurrentElement->info.capaciter){
            return(0);//capaciter depasser
        }
        CurrentElement=CurrentElement->next;
    }
    if(CurrentElement->info.capaciter ==0){
		return(1);
    }
	else
	{
		return(0);//capaciter non depacer 
	}
}

int CheckDeparturBeforeArival (Voiture car,SingleLinkedListElem* arret){
    if(arret->info.isDeparture==1){
        return(0);//if the element is a departure no need to call the function
    }
    else{
    int i=0;
	SingleLinkedListElem* CurrentElement = car.Route->head;
    while (CurrentElement!=arret)
	{
        if((CurrentElement->info.order.ID==arret->info.order.ID)&&(CurrentElement->info.isDeparture!=arret->info.isDeparture)){
			printf("%d ", CurrentElement->info.order.ID);
			return(1);//the departure of client is before the arival 
			
        }
        i++;
		CurrentElement = CurrentElement->next;
    }
    return(0);
    }
}    

int CheckDeparturTime (Voiture car){
    int i=0;
    Time timeMax;
    Time timeMin;
	SingleLinkedListElem* CurrentElement = car.Route->head;
	CurrentElement = CurrentElement->next;

    while (CurrentElement!=car.Route->tail)
    {
        timeMax=CurrentElement->info.order.intevalledepart[1];
        timeMin=CurrentElement->info.order.intevalledepart[0];

		if (!(est_sup(CurrentElement->info.priseencharge, timeMin)) && (est_inf(CurrentElement->info.priseencharge, timeMax))) {
			return(0);
			
        }
        i++;
		CurrentElement = CurrentElement->next;
    }
    return(1);
}

int CheckArivalTime (Voiture car){
    int i=0;
    Time timeMax;
    Time timeMin;
	SingleLinkedListElem* CurrentElement = car.Route->head;
	CurrentElement = CurrentElement->next;

    while (CurrentElement!= car.Route->tail)
    {
        timeMax=CurrentElement->info.order.intervallearrivee[1];
        timeMin=CurrentElement->info.order.intervallearrivee[0];

        if(!(est_sup(CurrentElement->info.depot,timeMin))&&(est_inf(CurrentElement->info.priseencharge,timeMax))){
            return(0);
        }
        i++;
        CurrentElement= CurrentElement->next;
    }
    return(1);
}

int CheckWorckTime (Voiture car){
    Time tempsCourse;
	tempsCourse.heure = car.Earrivee.heure - car.Edepart.heure;
	tempsCourse.minute=car.Earrivee.minute-car.Edepart.minute;

    if(est_sup(tempsCourse,car.dtravaille)){
        return(0);
    }
    else
    {
        return(1);
    }
}

bool est_sup(Time time1, Time time2)
{
	if (time1.heure > time2.heure) {
		return(true);
	}
	if (time1.heure == time2.heure) {
		if (time1.minute > time2.minute) {
			return(true);
		}
		else
		{
			return(false);
		}
	}
	return(false);
}

bool est_inf(Time time1, Time time2)
{
	if (time1.heure < time2.heure) {
		return(true);
	}
	if (time1.heure == time2.heure) {
		if (time1.minute < time2.minute) {
			return(true);
		}
		else
		{
			return(false);
		}
	}
	return(false);
}