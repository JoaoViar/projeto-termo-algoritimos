#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "..\\include\\manipulacao.h"
#include "..\\include\\arquivos.h"
#include "..\\include\\global.h"

// Função responsável pelo sortei de um número, numero esse que equivale a posição da palavra no array
int sorteio(char palavrasTemaAtual[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]) {

    // Sorteio de um número
    srand(time(NULL));
    int indiceSorteado = rand() % contador;

    // Armazenar a palavra da posição do array que foi sorteada no vetor palavraSorteada
    strcpy(palavraSorteada, palavrasTemaAtual[indiceSorteado]);
    return 0;
}

void mostrarCores(char tentativa[], char correta[]) {
    int usado[5] = {0};

    for(int i = 0; i < 5; i++) {
        if(tentativa[i] == correta[i]) {
            usado[i] = 1;
        }
    }

    for(int i = 0; i < 5; i++) {
        if(tentativa[i] == correta[i]) {
            printf(COR_VERDE "[%c]" COR_RESET, tentativa[i]);
        } else {
            int achou = 0;


            for(int j = 0; j < 5; j++) {
                if(!usado[j] && tentativa[i] == correta[j]) {
                    printf(COR_AMARELO "[%c]" COR_RESET, tentativa[i]);
                    usado[j] = 1;
                    achou = 1;
                    break;
                }
            }

            if(!achou) {
                printf(COR_CINZA "[%c]" COR_RESET, tentativa[i]);
            }
        }
    }
    printf("\n");
}

// Função responsavel por deixar as letras maiusculas e remover acentuação
char* removerTodosAcentos(char *palavra) {
    int i, j;
    char resultado[TAMANHO_PALAVRAS];  // Buffer temporário

    j = 0;
    for(i = 0; palavra[i] != '\0' && j < TAMANHO_PALAVRAS - 1; i++) {
        unsigned char c = palavra[i];

        // Se for caractere ASCII normal (0-127)
        if(c < 128) {
            // Converte para maiúsculo
            if(c >= 'a' && c <= 'z') {
                resultado[j] = c - 32;
            } else {
                resultado[j] = c;
            }
            j++;
        }
        // Se for início de caractere UTF-8 (0xC0-0xDF)
        else if(c >= 0xC0 && c <= 0xDF) {
            // É um caractere acentuado em UTF-8
            unsigned char next = palavra[i+1];

            // Mapeia para letra sem acento
            if((c == 0xC3 && next >= 0x80 && next <= 0x85) ||  (c == 0xC3 && next >= 0xA0 && next <= 0xA5)) {  //  ÀÁÂÃÄ àáâãä
                resultado[j] = 'A';
                j++;
            }
            else if((c == 0xC3 && (next == 0x87 || next == 0xA7))) {  // Ç ç
                resultado[j] = 'C';
                j++;
            }
            else if((c == 0xC3 && next >= 0x88 && next <= 0x8B) ||  (c == 0xC3 && next >= 0xA8 && next <= 0xAB)) {  // èéêë ÈÉÊË
                resultado[j] = 'E';
                j++;
            }
            else if((c == 0xC3 && (next == 0x8C || next == 0x8D || next == 0xAC || next == 0xAD))) { // ìí ÌÍ
                resultado[j] = 'I';
                j++;
            }
            else if((c == 0xC3 && next >= 0x92 && next <= 0x96) ||  (c == 0xC3 && next >= 0xB2 && next <= 0xB6)) {  // òóôõö ÒÓÔÕÖ
                resultado[j] = 'O';
                j++;
            }
            else if((c == 0xC3 && (next == 0x99 || next == 0x9A ||  next == 0xB9 || next == 0xBA))) { // ÙÚùú
                resultado[j] = 'U';
                j++;
            }

            // Pula o próximo byte (já processamos os 2 bytes)
            i++;
        }

    }

    resultado[j] = '\0';
    strcpy(palavra, resultado);
    return palavra;
}
