#include <stdio.h>
#include <stdlib.h>

//Structs usadas para a pilha encadeada
typedef struct node_{
    double val;
    struct node_ *next;
    struct node_ *prev;
}Node;

typedef struct stack_{
    Node *first;
    Node *last;
    int n_elem;
}Stack;

//Inicializa pilha
Stack* CreateStack(){
    Stack *stack = (Stack *) malloc(sizeof(Stack)); 
    
    stack->first = NULL; 
    stack->last = stack->first; 

    stack->n_elem = 0; 

    return stack;
}

//Checa se pilha está vazia
int IsEmptyStack(Stack *stack){
    if (stack->n_elem == 0) return 1;
    else return 0;
}

//Adiciona elemento após o último
int StackAddElem(Stack *stack, double e){
    Node *aux_node = (Node *) malloc(sizeof(Node));
    if (aux_node == NULL) return 1;

    if (IsEmptyStack(stack)){
        stack->first = aux_node;
        stack->first->prev = NULL;
    }
    else {
        stack->last->next = aux_node; 
        aux_node->prev = stack->last;
    }

    stack->last = aux_node;

    stack->last->val = e;
    stack->last->next = NULL;

    stack->n_elem++;

    return 0;
}

//Retira último elemento
int Pop(Stack *stack, double *e){

    if(IsEmptyStack(stack)) return 1;

    *e = stack->last->val;
    
    Node *aux_node = stack->last->prev;

    if (aux_node != NULL)
        aux_node->next = NULL; 

    free(stack->last);
    stack->last = aux_node;

    stack->n_elem--;

    return 0;
}

//Imprime a pilha
int PrintStack(Stack *stack){

    if(IsEmptyStack(stack)) return 1;

    Node *aux_node = stack->first;

    printf("Resultado: ");

    while(aux_node!=NULL){
        printf("%lf\n",aux_node->val);
        aux_node = aux_node->next;
    }

    return 0;
}

//Libera memória de stack
int FreeStack(Stack *stack){

    if(IsEmptyStack(stack)) return 1;

    double e;
    while(stack->last != NULL)
        Pop(stack, &e);

    free(stack);

    return 0;
}

//Lê de stream até encontrar ' '
#define READLINE_BUFFER 4096
char *readword(FILE *stream){
    char *string = 0;
    int pos = 0; 

	do{
        if (pos % READLINE_BUFFER == 0) {
            string = (char *) realloc(string, (pos / READLINE_BUFFER + 1) * READLINE_BUFFER);
        }
        string[pos] = (char) fgetc(stream);

    }while(string[pos++] != ' ' && string[pos-1] != '\n' && string[pos-1] != '$' && string[pos-1] != '\r' && !feof(stream));

    string[pos-1] = 0;
    string = (char *) realloc(string, pos);

    return string;
}

//Funções para as operações matemáticas
double Sum(Stack *stack){

    double n1, n2, res;

    Pop(stack, &n2);
    Pop(stack, &n1);

    res = n1 + n2;

    return res;
}

double Sub(Stack *stack){

    double n1, n2, res;

    Pop(stack, &n2);
    Pop(stack, &n1);

    res = n1 - n2;

    return res;
}

double Div(Stack *stack){

    double n1, n2, res;

    Pop(stack, &n2);
    Pop(stack, &n1);

    res = n1 / n2;

    return res;
}

double Mult(Stack *stack){

    double n1, n2, res;

    Pop(stack, &n2);
    Pop(stack, &n1);

    res = n1 * n2;

    return res;
}

int main(int argc, char *argv[]){
    
    /*PRESSUPOSTOS:
     *  -> apenas os caracteres de operação e os números serão digitados
     *  -> uma operação nunca será digitada sem haver no mínimo dois números antes na pilha
     *  -> as operações sempre serão finalizadas, deixando apenas um elemento na pilha ao final
    */

    double num;
    Stack *stack = CreateStack();

    char *aux_end;
    char *input;
    do{
        input = readword(stdin);
        if (input != NULL){

            switch(input[0]){
                case '+':
                    num = Sum(stack);
                    break;

                case '-':
                    num = Sub(stack);
                    break;

                case '/':
                    num = Div(stack);
                    break;

                case '*':
                    num = Mult(stack);
                    break;

                default:
                    num = strtod(input, &aux_end);
                    break;
            }

            //adicionando elemento à stack
            StackAddElem(stack, num);
        }
        free(input);
    }while(!feof(stdin));

    //imprime a pilha contendo o resultado final
    PrintStack(stack);

    FreeStack(stack);

    return 0;
}
