//
//  ex5.cpp
//  lab1-personale
//
//  Created by Marco Gretter on 01/12/25.
//
#include <stdio.h>
#define N 50

int main() {
    int r,i,j;
    printf("Inserisci la lunghezza del lato del quadrato di asterischi:\n");
    scanf("%d",&r);
    for(i=0;i<r;i++){
        for(j=0;j<r;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
