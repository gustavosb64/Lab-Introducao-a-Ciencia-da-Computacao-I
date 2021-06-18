#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

char *readline(FILE *stream) {
    char *string = 0;
    int pos = 0; 

    do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);
    }while(string[pos++] != '\r' && string[pos-1] != '\n' && !feof(stream));

    if (string[pos-1] == '\r'){
        printf("roi\n");
        string[pos-1] = (char) fgetc(stream);
    }

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

//checks whether char c is uppercase; return 0 if it's not a letter
int IsLetter(char c){
    
    if (c >= 65 && c <= 90 ) return 1; 
    
    if (c >= 97 && c <= 122) return -1;

    return 0;

}

void TranscribeMessage(FILE *stream, int **rotores, int *M) {
    char c;
    int pos; 
    int i = 0;

    do{
        c = (char) fgetc(stream);
        pos = IsLetter(c);

        if(pos != 0){
            if (pos < 0){
                c -= 97;
                for (int j=0; j<3; j++) c = rotores[j][c];
                c += 97;
            }       
            if (pos > 0){
                c -= 65;
                for (int j=0; j<3; j++) c = rotores[j][c];
                c += 65;
            }       
        }
        printf("%c",c);
       
    }while(!feof(stream));

    return;
}

int main(int argc, char *argv[]){
    int** rotores = (int **) malloc(3 * sizeof(int*));
    for (int i=0; i<3; i++) rotores[i] = (int *) malloc(26 * sizeof(int));

    //Read "Rotores:" and put in aux_string
    char *aux_string = readline(stdin);

    for (int i=0; i<3; i++){
        for (int j=0; j<26; j++){
            scanf(" %d",&rotores[i][j]);
        }
    }

    //Read characters before message and put in aux_string
    for (int i=0; i<3; i++) aux_string = readline(stdin);

    int M[3];
    M[0] = 0;
    M[1] = 0;
    M[2] = 0;

    do{
        TranscribeMessage(stdin, rotores, M);
    }while(!feof(stdin));

    /*
    printf(" %s\n", message);

    for (int i=0; i<3; i++){
        for (int j=0; j<26; j++){
            printf("%d ",rotores[i][j]);
        }
        printf("\n");
    }

    */

    free(aux_string);
   
    return 0;
}
