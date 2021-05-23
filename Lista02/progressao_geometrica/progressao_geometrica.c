#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    float a, q, n;
    scanf(" %f %f %f",&a,&q,&n);

    float n_termo = a * pow(q,(n-1));
    float soma = (a * (pow(q,n) - 1))/(q-1);

    printf("%.2f\n%.2f",n_termo,soma);
    return 0;
}
