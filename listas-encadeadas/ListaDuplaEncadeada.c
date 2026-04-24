#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *before;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof (struct node));
    if(!p){
        printf("Nao ha memoria disponivel");
    }
    return(p);
}

NODEPTR inserir(NODEPTR atual){
    NODEPTR newnode, aux;

    newnode = getnode();
    if(!newnode) return atual;

    printf("Digite o valor do nó: ");
    scanf("%d", &newnode->info);
    newnode->next = NULL;

    if(!atual){
        newnode->before = NULL;
        printf("Insercao finalizada!\n");
        return (newnode);
    }else{
        aux = atual;
        while(atual->next){
            atual = atual->next;
        }
        atual->next = newnode;
        newnode->before = atual;
        
        return(aux);
    }

}

void listar(NODEPTR atual){
    if(!atual){
        printf("A lista esta vazia");
        printf("\n");
        return;
    }
    while(atual){
        printf("%d ", atual->info);
        atual = atual->next;
    }
    printf("\n");
}

NODEPTR remover(NODEPTR atual){
    if(!atual){
        printf("Nao ha itens para remover.");
        printf("\n");
        return (atual);
    }

    int valor;
    printf("Qual valor deseja remover?\n");
    scanf("%d", &valor);

    NODEPTR aux;
    if(atual->info == valor){
        aux = atual->next;
        NODEPTR nextnode = atual->next;
        if(nextnode){
            nextnode->before = NULL;
        }
        free(atual);
        printf("Remocao bem sucedida\n");
        return(aux);
    }

    aux = atual;
    while(atual){
        if(atual->info == valor && atual->next){
            NODEPTR nextnode = atual->next;
            NODEPTR prevnode = atual->before;
            nextnode->before = atual->before;
            prevnode->next = atual->next;
            free(atual);
            printf("Remocao bem sucedida\n");
            return(aux);
        }else if(atual->info == valor && !atual->next){
            NODEPTR prevnode = atual->before;
            prevnode->next = NULL;
            free(atual);
            printf("Remocao bem sucedida\n");
            return(aux);
        }
        atual = atual->next;
    }

    printf("\n");
    printf("Valor nao encontrado.");
    printf("\n");

    return(aux);
}

int main(){
    NODEPTR cabeca = NULL;
    int condSaida = 0;
    do{
        int whichCase;

        printf("O que deseja fazer?\n");
        printf("(1) Inserir\n");
        printf("(2) Remover\n");
        printf("(3) Listar\n");
        printf("(4) Sair\n");

        scanf("%d", &whichCase);
        switch(whichCase){
            case 1:
                printf("\n");
                cabeca = inserir(cabeca);
                printf("\n");
                break;
            case 2:
                printf("\n");
                cabeca = remover(cabeca);
                printf("\n");
                break;
            case 3:
                printf("\n");
                printf("Listando todos os elementos...\n");
                printf("\n");
                listar(cabeca);
                break;
            case 4:
                printf("\n");
                printf("Saindo...\n");
                printf("\n");
                condSaida = 1;
                break;
            default:
                printf("\n");
                printf("Opcao invalida. Por favor selecione uma opcao valida.\n");
                printf("\n");
                break;
        }
    }while(!condSaida);
    return 0;
}