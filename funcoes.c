#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funcoes.h"

int palavraExiste(char *palavras[], int numPalavras, const char *palavra) {
    int i;
    for (i = 0; i < numPalavras; i++) {
        if (strcmp(palavras[i], palavra) == 0) {
            return 1; // Palavra encontrada na lista
        }
    }
    return 0; // Palavra nao encontrada na lista
}

void lerArquivo(const char *nomeArquivo, char *conteudo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fread(conteudo, 1, caracteresMaximo, arquivo);
    fclose(arquivo);
}

void listarPalavrasDiferentes(char *texto) {
    char *palavras[maximoPalavra];
    int numPalavras = 0;
    char palavra[palavraMaximoTamanho];
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) { // Verifica se é uma letra
            palavra[j++] = tolower(texto[i]);
        } else if (j > 0) {
            palavra[j] = '\0';
            int numVogais = contarVogais(palavra);
            int k;
            for (k = 0; k < numPalavras; k++) {
                if (contarVogais(palavras[k]) == numVogais && strcmp(palavra, palavras[k]) == 0) {
                    break; // Palavra já existe na lista
                }
            }
            if (k == numPalavras) {
                palavras[numPalavras] = strdup(palavra);
                numPalavras++;
            }
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        palavra[j] = '\0';
        int numVogais = contarVogais(palavra);
        int k;
        for (k = 0; k < numPalavras; k++) {
            if (contarVogais(palavras[k]) == numVogais && strcmp(palavra, palavras[k]) == 0) {
                break; // Palavra já existe na lista
            }
        }
        if (k == numPalavras) {
            palavras[numPalavras] = strdup(palavra);
            numPalavras++;
        }
    }

    printf("Palavras diferentes encontradas:\n");
    for (i = 0; i < numPalavras; i++) {
        printf("%s\n", palavras[i]);
        free(palavras[i]);  // Libera a memória alocada por strdup
    }
}

int contarVogais(const char *palavra) {
    int numVogais = 0;
    int i;
    for (i = 0; palavra[i] != '\0'; i++) {
        char c = tolower(palavra[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            numVogais++;
        }
    }
    return numVogais;
}

int contarOcorrencias(char *texto, const char *palavraBuscada) {
    int count = 0;
    char palavra[palavraMaximoTamanho];
    int i = 0, j = 0;

    while (texto[i] != '\0') {
        if (isalpha(texto[i])) { // Verifica se é uma letra
            palavra[j++] = tolower(texto[i]);
        } else if (j > 0) {
            palavra[j] = '\0';
            if (strcasecmp(palavra, palavraBuscada) == 0) {
                count++;
            }
            j = 0;
        }
        i++;
    }

    if (j > 0) {
        palavra[j] = '\0';
        if (strcasecmp(palavra, palavraBuscada) == 0) {
            count++;
        }
    }

    return count;
}
