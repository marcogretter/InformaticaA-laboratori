#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che acquisisca una sequenza di 10 numeri interi ed un
indice X tra 1 e 10. Il programma dovrà stampare la somma dei numeri in posizioni
minori di X e il prodotto dei numeri in posizioni successive a X. */

int main(){
    int numeri1,numeri2,numeri3,numeri4,numeri5,numeri6,numeri7,numeri8,numeri9,numeri10;
    int i, indice;
    int somma = 0, prodotto = 1;

    printf("Inserisci un numero: ");
    scanf("%d", &numeri1);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri2);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri3);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri4);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri5);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri6);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri7);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri8);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri9);
    printf("Inserisci un numero: ");
    scanf("%d", &numeri10);

    printf("Inserisci un indice tra 1 e 10 (inclusi): ");
    scanf("%d", &indice);

    if(indice==1){
	    prodotto= numeri1*numeri2*numeri3*numeri4*numeri5*numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==2){
        somma = numeri1;
        prodotto= numeri2*numeri3*numeri4*numeri5*numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==3){
        somma = numeri1+numeri2;
        prodotto= numeri3*numeri4*numeri5*numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==4){
        somma = numeri1+numeri2+numeri3;
        prodotto= numeri4*numeri5*numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==5){
        somma = numeri1+numeri2+numeri3+numeri4;
        prodotto= numeri5*numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==6){
        somma = numeri1+numeri2+numeri3+numeri4+numeri5;
        prodotto= numeri6*numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==7){
        somma = numeri1+numeri2+numeri3+numeri4+numeri5+numeri6;
        prodotto= numeri7*numeri8*numeri9*numeri10;
    }
    else if(indice==8){
        somma = numeri1+numeri2+numeri3+numeri4+numeri5+numeri6+numeri7;
        prodotto= numeri8*numeri9*numeri10;
    }
    else if(indice==9){
        somma = numeri1+numeri2+numeri3+numeri4+numeri5+numeri6+numeri7+numeri8;
        prodotto= numeri9*numeri10;
    }
    else if(indice==10){
        somma = numeri1+numeri2+numeri3+numeri4+numeri5+numeri6+numeri7+numeri8+numeri9;
        prodotto= numeri10;
    }
    else if(indice==11){//non richiesto
        somma = numeri1+numeri2+numeri3+numeri4+numeri5+numeri6+numeri7+numeri8+numeri9+numeri10;
    }

    printf("Somma dei primi %d numeri: %d\n", indice, somma);
    printf("Prodotto degli ultimi %d numeri: %d\n", 10-indice, prodotto);

    return 0;
}

