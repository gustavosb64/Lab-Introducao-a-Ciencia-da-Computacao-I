#include <stdio.h>
#include <stdlib.h>

#define VER_SIZE 32
#define HOR_SIZE 65

void print_belt(char **M){
    for (int i=0; i<VER_SIZE; i++){
        for (int j=0; j<HOR_SIZE; j++){
            printf("%c",M[i][j]);
        }
    }
    return;
}

int belt(char **M, int *cur_i, int *cur_j, char pre_value){
    int check = 1;
    char cur_char;

    if (M[*cur_i][*cur_j] == '#'){
        cur_char = pre_value;
        check = 0;
    }
    else cur_char = M[*cur_i][*cur_j];

    if (cur_char == '>'){
        if (check) M[*cur_i][*cur_j] = '.';
        *cur_j = *cur_j + 2;
        return cur_char;
    }  
    
    if (cur_char == 'v'){
        if (check) M[*cur_i][*cur_j] = '.';
        *cur_i = *cur_i + 1;
        return cur_char;
    }  

    if (cur_char == '^'){
        if (check) M[*cur_i][*cur_j] = '.';
        *cur_i = *cur_i - 1;
        return cur_char;
    }  

    if (cur_char == '<'){
        if (check) M[*cur_i][*cur_j] = '.';
        *cur_j = *cur_j - 2;
        return cur_char;
    }  

    if (cur_char == '.'){
        return -2;
    }

    if (cur_char == ']'){
        return -1;
    }

    return -3;
}

int main(int argc, char *argv[]){

    char **M = (char **) calloc(VER_SIZE, sizeof(char*));
    for(int i=0; i<VER_SIZE; i++) M[i] = (char *) calloc(HOR_SIZE, sizeof(char));

    int start_i, start_j;
    for (int i=0; i<VER_SIZE; i++){
        for (int j=0; j<HOR_SIZE; j++){
            scanf("%c", &M[i][j]);
            if (M[i][j] == '['){
                start_i = i;
                start_j = j;
            }
        }
    }

    int cur_i = start_i; 
    int cur_j = start_j+2; //1 element after start
    char cur_char = M[cur_i][cur_j];
    char pre_value = cur_char;
    while(cur_char != ']' && pre_value != -1){
        cur_char = belt(M, &cur_i, &cur_j, pre_value);
        pre_value = cur_char;
        if (pre_value == -2){
            printf("Loop infinito.\n");
            print_belt(M);
            return 0;
        }
        if (pre_value == -3){
            printf("Falha na esteira.\n");
            print_belt(M);
            return 0;
        }
    }

    printf("Ok.\n");
    print_belt(M);

    return 0;
}
