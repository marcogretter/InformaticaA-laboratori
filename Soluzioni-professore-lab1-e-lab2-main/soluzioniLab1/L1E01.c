#include <stdio.h>
#include <stdlib.h>

/* Scrivere un programma in linguaggio C che, letti due caratteri minuscoli
dallo standard input, stabilisce quale dei due viene prima e quale dopo in
ordine alfabetico e stampi l’intera porzione di alfabeto tra i due. */

int main(){
    char c1, c2, c3, tmp;

    printf("Inserisci due caratteri\n");
    scanf(" %c", &c1);
    scanf(" %c", &c2);

    // Sposta il carattere minore in c1
    if(c1 > c2){
        tmp = c1;
        c1 = c2;
        c2 = tmp;
    }

    c3 = c1;
    while(c3 <= c2){
        printf("%c ", c3);
        c3++;
    }

    return 0;
}
