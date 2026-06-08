/*Uma Fila é uma estrutura de dados na qual o primeiro elemento a ser adicionado é o primeiro a sair, ou seja, 
o primeiro elemento é sempre removido.*/

#include <stdio.h>

#define MAX 5

int add(int fila[], int tamFila){
    if(tamFila == MAX){
        printf("Fila cheia!");
        printf("\n");
        return tamFila;
    }

    int valor;
    printf("Digite um valor: ");
    scanf("%d", &valor);

    for(int i = tamFila; i > 0; i--){
        fila[i] = fila[i-1];
    }

    fila[0] = valor;
    
    tamFila++;
    return tamFila;
}

int rmv(int fila[], int tamFila){
    if(tamFila == 0){
        printf("Fila vazia!");
        printf("\n");
        return tamFila;
    }

    tamFila--;
    return tamFila;
}

void list(int fila[], int tamFila){
    if(tamFila == 0){
        printf("Fila vazia!");
        printf("\n");
        return;
    }

    for(int i = 0; i < tamFila; i++){
        printf("%d ", fila[i]);
    }
}

int main(){
    int fila[MAX];
    int tamFila = 0;

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
            tamFila = add(fila, tamFila);
            break;
        case 2:
            printf("\n");
            tamFila = rmv(fila, tamFila);
            break;
            case 3:
            printf("\n");
            list(fila, tamFila);
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