//
//  ex2.cpp
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

typedef struct ELL {
    SottoLista lista;
    struct ELL * prox;
} NodoLista;
typedef NodoLista * ListaDiListe;

SottoLista InsInFondoInt(SottoLista lista,int elem );
ListaDiListe InsInFondoLista( ListaDiListe lista,SottoLista lis );
void VisualizzaListaInt(SottoLista lista );
void VisualizzaListaDiListe(ListaDiListe lista );
ListaDiListe costruisci();
//
// TODO: PROTOTIPI DELLE FUNZIONI RICHIESTE
//
ListaDiListe pulisci(ListaDiListe lis);
int esploraLista(SottoLista lis);
int scorroLista(SottoLista lis,int n);
ListaDiListe Cancella( ListaDiListe lista, SottoLista elem );

int main(){
    ListaDiListe lis;
    ListaDiListe ris=NULL;
    lis=costruisci();
    printf("Lista (ogni elemento in una riga)\n");
    VisualizzaListaDiListe(lis);

    //TODO: invocazione funzione
    ris=pulisci(lis);
    
    printf("Lista dopo pulizia\n");
    VisualizzaListaDiListe(ris);

    return 0;
}

//
// TODO: SVILUPPARE QUI LE FUNZIONI RICHIESTE
//
ListaDiListe pulisci(ListaDiListe lis)
{
    if(lis==NULL)
        return NULL;
    while (lis->prox->prox!=NULL) {
        if(esploraLista(lis->lista)==0)
            lis=Cancella(lis, lis->lista);
        lis=lis->prox;
    }
    return lis;
}
int esploraLista(SottoLista lis)
{
    if(lis==NULL)
        return 1;//ritorno 0 se è da cancellare, se una sottolista è vuota non ci sono numeri che si ripetono, quindi si tiene.
    while (lis!=NULL) {
        if(scorroLista(lis,lis->info)==0)
            return 0;
        lis=lis->prox;
    }
    return 1;
}
int scorroLista(SottoLista lis,int n)
{
    if(lis==NULL)
        return 1;
    while (lis!=NULL) {
        if(n==lis->info)
            return 0;
        lis=lis->prox;
    }
    return 1;
}

ListaDiListe Cancella( ListaDiListe liste, SottoLista elem ) {
    ListaDiListe puntTemp;
    if( liste!=NULL)
        if( liste->lista == elem ) {
            puntTemp = liste->prox;
            free( liste );
            return puntTemp; // per cancellare tutte le istanze: return Cancella(PuntTemp, Elem);
        }
        else
            liste->prox=Cancella( liste->prox, elem );
    return liste;
}
ListaDiListe costruisci(){
    int M[8][10]={5,4,1,5,2,7,-1,-1,-1,-1,1,6,9,1,5,7,9,0,-1,-1,1,5,1,1,2,8,9,0,-1,-1,
                  1,3,2,4,0,9,8,6,-1,-1,1,2,9,8,4,0,9,0,-1,-1,1,8,7,8,3,-1,-1,-1,-1,-1,
                  1,3,4,2,5,7,9,0,-1,-1,7,8,9,-1,-1,-1,-1,-1,-1,-1};
    int i,k;ListaDiListe ris=NULL; SottoLista temp=NULL;
    for(i=0;i<8;i++){
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
void VisualizzaListaDiListe( ListaDiListe lista ) {
    if(lista==NULL) printf("\n");
    else{VisualizzaListaInt(lista->lista); VisualizzaListaDiListe(lista->prox);}
}
