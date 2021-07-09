#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096
int readword(FILE *stream, char **string) {
    char *new_string = 0; 
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            new_string = (char *) realloc(new_string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        new_string[pos] = (char) fgetc(stream);

    }while(new_string[pos++] != '\n' && new_string[pos-1] != '$' && new_string[pos-1] != '\r' && new_string[pos-1] != ' ' && !feof(stream));

    new_string[pos-1] = 0;
    new_string = (char *) realloc(new_string, pos);

    *string = new_string;

    return pos;
}

void myStrcat(char *tabu, char **string){
    char *new_word;
    char *sentence = (char *) calloc(READLINE_BUFFER, sizeof(char));
    int aux; 
    char *aux_tabu;

    do{
        aux = readword(stdin, &new_word);
        aux_tabu = strstr(new_word, tabu);
        if(aux_tabu == NULL){
            strcat(sentence,new_word);
            strcat(sentence, " ");
        }
        else{
            strcat(sentence,new_word);
            strcat(sentence, " ");
        }
    }while(!feof(stdin));

    printf("sentence: %s\n",sentence);

    return;
}

int main(int argc, char *argv[]){

    //lendo palavra tabu e frase
    char *tabu;
    readword(stdin, &tabu);
    printf("tabu: %s\n",tabu);
    char *string;
    readword(stdin, &string);
    myStrcat(tabu, &string);

    free(tabu);
    free(string);

    return 0;
}
