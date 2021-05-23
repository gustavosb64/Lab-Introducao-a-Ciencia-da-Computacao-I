#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int a, b;
    scanf(" %d %d", &a, &b);

    int res = 1;
    for (int i=0; i < b; i++){
        res *= a;
    }

    printf("%d",res);
    return 0;
}
