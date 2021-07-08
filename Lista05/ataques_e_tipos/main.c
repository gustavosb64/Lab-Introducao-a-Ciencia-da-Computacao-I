#include <stdio.h>
#include <stdlib.h>

typedef struct move_{
    int power;
    int type;
}Move;

int main(int argc, char *argv[]){

    //dimensão da matriz de tipos
    int dim;
    scanf(" %d",&dim);

    //lendo matriz de tipos
    float **M_type = (float **) malloc(dim * sizeof(int*));
    for (int i=0; i<dim; i++){
        M_type[i] = (float *) malloc(dim * sizeof(int));
        for (int j=0; j<dim; j++){
            scanf(" %f", &M_type[i][j]);
        }
    }

    //lendo e armazenando os ataques (moves);
    int n_moves = 0;
    Move *moves = 0;

    int aux_power, aux_type;

    scanf("%d", &aux_power);
    while(aux_power != -1){

        scanf("%d", &aux_type);

        moves = (Move *) realloc(moves, (n_moves+1)*sizeof(Move));
        moves[n_moves].power = aux_power;
        moves[n_moves].type = aux_type;

        n_moves++;

        scanf("%d", &aux_power);
    }

    //lendo o tipo do inimigo
    int enemy_type;
    scanf(" %d", &enemy_type);

    //cálculo do melhor ataque
    int best_move_idx;
    double best_damage = 0.0;

    double damage;
    for (int i=0; i < n_moves; i++){
        damage = moves[i].power *  M_type[moves[i].type][enemy_type];
        if (damage > best_damage){
            best_damage = damage;
            best_move_idx = i;
        }
    }
    printf("O melhor ataque possui indice %d e dano %.2lf\n", best_move_idx, best_damage);

    //liberando memória
    for (int i=0; i<dim; i++)
        free(M_type[i]);
    free(M_type);
    free(moves);

    return 0;
}
