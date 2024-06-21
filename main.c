#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

#define MAX_CARACTERES 1001 // Adicionamos 1 para incluir o caractere nulo '\0'

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Inserir um texto (limite 1000 caracteres)\n");
    printf("2. Apagar o conteudo do arquivo\n");
    printf("3. Listar palavras diferentes\n");
    printf("4. Contar ocorrencias de uma palavra\n");
    printf("5. Visualizar textos registrados\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
}

void inserirTexto(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[MAX_CARACTERES];

    printf("Digite o texto (limite de 1000 caracteres, finalize com uma linha vazia):\n");

    while (1) {
        fgets(linha, sizeof(linha), stdin);
        if (strcmp(linha, "\n") == 0) {
            fprintf(arquivo, "\n"); // Adiciona uma linha em branco após o texto
            break;
        }
        if (strlen(linha) > MAX_CARACTERES - 1) { // -1 para deixar espaço para o caractere nulo
            printf("O texto excede o limite de 1000 caracteres.\n");
            fclose(arquivo);
            return;
        }
        fprintf(arquivo, "%s", linha);
    }

    fclose(arquivo);
}

void apagarConteudo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fclose(arquivo);
    printf("Conteudo do arquivo apagado.\n");
}

void visualizarTextos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[MAX_CARACTERES];
    printf("Textos registrados:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

int main() {
    char conteudo[MAX_CARACTERES];
    char palavraBuscada[palavraMaximoTamanho];
    int opcao;
    const char *nomeArquivo = "texto.txt";

    while (1) {
        mostrarMenu();
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer do stdin

        switch (opcao) {
            case 1:
                inserirTexto(nomeArquivo);
                break;
            case 2:
                apagarConteudo(nomeArquivo);
                break;
            case 3:
                lerArquivo(nomeArquivo, conteudo);
                listarPalavrasDiferentes(conteudo);
                break;
            case 4:
                lerArquivo(nomeArquivo, conteudo);
                printf("\nDigite uma palavra para buscar no texto: ");
                scanf("%s", palavraBuscada);
                printf("A palavra '%s' aparece %d vezes no texto.\n", palavraBuscada, contarOcorrencias(conteudo, palavraBuscada));
                break;
            case 5:
                visualizarTextos(nomeArquivo);
                break;
            case 6:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
