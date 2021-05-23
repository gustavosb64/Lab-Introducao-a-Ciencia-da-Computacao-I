#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int mascara = 255;
    int c[4];

    int n_entrada;
    scanf (" %d", &n_entrada);
   
    for (int i=0; i<4; i++){
        c[i] = (n_entrada & mascara); 
        n_entrada = n_entrada>>8;
    }

    for (int i=3; i>=0; i--) printf("%c", c[i]);
    
    return 0;
}
