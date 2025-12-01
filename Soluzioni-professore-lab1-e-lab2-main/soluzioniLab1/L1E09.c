#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** Scrivere un programma che generi un numero intero casuale e chieda
all’utente di indovinarlo. Ad ogni tentativo fallito da parte dell’utente di
indovinare il numero il programma indica se il numero da indovinare è maggiore
o minore rispetto a quello appena inserito.

Per generare un numero casuale è necessario chiamare una volta la funzione
srand(time(0)) per inizializzare il generatore di numeri casuali ed in seguito,
per ogni numero casuale, la funzione rand() come di seguito.

Es. r = rand()

N.B. Si noti che la funzione rand() restituisce un numero casuale tra zero e la
costante  RAND_MAX (costante molto grande). Si può usare il solito
operatore % per limitare questo range (L’uso della funzione time(..) necessita
della libreria time.h. Le funzioni srand(..) e rand(..) sono invece parte di
stdlib.h).

 */

#define N 100

int main(){
    int n, guess, nguesses = 0;

    srand(time(0));
    n = rand() % N + 1;

    printf("Indovina il numero a cui sto pensando (tra 1 e %d)\n", N);
    do{
        nguesses++;
        printf(" > ");
        scanf(" %d", &guess);

        if(guess < n){
            printf("Troppo basso\n\n");
        } else if(guess > n){
            printf("Troppo alto!\n\n");
        } else {
            printf("\nHAI INDOVINATO!!!\n");
            printf("Hai fatto %d tentativi\n", nguesses);
        }
    }while(guess != n);

}
