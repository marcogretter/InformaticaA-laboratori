#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definiamo il grado minimo g e il grado massimo G di una parola P
rispettivamente come il minimo e il massimo numero di occorrenze delle lettere
di P in P. Ad esempio:
POLENTA    g=1, G=1 ( tutte le lettere della parola compaiono in essa una e una sola volta )
ORGOGLIO   g=1, G=3 ( R, L, I compaiono una sola volta, O compare tre volte )
MAMMA      g=2, G=3 ( A compare due volte, M compare tre volte )

G e g valgono convenzionalmente 0 per la parola vuota (cioè per una parola priva di caratteri).
Si scriva un programma C che legge una stringa di lunghezza generica che
rappresenta P, calcola G e g, e li stampa*/

#define N 100
int main(){
    char parola[N] = "MAMMA";
    char lettere[N], occorrenza[N];
    int num_lettere = 0;
    int min_occ, max_occ;
    int i, j, trovato;

    // Scorro tra tutte le lettere della parola e mi creo una lista di lettere trovate (senza ripetizioni)
    // insieme ad un array contenente il numero di volte in cui le ho trovate
    for(i = 0; i < strlen(parola); i++){
        // Cerco la lettera parola[i] tra le mie lettere
        trovato = 0;
        for(j = 0; j < num_lettere; j++){
            if(lettere[j] == parola[i]){
                occorrenza[j]++;
                trovato = 1;
            }
        }

        // Se non l'ho trovata, la aggiungo alla mia lista
        if(!trovato){
            lettere[num_lettere] = parola[i];
            occorrenza[num_lettere] = 1;
            num_lettere++;
        }
    }

    // Ricerca minimo e massimo (inizializzo i valori con le occorrenze della prima lettera)
    min_occ = occorrenza[0];
    max_occ = occorrenza[0];
    for(j = 0; j < num_lettere; j++){
        if(occorrenza[j] < min_occ){
            min_occ = occorrenza[j];
        }
        if(occorrenza[j] > max_occ){
            max_occ = occorrenza[j];
        }
    }

    printf("g = %d\n", min_occ);
    printf("G = %d\n", max_occ);

    return 0;
}
