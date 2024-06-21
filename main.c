#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

void mostrarMenu() {
    printf("Menu:\n");
    printf("1. Inserir um texto\n");
    printf("2. Apagar o conteúdo do arquivo\n");
    printf("3. Listar palavras diferentes\n");
    printf("4. Contar ocorrências de uma palavra\n");
    printf("5. Visualizar textos registrados\n");
    printf("6. Sair\n");
    printf("Escolha uma opção: ");
}

void inserirTexto(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    
    char linha[caracteresMaximo];

    printf("Digite o texto (finalize com uma linha vazia):\n");
    
    while (1) {
        fgets(linha, caracteresMaximo, stdin);
        if (strcmp(linha, "\n") == 0) {
            break;
        }
        fprintf(arquivo, "%s", linha);
    }

    fprintf(arquivo, "\n"); // Adiciona uma linha em branco após o texto
    fclose(arquivo);
}

void apagarConteudo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fclose(arquivo);
    printf("Conteúdo do arquivo apagado.\n");
}

void visualizarTextos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[caracteresMaximo];
    printf("Textos registrados:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

int main() {
    char conteudo[caracteresMaximo];
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
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
