#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Scrivere un programma che chiede due sequenze di caratteri all’utente,
 e conta quante volte nella prima stringa è contenuta interamente la seconda. */

#define N 100

int main(){
    char s1[N], s2[N];
    int l1, l2;
    int occurrences = 0;
    int i, j, found;

    // Lettura caratteri (come stringhe)
    printf("Enter the first string:\n");
    scanf(" %s", s1);

    printf("Enter the second string:\n");
    scanf(" %s", s2);

    // Calcolo lunghezze
    l1 = strlen(s1);
    l2 = strlen(s2);

    // Scorro sulla stringa s1 per cercare la sottostringa s2
    for(i = 0; i <= l1-l2; i++){
        found = 1;
        for(j = 0; j < l2; j++){
            if(s1[i+j] != s2[j]){
                found = 0;
                break;
            }
        }

        if(found){
            occurrences++;
        }
    }

    printf("The second string is contained %d times in the first one\n", occurrences);


    return 0;
}
