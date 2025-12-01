#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Due parole p e q si definiscono Hertzianamente compatibili se entrambe sono
 leggibili anche “oscillando” e leggendo alternativamente i caratteri dell’una
 e dell’altra. La figura mostra tigre con fiera e fiera con fresa. In figura
 parole uguali sono tracciate da linee di ugual stile.
 Si noti anche che la relazione sussiste in due modi (diretto o inverso).
 In figura: fiera e tigre si leggono iniziando dalla stessa lettera
 (modo diretto), per fiera e fresa occorre iniziare dall’iniziale dell’ “altra”
 parola nella coppia (modo inverso). Se la relazione fosse definita solo in modo
 diretto o solo in modo inverso varrebbe anche la proprietà transitiva (esempio:
 aria, prua, erba, orma sono tutte direttamente compatibili tra loro),ma
 consideriamo due parole compatibili indipendentemente dal modo in cui la
 proprietà si manifesta.

Si scriva un programma che verifica la compatibilità Hertziana di due stringhe.*/

#define N 100
int main(){
    //char s1[N] = "tigre";
    //char s2[N] = "fiera";

    char s1[N] = "fiera";
    char s2[N] = "fresa";

    int l1 = strlen(s1);
    int l2 = strlen(s2);

    printf("%s\n%s\n", s1, s2);

    if(l1 != l2){
        printf("Le parole devono essere della stessa lunghezza!\n");
    }

    int i, hertziana = 1;
    // Controllo proprietà diretta
    for(i = 0; i < l1; i++){
        if(i % 2 == 1){
            if(s1[i] != s2[i]){
                hertziana = 0;
            }
        }
    }
    if(hertziana){
        printf("Le stringhe godono della proprieta' diretta\n");
    }

    hertziana = 1;
    // Controllo proprietà diretta
    for(i = 0; i < l1; i++){
        if(i % 2 == 0){
            if(s1[i] != s2[i]){
                hertziana = 0;
            }
        }
    }
    if(hertziana){
        printf("Le stringhe godono della proprieta' inversa\n");
    }



    return 0;
}
