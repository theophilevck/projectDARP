#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "liste.h"
#include "Structures.h"
#include <math.h>
#define TAILLE_MAX 10000







int main(){

// le taxi part de l'entrepot donc la première valeur de la liste c'est la position de l'entrepot

Pos entrepot;
entrepot.X =0;
entrepot.Y=0;

Client listclient[8];
Client client1;
listclient[0]=client1;
Client client2;
listclient[1]=client2;
Client client3;
listclient[2]=client3;
Client client4;
listclient[3]=client4;
Client client5;
listclient[4]=client5;
Client client6;
listclient[5]=client6;
Client client7;
listclient[6]=client7;
Client client8;
listclient[7]=client8;



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



// matrice des distances:

Pos A[17];
A[0]=entrepot;
for (int k=0; k<8 ; k++){
    A[k]=listclient[k].depart;

}
for (int k=8; k<17 ; k++){
    A[k]=listclient[k].arrivee;
}
float Matrice_des_distances[17][17];

for (int i=0 ; i<17 ; i++){
    for (int j=0 ; j<17 ; j++){
        Matrice_des_distances[i][j]= sqrt( pow((A[j].X -A[i].X),2) + pow((A[j].Y -A[i].Y),2))
        printf( "%d", Matrice_des_distances[i][j]);

    }
}


    //ça on le garde pour nous:







// le taxi revient de sa course pour repartir à l'entrepot donc la dernière valeur de la liste c'est l'entrepot
    return(0);
}