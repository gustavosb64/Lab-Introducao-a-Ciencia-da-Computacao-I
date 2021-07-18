#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096
char* readword(FILE *stream){
    char *new_string = 0; 
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            new_string = (char *) realloc(new_string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        new_string[pos] = (char) fgetc(stream);

    }while(new_string[pos++] != '\n' && new_string[pos-1] != '$' && new_string[pos-1] != '\r' && !feof(stream));

    new_string[pos-1] = 0;
    new_string = (char *) realloc(new_string, pos);

    return new_string;
}

//função para printar frase final
void Print(char *tabu, char *string){

    char *new_string = (char *) calloc(READLINE_BUFFER, sizeof(char));

    //ptr recebe um ponteiro para a primeira ocorrência de tabu
    char *ptr = strstr(string, tabu);

    int control = 0;
    int counter = 0;
    while (ptr != NULL){
        counter++;
        
        //delimita a string até a ocorrência de tabu
        ptr[0] = 0;

        //caso não haja memória suficiente para a concatenação, realocar
        if (strlen(new_string) < strlen(new_string) + strlen(string))
            new_string = (char *) realloc(new_string, strlen(new_string) + READLINE_BUFFER);

        //concatena string com novo delimitador em new_string
        strcat(new_string, string);

        //reposiciona o início da string após a ocorrência de tabu
        control = strlen(string) + strlen(tabu);
        string += control;

        ptr = strstr(string, tabu);
    }
    strcat(new_string, string);

    printf("A palavra tabu foi encontrada %d vezes\n", counter);
    printf("Frase: %s",new_string);

    free(new_string);

    return;
}

int main(int argc, char *argv[]){

    //lê palavra tabu e frase
    char *tabu, *string;
    tabu = readword(stdin);
    string = readword(stdin);

    Print(tabu, string);

    free(tabu);
    free(string);

    return 0;
}
