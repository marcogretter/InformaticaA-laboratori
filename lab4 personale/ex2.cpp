//
//  ex2.cpp
//  lab4 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500

typedef struct{
    float x;
    float y;
}Punto;

void stampaPunto(Punto p);
Punto acquisisciPunto(float x,float y);
float calcolaNorma(Punto p);
float calcolaDistanza(Punto p1, Punto p2);
float lunghezza(Punto linea[]);

int main(){
    float X,Y,W,Z;
    Punto g;
    Punto h;
    float d;
    float j;
    
//    richiedo le coordinate:
    printf("Inserisci coordinate x:\n");
    scanf("%f",&X);
    printf("Inserisci coordinate y:\n");
    scanf("%f",&Y);
    
    g=acquisisciPunto(X, Y);
    
    //    stampo il punto richiamando la funzione 'acquisisciPunto':
    printf("%f,%f\n",g.x,g.y);
    
    d=calcolaNorma(g);
    printf("La distanza dall'origine è:%f\n",d);
//    impostazione per la terza funzione 'float calcolaDistanza(Punto p1, Punto p2)':
    printf("Inserisci coordinate di x del secondo punto:\n");
    scanf("%f",&W);
    printf("Inserisci coordinate di y del secondo punto:\n");
    scanf("%f",&Z);
    h=acquisisciPunto(W, Z);
    
    j=calcolaDistanza(g, h);
    printf("La distanza tra i due punti:%f\n",j);
    
}
void stampaPunto(Punto p)
{
    printf("%f,%f",p.x,p.y);
}
Punto acquisisciPunto(float x,float y)
{
    Punto coordinata;
    coordinata.x=x;
    coordinata.y=y;
    
    return coordinata;
}
float calcolaNorma(Punto p)
{
    float distanza;
    float coordinatax;
    float coordinatay;
    
    coordinatax=p.x*p.x;
    coordinatay=p.y*p.y;
    distanza=sqrtf(coordinatax+coordinatay);
    return distanza;
}
float calcolaDistanza(Punto p1, Punto p2)
{
    float distanzax,distanzay,distanzatot;
    float coordinatax;
    float coordinatay;
    float coordinataw;
    float coordinataz;
    
    coordinatax=p1.x*p1.x;
    coordinatay=p1.y*p1.y;
    coordinataw=p2.x*p2.x;
    coordinataz=p2.y*p2.y;
    
    distanzax=coordinataw-coordinatax;
    distanzay=coordinataz-coordinatay;
    
    distanzatot=sqrtf(distanzay-distanzax);
    return distanzatot;
}
float lunghezza(Punto linea[])
{
    int i;
    int sumDist;
    int sum0;
    int distanzax0,distanzay0;
    int distanzax,distanzay;
    
    distanzax0=linea[0].x*linea[0].x;
    distanzay0=linea[0].y*linea[0].y;
    
    sum0=sqrtf(distanzax0+distanzay0);
    
    sumDist=sum0;
    
    for (i=1; i<N; i++) {
        distanzax=linea[i].x*linea[i].x;
        distanzay=linea[i].y*linea[i].y;
        sumDist+=sqrtf(distanzax+distanzay);
    }
    return sumDist;;
}
