#include <stdio.h>
#include <stdlib.h>

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

char *TranscribeMessage(FILE *stream, int **rotores) {
    char c;
    int pos; 

    do{
        c = (char) fgetc(stream);

        pos = IsLetter(c);
        if(pos != 0){
            if (pos < 0){
             
            }       
            
        }

    }while(!feof(stream));

    return string;
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

    char *message = readline(stdin); 

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
