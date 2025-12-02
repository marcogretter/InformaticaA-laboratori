//
//  ex3.cpp
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
albero creaAlbero1(); albero creaAlbero2(); albero creaAlbero3();
void print(albero t);
void stampa(albero T);

int verificaPres(albero t,int elem);
int valoriInComune(albero t1,albero t2);

int main(){
    int ris=0;
    albero T1,T2,T3;
    T1 = creaAlbero1(); T2 = creaAlbero2(); T3 = creaAlbero3();
    printf("\nT1: "); stampa(T1);
    printf("\nT2: "); stampa(T2);
    printf("\nT3: "); stampa(T3);

   //LA FUNZIONE valoriInComune  VIENE INVOCATA QUI
    ris=valoriInComune(T1, T2);
   //VIENE STAMPATO IL RISULTATO DELLE INVOCAZIONI PER RESTITUIRE COME DA ESEMPIO
    printf("I due alberi hanno %d elementi comuni.\n",ris);
    return 0;
}

//
// TODO: SVILUPPARE QUI valoriInComune
//
int valoriInComune(albero t1,albero t2)
{
    if(t1==NULL&&t2==NULL)
        return 1;
    if(t1==NULL||t2==NULL)
        return 0;
    if(verificaPres(t2, t1->val))
        return 1+valoriInComune(t1->right, t2)+valoriInComune(t1->left,t2);
    return valoriInComune(t1->right, t2)+valoriInComune(t1->left,t2);
}
int verificaPres(albero t,int elem)
{
    if(t==NULL)
        return 0;
    if(t->val==elem)
        return 1;
    return verificaPres(t->right, elem)+verificaPres(t->left, elem);
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
