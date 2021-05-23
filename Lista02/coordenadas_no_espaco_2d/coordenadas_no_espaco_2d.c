#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char c;
    int x = 0, y = 0;

    /*tabela ascii:
     * A = 65; D = 68; W = 87; S = 83
    */
    scanf("%c", &c);
    while(!feof(stdin)){
        switch(c){
            case (68):
                x++;
                break;
            case (65):
                x--;
                break;
            case (87):
                y++;
                break;
            case (83):
                y--;
                break;
            default:
                break;
        }
        scanf("%c", &c);
    }

    printf("%d %d",x,y);

    return 0;
}
