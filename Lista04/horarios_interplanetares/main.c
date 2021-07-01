#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define READLINE_BUFFER 4096

char *readline(FILE *stream) {
    char *string = 0;
    int pos = 0; 

    do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }

        string[pos] = (char) fgetc(stream);
    }while(string[pos++] != '\n' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

/*
 * O dia em Vênus equivale a 243 dias terrestres.
 * O dia em Mercúrio equivale a 58 dias e 16 horas terrestes.
 * O dia em Júpiter equivale a 9 horas e 56 minutos terrestres.
*/

void converter(char *planet_name, long long unsigned time, long long unsigned *days, long long unsigned *hours, long long unsigned *min, long long unsigned *sec){

    //armazena a conversão em dias
    int c_day_hour = 0;

    //utilizada para adicionar horas ou minutos às contas quando necessário
    int incr_days = 0;
    
    if(!strcmp(planet_name, "Terra")){
        c_day_hour = 24;
    }
    if(!strcmp(planet_name, "Venus")){
        c_day_hour = 243 * 24;
    }
    if(!strcmp(planet_name, "Mercurio")){
        c_day_hour = 58 * 24;
        incr_days = 16 * 60 * 60;
    }
    if(!strcmp(planet_name, "Jupiter")){
        c_day_hour = 9;
        incr_days = 56 * 60;
    }

    *days = time/(c_day_hour*60*60 + incr_days); 
    time %= (c_day_hour*60*60 + incr_days);

    *hours = time/((60*60)); 
    time %= ((60*60));

    *min = time/60; 
    time %= 60;

    *sec = time;

    return;
}

int main(int argc, char *argv[]){
    long long unsigned time; 
    char *planet;

    scanf(" %llu",&time);
    getc(stdin); //pega caractere de espaço em branco remanescente no stdin
    planet = readline(stdin);

    long long unsigned days, hours, min, sec;

    converter(planet, time, &days, &hours, &min, &sec);

    printf("%llu segundos no planeta %s equivalem a:\n", time, planet);
    printf("%llu dias, %llu horas, %llu minutos e %llu segundos\n", days, hours, min, sec);

    free(planet);

    return 0;
}
