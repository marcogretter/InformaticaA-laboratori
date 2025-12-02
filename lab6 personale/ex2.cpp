//
//  ex2.cpp
//  lab6 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include<stdio.h>
#include<stdlib.h>

typedef struct EL{
        int info;
        struct EL * prox;
} ElemLista;
typedef ElemLista * ListaDiElem;

int ListaVuota( ListaDiElem lista );
ListaDiElem InsInTesta( ListaDiElem lista, int elem );
ListaDiElem crea1();
ListaDiElem crea2();
void VisualizzaLista( ListaDiElem lista );

int scorriLista1(int lis1Dato,ListaDiElem lis2)
{
    if(lis2==NULL)
        return 0;
    while (lis2!=NULL) {
        if(lis1Dato==lis2->info)
            return lis2->info;
        lis2=lis2->prox;
    }
    return 0;
}
int CalcoloMedia(ListaDiElem lis1,ListaDiElem lis2)
{
    float media;
    int sum=0,cont=0;
    if(lis1==NULL&&lis2==NULL)
        return 0;
    if(lis1==NULL||lis2==NULL)
        return 0;
    while (lis1!=NULL) {
        scorriLista1(lis1->info, lis2);
        if(scorriLista1(lis1->info, lis2)!=0)
            sum+=lis1->info;
        if(scorriLista1(lis1->info, lis2)!=0)
            cont++;
        lis1=lis1->prox;
    }
    media=sum/cont;
    return media;
}


int main() {
    ListaDiElem lista=NULL,lista1=NULL,lista2=NULL;
    lista1=crea1();
    lista2=crea2();
    VisualizzaLista(lista1);
    printf("\n\n");
    VisualizzaLista(lista2);
    printf("\n\n");
    
    //inserire qui il codice
    float media;
    media=CalcoloMedia(lista1, lista2);
    printf("%f\n",media);
    VisualizzaLista(lista);
    printf("\n\n");
    
    return 0;
}

void VisualizzaLista( ListaDiElem lista ) {
    if ( ListaVuota(lista) )
        printf(" ---| \n");
    else {
        printf(" %d ---> ",lista->info);
        VisualizzaLista(lista->prox);
    }
}

ListaDiElem InsInTesta( ListaDiElem lista, int elem ) {
    ListaDiElem punt;
    punt = (ListaDiElem) malloc(sizeof(ElemLista));
    punt->info = elem;
    punt->prox = lista;
    return  punt;
}

int ListaVuota( ListaDiElem lista ) {
    return lista == NULL;
}

ListaDiElem crea1() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 12 );
    lis=InsInTesta( lis, 1 );
    lis=InsInTesta( lis, 4 );
    lis=InsInTesta( lis, 8 );
    lis=InsInTesta( lis, 34 );
    lis=InsInTesta( lis, 78 );
    lis=InsInTesta( lis, 26 );
    lis=InsInTesta( lis, 33 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 67 );
    lis=InsInTesta( lis, 83 );
    lis=InsInTesta( lis, 92 );
    return lis;
}

ListaDiElem crea2() {
    ListaDiElem lis=NULL;
    lis=InsInTesta( lis, 2 );
    lis=InsInTesta( lis, 10 );
    lis=InsInTesta( lis, 15 );
    lis=InsInTesta( lis, 48 );
    lis=InsInTesta( lis, 82 );
    lis=InsInTesta( lis, 11 );
    lis=InsInTesta( lis, 92 );
    lis=InsInTesta( lis, 22 );
    lis=InsInTesta( lis, 36 );
    lis=InsInTesta( lis, 19 );
    lis=InsInTesta( lis, 69 );
    return lis;
}
