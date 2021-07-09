#include <stdio.h>
#include <stdlib.h>

//função para imprimir bordas do cabeçalho e rodapé
void printHeaderFooter(int width, int border_size){

    for (int i=0; i < border_size; i++){
        for (int j=0; j < (2*border_size)+width; j++){
            printf("0 ");
        }
        printf("\n");
    }
    return;
}

int main(int argc, char *argv[]){
    
    //lendo largura e altura
    int width, height;
    scanf(" %d",&width);
    scanf(" %d",&height);

    //lendo matriz da imagem
    int **M_pic = (int **) malloc(height * sizeof(int *));
    for(int i=0; i<height; i++){
        M_pic[i] = (int *) malloc(width * sizeof(int));
        for (int j=0; j<width; j++){
            scanf(" %d",&M_pic[i][j]);
        }
    }

    //lendo tamanho da borda
    int border_size;
    scanf(" %d",&border_size);

    //imprimindo imagem com bordas
    printHeaderFooter(width, border_size);
    for (int i=0; i<height; i++){
        for (int j=0; j < border_size; j++)
            printf("0 ");
        
        for (int j=0; j < width; j++)
            printf("%d ",M_pic[i][j]);

        for (int j=0; j < border_size; j++)
            printf("0 ");

        printf("\n");
    }
    printHeaderFooter(width, border_size);

    //imprimindo imagem sem bordas
    printf("\n");
    for (int i=0; i<height; i++){
        for (int j=0; j<width; j++){
            printf("%d ",M_pic[i][j]);
        }
        printf("\n");
    }

    return 0;
}
