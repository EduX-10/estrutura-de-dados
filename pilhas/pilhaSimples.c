#include <stdio.h>

#define MAX 10

void menu(){
    printf("\n");
    printf("O que deseja fazer na sua pilha?\n");
    printf("1 - Inserir um elemento;\n");
    printf("2 - Remover um elemento;\n");
    printf("3 - Listar;\n");
    printf("4 - Sair.\n");
}

int push(int* q, int t){
    if(t >= MAX){
        printf("Lista cheia!\n");
        return t;
    }

    printf("Digite o valor a ser adicionado a pilha: ");
    scanf("%d", &q[t]);
    printf("Insercao finalizada.\n");
    t++;

    return t;
}

int pop(int* q, int t){
    if(t <= 0){
        printf("Lista vazia.\n");
        return t;
    }

    printf("Removendo...\n");
    t--;
    printf("Remocao finalizada.\n");

    return t;
}

void list(int* q, int t){
    int aux = 0;
    
    if(t <= 0){
        printf("Lista vazia.\n");
        return;
    }

    printf("Listando...\n");
    while(aux < t){
        printf("%d ", q[aux]);
        aux++;
    }

    return;
}

int main(){
    int topo = 0;
    int pilha[MAX];

    int condSaida = 0;
    while(!condSaida){
        menu();
        int whichCase;
        scanf("%d", &whichCase);
        switch(whichCase){
            case 1:
                printf("\n");
                topo = push(pilha, topo);
                break;
            case 2:
                printf("\n");
                topo = pop(pilha, topo);
                break;
            case 3:
                printf("\n");
                list(pilha, topo);
                break;
            case 4:
                printf("Saindo...\n");
                condSaida = 1;
                break;
            default: 
                printf("\n");
                printf("Valor invalido.");
        }
    }
    return 0;
}