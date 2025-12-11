#ifndef GLOBAL_H
#define GLOBAL_H

#define TAMANHO_PALAVRAS 7
#define MAXIMO_PALAVRAS 50

// DECLARAÇÕES de todas as variáveis globais (usar extern)
extern char palavras[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS];
extern char palavraSorteada[TAMANHO_PALAVRAS];
extern int totalPalavras;
extern int contador;
extern int vidasRestantes;
extern int vitoria;
extern int opcaoInicial; 

#endif