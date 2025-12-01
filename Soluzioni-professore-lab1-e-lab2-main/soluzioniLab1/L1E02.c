#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma per il calcolo delle tabelline. Il programma riceve
dall’utente due numeri. Il primo corrisponde al numero di cui è necessario
calcolare la tabellina mentre il secondo indica la lunghezza della tabellina
richiesta.

Es: 2, 10 produce come risultato: 2 4 6 8 10 12 14 16 18 20
Es: 3, 8 produce come risultato: 3 6 9 12 15 18 21 24

Accettare solamente numeri positivi: se l’utente inserisce un numero negativo
mostrare un messaggio di errore e richiede un altro numero.
*/

int main(){
    int base, lung, i;
    do {
        printf("Di quale numero vuoi calcolare la tabellina?\n");
        scanf(" %d", &base);

        if(base < 1){
            printf(" -- ATTENZIONE! INSERISCI SOLO NUMERI POSITIVI!\n");
        }
    } while(base < 1);

    do {
        printf("Quanti multipli vuoi calcolare?\n");
        scanf(" %d", &lung);

        if(lung < 1){
            printf(" -- ATTENZIONE! INSERISCI SOLO NUMERI POSITIVI!\n");
        }
    } while(lung < 1);

    for(i = 1; i <= lung; i++){
        printf("%d ", i * base);
    }

    return 0;
}
