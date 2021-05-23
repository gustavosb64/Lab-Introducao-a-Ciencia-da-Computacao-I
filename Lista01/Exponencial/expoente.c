#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[]){
    double a, b;
    scanf("%lf %lf",&a,&b);

    printf("%0.4f\n",pow(a,b));

    return 0;
}
