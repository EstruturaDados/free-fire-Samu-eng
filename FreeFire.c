#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

// Struct que representa um item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor de itens (mochila) e controle
Item mochila[MAX_ITENS];
int totalItens = 0;

// Protótipos
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();
void limparBuffer();
void pausarTela();

int main() {
    int opcao;

    do {
        printf("\n===== MOCHILA DO JOGADOR =====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                inserirItem();
                listarItens();
                pausarTela();
                break;

            case 2:
                removerItem();
                listarItens();
                pausarTela();
                break;

            case 3:
                listarItens();
                pausarTela();
                break;

            case 4:
                buscarItem();
                pausarTela();
                break;

            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                pausarTela();
        }

    } while (opcao != 0);

    return 0;
}

// ================= FUNÇÕES =================

// Limpa o buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pausa a execução para o usuário visualizar
void pausarTela() {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

// Insere um novo item
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Mochila cheia! Limite atingido.\n");
        return;
    }

    printf("\nNome do item: ");
    fgets(mochila[totalItens].nome, 30, stdin);
    mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = '\0';

    printf("Tipo do item (arma, municao, cura, etc): ");
    fgets(mochila[totalItens].tipo, 20, stdin);
    mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[totalItens].quantidade);
    limparBuffer();

    totalItens++;

    printf("Item cadastrado com sucesso!\n");
}

// Remove item pelo nome
void removerItem() {
    char nomeBusca[30];
    int encontrado = 0;

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("\nDigite o nome do item a remover: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {

            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            totalItens--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}

// Lista todos os itens
void listarItens() {
    if (totalItens == 0) {
        printf("\nMochila vazia.\n");
        return;
    }

    printf("\n===== ITENS NA MOCHILA =====\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Item %d\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n\n", mochila[i].quantidade);
    }
}

// Busca sequencial por nome
void buscarItem() {
    char nomeBusca[30];
    int encontrado = 0;

    if (totalItens == 0) {
        printf("A mochila esta vazia.\n");
        return;
    }

    printf("\nDigite o nome do item para buscar: ");
    fgets(nomeBusca, 30, stdin);
    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("\nItem encontrado!\n");
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}
