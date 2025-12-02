//
//  main.cpp
//  lab7 personale
//
//  Created by Marco Gretter on 02/12/25.
//

#include<stdio.h>
#include<stdlib.h>

typedef struct EL {
    int info;
    struct EL * prox;
} ElemLista;

typedef ElemLista * SottoLista;

typedef struct ELD {
    double info;
    struct ELD * prox;
} ElemListaDouble;

typedef ElemListaDouble * ListaDouble;

typedef struct ELL {
    SottoLista lista;
    struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDouble InsInFondoDouble(ListaDouble lista,double elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaDouble(ListaDouble lista );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//

ListaDouble aggrega(ListaDiListe lis);
double esploraLista(SottoLista lis);

int main(){
    ListaDiListe lis;
    ListaDouble ris=NULL;
    lis=costruisci();
    printf("Lista (ogni elemento in una riga)\n");
    VisualizzaListaDiListe(lis);

    //TODO: invocazione funzione
    ris=aggrega(lis);
    printf("Lista delle medie\n");
    VisualizzaListaDouble(ris);

    return 0;
}
//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
ListaDouble aggrega(ListaDiListe lis)
{
    ListaDouble nuova=NULL;
    if(lis==NULL)
        return NULL;
    while (lis!=NULL) {
        nuova=InsInFondoDouble(nuova,esploraLista(lis->lista));
        lis=lis->prox;
    }
    return nuova;
}
double esploraLista(SottoLista lis)
{
    float sum=0;
    float cont=0;
    if(lis==NULL)
        return 0;
    while (lis!=NULL) {
        sum+=lis->info;
        cont++;
        lis=lis->prox;
    }
    return sum/cont;
}

ListaDiListe costruisci(){
    int M[5][10]={5,4,6,5,3,7,-1,-1,-1,-1,
                  1,6,9,1,5,5,9,0,-1,-1,
                  1,5,1,1,1,1,8,9,0,-1,
                  1,3,2,4,0,-1,-1,-1,-1,-1,
                  1,2,8,8,4,0,9,0,-1,-1};
    int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
    for(i=0;i<5;i++){
        temp=NULL;for(k=0;k<10;k++)if(M[i][k]!=-1)temp=InsInFondoInt(temp,M[i][k]);
        ris=InsInFondoLista(ris,temp);}
    return ris;
}

SottoLista InsInFondoInt(SottoLista lista,int elem ) {
    SottoLista punt;
    if(lista==NULL) { punt = malloc( sizeof(ElemLista) );
                     punt->prox = NULL; punt->info = elem; return  punt;
    }else{lista->prox = InsInFondoInt(lista->prox,elem); return lista;}
}

ListaDouble InsInFondoDouble(ListaDouble lista,double elem ) {
    ListaDouble punt;
    if(lista==NULL) { punt = malloc( sizeof(ElemLista) );
                     punt->prox = NULL; punt->info = elem; return  punt;
    }else{lista->prox = InsInFondoDouble(lista->prox,elem); return lista;}
}

ListaDiListe InsInFondoLista(ListaDiListe lista,SottoLista lis ) {
   ListaDiListe punt;
   if(lista==NULL) { punt = malloc( sizeof(NodoLista) );
                     punt->prox=NULL; punt->lista=lis; return  punt;
   }else{lista->prox = InsInFondoLista(lista->prox,lis); return lista;}
}
void VisualizzaListaInt(SottoLista lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %d ---> ", lista->info); VisualizzaListaInt( lista->prox );}
}
void VisualizzaListaDouble(ListaDouble lista) {
    if (lista==NULL) printf(" ---| \n");
    else{printf(" %lf ---> ", lista->info); VisualizzaListaDouble( lista->prox );}
}
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox);}
}
