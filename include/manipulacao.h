#ifndef MANIPULACAO_H
#define MANIPULACAO_H

#include "arquivos.h"
#include "global.h"


#define COR_VERDE "\033[1;32m"
#define COR_AMARELO "\033[1;33m"
#define COR_CINZA "\033[1;90m"
#define COR_VERMELHO "\033[1;31m"                     //  Cor para mensagens de erro
#define COR_RESET "\033[0m"


int sorteio(char palavrasTemaAtual[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]);
void mostrarCores(char tentativa[], char correta[]);
char* removerTodosAcentos(char *palavra);

#endif