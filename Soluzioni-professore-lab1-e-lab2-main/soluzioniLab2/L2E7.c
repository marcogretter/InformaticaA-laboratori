#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Si scriva un programma che chiede all'utente una stringa "txt" di 100 massimo
 caratteri contenente del testo e stampa una stringa "res" contenente la lettera
 iniziale e finale di ogni parola

 PS: per comodità si può assumere che "txt" non termini con uno spazio

 risultato atteso:
  che bella giornata su Zoom
  cebagasuZm

  misione compiuta!
  mec!
*/

#define N 100
int main(){
    char s1[N] = "che bella giornata su Zoom";
    // char s1[N] = "missione compiuta!";
    int l1 = strlen(s1);
    int i, curr = 0;

    for(i = 0; i <= l1; i++){
        // Se curr==0 significa che è l'inizio di una nuova parola
        if(curr == 0){
            // Stampo la prima lettera di questa nuova parola
            printf("%c", s1[i]);
        }
        if(s1[i] == ' ' || s1[i] == '\0'){
            // Sono arrivato in fondo alla parola precedente, stampo la sua ultima letera
            printf("%c", s1[i-1]);
            curr = 0;
        } else {
            curr++;
        }
    }

    // Soluzione alternativa: creare una stringa risultato in cui mettere queste lettere

    return 0;
}
