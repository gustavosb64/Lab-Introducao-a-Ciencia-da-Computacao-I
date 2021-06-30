#include<stdio.h>
#include<stdlib.h>

void calculoTroco(int valor, int *c100, int *c50, int *c25, int *c10, int *c05, int *c01){

    *c100 = valor/100;
    valor%=100;

    *c50 = valor/50;
    valor%=50;

    *c25 = valor/25;
    valor%=25;

    *c10 = valor/10;
    valor%=10;

    *c05 = valor/5;
    valor%=5;

    *c01 = valor/1;

    return;
}


int main(int argc, char *argv[]){

    //valor de entrada (em centavos)
    int valor;
    scanf(" %d",&valor);

    //variáveis que contêm a quantidade de cada moeda
    int c100, c50, c25, c10, c05, c01;

    calculoTroco(valor, &c100, &c50, &c25, &c10, &c05, &c01);
    
    printf("O valor consiste em %d moedas de 1 real\n", c100);
    printf("O valor consiste em %d moedas de 50 centavos\n", c50);
    printf("O valor consiste em %d moedas de 25 centavos\n", c25);
    printf("O valor consiste em %d moedas de 10 centavos\n", c10);
    printf("O valor consiste em %d moedas de 5 centavos\n", c05);
    printf("O valor consiste em %d moedas de 1 centavo\n", c01);

    return 0;
}
