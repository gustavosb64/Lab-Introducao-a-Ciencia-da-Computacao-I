#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 4 tipos de elementos:
    * # areia
    * ~ água
    * @ cimento
    * <espaço> ar
*/

#define LIN 32
#define COL 64

void PrintFrame(char **M, int idx_frame);

int main(int argc, char *argv[]){

    char **M = (char **) calloc(LIN, sizeof(char*));
    for (int i=0; i<LIN; i++){
        M[i] = (char *) calloc(COL, sizeof(char));
        memset(M[i], 32, COL-1);
    }

    int n_frames;
    scanf(" %d",&n_frames);

    int aux;
    int lin, col;
    for (int i=0; i<n_frames; i++){
        scanf(" %d", &aux);
        
        getc(stdin); //lê ':' de stdin
        getc(stdin); //lê ' ' de stdin
        
        scanf(" %d", &lin);
        scanf(" %d", &col);

        scanf(" %c", &M[col][lin]);
    }

    for (int i=0; i<n_frames; i++){
        PrintFrame(M, i);
    }

    for(int i=0; i<LIN; i++)
        free(M[i]);
    free(M);

    return 0;
}

void PrintFrame(char **M, int idx_frame){

    printf("Frame %d:",idx_frame);
    for (int i=0; i<LIN; i++){
        printf("%s",M[i]);
        printf("\n");
    }

    return;
}
