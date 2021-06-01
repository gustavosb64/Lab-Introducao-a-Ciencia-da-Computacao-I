#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/*This function reads a file and writes down its contents in ascii code
*/
int main(int argc, char *argv[]){
    char *filename = (char *) calloc(4096, sizeof(char));
    scanf(" %[^\r\n]",filename);

    FILE *file = fopen(filename,"r");

    char c;
    do{
        fread(&c, sizeof(char), 1, file);
        printf("%d ",c); 
    }while(!feof(file));

    return 0;
}
