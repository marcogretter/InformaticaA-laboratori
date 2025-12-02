//
//  ex6.cpp
//  lab4 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#define N 3

int analizzaRighe(int M[][N],int casella,int riga,int colonna);
void AnalizzaMatrice(int M[][N]);
int analizzaDiagonali(int M[][N],int casella, int riga,int colonna);
int analizzaDiagonaliSx(int M[][N],int casella,int riga,int colonna);

int main(){
    int M[N][N]={1,2,3,
                 4,5,6,
                 7,8,9};
    AnalizzaMatrice(M);
    
    return 0;
}
void AnalizzaMatrice(int M[][N])
{
    int r,c;
    for (r=0; r<N; r++) {
        for (c=0; c<N; c++) {
            if((analizzaRighe(M,M[r][c],r,c))&&(analizzaDiagonali(M,M[r][c],r,c))&&(analizzaDiagonaliSx(M, M[r][c],r,c)))
                printf("%d\t",M[r][c]);
        }
    }
}
int analizzaRighe(int M[][N],int casella,int riga,int colonna)
{
    int r,c;
//    esploro le righe, cioé vado dall'alto verso il basso della colonna:
    for (r=0; r<N; r++) {
        if(casella<M[r][colonna])
            return 0;
    }
    for (c=0; c<N; c++) {
        if(casella<M[riga][c])
            return 0;
    }
    return 1;
}

int analizzaDiagonali(int M[][N],int casella, int riga,int colonna)
{
    int r,c;
    int i=0;
    r=riga;
    c=colonna;
    while (r+i>=0&&c+i>=0&&c+i<=N&&c+i<=N) {
        for (i=0; i<N; i++) {
            if(casella<M[r+i][c+i])
                return 0;
        }
    }
    while (r+i>=0&&c+i>=0&&c+i<=N&&c+i<=N) {
        for (i=0; i>-N; i--) {
            if(casella<M[r+i][c+i])
                return 0;
        }
    }
    return 1;
}
int analizzaDiagonaliSx(int M[][N],int casella,int riga,int colonna)
{
    int r,c;
    int i=0;
    r=riga;
    c=colonna;
    while (r+i>=0&&c+i>=0&&c+i<=N&&c+i<=N) {
        for (i=0; i<N; i++) {
            if(casella<M[r+i][c-i])
                return 0;
        }
    }
    while (r+i>=0&&c+i>=0&&c+i<=N&&c+i<=N) {
        for (i=0; i<N; i++) {
            if(casella<M[r-i][c+i])
                return 0;
        }
    }
    return 1;
}
