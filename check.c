#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"



//int CheckCapacity(Voiture car) {
//	int capaciter = 0;
//	int size = car.Route->size;
//	SingleLinkedListElem* CurrentElement;
//
//	for (int i = 0, i < size; i++) {
//		CurrentElement = GetElementAt(car.Route, i);
//		if (CurrentElement->info.isDeparture == 1) {
//			capaciter = capaciter + CurrentElement->info.order.nbrpersonne;
//		}
//		else {
//			capaciter = capaciter - CurrentElement->info.order.nbrpersonne;
//		}
//		if (car.Cn < capaciter) {
//			return(0);//capaciter depasser
//		}
//	}
//	return(1);//capaciter non depacer 
//}

int CheckCapacity(Voiture car){
    int capaciter=0;
    int i=0;
    SingleLinkedListElem* CurrentElement;
    CurrentElement=GetElementAt(car.Route,i);
    while (CurrentElement!=car.Route.tail)
    {
        if (CurrentElement->info.isDeparture==1){
            capaciter=capaciter + CurrentElement->info.order.nbrpersonne;
        }
        else{
            capaciter=capaciter - CurrentElement->info.order.nbrpersonne;
        }
        if (car.Cn<capaciter){
            return(0);//capaciter depasser
        }
        i++;
        CurrentElement=GetElementAt(car.Route,i);
    }
    if(capaciter!=0){
        return(0)
    }
    return(1);//capaciter non depacer 
}

int CheckDeparturBeforeArival(LinkedList route,SingleLinkedListElem* arret){
    if(arret->info.isDeparture==1){
        return(0);//if the element is a departure no need to call the function
    }
    else{
    int i=0;
    SingleLinkedListElem* CurrentElement;
    CurrentElement=GetElementAt(route,i);
     while (CurrentElement!=arret)
    {
        if((CurrentElement->info.order.ID==arret->info.order.ID)&&(CurrentElement->info.isDeparture!=arret->info.isDeparture)){
            return(1);//the departure of client is before the arival 
        }
        i++;
        CurrentElement=GetElementAt(route,i);
    }
    return(0);
    }
}    

int CheckDeparturTime(LinkedList route){
    int i=0;
    Time timeMax;
    Time timeMin;
    SingleLinkedListElem* CurrentElement;
    CurrentElement=GetElementAt(route,i);
    while (CurrentElement!=route.tail)
    {
        timeMax=CurrentElement->info.order.intevalledepart[1];
        timeMin=CurrentElement->info.order.intevalledepart[0];

        if(!(CurrentElement->info.priseencharge>timeMin)&&(CurrentElement->info.priseencharge<timeMax)){
            return(0);
        }
        i++;
        CurrentElement=GetElementAt(route,i);
    }
    return(1);
}

int CheckArivalTime(LinkedList route){
    int i=0;
    Time timeMax;
    Time timeMin;
    SingleLinkedListElem* CurrentElement;
    CurrentElement=GetElementAt(route,i);
    while (CurrentElement!=route.tail)
    {
        timeMax=CurrentElement->info.order.intervallearrivee[1];
        timeMin=CurrentElement->info.order.intervallearrivee[0];

        if(!(CurrentElement->info.depot>timeMin)&&(CurrentElement->info.priseencharge<timeMax)){
            return(0);
        }
        i++;
        CurrentElement=GetElementAt(route,i);
    }
    return(1);
}

int CheckWorckTime(Voiture car){
    Time tempsCourse;
    tempsCourse=car.Earrivee-car.Edepart ;
    if(tempsCourse>car.dtravaille){
        return(0);
    }
    else
    {
        return(1);
    }
}