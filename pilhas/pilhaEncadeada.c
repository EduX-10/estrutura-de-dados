#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node* next;
};
typedef struct node* NODEPTR;

NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof (struct node));
    if(!p){
        printf("Nao ha memoria disponível.\n");
    }
    return p;
}

NODEPTR push(NODEPTR q){
    NODEPTR newnode;
    newnode = getnode();
    if(!newnode) return q;

    printf("Digite o valor que deseja inserir na pilha: ");
    scanf("%d", &newnode->value);

    newnode->next = q;
    printf("Inserido com sucesso!\n");
    return newnode;
}

NODEPTR pop(NODEPTR q){
    NODEPTR aux;
    if(!q){
        printf("Lista vazia.\n");
        return q;
    }

    aux = q->next;
    printf("Removido com sucesso!\n");
    free(q);
    return aux;
}

void list(NODEPTR q){
    NODEPTR aux;
    
    if(!q){
        printf("Lista vazia.\n");
        return;
    }
     
    aux = q;
    while(aux){
        printf("%d ", aux->value);
        aux = aux->next;
    }
}

void menu(){
    printf("\n");
    printf("O que deseja fazer na sua pilha?\n");
    printf("1 - Inserir um elemento;\n");
    printf("2 - Remover um elemento;\n");
    printf("3 - Listar;\n");
    printf("4 - Sair.\n");
}

int main(){
    NODEPTR topo = NULL;

    int condSaida = 0;
    while(!condSaida){
        menu();
        int whichCase;
        scanf("%d", &whichCase);
        switch(whichCase){
            case 1:
                printf("\n");
                topo = push(topo);
                break;
            case 2:
                printf("\n");
                topo = pop(topo);
                break;
            case 3:
                printf("\n");
                list(topo);
                break;
            case 4:
                printf("Saindo...\n");
                condSaida = 1;
                break;
            default: 
                printf("\n");
                printf("Valor invalido.\n");
        }
    }
    return 0;
}