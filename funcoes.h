#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#define caracteresMaximo 1000
#define palavraMaximoTamanho 50
#define maximoPalavra 100

void lerArquivo(const char *nomeArquivo, char *conteudo);
void listarPalavrasDiferentes(char *texto);
int contarOcorrencias(char *texto, const char *palavraBuscada);

#endif // FUNCOES_H_INCLUDED

