#include <stdio.h>
#include "..\\include\\menus.h"
#include "..\\include\\global.h"

int menuInicial(){

    printf("\033[0;32m");

    printf("\n\n------------------------------------------------------------- MENU TERMO ------------------------------------------------------------\n\n");
    printf("                                                   ESSAS SÃO AS OPÇÕES DISPONIVEIS:\n");
    printf("                                                              1- JOGAR\n");
    printf("                                                              2- TUTORIAL\n");
    printf("                                                              3- SOBRE\n");
    printf("                                                              4- SAIR\n");
    printf("                                                    DIGITE O NÚMERO DA OPÇÃO DESEJADA: ");
    scanf("%d", &opcaoInicial);
    while (getchar() != '\n');
    return opcaoInicial;
}

int menuTema(){

    int opcaoTema = 0;

    printf("\033[0;32m");

    printf("------------------------------------------------------------ MENU DE TEMAS ------------------------------------------------------------\n\n");
    printf("                                                  DIGITE O NÚMERO DA OPÇÃO DESEJADA:\n");
    printf("                                                           1- TEMA ANIMAIS\n");
    printf("                                                           2- TEMA MÚSICAS\n");
    printf("                                                           3- TEMA COMIDAS\n");
    printf("                                                    DIGITE O NÚMERO DA OPÇÃO DESEJADA: ");
    scanf("%d", &opcaoTema);
    while (getchar() != '\n');
    return opcaoTema;
}

void tutorial(){
     while (getchar() != '\n');

     printf("---------------------------------------------------------------TUTORIAL----------------------------------------------------------------\n\n");
    printf("COMO JOGAR:\n\n");
    printf("Você tem 6 tentativas para adivinhar a palavra secreta\n");
    printf("Cada tentativa deve ser uma palavra válida com EXATAMENTE 5 letras\n");
    printf("Após cada tentativa, as cores das letras indicarão o quão perto você está:\n\n");
    printf("VERDE   - A letra está na posição correta\n");
    printf("AMARELO - A letra existe, mas em outra posição\n");
    printf("CINZA   - A letra não existe na palavra\n\n");
    printf("BOA SORTE E DIVIRTA-SE!\n\n");
    printf("Pressione ENTER para voltar ao menu...\n");
    getchar();
}

void sobre() {
     while (getchar() != '\n');

    printf("=====================================================\n");
    printf("                       SOBRE\n");
    printf("=====================================================\n\n");
    printf("Projeto: Jogo TERMO\n");
    printf("Disciplina: Algoritmos e Estrutura de Dados II\n");
    printf("Linguagem: C\n\n");
    printf("Funcionalidades do projeto:\n");
    printf("- Sistema de vidas\n");
    printf("- Leitura de palavras por arquivos TXT\n");
    printf("- Temas diferentes\n");
    printf("- Sistema de tentativas\n\n");
    printf("Projeto desenvolvido para fins academicos.\n");
    printf("\nPressione ENTER para voltar ao menu...\n");
    getchar();
}