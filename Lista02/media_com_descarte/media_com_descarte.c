#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double a, b, c, d;
    double M, min;

    scanf("%lf %lf %lf %lf",&a,&b,&c,&d);

    min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    if (min > d) min = d;

    M = (a + b + c + d - min)/3;

    printf("%.4lf",M);

    return 0;
}
