#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR getnode(){
    NODEPTR p;
    p = (NODEPTR) malloc(sizeof (struct node));
    if(!p){
        printf("Nao foi possivel criar o no");
    }
    return p;
}

NODEPTR inserir(NODEPTR cabeca){
    NODEPTR newnode, atual, before;
    atual = cabeca;

    newnode = getnode();
    if(!newnode) return cabeca;
 
    printf("Digite o valor: ");
    scanf("%d", &newnode->info);

    newnode->next = NULL;

    if(!atual){
        printf("Insercao finalizada!");
        return newnode;
    }
    if(newnode->info < atual->info){
        printf("Insercao finalizada!");
        newnode->next = atual;
        while(atual->next != cabeca){
            atual = atual->next;
        }
        atual->next = newnode;
        return newnode;
    }

    before = cabeca;
    do{
        before = atual;
        atual = atual->next;
    }while(atual != cabeca && newnode->info > atual->info);

    before->next = newnode;
    newnode->next = atual;

    printf("Insercao finalizada!");
    return cabeca;
}

NODEPTR remover(NODEPTR cabeca){
    NODEPTR atual, anterior;
    atual = cabeca;
    
    if(!cabeca){
        printf("Nao ha itens para remover.");
        return cabeca;
    }

    int valor;
    printf("Digite o valor que deseja remover: ");
    scanf("%d", &valor);

    if(cabeca->info == valor){
        atual = cabeca->next;
        free(cabeca);
        printf("Remocao bem sucedida");
        return atual;
    }

    anterior = NULL;
    while(atual && atual->info != valor){
        anterior = atual;
        atual = atual->next;
    }

    if(!atual){
        printf("Valor nao encontrado.");
        return cabeca;
    }
    
    anterior->next = atual->next;
    free(atual);

    printf("Remocao bem sucedida");
    return cabeca;
}

void listar(NODEPTR atual){
    if(!atual){
        printf("A lista esta vazia.");
        return;
    }
    while(atual){
        printf("%d ", atual->info);
        atual = atual->next;
    }
}

int main(){
    NODEPTR cabeca = NULL;
    int condSaida = 0;
    do{
        printf("O que deseja fazer?\n");
        printf("(1) Inserir\n");
        printf("(2) Remover\n");
        printf("(3) Listar\n");
        printf("(4) Sair\n");
        int control;
        scanf("%d", &control);
        switch(control){
            case 1:
                printf("\n");
                cabeca = inserir(cabeca);
                printf("\n\n");
                break;
            case 2:
                printf("\n");
                cabeca = remover(cabeca);
                printf("\n\n");
                break;
            case 3:
                printf("\n");
                printf("Listando...\n");
                listar(cabeca);
                printf("\n\n");
                break;
            case 4:
                condSaida = 1;
                printf("\n");
                printf("Saindo...");
                printf("\n\n");
                break;
            default:
                printf("\n");
                printf("Opcao invalida!");
                printf("\n\n");
        }
    }while(!condSaida);
    return 0;
}