#include <stdio.h>
#include <stdlib.h>

/*First called function checks whether the game might still be running
*/
int check_hor(char **m, int *check_run){
    for (int i=0; i<3; i++){
        if (m[i][0] == '-' || m[i][1] == '-' || m[i][2] == '-') *check_run = 1;
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2]){
            return m[i][0];
        }
    }
    return 0;
}

int check_ver(char **m){
    for (int i=0; i<3; i++){
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i]) return m[0][i];
    }
    return 0;
}

int check_diag(char **m){
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2]) return m[0][0];
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0]) return m[0][2];
    return 0;
}

int main(int argc, char *argv[]){
    char **mat = (char **) calloc (3, sizeof(char*));

    for (int i=0; i<3; i++){
        mat[i] = (char *) calloc (3, sizeof(char));
        for (int j=0; j<3; j++) scanf(" %c", &mat[i][j]);
    }

    int check_run = 0; //checks whether there are empty slots or not
    char c; 

    c = check_hor(mat, &check_run);
    if (c > 0 && c != '-' ){
        printf("%c ganhou", c);
        return 0;
    }

    c = check_ver(mat);
    if (c > 0 && c != '-' ){
        printf("%c ganhou", c);        
        return 0;
    }

    c = check_diag(mat);
    if (c > 0 && c != '-' ){
        printf("%c ganhou", c);        
        return 0;
    }
    
    (check_run == 1) ? printf("em jogo") : printf("empate");

    return 0;
}
