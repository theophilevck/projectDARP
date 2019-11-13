#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include "check.h"


int CheckCapacity(Voiture car){
    int capaciter=0;
    int size=car.Route->size;
    SingleLinkedListElem* CurrentElement;

    for (int i=0,i<size;i++ ){
        CurrentElement=GetElementAt(car.Route,i);
        if (CurrentElement->info.isDeparture==1){
            capaciter=capaciter + CurrentElement->info.order.nbrpersonne;
        }
        else{
            capaciter=capaciter - CurrentElement->info.order.nbrpersonne;
        }
        if (car.Cn<capaciter){
            return(0);//capaciter depasser
        }
    }
    return(1);//capaciter non depacer 
}

int CheckCapacity(Voiture car){
    int capaciter=0;
    int i=0;
    int size=car.Route->size;
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

    





}