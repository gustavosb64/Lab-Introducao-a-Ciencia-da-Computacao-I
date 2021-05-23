#include <stdio.h>
#include <stdlib.h>

#define READLINE_BUFFER 4096

char *readline(FILE *stream);

int main(int argc, char *argv[]){
    char *string = readline(stdin);
    FILE *file = fopen(string, "rb");

    char l;
    while (!feof(file)){
        fread(&l, sizeof(char), 1, file);
        printf("%d ",l);
    }

    fclose(file);
    return 0;
}

char *readline(FILE *stream) {
    char *string = 0;
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);
    }while(string[pos++] != '\n' && string[pos-1] != ' ' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}
