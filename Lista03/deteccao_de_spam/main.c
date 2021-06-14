#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

char **getSpamList(){
    
    char **spam_list = (char **) calloc(12, sizeof(char*));
    for (int i=0; i < 12; i++) spam_list[i] = (char *) calloc(20, sizeof(char));
    strcpy(spam_list[0],"gratuito");
    strcpy(spam_list[1],"atencao");
    strcpy(spam_list[2],"urgente");
    strcpy(spam_list[3],"imediato");
    strcpy(spam_list[4],"zoombie");
    strcpy(spam_list[5],"oferta");
    strcpy(spam_list[6],"dinheiro");
    strcpy(spam_list[7],"renda");
    strcpy(spam_list[8],"fundo");
    strcpy(spam_list[9],"limitado");
    strcpy(spam_list[10],"ajuda");
    strcpy(spam_list[11],"SOS");

    return spam_list;
}

char *readword(FILE *stream, int *n_char, char **spam_list) {
    char *string = 0;
    int pos = 0;

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }

        string[pos] = (char) fgetc(stream);

        //checks whether line has more than 76 characters
        if (string[pos] == '\n'){
            if (*n_char > 76){
                printf("Spam\n");

                fclose(stream);
                free(string);
                for (int i=0; i<12; i++) free(spam_list[i]);
                free(spam_list);

                exit(0);
            }
           *n_char = 0;
        }
        else (*n_char)++;

    }while(string[pos++] != '\n' && string[pos-1] != ' ' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    //if last character isn't a letter, takes it off for futher comparison
    pos--;
    if (strlen(string) > 2 && string[pos-1] < 65){
        string[pos-1] = 0;
        string = (char *) realloc(string, pos);
    }

    //compares string to each word in spam_list
    for(int i=0; i<12; i++){
        if (!strcmp(string, spam_list[i])){
            printf("Spam\n");
            for (int i=0; i < 12; i++) free(spam_list[i]);
            free(spam_list);
            free(string);

            exit(0);
        }
    }

    return string;
}

int main(int argc, char *argv[]){
    int n_char = 0;

    char **spam_list = getSpamList();
    char *string;
    while(n_char <= 76 && !feof(stdin)){
        string = readword(stdin, &n_char, spam_list);
        free(string);
    }
    
    printf("Inbox\n");

    return 0;
}
