#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long long int a, r, n;
    scanf(" %lld %lld %lld",&a,&r,&n);

    long long int n_termo = a + (n-1)*r;
    long long int soma = ((a + n_termo)*n)/2;

    printf("%lld\n%lld",n_termo,soma);
    return 0;
}
