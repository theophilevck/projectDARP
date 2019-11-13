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


// client1 initialisation

    listclient[0].depart.X= -5.524;
    listclient[0].depart.Y= 1.701;

    listclient[0].arrivee.X = 6.473 ;
    listclient[0].arrivee.Y = 6.536;

    listclient[0].dureemax.heure = 0;
    listclient[0].dureemax.minute = 30;

    listclient[0].ID= 1;

    listclient[0].intervallearrivee[0].heure= 0;
    listclient[0].intervallearrivee[0].minute= 0;

    listclient[0].intervallearrivee[1].heure=24;
    listclient[0].intervallearrivee[1].minute=0;


    listclient[0].intevalledepart[0].heure=3;
    listclient[0].intevalledepart[0].minute=33;

    listclient[0].intevalledepart[1].heure=3;
    listclient[0].intevalledepart[1].minute=48;

    listclient[0].nbrpersonne = 1 ;



// client 2 initialisation




    listclient[1].depart.X= -9.908;
    listclient[1].depart.Y= 6.598;

    listclient[1].arrivee.X = -1.367 ;
    listclient[1].arrivee.Y = 4.495;


    listclient[1].dureemax.heure = 0;
    listclient[1].dureemax.minute = 30;

    listclient[1].ID= 2;

    listclient[1].intervallearrivee[0].heure= 0;
    listclient[1].intervallearrivee[0].minute= 0;

    listclient[1].intervallearrivee[1].heure=24;
    listclient[1].intervallearrivee[1].minute=0;


    listclient[1].intevalledepart[0].heure=1;
    listclient[1].intevalledepart[0].minute=47;

    listclient[1].intevalledepart[1].heure=2;
    listclient[1].intevalledepart[1].minute=2;

    listclient[1].nbrpersonne = 1 ;



// client 3 initialisation


    listclient[2].depart.X= 4.771   ;
    listclient[2].depart.Y= 6.467;

    listclient[2].arrivee.X = 4.325  ;
    listclient[2].arrivee.Y = 8.434;


    listclient[2].dureemax.heure = 0;
    listclient[2].dureemax.minute = 30;

    listclient[2].ID= 3;

    listclient[2].intervallearrivee[0].heure= 0;
    listclient[2].intervallearrivee[0].minute= 0;

    listclient[2].intervallearrivee[1].heure=24;
    listclient[2].intervallearrivee[1].minute=0;


    listclient[2].intevalledepart[0].heure=5;
    listclient[2].intevalledepart[0].minute=18;

    listclient[2].intevalledepart[1].heure=5;
    listclient[2].intevalledepart[1].minute=33;

    listclient[2].nbrpersonne = 1 ;




// client 4 initialisation



    listclient[3].depart.X= 8.902  ;
    listclient[3].depart.Y= 3.344;

    listclient[3].arrivee.X =  -2.297  ;
    listclient[3].arrivee.Y = -9.508;


    listclient[3].dureemax.heure = 0;
    listclient[3].dureemax.minute = 30;

    listclient[3].ID= 4;

    listclient[3].intervallearrivee[0].heure= 0;
    listclient[3].intervallearrivee[0].minute= 0;

    listclient[3].intervallearrivee[1].heure=24;
    listclient[3].intervallearrivee[1].minute=0;


    listclient[3].intevalledepart[0].heure=6;
    listclient[3].intevalledepart[0].minute=24;

    listclient[3].intevalledepart[1].heure=6;
    listclient[3].intevalledepart[1].minute=39;

    listclient[3].nbrpersonne = 1 ;




// client 5 initialisation



    listclient[4].depart.X=  -8.599 ;
    listclient[4].depart.Y=  1.372;

    listclient[4].arrivee.X =  2.356  ;
    listclient[4].arrivee.Y =  0.364;


    listclient[4].dureemax.heure = 0;
    listclient[4].dureemax.minute = 30;

    listclient[4].ID= 5;

    listclient[4].intervallearrivee[0].heure= 0;
    listclient[4].intervallearrivee[0].minute= 0;

    listclient[4].intervallearrivee[1].heure=24;
    listclient[4].intervallearrivee[1].minute=0;


    listclient[4].intevalledepart[0].heure=2;
    listclient[4].intevalledepart[0].minute=38;

    listclient[4].intevalledepart[1].heure=2;
    listclient[4].intevalledepart[1].minute=53;

    listclient[4].nbrpersonne = 1 ;




// client6 initialisation



    listclient[5].depart.X= -7.993  ;
    listclient[5].depart.Y=  8.502;

    listclient[5].arrivee.X =  -1.315 ;
    listclient[5].arrivee.Y = 1.371;


    listclient[5].dureemax.heure = 0;
    listclient[5].dureemax.minute = 30;

    listclient[5].ID= 6;

    listclient[5].intervallearrivee[0].heure= 0;
    listclient[5].intervallearrivee[0].minute= 0;

    listclient[5].intervallearrivee[1].heure=24;
    listclient[5].intervallearrivee[1].minute=0;


    listclient[5].intevalledepart[0].heure=1;
    listclient[5].intevalledepart[0].minute=0;

    listclient[5].intevalledepart[1].heure=1;
    listclient[5].intevalledepart[1].minute=15;

    listclient[5].nbrpersonne = 1 ;



// client 7 initialisation



    listclient[6].depart.X= -2.572  ;
    listclient[6].depart.Y=  9.361;

    listclient[6].arrivee.X = 5.847 ;
    listclient[6].arrivee.Y = 9.129;


    listclient[6].dureemax.heure = 0;
    listclient[6].dureemax.minute = 30;

    listclient[6].ID= 7;

    listclient[6].intervallearrivee[0].heure= 0;
    listclient[6].intervallearrivee[0].minute= 0;

    listclient[6].intervallearrivee[1].heure=24;
    listclient[6].intervallearrivee[1].minute=0;


    listclient[6].intevalledepart[0].heure=4;
    listclient[6].intevalledepart[0].minute=20;

    listclient[6].intevalledepart[1].heure=4;
    listclient[6].intevalledepart[1].minute=35;

    listclient[6].nbrpersonne = 1 ;




// client 8 initialisation



    listclient[7].depart.X= -0.482 ;
    listclient[7].depart.Y= -8.983;

    listclient[7].arrivee.X = 9.221 ;
    listclient[7].arrivee.Y = -3.885;


    listclient[7].dureemax.heure = 0;
    listclient[7].dureemax.minute = 30;

    listclient[7].ID= 8;

    listclient[7].intervallearrivee[0].heure= 0;
    listclient[7].intervallearrivee[0].minute= 0;

    listclient[7].intervallearrivee[1].heure=24;
    listclient[7].intervallearrivee[1].minute=0;


    listclient[7].intevalledepart[0].heure=2;
    listclient[7].intevalledepart[0].minute=48;

    listclient[7].intevalledepart[1].heure=3;
    listclient[7].intevalledepart[1].minute=3;

    listclient[7].nbrpersonne = 1 ;



    //ça on le garde pour nous:

    listclient[0].priseencharge.heure = ;
    listclient[0].priseencharge.minute = ;


    listclient[0].depot.heure=;
    listclient[0].depot.minute=;





// le taxi revient de sa course pour repartir à l'entrepot donc la dernière valeur de la liste c'est l'entrepot
    return(0);
}








// 2 -> nbr voiture 16 -> nombre de demandes totale  480 -> tps de travail taxi 3 -> capa taxi  30 -> temps maximale que peut passer une personne dans le vehicule


