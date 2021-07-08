#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

char *readline(FILE *stream, int *check) {
    char *string = 0;
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);

        if (string[pos] == '$') *check = 1;

    }while(string[pos++] != '\n' && string[pos-1] != '$' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

void myStrcat(char *src_string, char **dest_string){
    char *new_last_name = 0;
    int pos = 0;

    //lê até encontrar \0
    do{
        if (pos % READLINE_BUFFER == 0) {
            new_last_name = (char *) realloc(new_last_name, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        new_last_name[pos] = (char) src_string[pos];
    }while(new_last_name[pos++] != 0);

    new_last_name = (char *) realloc(new_last_name, pos);

    *dest_string = (char *) realloc(*dest_string, strlen(*dest_string)+pos);
    strcat(*dest_string, new_last_name);

    free(new_last_name);

    return;
}

int main(int argc, char *argv[]){
    char **names = (char **) malloc(sizeof(char*) * 1);
    names[0] = 0;
    int check = 0;
    int counter = 0;

    //lendo nomes
    while(!check){
        names[counter++] = readline(stdin, &check);
        names = (char **) realloc(names, (counter+1)*sizeof(char*));
    }

    //concatenando sobrenomes
    for (int i=0; i < counter; i+=2){
        char *aux = strrchr(names[i], ' '); 
        if ((i+1) < counter){
            myStrcat(aux, &names[i+1]);
        }
    }

    //imprimindo novos nomes
    for (int i=0; i<(counter); i++){
        printf("%s\n",names[i]);
    }

    //Liberando memória
    for (int i=0; i < counter; i++){
        free(names[i]);
    }
    free(names);

    return 0;
}
