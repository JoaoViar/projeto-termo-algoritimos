#include <stdio.h>
#include <string.h>
#include "..\\include\\arquivos.h"
#include "..\\include\\manipulacao.h"
#include "..\\include\\global.h"

// Funcao que recebe o nome do arquivo dependendo do tema e copia as palavras do arquivo para uma matriz
int carregarPalavras(const char* nomeArquivo) {

    // Leitura do arquivo
    FILE *arquivo = fopen(nomeArquivo, "r");

    // Identifica se o arquivo foi encontrado com sucesso
    if (arquivo == NULL) {
        printf("Erro: Arquivo não encontrado!\n");
        return 0;
    }

    char linha[TAMANHO_PALAVRAS];

    // while responsavel por armazenar as palavras do arquivo em um array char
    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalPalavras < MAXIMO_PALAVRAS) {  // Roda enquanto o fgets não identificar uma linha nula ou enquanto o maximo de palavras não for atingido

        linha[strcspn(linha, "\n")] = 0;      // Remove o sinalizador de fim de string '\n' por 0, ou seja, caracter nulo '\0'

        removerTodosAcentos(linha);

        strcpy(palavras[totalPalavras], linha);   // Atribui a palavra da linha a matriz palavras
        totalPalavras++;
        contador++;
    }

    fclose(arquivo);       // Fecha o arquivo

    return 1;
}