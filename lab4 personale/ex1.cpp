//
//  main.cpp
//  lab4 personale
//
//  Created by Marco Gretter on 02/12/25.
//

#include <stdio.h>
#include <stdlib.h>

int sommaDivisori(int num);
int controllaSePerfetto(int num);

int main(){
    int n;
    
    do {
        printf("Inserisci numero:\n");
        scanf("%d",&n);
    } while (n<0);
    
    if(controllaSePerfetto(n)==1)
        printf("perfetto.\n");
    if(controllaSePerfetto(n)==2)
        printf("abbondante.\n");
    if(controllaSePerfetto(n)==0)
        printf("difettivo.\n");
}
int sommaDivisori(int num)
{
    int i;
    int sum=0;
    if(num==1)
        return 1;
    else
        for (i=1; i<num; i++) {
            if(num%i==0)
                sum+=i;
        }
    return sum;
}
int controllaSePerfetto(int num)
{
    if(num==sommaDivisori(num))
        return 1;
    if(num>sommaDivisori(num))
        return 2;
    else
        return 0;
}
