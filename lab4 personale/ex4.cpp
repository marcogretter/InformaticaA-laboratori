//
//  ex4.cpp
//  lab4 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#define N 8

int somma(int M[][N],int v[]);

int main(){
    int i,k;
    int M[N][N]={1,4,6,8,9,3,2,6,
                  4,7,2,4,1,8,1,1,
                  5,7,3,9,1,2,0,3,
                  3,7,7,5,5,3,8,0,
                  2,1,5,5,7,3,5,7,
                  2,4,9,3,7,5,8,9,
                  3,5,7,8,9,5,7,8,
                  1,2,6,4,8,9,9,0};
    int v[]={4,7,2,4,1,8,1,1};
    
    printf("M\n");
    for(i=0;i<N;i++){for(k=0;k<N;k++){printf("%d ",M[i][k]);}printf("\n");}
    printf("v\n");
    for(i=0;i<N;i++){printf("%d ",v[i]);}
    printf("\n");

    /*SCRIVERE QUI LE CHIAMATE DI FUNZIONI E I COMANDI DI STAMPA*/
    printf("%d\n",somma(M, v));
    return 0;
}

int somma(int M[][N],int v[])
{
    int r,c;
    int i=0,sum=0;
    for (i=0; i<N; i++) {
        for (r=0; r<N; r++) {
            if(r==i){
                for (c=0; c<N; c++) {
                    if(c==(v[i]-1)){
                        sum+=M[r][c];
                    }
                }
            }
        }
    }
    return sum;
}
