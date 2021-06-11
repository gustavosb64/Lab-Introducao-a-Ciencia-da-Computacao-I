#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READLINE_BUFFER 4096

char *readline(FILE *stream, int *n_char) {
    char *string = 0;
    int pos = 0;

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);
        (*n_char)++;
    }while(string[pos++] != '\n' && string[pos-1] == ' ' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    pos--;
    if (strlen(string) > 2 && string[pos-1] < 65){
        string[pos-1] = 0;
        string = (char *) realloc(string, pos);
    }

    return string;
}

char **getSpamList(){

    FILE *file_spam = fopen("file_spamlist.txt","r");
    if(file_spam == NULL){
        printf("File does not exist\n");
        exit(0);
    }

    int aux_count = 0;
    char **spam_list = (char **) calloc(12, sizeof(char*));
    for (int i=0; i<12; i++){
        spam_list[i] = readline(file_spam, &aux_count);
    }

    fclose(file_spam);
    return spam_list;
}

int main(int argc, char *argv[]){
    int n_char = 0;

    char **spam_list = getSpamList();

    char *string;
    while(n_char <= 76 && !feof(stdin)){

        string = readline(stdin, &n_char);
        //printf("n_char: %d\n",n_char);

        if (n_char > 76){
            printf("charSpam\n");
            for (int i=0; i < 12; i++) free(spam_list[i]);
            free(spam_list);
            free(string);

            exit(0);
        }
     
        for(int i=0; i<12; i++){
            if (!strcmp(string, spam_list[i])){
                printf("listaSpam: %s\n");
                for (int i=0; i < 12; i++) free(spam_list[i]);
                free(spam_list);
                free(string);

                exit(0);
            }
        }
        n_char = 0;
        free(string);
    }
    
    printf("Inbox\n");

    return 0;
}
