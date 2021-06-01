#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

void print_walk(char **M){
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<(SIZE*2)+1; j++){
            printf("%c",M[i][j]);
        }
    }
    return;
}

int walk(char **M, int *cur_i, int *cur_j, char pre_value){
    /*
    printf("cur_i: %d cur_j: %d ",*cur_i, *cur_j);
    printf("%c",M[*cur_i][*cur_j]);
    printf("%d %d\n",M[*cur_i][*cur_j], pre_value);
    */
    int check = 1;
    char cur_char;

    if (M[*cur_i][*cur_j] == '#'){
        cur_char = pre_value;
        check = 0;
//        printf("cur_char: %d\n",cur_char);
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
    char **M = (char **) calloc(SIZE, sizeof(char*));
    for(int i=0; i<SIZE; i++) M[i] = (char *) calloc((SIZE*2)+1, sizeof(char));

    int start_i, start_j;
    for (int i=0; i<SIZE; i++){
        for (int j=0; j<(SIZE*2)+1; j++){
            scanf("%c", &M[i][j]);
            if (M[i][j] == '['){
                start_i = i;
                start_j = j;
            }
        }
    }

    int cur_i = start_i; //1 element after start
    int cur_j = start_j+2;
    char cur_char = M[cur_i][cur_j];
    char pre_value = cur_char;
    while(cur_char != ']'){
//        printf("~cur_i: %d cur_j: %d \n",cur_i, cur_j);
        cur_char = walk(M, &cur_i, &cur_j, pre_value);
        pre_value = cur_char;
//        printf("cur_i:%d cur_j:%d cur_char:%d\n",cur_i,cur_j,cur_char);
        if (pre_value == -2){
            printf("Loop infinito.\n");
            print_walk(M);
            return 0;
        }
        if (pre_value == -3){
            printf("Falha na esteira.\n");
            print_walk(M);
            return 0;
        }
        if (pre_value == -1){
            printf("Ok.\n");
            print_walk(M);
            return 0;
        }
    }

    return 0;
}
