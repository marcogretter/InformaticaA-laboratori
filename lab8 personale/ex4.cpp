//
//  ex4.cpp
//  lab8 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct t{
    char c;
    struct t* left;
    struct t* right;
} Nodo;
typedef Nodo* Tree;

Nodo* creaNodo(char c);
Tree costruisci();

// TODO: implementa funzioni
int profondita(Tree t);
void aux(Tree t,int livello,int v[],char radice);
int profonditaMassimaRipetizione(Tree t);

int main(){
    Tree t = costruisci();

    int prof_rip;

    // TODO: chiamata funzioni
    prof_rip=profonditaMassimaRipetizione(t);

    printf("La profondita' massima alla quale si trova ripetuto il carattere '%c' e' %d\n", t->c, prof_rip);

    return 0;
}
int profonditaMassimaRipetizione(Tree t)
{
    int i,prof,profTmp=0;
    prof=profondita(t);
    int v[prof];
    char radice;
    radice=t->c;
    for (i=0; i<prof; i++) {
        v[i]=0;
    }
    aux(t, 1, v, radice);
    for (i=0; i<prof; i++) {
        if(v[i]==1)
            if(i>profTmp)
                profTmp=i;
    }
    return profTmp;
}
void aux(Tree t,int livello,int v[],char radice)
{
    if(t==NULL)
        return;
    if(t->c==radice)
        v[livello-1]=1;
    aux(t->right, livello+1, v, radice);
    aux(t->left, livello+1, v, radice);
}
int profondita(Tree t)
{
    int d,s;
    if(t==NULL)
        return 0;
    d=profondita(t->right);
    s=profondita(t->left);
    if(d>s)
        return d+1;
    return s+1;
}


Nodo* creaNodo(char c){
    Nodo* nodo = (Nodo*) malloc(sizeof(Nodo));
    nodo->c = c;
    nodo->left = NULL;
    nodo->right = NULL;
    return nodo;
}

Tree costruisci(){
    Tree t = creaNodo('i');

    t->left = creaNodo('a');
    t->right = creaNodo('g');

    t->left->left = creaNodo('o');
    t->left->right = creaNodo('i');

    t->right->left = creaNodo('q');
    t->right->right = creaNodo('n');

    t->left->left->left = creaNodo('q');
    t->left->left->right = creaNodo('f');
    t->left->right->left = creaNodo('g');
    t->left->right->right = creaNodo('w');

    t->right->left->left = creaNodo('z');
    t->right->left->right = creaNodo('i');
    t->right->right->left = creaNodo('w');
    t->right->right->right = creaNodo('h');

    t->left->left->left->left = creaNodo('c');
    t->left->left->left->right = creaNodo('e');
    t->left->left->right->left = creaNodo('f');
    t->left->left->right->right= creaNodo('h');
    t->left->right->left->left = creaNodo('a');
    t->left->right->left->right = creaNodo('i');
    t->left->right->right->left = creaNodo('l');
    t->left->right->right->right = creaNodo('m');

    t->right->left->left->left = creaNodo('n');
    t->right->left->left->right = creaNodo('d');
    t->right->left->right->left = creaNodo('r');
    t->right->left->right->right= creaNodo('s');
    t->right->right->left->left = creaNodo('j');
    t->right->right->left->right = creaNodo('p');
    t->right->right->right->left = creaNodo('o');
    t->right->right->right->right = creaNodo('k');

    return t;
}
