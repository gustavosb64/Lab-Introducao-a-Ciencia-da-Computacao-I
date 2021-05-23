#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n_brincadeiras, n_mordidas;

    scanf("%d %d", &n_brincadeiras, &n_mordidas);

    int res = (n_mordidas*3 - n_brincadeiras * 5);
    if (res <= 0){
        if (res <= (-30)) printf("P");
        else printf("B");
        return 0;
    }
    printf("R");
    return 0;

    /*pode ser substituído por:
     *res <= 0 ? (res <= (-30) ? printf("P") : printf("B")) : printf("R");
    */
}
