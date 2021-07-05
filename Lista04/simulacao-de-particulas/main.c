#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*swap
*/

/* 4 tipos de elementos:
    * # areia
    * ~ água
    * @ cimento
    * <espaço> ar
*/

#define LIN 32
#define COL 64
enum elemento{Areia = 35, Agua=126, Cimento = 64, Ar = 32};

void swap(char *x, char *y);
void PrintFrame(char **M, int idx_frame);
void MoveAreia(char **M, char **M_aux, int y, int x);
void MoveAgua(char **M, char **M_aux, int y, int x);
char** AtualizacaoFisica(char **M);
void FreeM(char **M);

int main(int argc, char *argv[]){

    char **M = (char **) malloc(LIN * sizeof(char*));
    for (int i=0; i<LIN; i++){
        M[i] = (char *) malloc((COL+1) * sizeof(char));
        memset(M[i], 32, COL); //iniciando todas as posições com espaço (ar)
        M[i][COL] = 0;
    }

    /*
    int n_frames;
    scanf(" %d",&n_frames);

    int frame, lin, col;
    char aux_c;

    for (int i=1; i <= n_frames; i++){
        do{
            scanf(" %d: %d %d %c", &frame, &col, &lin, &aux_c);
            M[lin][col] = aux_c;
            if (frame > i) break;
        }while(!feof(stdin));
        PrintFrame(M, i);
        M = AtualizacaoFisica(M);
    }
    */


    int  n_frames, frame, x, y;
    char nova_particula;

    scanf("%d", &n_frames);

    int contador = 0;
    while (contador < n_frames) {

            // `scanf` retorna EOF quando chega ao fim da entrada.
            int n_lido = scanf(" %d: %d %d %c", &frame, &x, &y, &nova_particula);

            // Se não há mais partículas a serem criadas, continue até o final
            // da simulação.
            if (n_lido == EOF) {
                    frame = n_frames;
            }

            // Calcula todos os frames até o próximo frame onde queremos criar
            // uma partícula.
            while (contador < frame) {
    //                printf("frame: %d\n", contador + 1);
                    PrintFrame(M, contador+1);
                    // Seu código de imprimir a matriz 
                    // Seu código de calcular a física 
                    M = AtualizacaoFisica(M);
                    contador++;
            }

            // Se há uma particula a ser criada, crie ela.
            if (n_lido != EOF) {
                    M[y][x] = nova_particula;
            }
    }
       


/*    M = AtualizacaoFisica(M);
    for (int i=0; i<n_frames; i++){
        PrintFrame(M, i);
    }
*/


    FreeM(M);

    return 0;
}

void PrintFrame(char **M, int idx_frame){

    printf("frame: %d\n",idx_frame);
    for (int i=0; i<LIN; i++){
        printf("%s",M[i]);
        printf("\n");
    }
    /*
    printf("Frame %d:",idx_frame);
    for (int i=0;i<LIN; i++){
        for (int j=0; j<COL; j++){
            printf("%c",M[i][j]);
        }
        printf("\n");
    }
    */

    return;
}

void swap(char *x, char *y){
    char aux = *x;
    *x = *y;
    *y = aux;
    return;
}

void MoveAreia(char **M, char **M_aux, int y, int x){

    if ((y+1 < LIN) && (M[y+1][x] == Agua || M[y+1][x] == Ar)){
//        printf("y:%d x:%d\n",y,x);
//        swap(&M[y+1][x], &M[y][x]);
        char aux = M_aux[y+1][x];
        M_aux[y+1][x] = M_aux[y][x];
        M_aux[y][x] = aux;

//        swap(&M_aux[y+1][x], &M_aux[y][x]);
        return;
    } 

    if ((y+1 < LIN && x-1 >= 0) && (M[y+1][x-1] == Agua || M[y+1][x-1] == Ar)){
//        swap(&M[y+1][x-1], &M[y][x]);
//        swap(&M_aux[y+1][x], &M_aux[y][x]);
        char aux = M_aux[y+1][x-1];
        M_aux[y+1][x-1] = M_aux[y][x];
        M_aux[y][x] = aux;
        return;
    } 

    if ((y+1 < LIN && x+1 <= COL) && (M[y+1][x+1] == Agua || M[y+1][x+1] == Ar)){
//        swap(&M[y+1][x+1], &M[y][x]);
//        swap(&M_aux[y+1][x], &M_aux[y][x]);
        char aux = M_aux[y+1][x+1];
        M_aux[y+1][x+1] = M_aux[y][x];
        M_aux[y][x] = aux;
        return;
    } 

    return;
}

void MoveAgua(char **M, char **M_aux, int y, int x){

    if ((y+1 < LIN) && (M[y+1][x] == Ar)){
//        swap(&M[y+1][x], &M[y][x]);
        char aux = M_aux[y+1][x];
        M_aux[y+1][x] = M_aux[y][x];
        M_aux[y][x] = aux;

        return;
    } 

    if ((y+1 < LIN && x-1 >= 0) && (M[y+1][x-1] == Ar)){
//        swap(&M[y+1][x-1], &M[y][x]);
        char aux = M_aux[y+1][x-1];
        M_aux[y+1][x-1] = M_aux[y][x];
        M_aux[y][x] = aux;

        return;
    } 

    if ((y+1 < LIN && x+1 <= COL) && (M[y+1][x+1] == Ar)){
//        swap(&M[y+1][x+1], &M[y][x]);
        char aux = M_aux[y+1][x+1];
        M_aux[y+1][x+1] = M_aux[y][x];
        M_aux[y][x] = aux;

        return;
    } 

    if ((x-1 >= 0) && (M[y][x-1] == Ar)){
//        swap(&M[y][x-1], &M[y][x]);
        char aux = M_aux[y][x-1];
        M_aux[y][x-1] = M_aux[y][x];
        M_aux[y][x] = aux;

        return;
    } 

    if ((x+1 <= COL) && (M[y][x+1] == Ar)){
//        swap(&M[y][x+1], &M[y][x]);
        char aux = M_aux[y][x+1];
        M_aux[y][x+1] = M_aux[y][x];
        M_aux[y][x] = aux;
        return;
    } 

    return;
}

char** AtualizacaoFisica(char **M){

    //copiando M para uma matriz auxiliar M_aux
    char **M_aux = (char **) malloc(LIN * sizeof(char*));
    for (int i=0; i<LIN; i++){
        M_aux[i] = (char *) malloc((COL+1) * sizeof(char));
        strcpy(M_aux[i], M[i]);
    }

    for (int i=0; i<LIN; i++){
        for (int j=0; j<(COL+1); j++){
            if (M[i][j] == Areia)
                MoveAreia(M, M_aux, i, j);
            if (M[i][j] == Agua)
                MoveAgua(M, M_aux, i, j);
        }
    }

    FreeM(M);

    return M_aux;
}

void FreeM(char **M){

    for(int i=0; i<LIN; i++)
        free(M[i]);
    free(M);

    return;
}
