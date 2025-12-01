#include <stdio.h>
#include <stdlib.h>

/*
Si realizzi un programma che legga da tastiera un valore intero N, compreso tra
1 e 10, e stampi a video un “quadrato di asterischi” di lato N.

Esempio con N=5

*****
*****
*****
*****
*****

Si realizzi una variante del programma per visualizzare solo i lati del quadrato
*/

int main(){
    int i, j, N;
    printf("Inserisci un valore tra 1 e 10: ");
    scanf(" %d", &N);

    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            /// [Originale]
            // printf("*");

            /// [Variante]
            if(i == 0 || i == N - 1 || j == 0 || j == N - 1){
                printf("*");
            } else {
                printf(" ");
            }

        }
        printf("\n");
    }

    return 0;
}
