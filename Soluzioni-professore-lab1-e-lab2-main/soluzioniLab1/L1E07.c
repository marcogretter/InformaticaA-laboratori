#include <stdio.h>
#include <stdlib.h>

/** Scrivere un programma che chiede due numeri all’utente e ne stampa a video
tutti i divisori comuni.*/

int main(){
    // Leggi i valori
    int a, b, tmp, i;
    printf("Inserisci due numeri:\n");
    scanf(" %d", &a);
    scanf(" %d", &b);

    // Metto il numero minore in a
    if(b < a){
        tmp = a;
        a = b;
        b = tmp;
    }

    // Scorri tra tutti i numeri minori del minore tra a e b
    // Ogni volta che trovi un divisore comune, stampalo
    printf("Divisori comuni:\n");
    for(i = 1; i <= a; i++){
        if(a % i == 0 && b % i == 0){
            printf("%d ", i);
        }
    }

    return 0;
}
