#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che stampi la tavola pitagorica 10x10. */

int main(){
    int i, j;
    for(i = 1; i <= 10; i++){
        for(j = 1; j <= 10; j++){
            printf("%2d ", i * j);
        }
        printf("\n");
    }

    return 0;
}
