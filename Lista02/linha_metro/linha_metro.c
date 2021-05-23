#include <stdio.h>
#include <stdlib.h>

void imprimirAteOscarFreire(int in);
void imprimirAteLuz(int in);

int main(int argc, char *argv[]){
    int in;
    scanf(" %d", &in);

    (in <= 5) ? imprimirAteOscarFreire(in) : imprimirAteLuz(in);

    return 0;
}

void imprimirAteOscarFreire(int in){

    do{
        switch(in){
            case 0:
                printf("* Morumbi\n");
                if (in < 5) printf("|\n");
                break;
            case 1:
                printf("* Butanta\n");
                if (in < 5) printf("|\n");
                break;
            case 2:
                printf("* Pinheiros\n");
                if (in < 5) printf("|\n");
                break;
            case 3:
                printf("* Faria Lima\n");
                if (in < 5) printf("|\n");
                break;
            case 4:
                printf("* Fradique Coutinho\n");
                if (in < 5) printf("|\n");
                break;
            case 5:
                printf("* Oscar Freire\n");
                if (in < 5) printf("|\n");
                break;
        }
    }while(++in <= 5);

    return;
}

void imprimirAteLuz(int in){

    do{
        switch(in){
            case 6:
                printf("* Paulista\n");
                if (in < 9) printf("|\n");
                break;
            case 7:
                printf("* Higienopolis-Mackenzie\n");
                if (in < 9) printf("|\n");
                break;
            case 8:
                printf("* Republica\n");
                if (in < 9) printf("|\n");
                break;
            case 9:
                printf("* Luz\n");
                if (in < 9) printf("|\n");
                break;
        }
    }while(++in <= 9);

    return;
}
