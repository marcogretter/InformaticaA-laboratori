#include <stdio.h>
#include <stdlib.h>

/*
Scrivere un programma che chiede all'utente un numero compreso da 1 a 9 e stampa
un quadrato come mostrato di seguito.

Se l'utente inserisce 4:

4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4

Se inserisce 2

2 2 2
2 1 2
2 2 2

Se inserisce 7

7 7 7 7 7 7 7 7 7 7 7 7 7
7 6 6 6 6 6 6 6 6 6 6 6 7
7 6 5 5 5 5 5 5 5 5 5 6 7
7 6 5 4 4 4 4 4 4 4 5 6 7
7 6 5 4 3 3 3 3 3 4 5 6 7
7 6 5 4 3 2 2 2 3 4 5 6 7
7 6 5 4 3 2 1 2 3 4 5 6 7
7 6 5 4 3 2 2 2 3 4 5 6 7
7 6 5 4 3 3 3 3 3 4 5 6 7
7 6 5 4 4 4 4 4 4 4 5 6 7
7 6 5 5 5 5 5 5 5 5 5 6 7
7 6 6 6 6 6 6 6 6 6 6 6 7
7 7 7 7 7 7 7 7 7 7 7 7 7
*/

int main(){
    int i, j, N;

    printf("Inserisci un numero tra 1 e 9 (estremi compresi): ");
    scanf(" %d", &N);

    /** SOLUZIONE PROPOSTA
    Suddivido il problema in sotto-problemi:
    - parte superiore,
    - riga centrale
    - parte inferiore
    */

    /// Parte superiore
    /* Ciascuna riga:
    - parte da N
    - scende fino a i (dipende dalla riga)
    - ha una parte costante fatta di i
    - sale fino a N
    */
    for(i = N; i > 1; i--){
        // Discesa
        for(j = N; j > i - 1; j--) printf("%d", j);
        // Costante
        for(j = 0; j < 2*(i-1)-1; j++) printf("%d", i);
        // Salita
        for(j = i; j <= N; j++) printf("%d", j);
        printf("\n");
    }

    /// Parte centrale
    // Da N a 1 a N
    for(j = N; j >= 1; j--) printf("%d", j);
    for(j = 2; j <= N; j++) printf("%d", j);
    printf("\n");

    /// Parte inferiore
    // Come la parte superiore, ma in ordine inverso
    for(i = 2; i <= N; i++){
        // Discesa
        for(j = N; j > i - 1; j--) printf("%d", j);
        // Costante
        for(j = 0; j < 2*(i-1)-1; j++) printf("%d", i);
        // Salita
        for(j = i; j <= N; j++) printf("%d", j);
        printf("\n");
    }


    return 0;
}
