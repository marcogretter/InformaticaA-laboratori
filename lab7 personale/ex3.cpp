//
//  ex3.cpp
//  lab7 personale
//
//  Created by Marco Gretter on 02/12/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int giorno, mese, anno;
} Data;
typedef struct ELP {
    char nome[50];
    Data giorno_scadenza;
    struct ELP * next;
} NodoP;

typedef NodoP * ListaP;

typedef struct ELS {
    ListaP prodotti;
    struct ELS * next;
} NodoS;

typedef NodoS * ListaS;

/// Funzioni implementate
ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno);
ListaS costruisci();
void stampaData(Data d);
void stampaProdotto(NodoP* prodotto);
void stampaProdotti(ListaP prodotti);
void stampaScaffale(NodoS* scaffale);
void stampaScaffali(ListaS scaffali);
/// -------------------------

/// INSERIRE QUI PROTOTIPI E IMPLEMENTAZIONI DELLE FUNZIONI RICHIESTE
// TODO
ListaS eliminaScaduti(ListaS lis,Data G);
int primaDi(Data d1, Data d2);
ListaP Cancella( ListaP lista, char elem[],Data D );
ListaP esploraECancellaProd(ListaP lis,Data G);
ListaP InsInFondo( ListaP lista,char *elem,Data G );
/// -------------------------------------------------------------------
int primaDi(Data d1, Data d2)
{
//    restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti.
    if(d1.anno<d2.anno)
        return 1;
    if(d1.anno==d2.anno&&d1.mese<d2.mese)
        return 1;
    if(d1.anno==d2.anno&&d1.mese==d2.mese&&d1.giorno<d2.giorno)
        return 1;
    return 0;
}
ListaS eliminaScaduti(ListaS lis,Data G)
{
    if(lis==NULL)
        return lis;
    while (lis!=NULL) {
        lis->prodotti=esploraECancellaProd(lis->prodotti, G);
        lis=lis->next;
    }
    return lis;
}
ListaP esploraECancellaProd(ListaP lis,Data G)
{
    ListaP nuova=NULL;
    if(lis==NULL)
        return lis;
    while (lis!=NULL) {
        if(primaDi(lis->giorno_scadenza, G)==0)
            nuova=InsInFondo(nuova, lis->nome, lis->giorno_scadenza);
        lis=lis->next;
    }
    return nuova;
}
ListaP InsInFondo( ListaP lista,char *elem,Data G ) {
    ListaP punt;
    if( lista==NULL ) {
        punt = malloc( sizeof(NodoP) );
        punt->next = NULL;
        strcpy(punt->nome, elem);
        punt->giorno_scadenza=G;
        return punt;
    } else {
        lista->next = InsInFondo( lista->next, elem,G );
        return lista;
    }
}
/// MAIN ED ALTRE FUNZIONI
int main(){
    ListaS scaffali = costruisci();
    Data G = {5, 9, 2022};
    printf("Data di scadenza: "); stampaData(G); printf("\n\n");
    printf("Prima della rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);

    /// INSERIRE QUI LE CHIAMATE A FUNZIONE
    // TODO
    /// -----------------------------------
    eliminaScaduti(scaffali, G);
    printf("Dopo la rimozione dei prodotti scaduti:\n");
    stampaScaffali(scaffali);
    return 0;
}

ListaP aggiungiProdotto(ListaP prodotti, char nome[50], int giorno, int mese, int anno){
    if(prodotti == NULL){
        prodotti = (ListaP) malloc(sizeof(NodoP));
        Data scad = {giorno, mese, anno}; strcpy(prodotti->nome, nome); prodotti->giorno_scadenza = scad; prodotti->next = NULL;
        return prodotti;
    } else { prodotti->next = aggiungiProdotto(prodotti->next, nome, giorno, mese, anno); return prodotti;}
}
ListaS costruisci(){
    ListaS scaffali = NULL;
    scaffali = (ListaS) malloc(sizeof(NodoS));scaffali->prodotti = NULL; scaffali->next = NULL;
    scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Pasta", 14, 7, 2027);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Riso", 8, 11, 2020);scaffali->prodotti = aggiungiProdotto(scaffali->prodotti, "Farro", 9, 3, 2029);
    scaffali->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->prodotti = NULL; scaffali->next->next = NULL;
    scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Biscotti", 4, 6, 2020);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Cereali", 2, 7, 2025);scaffali->next->prodotti = aggiungiProdotto(scaffali->next->prodotti, "Toast", 1, 3, 2018);
    scaffali->next->next = (ListaS) malloc(sizeof(NodoS));scaffali->next->next->prodotti = NULL; scaffali->next->next->next = NULL;
    scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "More", 7, 9, 2016);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Lamponi", 25, 12, 2017);scaffali->next->next->prodotti = aggiungiProdotto(scaffali->next->next->prodotti, "Ribes", 18, 5, 2010);
    return scaffali;
}
void stampaData(Data d){ printf("%d/%d/%d", d.giorno, d.mese, d.anno); }
void stampaProdotto(NodoP* prodotto){printf(" ~ %s in scadenza il ", prodotto->nome);stampaData(prodotto->giorno_scadenza);}
void stampaProdotti(ListaP prodotti){
    if(prodotti == NULL){ printf(" * \n"); return; }
    stampaProdotto(prodotti); printf("\n"); stampaProdotti(prodotti->next);
}
void stampaScaffale(NodoS* scaffale){printf("+ - - -\n"); stampaProdotti(scaffale->prodotti);}
void stampaScaffali(ListaS scaffali){
    if(scaffali == NULL){ printf("+ _ _ _\n\n"); return; }
    stampaScaffale(scaffali);stampaScaffali(scaffali->next);
}
