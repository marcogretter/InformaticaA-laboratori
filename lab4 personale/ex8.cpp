//
//  ex8.cpp
//  lab4 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define N 4

int valida (int gioco[N][N], int mossa);
int risolto (int gioco[N][N]);
void stampa (int gioco[N][N]);
void muovi (int gioco[N][N], int mossa);

int main(){
    int M[N][N]={8,5,2,4,
                 11,1,0,7,
                 12,10,3,15,
                 9,13,14,6};
    int n;
    stampa(M);
    do{
        printf("Prossima mossa:\n");
        scanf("%d",&n);
        muovi(M,n);
    } while (risolto(M)==0);
    
    if(risolto(M)!=0)
        printf("Complimenti hai vinto!\n");
    return 0;
}
int risolto (int gioco[N][N])
{
    int r,c;
    for (r=0; r<N; r++) {
        for (c=0; c<N; c++) {
            if(gioco[r][c]>gioco[r][c+1])
                return 0;
        }
    }
    return 1;
}
int valida (int gioco[N][N], int mossa)
{
    int r,c,rzero=0,czero=0;
    int zero=0;
    for (r=0; r<N; r++) {
        for (c=0; c<N; c++) {
            if(gioco[r][c]==zero){
                rzero=r;
                czero=c;
            }
        }
    }
    if(mossa==gioco[rzero+1][czero]||mossa==gioco[rzero-1][czero]||mossa==gioco[rzero][czero+1]||mossa==gioco[rzero][czero-1])
        return 1;
    else
        printf("Mossa non valida.\n");
        return 0;
}
void muovi (int gioco[N][N], int mossa)
{
    int r,c,rzero = 0,czero = 0,rmossa = 0,cmossa = 0;
    int zero=0,temp;;
    if(valida(gioco,mossa)){
        for (r=0; r<N; r++) {
            for (c=0; c<N; c++) {
                if(gioco[r][c]==zero){
                    rzero=r;
                    czero=c;
                }
                if(gioco[r][c]==mossa){
                    rmossa=r;
                    cmossa=c;
                }
            }
        }
        temp=gioco[rzero][czero];
        gioco[rzero][czero]=gioco[rmossa][cmossa];
        gioco[rmossa][cmossa]=temp;
    }
    stampa(gioco);
}
void stampa (int gioco[N][N])
{
    int r,c;
    for (r=0; r<N; r++) {
        for (c=0; c<N; c++) {
            printf("%d\t",gioco[r][c]);
        }
        printf("\n");
    }
}
