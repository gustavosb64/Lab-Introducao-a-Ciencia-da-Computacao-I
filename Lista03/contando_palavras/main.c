#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //mark the last read char
    int lastIsN = 0;
    int lastIsR = 0;
    int lastIsTS = 0;

    //mark the last read char
    int n_palavras = 0;
    int n_linhas = 0;
    int n_chars = 0;

    char c = (char) fgetc(stdin);
    while(c != -1 && !feof(stdin)){
        c = (char) fgetc(stdin);
        n_chars++;
        switch(c){
            case -1:
                if(!lastIsR && !lastIsN && !lastIsTS){
                    n_palavras++;
                }

                break;
            case 9:
                if(!lastIsR && !lastIsN && !lastIsTS){
                    n_palavras++;
                }
                lastIsR = 0;
                lastIsN = 0;
                lastIsTS = 1;

                break;
            case 10:
                if(!lastIsR){
                    n_linhas++;
                    if(!lastIsTS && !lastIsN){
                        n_palavras++;
                    }
                }

                lastIsR = 0;
                lastIsN = 1;
                lastIsTS = 0;

                break;
            case 13:
                if(!lastIsTS && !lastIsN){
                    n_palavras++;
                }
                n_linhas++;
                lastIsR = 1;
                lastIsN = 0;
                lastIsTS = 0;

                break;
            case 32:
                if(!lastIsR && !lastIsN && !lastIsTS){
                    n_palavras++;
                }
                lastIsR = 0;
                lastIsN = 0;
                lastIsTS = 1;

                break;
            default:
                lastIsR = 0;
                lastIsN = 0;
                lastIsTS = 0;

                break;
        }

    }

    printf("Linhas\tPalav.\tCarac.\n");
    printf("%d\t%d\t%d", n_linhas, n_palavras, n_chars);

    return 0;
}
