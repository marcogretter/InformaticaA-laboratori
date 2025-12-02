//
//  main.cpp
//  lab8 personale
//
//  Created by Marco Gretter on 02/12/25.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct s_nodo {
        int val;
        struct s_nodo *left;
        struct s_nodo *right;
} nodo;
typedef nodo *albero;


albero creaAlbero(void);
albero createVal(int val);

void print(albero t);
void printConLivello(albero t,int liv);

int fPari(albero t);
int prodTre(albero t);
int maxPari(albero t,int tmp);

int main(){
  int ris=0;
  albero alb = creaAlbero();
  print(alb);
  printf("\n");
  printConLivello(alb,1);
  printf("\n");
    int tre,maxPar;
  
  //chiamata alla funzione da scrivere
  ris=fPari(alb);
    tre=prodTre(alb);
    maxPar=maxPari(alb,0);
  printf("\n%d,%d,%d\n", ris,tre,maxPar);
  fflush(stdin);
  return 0;
}
int fPari(albero t)
{
    if(t==NULL)
        return 0;
    if(t->val%2==0)
        return t->val+fPari(t->right)+fPari(t->left);
    return fPari(t->right)+fPari(t->left);
}
int prodTre(albero t)
{
    if(t==NULL)
        return 1;
    if(t->val%3==0)
        return t->val*prodTre(t->right)*prodTre(t->left);
    return prodTre(t->right)*prodTre(t->left);
}
int maxPari(albero t,int tmp)
{
    if(t==NULL)
        return tmp;
    if(t->val%2==0&&tmp<t->val){
        tmp=t->val;
    }
     return maxPari(t->right, tmp);
     return maxPari(t->left, tmp);
}
albero creaAlbero() {
       albero tmp = createVal(7);
       tmp->left = createVal(3);
       tmp->left->left = createVal(9);
       tmp->left->right = createVal(10);
       tmp->right = createVal(8);
       tmp->right->left = createVal(5);
       tmp->right->right = createVal(12);
       tmp->right->right->left = createVal(11);
       tmp->right->right->right = createVal(6);

       return tmp;
}

albero createVal(int val) {
       albero tmp = malloc(sizeof(nodo));
       tmp->val = val;
       tmp->left = NULL;
       tmp->right = NULL;
       return tmp;
}

void print(albero t){
       if(t==NULL)
           return;
       printf(" (");
       print(t->left);
       printf(" %d ",t->val);
       print(t->right);
       printf(") ");
}

void printConLivello(albero t,int liv){
       if(t==NULL)
           return;
       printf(" (");
       printConLivello(t->left,liv+1);
       printf("(v: %d, l: %d)",t->val,liv);
       printConLivello(t->right,liv+1);
       printf(") ");
}

