#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double a, b;
    char op;

    scanf(" %lf %c %lf",&a,&op,&b);

    /*ASCII table:
     * 37 -> %
     * 42 -> *
     * 43 -> +
     * 45 -> -
     * 47 -> /
    */

    float res;
    switch(op){
        case(37):
            res = (a*100/b);
            break;
        case(42):
            res = a*b;
            break;
        case(43):
            res = a+b;
            break;
        case(45):
            res = a-b;
            break;
        case(47):
            res = a/b;
            break;
        default:
            printf("Entrada inválida!\n");
    }
    printf("%lf", res);

    return 0;
}
