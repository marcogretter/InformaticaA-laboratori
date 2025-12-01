#include <stdio.h>
#include <stdlib.h>

/*
Un numero altamente composto è tale che qualunque numero minore di esso ha meno
divisori. I primi numeri altamente composti sono 1, 2, 4, 6, 12, 24, 36, 48, 60,
120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080

Scrivere un programma che stampa i primi 20 numeri altamente composti.
*/

int main(){
    int naltcomp = 0;   // numero di numeri altamente composti trovati
    int best = 0;
    int n = 1;
    int i, ndivs;

    while(naltcomp <= 20){
        ndivs = 0;
        for(i = 1; i <= n; i++){
            if(n % i == 0){
                ndivs++;
            }
        }

        if(ndivs > best){
            printf("%d\n", n);
            best = ndivs;
            naltcomp++;
        }

        n++;
    }


    return 0;
}
