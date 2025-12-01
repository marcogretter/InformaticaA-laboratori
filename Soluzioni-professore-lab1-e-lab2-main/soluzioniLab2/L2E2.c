#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che acquisisca una sequenza di 10 numeri interi ed un
indice X tra 0 e 9. Il programma dovrà stampare la somma dei numeri in posizioni
minori di X e il prodotto dei numeri in posizioni successive a X. */

int main(){
    int numeri[10];
    int i, indice;
    int somma = 0, prodotto = 1;

    for(i = 0; i < 10; i++){
        printf("Inserisci numero: ");
        scanf(" %d", &numeri[i]);
    }

    printf("Inserisci un indice tra 0 e 9 (inclusi): ");
    scanf(" %d", &indice);

    for(i = 0; i < indice; i++){
        somma += numeri[i];
    }
    for(i = indice; i < 10; i++){
        prodotto *= numeri[i];
    }

    printf("Somma dei primi %d numeri: %d\n", indice, somma);
    printf("Prodotto degli ultimi %d numeri: %d\n", 10-indice, prodotto);

    return 0;
}

