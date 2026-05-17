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
        newnode->next = newnode;
        return newnode;
    }

    //Caso a inserção seja na cabeça
    if(newnode->info < ref->info){
        nav = ref;
        while(nav->next != ref){
            nav = nav->next;
        }
        newnode->next = ref;
        nav->next = newnode;

        printf("Insercao bem sucedida.\n");
        return newnode;
    }

    aux = ref;
    nav = ref->next;
    while(nav != ref && newnode->info > nav->info){
        aux = nav;
        nav = nav->next;
    }

    //Caso a inserção seja na cauda
    if(nav == ref){
        aux->next = newnode;
        newnode->next = ref;

        printf("Insercao bem sucedida.\n");
        return ref;
    }

    //Outros casos
    newnode->next = nav;
    aux->next = newnode;

    printf("Insercao bem sucedida.\n");
    return ref;
}

void list(NODEPTR ref){
    NODEPTR aux;

    if(!ref){
        printf("A lista esta vazia.\n");
        return;
    }

    printf("%d ", ref->info);
    aux = ref->next;
    while(aux != ref){
        printf("%d ", aux->info);
        aux = aux->next;
    }

}

NODEPTR remover(NODEPTR ref){
    NODEPTR aux, nav;

    //Caso a lista esteja vazia
    if(!ref){
        printf("A lista esta vazia.\n");
        return ref;
    }

    int value;
    printf("Digite o valor que deseja remover: ");
    scanf("%d", &value);

    if(ref->info == value){
        aux = ref->next;

        nav = ref;
        while(nav->next != ref){
            nav = nav->next;
        }
        nav->next = aux;

        free(ref);
        printf("Remocao bem sucedida.\n");
        return aux;
    }

    //Percorre a lista procurando o valor
    aux = ref;
    nav = ref->next;
    while(nav != ref && nav->info != value){
        aux = nav;
        nav = nav->next;
    }

    //Caso nao tenha encontrado
    if(nav == ref){
        printf("Valor nao encontrado.\n");
        return ref;
    }
    
    //Caso tenha encotrado
    aux->next = nav->next;
    free(nav);
    printf("Remocao bem sucedida.\n");

    return ref;
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