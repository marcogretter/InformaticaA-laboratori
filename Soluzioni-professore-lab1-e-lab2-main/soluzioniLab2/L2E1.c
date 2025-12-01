#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che riceva in ingresso dall'utente un vettore di 5
 caratteri tutti minuscoli. Il programma dica all'utente se le lettere contenute
 nel vettore sono in ordine alfabetico.*/

#define L 5

int main(){

    char letters[L];
    int i, sorted = 1;

    // Lettura lettere
    for(i = 0; i < L; i++){
        printf("Inserisci una lettera: ");
        scanf(" %c", &letters[i]);
    }

    // Controllo l'ordine
    for(i = 0; i < L-1; i++){
        if(letters[i] > letters[i+1]){
            sorted = 0;
            break;
        }
    }

    // Stampa risultato
    if(sorted){
        printf("Le lettere sono in ordine alfabetico\n");
    } else {
        printf("Le lettere NON sono in ordine alfabetico\n");
    }

    return 0;
}
