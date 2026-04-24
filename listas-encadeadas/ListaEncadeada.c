#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};
typedef struct node *NODEPTR;

NODEPTR getnode(){
    NODEPTR aux;
    aux = (NODEPTR) malloc(sizeof (struct node));
    if(aux == NULL){
        printf("Nao ha espaco disponivel.\n");
    }
    return(aux);
}

NODEPTR inserir(NODEPTR atual, int *tam){
    NODEPTR newnode, aux;

    newnode = getnode();

    if(newnode == NULL){
        return atual;
    }

    printf("Digite o valor: \n");
    scanf("%d", &newnode -> info);
    newnode -> next = NULL;

    if(atual == NULL){
        printf("Insercao finalizada!\n");
        (*tam)++;
        return(newnode);
    }else{
        aux = atual;
        while(atual->next != NULL){
            atual = atual->next;
        }
        atual->next = newnode;
        printf("Insercao finalizada!\n");
        (*tam)++;;
        return(aux);
    }    
}

NODEPTR inserirPorPosicao(NODEPTR atual, int *tam){
    NODEPTR newnode, aux, aux1; 
    
    newnode = getnode();
    if(!newnode) return atual;

    int pos;
    do{
        printf("Digite a posicao que deseja inserir: ");
        scanf("%d", &pos);
    }while(pos < 1 || pos > (*tam) + 1);
    printf("Digite um valor: ");
    scanf("%d", &newnode->info);

    if(pos == 1){
       newnode->next = atual;
       printf("Insercao finalizada!\n");
       (*tam)++;
       return(newnode);
    }

    aux = atual;
    for(int i = 1; i < pos-1; i++){
        atual = atual->next;
    }
    NODEPTR nextnode = atual->next;
    atual->next = newnode;
    newnode->next = nextnode;
    printf("Insercao finalizada!\n");
    (*tam)++;
    return (aux);
}

NODEPTR remover(NODEPTR atual){
    if(atual == NULL){
        printf("Nao ha itens para remover.\n");
        return atual;
    }

    printf("Digite o valor que deseja remover: ");
    int valor;
    scanf("%d", &valor);

    NODEPTR nav, aux;

    if(atual->info == valor){
        aux = atual->next;
        free(atual);
        printf("Remocao bem sucedida\n");
        return(aux);
    }

    nav = atual->next;
    aux = atual;

    while(nav != NULL){
        if(nav->info == valor){
            aux->next = nav->next;
            free(nav);
            printf("Remocao bem sucedida\n");
            return atual;
        }
        aux = nav;
        nav = nav->next;
    }

    printf("Valor não encontrado\n");
    return atual;
}

void listar(NODEPTR atual){
    if(atual == NULL){
        printf("Nao ha itens na lista.\n");
        printf("\n");
        return;
    }
    while(atual != NULL){
        printf("%d ", atual->info);
        atual = atual->next;
    }
    printf("\n");
}

int main(){
    NODEPTR cabeca = NULL;
    int condSaida = 0;
    int tam = 0;
    do{
        int whichCase;

        printf("O que deseja fazer?\n");
        printf("(1) Inserir\n");
        printf("(2) Inserir por posicao\n");
        printf("(3) Remover\n");
        printf("(4) Listar\n");
        printf("(5) Sair\n");

        scanf("%d", &whichCase);
        switch(whichCase){
            case 1:
                printf("\n");
                cabeca = inserir(cabeca, &tam);
                printf("\n");
                break;
            case 2:
                printf("\n");
                cabeca = inserirPorPosicao(cabeca, &tam);
                printf("\n");
                break;
            case 3:
                printf("\n");
                cabeca = remover(cabeca);
                printf("\n");
                break;
            case 4:
                printf("\n");
                printf("Listando todos os elementos...\n");
                printf("\n");
                listar(cabeca);
                break;
            case 5:
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