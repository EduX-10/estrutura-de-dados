#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node* next;
    struct node* before;
};
typedef struct node* NODEPTR;

int main(){
    NODEPTR cabeca = NULL;
    int condSaida = 0;
    while(!condSaida){
        int whichCase;
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar um item;\n");
        printf("2 - Remover um item;\n");
        printf("3 - Listar itens;\n");
        printf("4 - Sair\n");
        scanf("%d", &whichCase);

        switch(whichCase){
            case 1:
                printf("\n");
                cabeca = insert(cabeca);
                break;
            case 2:
                printf("\n");
                cabeca = remover(cabeca);
                break;
            case 3:
                printf("\n");
                list(cabeca);
                break;
            case 4:
                printf("\n");
                printf("Saindo...\n");
                condSaida = 1;
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }

    return 0;
}