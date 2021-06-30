#include<stdio.h>
#include<stdlib.h>

#define TAM 10

double getMedia(double *n){
    double soma = 0.0;

    for (int i=0; i<TAM; i++){
        soma += n[i];
    }
    return (soma/TAM);
}

double getMenor(double *n){
    double menor = n[0];

    for (int i=1; i<TAM; i++){
        if (n[i] < menor) menor = n[i];
    }
    return menor;
}

double getMaior(double *n){
    double maior = n[0];

    for (int i=1; i<TAM; i++){
        if (n[i] > maior) maior = n[i];
    }
    return maior;
}

double getModa(double *n){

    int size_cont = 1;
    int **cont = (int **) calloc(size_cont, sizeof(int*));
    cont[0] = (int *) calloc(2 , sizeof(int));

    int flag = 0;
    for (int i=0; i<TAM; i++){

        for (int j=0; j<size_cont; j++){
            if (cont[j][0] == n[i]){
                cont[j][1]++;
                flag = 1;
                break;
            }
        }

        if (flag != 1){
            cont = (int **) realloc(cont, (size_cont+1) * sizeof(int*));
            cont[size_cont] = (int *) calloc (2 , sizeof(int)); 

            cont[size_cont][0] = n[i];
            cont[size_cont][1] = 1;
            size_cont++;
        }
    
    }

    int maior = cont[0][1];
    int maior_num = cont[0][0];

    for (int i=1; i<size_cont; i++){
        if (cont[i][1] > maior){
            maior = cont[i][1];
            maior_num = cont[i][0];
        }
    }

    for (int i=0; i<size_cont; i++)
        free(cont[i]);
    free(cont);

    return maior_num;
}

int main(int argc, char *argv[]){
    double *n = (double *) malloc(TAM * sizeof(double));

    for (int i=0; i < TAM; i++){
        scanf("%lf",&n[i]);
    }

    printf("%0.0lf %0.0lf %0.2lf %0.0lf\n", getMaior(n), getMenor(n), getMedia(n), getModa(n));

    free(n);

    return 0;
}
