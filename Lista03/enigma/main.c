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

int *SpinRotor(int *rotor){

    char first_c = rotor[0];
    for (int i=0; i < 25; i++){
        rotor[i] = rotor[i+1];
    }
    rotor[25] = first_c;

    return rotor;
}

void TranscribeMessage(FILE *stream, int **rotores, int *M) {
    unsigned char c;
    int check; 
    int inc;

    c = (char) fgetc(stream);
    do{
        check = IsLetter(c);

        if(check != 0){
            (check < 0) ? (inc = 97) : (inc = 65);
            c -= inc;
            for (int j=0; j<3; j++) c = rotores[j][c];
            c += inc;

            //Counting each spin
            M[0] += 1;
            rotores[0] = SpinRotor(rotores[0]);
            if (M[0] == 26){

                M[1] += 1;
                rotores[1] = SpinRotor(rotores[1]);
                
                if (M[1] == 26){
                    rotores[2] = SpinRotor(rotores[2]);
                    M[1] = 0;
                }

                M[0] = 0;
            }
        }

        printf("%c",c);
        c = (char) fgetc(stream);
    }while(!feof(stream));

    return;
}

int main(int argc, char *argv[]){
    int** rotores = (int **) malloc(3 * sizeof(int*));
    for (int i=0; i<3; i++) rotores[i] = (int *) malloc(26 * sizeof(int));

    //Read "Rotores:" and put in aux_string
    char *aux_string = readline(stdin);
    free(aux_string);

    for (int i=0; i<3; i++){
        for (int j=0; j<26; j++){
            scanf(" %d",&rotores[i][j]);
        }
    }

    //Read characters before message and put in aux_string
    for (int i=0; i<3; i++){
        aux_string = readline(stdin);
        free(aux_string);
    }

    //Counter for rotors
    int *M = (int *) malloc(2 * sizeof(int));
    M[0] = 0;
    M[1] = 0;

    do{
        TranscribeMessage(stdin, rotores, M);
    }while(!feof(stdin));


    for (int i=0; i<3; i++){
        free(rotores[i]);
    }
    free(rotores);
    free(M);
   
    return 0;
}
