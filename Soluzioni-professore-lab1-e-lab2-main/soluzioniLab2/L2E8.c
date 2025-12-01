#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
int main(){
    char s1[N] = "ho studiato e mi pace fare questo esercizio bene";
    int lunghezze[N];
    int num_parole = 0;
    int len_s1 = strlen(s1);

    // Passata 1: calcolare la lunghezza delle parole
    int i, curr = 0;
    for(i = 0; i <= len_s1; i++){
        if(s1[i] != ' ' && s1[i] != '\0'){
            curr++;
        } else {
            lunghezze[num_parole] = curr;
            num_parole++;
            curr = 0;
        }
    }

    // Calcolo della media
    int sum = 0;
    float avg;
    for(i = 0; i < num_parole; i++){
        sum += lunghezze[i];
        printf("%d\n", lunghezze[i]);
    }
    avg = (1.0 * sum) / num_parole;
    printf("%f\n", avg);

    // Passata 2: per ciascuna parola stampo +, =, -
    for(i = 0; i <= len_s1; i++){
        if(s1[i] != ' ' && s1[i] != '\0'){
            curr++;
        } else {
            if(curr > avg){
                printf("+");
            } else if(curr < avg){
                printf("-");
            } else {
                printf("=");
            }
            curr = 0;
        }
    }

    return 0;
}
