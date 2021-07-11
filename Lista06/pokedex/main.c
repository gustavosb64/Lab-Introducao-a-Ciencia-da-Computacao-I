#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//definindo estruturas
typedef struct move_{
    char *name;
    int power;
    float accuracy;
    char category;
}Move;

typedef struct stats_{
    int HP;
    int atk;
    int def;
    int spAtk;
    int spDef;
    int speed;
}Stats; 

typedef struct pokemon_{
    char *name;
    char *type1;
    char *type2;
    Stats stats;
    Move *moves;
}Pokemon;

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

//cadastra um Pokémon
void command1(Pokemon *pokemon){

    pokemon->moves = (Move *) calloc(4, sizeof(Move));

    pokemon->name = readline(stdin);
    pokemon->type1 = readline(stdin);
    pokemon->type2 = readline(stdin);
    scanf(" %d", &pokemon->stats.HP);
    scanf(" %d", &pokemon->stats.atk);
    scanf(" %d", &pokemon->stats.def);
    scanf(" %d", &pokemon->stats.spAtk);
    scanf(" %d", &pokemon->stats.spDef);
    scanf(" %d", &pokemon->stats.speed);

    return;
}

//Adiciona um move a um pokémon
void command2(Pokemon *pokedex){

    int idx_pok, idx_move;
    scanf(" %d",&idx_pok);
    scanf(" %d",&idx_move);
    getc(stdin);

    pokedex[idx_pok].moves[idx_move].name = readline(stdin);
    scanf(" %d",&pokedex[idx_pok].moves[idx_move].power);
    scanf(" %f",&pokedex[idx_pok].moves[idx_move].accuracy);
    scanf(" %c",&pokedex[idx_pok].moves[idx_move].category);

    return;
}

void command3(Pokemon *pokedex){

    int idx_pok;
    scanf(" %d",&idx_pok);

    printf("Nome do Pokemon: %s\n", pokedex[idx_pok].name);
    printf("Tipo primario: %s\n", pokedex[idx_pok].type1);
    printf("Tipo secundario: %s\n", pokedex[idx_pok].type2);
    printf("Status:\n");
    printf("\tHP: %d\n", pokedex[idx_pok].stats.HP);
    printf("\tAtaque: %d\n", pokedex[idx_pok].stats.atk);
    printf("\tDefesa: %d\n", pokedex[idx_pok].stats.def);
    printf("\tAtaque Especial: %d\n", pokedex[idx_pok].stats.spAtk);
    printf("\tDefesa Especial: %d\n", pokedex[idx_pok].stats.spDef);
    printf("\tVelocidade: %d\n\n", pokedex[idx_pok].stats.speed);

    return;
}

void command4(Pokemon *pokedex){

    int idx_pok, idx_move;
    scanf(" %d",&idx_pok);
    scanf(" %d",&idx_move);
    getc(stdin);

    printf("Nome do Ataque: %s\n", pokedex[idx_pok].moves[idx_move].name);
    printf("Poder base: %d\n", pokedex[idx_pok].moves[idx_move].power);
    printf("Acuracia: %f\n", pokedex[idx_pok].moves[idx_move].accuracy);
    printf("Classe: %c\n\n", pokedex[idx_pok].moves[idx_move].category);

    return;
}
int main(int argc, char *argv[]){

    Pokemon *pokedex = (Pokemon *) malloc(1 * sizeof(Pokemon));
    int n_pokemon = 0;

    int option;
    scanf(" %d ",&option);

    while (option != 0){

        switch(option){
            case 1:
                command1(&pokedex[n_pokemon]);
                n_pokemon++;
                pokedex = (Pokemon *) realloc(pokedex, (n_pokemon+1) * sizeof(Pokemon));
                break;

            case 2:
                command2(pokedex);
                break;

            case 3:
                command3(pokedex);
                break;

            case 4:
                command4(pokedex);
                break;
        }

        scanf(" %d",&option);
        getc(stdin);
    }

    //liberando memória
    for(int i=0; i<n_pokemon; i++){
        free(pokedex[i].name);
        free(pokedex[i].type1);
        free(pokedex[i].type2);
        for (int j=0; j<4; j++)
            free(pokedex[i].moves[j].name);
        free(pokedex[i].moves);
    }
    free(pokedex);

    return 0;
}
