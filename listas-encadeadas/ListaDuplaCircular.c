#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *before;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof (struct node));
    if(!p){
        printf("\n");
        printf("Erro de memoria");
        printf("\n");
    }
    return p;
}

NODEPTR inserir(NODEPTR cabeca){
    NODEPTR newnode, atual, aux;

    newnode = getnode();
    if(!newnode) return cabeca;

    newnode->before = NULL;
    newnode->next = NULL;

    printf("Digite o valor: ");
    scanf("%d", &newnode->info);

    if(!cabeca){
        printf("\n");
        printf("Insercao bem sucedida.");
        printf("\n");
        return newnode;
    }

    if(newnode->info < cabeca->info){
        newnode->next = cabeca;
        cabeca->before = newnode;
        printf("\n");
        printf("Insercao bem sucedida.");
        printf("\n");
        return newnode;
    }

    atual = cabeca;
    aux = NULL;
    while(atual && newnode->info > atual->info){
        aux = atual;
        atual = atual->next;
    }

    if(!atual){
        newnode->next = NULL;
        newnode->before = aux;
        aux->next = newnode;
        printf("\n");
        printf("Insercao bem sucedida.");
        printf("\n");
        return cabeca;
    }
    
    newnode->next = atual;
    newnode->before = aux;
    atual->before = newnode;
    aux->next = newnode;
    
    printf("\n");
    printf("Insercao bem sucedida.");
    printf("\n");
    return cabeca;
}

NODEPTR remover(NODEPTR cabeca){
    NODEPTR atual, aux;

    if(!cabeca){
        printf("\n");
        printf("Lista vazia.");
        printf("\n");
        return cabeca;
    }

    int valor;
    printf("Digite o valor a ser removido: ");
    scanf("%d", &valor);

    if(cabeca->info == valor){
        if(!cabeca->next){
            free(cabeca);
            printf("\n");
            printf("Removido com sucesso.");
            printf("\n");
            return NULL;
        }
        atual = cabeca->next;
        cabeca->next->before = NULL;
        free(cabeca);
        printf("\n");
        printf("Removido com sucesso.");
        printf("\n");
        return atual;
    }

    atual = cabeca;
    aux = NULL;
    while(atual && atual->info != valor){
        aux = atual;
        atual = atual->next;
    }

    if(!atual){
        printf("\n");
        printf("Valor nao encontrado na lista");
        printf("\n");
        return cabeca;
    }

    if(!atual->next){
            aux->next = NULL;
            free(atual);
            printf("\n");
            printf("Removido com sucesso.");
            printf("\n");
            return cabeca;
        }

        atual->next->before = atual->before;
        aux->next = atual->next;
        free(atual);
        printf("\n");
        printf("Removido com sucesso.");
        printf("\n");
        return cabeca;
}

void listar(NODEPTR cabeca){
    NODEPTR aux;

    if(!cabeca){
        printf("\n");
        printf("Lista vazia");
        printf("\n");
        return;
    }

    aux = cabeca;
    printf("\n");
    while(aux){
        printf("%d ",aux->info);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    NODEPTR cabeca = NULL;
    int exit = 0;
    int whichCase;
    do{
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
                printf("Listando...\n");
                listar(cabeca);
                printf("\n");
                break;
            case 4:
                printf("\n");
                printf("Saindo...");
                printf("\n");
                exit = 1;
                break;
            default:
                printf("\n");
                printf("Opcao invalida.");
                printf("\n");
        }
    } while (!exit);
    
    return 0;
}