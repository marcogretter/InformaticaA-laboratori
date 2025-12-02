//
//  ex2.cpp
//  lab8 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
        int val;
        struct n * left;
        struct n * right;
} nodo;
typedef nodo * albero;

albero createVal(int val);
albero creaAlbero1();albero creaAlbero2();albero creaAlbero3();
void print(albero t);
void stampa(albero T);
int f(albero t);

int profondita(albero t);
void aux(albero t,int livello,int v[]);

int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);

   //LA FUNZIONE DA SVILUPPARE VIENE USATA QUI


   if(f(T1)==1)
        printf("T1 ok\n");
    else printf("T1 non ok\n");

   if(f(T2)==1)
        printf("T2 ok\n");
    else printf("T2 non ok\n");

   if(f(T3)==1)
        printf("T3 ok\n");
    else printf("T3 non ok\n");

    return 0;
}

//
// TODO: SVILUPPARE QUI DENTRO QUANTO RICHIESTO
//
int f(albero t){
    int i,prof;
    prof=profondita(t);
    int v[prof];
    for(i=0; i<prof; i++) {
        v[i]=1;
    }
    aux(t, 1, v);
    for (i=0; i<prof; i++) {
        if(v[i]==0)
            return 0;
    }
    return 1;
}
void aux(albero t,int livello,int v[])
{
    if(t==NULL)
        return;
    if(t->val<livello)
        v[livello-1]=0;
    aux(t->right, livello+1, v);
    aux(t->left, livello+1, v);
}
int profondita(albero t)
{
    int d,s;
    if(t==NULL)
        return 0;
    d=profondita(t->right);
    s=profondita(t->left);
    if(d>s)
        return 1+d;
    return 1+s;
}

albero creaAlbero1() {
    albero tmp = createVal(7);
    tmp->left = createVal(3);tmp->left->left = createVal(9);tmp->left->right = createVal(10);
    tmp->right = createVal(8);tmp->right->left = createVal(5);tmp->right->right = createVal(12);
    tmp->right->right->left = createVal(11); tmp->right->right->right = createVal(6);
    return tmp;
}

albero creaAlbero2() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(1);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(11);tmp->left->left->left = createVal(6);
    return tmp;
}

albero creaAlbero3() {
    albero tmp = createVal(7);
    tmp->right = createVal(3);tmp->right->right = createVal(9);tmp->right->left = createVal(10);
    tmp->left = createVal(4);tmp->left->right = createVal(5);tmp->left->left = createVal(12);
    tmp->left->left->right = createVal(2);tmp->left->left->left = createVal(6);
    return tmp;
}

void print(albero t){
       if(t==NULL)return;
       else{printf(" (");print(t->left);printf(" %d ",t->val);print(t->right);printf(") ");}
}

void stampa(albero T){print(T);printf("\n");}

albero createVal(int val) {
    albero tmp = malloc(sizeof(nodo));
    tmp->val = val;    tmp->left = NULL;    tmp->right = NULL;
    return tmp;
}
