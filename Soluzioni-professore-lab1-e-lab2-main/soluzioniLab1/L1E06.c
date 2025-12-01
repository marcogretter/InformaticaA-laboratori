#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma che richiede l'inserimento di voti ottenuti in un certo
numero di corsi. Il programma chiede qual è il numero di voti da inserire. Per
ciascuno, l'utente deve inserire numero di crediti e voto ottenuto (in 30imi).
Il programma infine stampa la media pesata dei corsi e il numero totale dei
crediti. Si ricorda che la media pesata, ad esempio su due voti, si calcola come:

media = (voto1*crediti1+voto2*crediti2)/(crediti1+crediti2).
 */

 #define N 100

int main(){
    // Creazione degli array per contenere voti e crediti
    int voti[N], crediti[N];
    int somma_pesata = 0, totale_crediti = 0;
    int i, n;
    float media_pesata;

    // Chiedere quanti esami vanno inseriti
    printf("Quanti corsi hai completato? ");
    scanf(" %d", &n);

    // Leggere il numero di crediti ed il voto di ciascun esame
    for(i = 0; i < n; i++){
        printf("Corso %d.\n", i+1);
        printf("   Inserisci voto: ");
        scanf(" %d", &voti[i]);
        printf("   Inserisci crediti: ");
        scanf(" %d", &crediti[i]);
    }

    // Calcolare la media pesata

    for(i = 0; i < n; i++){
        somma_pesata += voti[i] * crediti[i];
        totale_crediti += crediti[i];
    }
    media_pesata = (1.0 * somma_pesata) / totale_crediti;

    // Visualizzare il risultato
    printf("La media pesata dei voti e' %f\n", media_pesata);

    return 0;
}
