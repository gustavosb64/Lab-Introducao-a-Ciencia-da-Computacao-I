#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct para o estudante
typedef struct student_{
    long long int id;
    char *name;
    char *course;
    int age;
}Student;

#define BUFFER 4096
char *readline(FILE *stream) {
    char *string = 0;
    int pos = 0; 

	do{
        if (pos % BUFFER == 0) {
            string = (char *) realloc(string, (pos / BUFFER + 1) * BUFFER);
        }
        string[pos] = (char) fgetc(stream);

    }while(string[pos++] != '\n' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

void printStudentData(Student student){
    
    printf("Nome: %s\n",student.name);
    printf("Curso: %s\n",student.course);
    printf("N USP: %lld\n",student.id);
    printf("IDADE: %d\n",student.age);

    printf("\n");
    return;
}

void operacao1(Student *students, long long int id, int counter){

    int i = 0;
    do{
        if(students[i].id == id){
            printStudentData(students[i]);
            return;
        }
        i++;
    }while(i < counter);

    return;
}

void operacao2(Student *students, char *course, int counter){

    int i = 0;
    do{
        if(!strcmp(students[i].course, course)){
            printStudentData(students[i]);
        }
        i++;
    }while(i < counter);

    return;
}

void operacao3(Student *students, int counter){

    int i = 0;
    do{
        printStudentData(students[i]);
        i++;
    }while(i < counter);

    return;
}

int main (int argc, char *argv[]){

    Student *students = NULL;

    //lendo dados de estudantes
    int counter = 0; 
    long long int aux_id;
    scanf(" %lld ",&aux_id);
    while(aux_id != -1){

        if ( (counter % BUFFER) == 0 ){
            students = (Student *) realloc(students, ((counter/BUFFER) + 1) * BUFFER);
        }

        students[counter].id = aux_id;
        students[counter].name = readline(stdin);
        students[counter].course = readline(stdin);
        scanf(" %d ",&students[counter].age);

        counter++;
        scanf(" %lld ",&aux_id);
    }
    students = (Student *) realloc(students, counter * BUFFER);

    //lendo opções de operações e as realizando
    int option;
    char *aux_course;
    scanf(" %d",&option);
    while (option != -1){

        switch (option){
            case 1:
                scanf(" %lld ",&aux_id);
                operacao1(students, aux_id, counter); 
                break;

            case 2:
                aux_course = readline(stdin);
                operacao2(students, aux_course, counter); 
                free(aux_course);
                break;

            case 3:
                operacao3(students, counter);
                break;
        }

        scanf(" %d",&option);
    }

    //liberando memória
    for (int i=0; i<counter; i++){
        free(students[i].name);
        free(students[i].course);
    }
    free(students);

    return 0;
}
