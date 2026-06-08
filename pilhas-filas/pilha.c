/*Uma Pilha é uma estrutura de dados em que o último elemento adicionado é o primeiro a ser removido, ou seja, o último elemen-
to é sempre removido.*/

#include <stdio.h>

#define MAX 5

int push(int pilha[], int tamPilha){
    if(tamPilha == MAX){
        printf("Pilha cheia!");
        printf("\n");
        return tamPilha;
    }

    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    pilha[tamPilha] = valor;
    tamPilha++;
    return tamPilha;
}

int pop(int pilha[], int tamPilha){
    if(tamPilha == 0){
        printf("Pilha vazia!");
        printf("\n");
        return tamPilha;
    }

    printf("Removido com sucesso!");
    tamPilha--;
    return tamPilha;
}

void list(int pilha[], int tamPilha){
    if(tamPilha == 0){
        printf("Pilha vazia!");
        printf("\n");
        return;
    } 
    
    for(int i = tamPilha-1; i >= 0; i--){
        printf("%d ", pilha[i]);
    }
}

int main(){
    int pilha[MAX];
    int tamPilha = 0;

    while(1){
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar um item;\n");
        printf("2 - Remover um item;\n");
        printf("3 - Listar itens;\n");
        printf("4 - Sair\n");
        int caso;
        scanf("%d", &caso);

        switch (caso){
        case 1:
            printf("\n");
            tamPilha = push(pilha, tamPilha);
            break;
        case 2:
            printf("\n");
            tamPilha = pop(pilha, tamPilha);
            break;
            case 3:
            printf("\n");
            list(pilha, tamPilha);
            break;
        case 4:
            printf("\n");
            printf("Saindo...");
            return 0;
        default:
            printf("\n");
            printf("Opcao invalida.");
            break;
        }
    }
    return 0;
}