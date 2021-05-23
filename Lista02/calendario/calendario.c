#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int dia=30;
    scanf(" %d",&dia);

    //Cabeçalho
    printf("         Abril 2021         \n");
    printf(" Do  Se  Te  Qu  Qu  Se  Sa \n");
    printf("                ");
    int d = 1, j = 4;
    for (int i = 0; i < 5; i++){
        for (j=j; j < 7 && (d >= 1 && d<= 30); j++){
            if (d < 10) (d != dia) ? printf(" ") : printf("(");
            if (d == dia){
                (d < 10) ? printf(" ") : printf("(");
                printf("%d)",d);
            }
            else printf(" %d ",d);
            d++;
        }
        j = 0;
        printf("\n");
    }
    
    return 0;
}
