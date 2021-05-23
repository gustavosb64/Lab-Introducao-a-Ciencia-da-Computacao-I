#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    /*Ano é bissexto se for divisível por 400 ou for divisível por 4, mas não por 100
    */
    int ano;
    scanf(" %d",&ano);
    if (!(ano%400) || (!(ano%4) && ano%100)) printf("SIM");
    else printf("NAO");

    return 0;
}
