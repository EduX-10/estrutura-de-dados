#include <stdio.h>
#include <stdlib.h>

struct node{

    int info;
    struct node* next;

};
typedef struct node* NODEPTR;

NODEPTR getnode(){

    NODEPTR newnode;
    newnode = (NODEPTR) malloc(sizeof (struct node));
    if(!newnode){
        printf("Espaco insuficiente\n");
    }

    return newnode;
}

NODEPTR insert(NODEPTR ref){
    NODEPTR newnode, aux, nav;

    //Gera um novo node e controla erros
    newnode = getnode();
    if(!newnode) return ref;

    newnode->next = NULL;

    printf("Digite o valor que deseja adicionar: ");
    scanf("%d", &newnode->info);

    //Caso a lista esteja vazia
    if(!ref) {
        printf("Insercao bem sucedida.\n");
        return newnode;
    }

    //Caso o valor inserido seja o menor
    if(newnode->info < ref->info){
        newnode->next = ref;
        printf("Insercao bem sucedida.\n");
        return newnode;
    }

    nav = ref;
    aux = NULL;
    while(nav && newnode->info > nav->info){
        aux = nav;
        nav = nav->next;
    }

    //Caso o valor inserido seja o maior
    if(!nav){
        aux->next = newnode;
        printf("Insercao bem sucedida.\n");
        return ref;
    }

    //Outros Casos
    aux->next = newnode;
    newnode->next = nav;

    printf("Insercao bem sucedida.\n");
    return ref;
}

void list(NODEPTR ref){

    if(!ref){
        printf("A lista esta vazia.\n");
        return;
    }

    while(ref){
        printf("%d ", ref->info);
        ref = ref->next;
    }

}

NODEPTR remover(NODEPTR ref){
    NODEPTR aux, cabeca;

    //Caso a lista esteja vazia
    if(!ref){
        printf("A lista esta vazia.\n");
        return ref;
    }

    int value;
    printf("Digite o valor que deseja remover");
    scanf("%d", &value);

    if(ref->info == value){
        aux = ref->next;
        free(ref);
        printf("Remocao bem sucedida.\n");
        return aux;
    }

    //Percorre a lista procurando o valor
    aux = NULL;
    cabeca = ref;
    while(ref && ref->info != value){
        aux = ref;
        ref = ref->next;
    }

    //Caso nao tenha encontrado
    if(!ref){
        printf("Valor nao encontrado.\n");
        return cabeca;
    }
    
    //Caso tenha encotrado
    aux->next = ref->next;
    free(ref);
    printf("Remocao bem sucedida.\n");

    return cabeca;
}

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