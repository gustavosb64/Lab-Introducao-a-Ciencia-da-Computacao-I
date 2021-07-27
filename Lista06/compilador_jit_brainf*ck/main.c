#include<stdio.h>
#include<stdlib.h>

//escreve o cabeçalho do código no arquivo de output
void write_header(FILE *output){
    fprintf(output, "#include <stdio.h>\n\n");
    fprintf(output, "int main(int argc, char *argv[]) {\n");
    fprintf(output, "\tchar mem[30000];\n\n");
    fprintf(output, "\tfor (int i=0; i<30000; i++) {\n");
    fprintf(output, "\t\tmem[i]=0;\n");
    fprintf(output, "\t}\n\n");
    fprintf(output, "\tint i=0;\n\n");

    return;
}

//escreve o final do código no arquivo de output
void write_footer(FILE *output){
    fprintf(output, "\tprintf(\"\\n\");\n");
    fprintf(output, "\tfor (int j=0; j<30000; j++) {\n");
    fprintf(output, "\t\tif (mem[j] != 0) {\n");
    fprintf(output, "\t\t\tprintf(\"%%d \", mem[j]);\n");
    fprintf(output, "\t\t}\n");
    fprintf(output, "\t}\n");
    fprintf(output, "\tprintf(\"\\n\");\n");

    fprintf(output, "\n\treturn 0;\n");

    fprintf(output, "}\n");
    
    return;
}

//escreve a quantidade de \t necessária no arquivo de output
void write_tab(FILE *output, int tab_counter){

    for (int i=0; i<tab_counter; i++)
        fprintf(output,"\t");

    return;
}

//traduz a entrada para um arquivo de output
void write_transcription(FILE *output){
    
    char c;
    int tab_counter = 1;
    while(!feof(stdin)){
        c = (char) fgetc(stdin); 
        switch(c){
            case '+':
                write_tab(output, tab_counter);
                fprintf(output,"mem[i]++;\n");
                break;

            case '-':
                write_tab(output, tab_counter);
                fprintf(output,"mem[i]--;\n");
                break;

            case '.':
                write_tab(output, tab_counter);
                fprintf(output,"putchar(mem[i]);\n");
                break;
                
            case '>':
                write_tab(output, tab_counter);
                fprintf(output,"i++;\n");
                break;

            case '<':
                write_tab(output, tab_counter);
                fprintf(output,"i--;\n");
                break;

            case '[':
                write_tab(output, tab_counter);
                fprintf(output,"while (mem[i]) {\n");
                tab_counter++;
                break;

            case ']':
                tab_counter--;
                write_tab(output, tab_counter);
                fprintf(output,"}\n");
                break;
        }
    }

    return;
}

int main(int argc, char *argv[]){

    FILE *jit_file = fopen("jit-gerado.c","w+");

    write_header(jit_file);
    write_transcription(jit_file);
    fprintf(jit_file,"\n");
    write_footer(jit_file);

    fclose(jit_file);

    //comandos para compilar e rodar o código
    system("gcc jit-gerado.c -o jit-gerado");
    system("./jit-gerado");

    return 0;
}
