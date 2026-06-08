#include <stdio.h>

#define MAX 100

int add(int fila[], int tamFila, int tamPilha){
    if(tamFila + tamPilha == MAX){
        printf("\n");
        printf("Memoria cheia!");
        return tamFila;
    }

    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);

    for(int i = MAX-tamFila-1; i < MAX-1 ; i++){
        fila[i] = fila[i+1];
    }

    fila[MAX-1] = valor;
    
    tamFila++;
    return tamFila;
}

int rmv(int fila[], int tamFila, int tamPilha){
    if(tamFila == 0){
        printf("Fila vazia!");
        printf("\n");
        return tamFila;
    }
    tamFila--;
    return tamFila;
}

int push(int pilha[], int tamPilha, int tamFila){
    if(tamFila + tamPilha == MAX){
        printf("\n");
        printf("Memoria cheia!");
        return tamPilha;
    }
    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);
    pilha[tamPilha] = valor;
    tamPilha++;
    return tamPilha;
}

int pop(int pilha[], int tamPilha, int tamFila){
    if(tamPilha == 0){
        printf("Pilha vazia!");
        printf("\n");
        return tamPilha;
    }
    printf("Removido com sucesso!");
    tamPilha--;
    return tamPilha;
}

void list(int arm[], int tamFila, int tamPilha){
    if(tamPilha == 0){
        printf("Pilha vazia!");
        printf("\n");
    }else{
        for(int i = tamPilha-1; i >= 0; i--){
            printf("%d ", arm[i]);
        }
    }

   printf("\n");


   if(tamFila == 0){
        printf("Fila vazia!");
        printf("\n");
    }else{
        for(int i = MAX-tamFila; i < MAX; i++){
            printf("%d ", arm[i]);
        }
    }
   
}

int main(){
    int arm[MAX];
    int tamFila = 0;
    int tamPilha = 0;

    while(1){
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("1 - Adicionar um item na fila;\n");
        printf("2 - Adicionar um item na pilha;\n");
        printf("3 - Remover um item da fila;\n");
        printf("4 - Remover um item da pilha;\n");
        printf("5 - Listar itens;\n");
        printf("6 - Sair\n");
        int caso;
        scanf("%d", &caso);

        switch (caso){
        case 1:
            printf("\n");
            tamFila = add(arm, tamFila, tamPilha);
            break;
        case 2:
            printf("\n");
            tamPilha = push(arm, tamPilha, tamFila);
            break;
        case 3:
            printf("\n");
            tamFila = rmv(arm, tamFila, tamPilha);
            break;
        case 4:
            printf("\n");
            tamPilha = pop(arm, tamPilha, tamFila);
            break;
        case 5:
            printf("\n");
            list(arm, tamFila, tamPilha);
            break;
        case 6:
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