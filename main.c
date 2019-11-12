#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"




int main(){

// le taxi part de l'entrepot donc la première valeur de la liste c'est la position de l'entrepot

LinkedList* chemin;
chemin = NewLinkedList();

Pos position;
position.X=0;
position.Y=0;

NewLinkedListElement(position);

Client listclient[8];
Client client1;
listclient.append(client1);
Client client2;
listclient.append(client2);
Client client3;
listclient.append(client3);
Client client4;
listclient.append(client4);
Client client5;
listclient.append(client5);
Client client6;
listclient.append(client6);
Client client7;
listclient.append(client7);
Client client8;
listclient.append(client8);



for (int i=0; i<8; i++){

    listclient[i].arrivee.X = ;
    listclient[i].arrivee.Y = ;

    listclient[i].depart.X= ;
    listclient[i].depart.Y= ;

    listclient[i].depot.heure=;
    listclient[i].depot.minute=;

    listclient[i].dureemax.heure;
    listclient[i].dureemax.minute;

    listclient[i].ID=;

    listclient[i].intervallearrivee[0].heure=;
    listclient[i].intervallearrivee[0].minute=;

    listclient[i].intervallearrivee[1].heure=;
    listclient[i].intervallearrivee[1].minute=;


    listclient[i].intevalledepart[0].heure=;
    listclient[i].intevalledepart[0].minute=;

    listclient[i].intevalledepart[1].heure=;
    listclient[i].intevalledepart[1].minute=;
    
    listclient[i].nbrpersonne =  ;

    listclient[i].priseencharge.heure = ;
    listclient[i].priseencharge.minute = ;


}





// le taxi revient de sa course pour repartir à l'entrepot donc la dernière valeur de la liste c'est l'entrepot
    return(0);
}