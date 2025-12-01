#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che costruisce un array A di 50 interi e un B di 5
 interi e stampa 1 se esiste in A una SEQUENZA di 5 elementi che sono
 esattamente gli elementi di B anche in un ordine differente. */

#define N 10
#define M 5

int main(){
    // Creazione array (in alternativa si puù usare rand() in un for)
    int A[N] = {4, 6, 1, 7, 5, 2, 9, 0, 3, 8};
    int B[M] = {0, 8, 2, 3, 9};
    int i, j, k, idx, found;
    int flags[M];

    // Scorriamo lungo A controllando finestre lunghe M
    for(i = 0; i < N - M + 1; i++){

        // Inizializzo i flag che ci dicono quali elementi abbiamo trovato
        for(j = 0; j < M; j++){
            flags[j] = 1;
        }

        // Scorro tra gli elementi della finestra per cercarli in B
        for(j = 0; j < M; j++){
            found = 0;

            // Scorro tra gli elementi di B
            // (considero solo quelli che non ho già usato)
            for(k = 0; k < M; k++){
                if(flags[k] == 1 && A[i+j]==B[k]){
                    flags[k] = 0;
                    found = 1;
                    break;
                }
            }

            // Se non ho trovato A[i+j] in B posso fermarmi e passare alla prossima finestra
            if(!found){
                // Possibile ottimizzazione: se A[i+j] non è in B, posso cominciare a cercare da A[i+j+1] invece che tornare ad A[i+1]
                break;
            }
        }

        // Arrivo qui con found==1 solo se ho trovato tutti gli elementi cercati
        if(found){
            printf("Sequence found (starting from %d)\n", i);
            break;
        }
    }

    if(!found){
        printf("Sequence not found\n");
    }

    return 0;
}
