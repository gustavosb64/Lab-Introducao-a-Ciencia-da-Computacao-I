#include <stdio.h>
#include <stdlib.h>

void imprimirPinguim(int k);
void imprimirNoGelo();
void imprimirUhuu();

int main(int argc, char *argv[]){
    int n, m, p;
    scanf(" %d %d %d",&n,&m,&p);

    int i = 0;
    int k = 1;
    int cont = 1;
    int vez = p;

    while (cont <= n){
        for (i=0; i<k; i++){
            if (cont == vez){
                imprimirPinguim(k);
                vez += m;
            }
            cont++;
        }
        if (cont > n) break;
        for (i=0; i<k; i++){
            if (cont == vez){
                imprimirNoGelo();
                vez += m;
            }
            cont++;
        }
        if (cont > n) break;
        for (i=0; i<k; i++){
            if (cont == vez){
                imprimirUhuu();
                vez += m;
            }
            cont++;
        }
        if (cont > n) break;
        k++;
    }

    return 0;
}

void imprimirPinguim(int k){
    (k > 1) ? printf("%d pinguins\n", k) : printf("%d pinguim\n", k);
    return;
}

void imprimirNoGelo(){
    printf("no gelo\n");
    return;
}

void imprimirUhuu(){
    printf("uhuu!\n");
    return;
}
