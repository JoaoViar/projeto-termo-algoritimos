#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "..\\include\\jogar.h"
#include "..\\include\\interface.h"
#include "..\\include\\global.h"
 
int jogar() {

    

    const int maxPalavras = 6;
    char tentativaAtual[TAMANHO_PALAVRAS];
    char todasTentativas[maxPalavras][TAMANHO_PALAVRAS];     // Variavel responsável por armazenar todas as palvars tentadas pelo jogador
    int contadorPreenchidas = 0;

    // Inicialização da matriz todasTentativas
    for(int i = 0; i < maxPalavras; i++) {
        todasTentativas[i][0] = '\0';
    }


    while(vidasRestantes > 0 && vitoria == 0) {

        // Antes de cada tentativa os corações da vida do jogador são printados
        printf("\033[0;31m");
        coracoesVidas(vidasRestantes);


        for (int i = 0; i < maxPalavras; i++) {
            // Se o jogador ja deu algum palpite
            if (strlen(todasTentativas[i]) > 0) {
                //Transforma as palvras chutadas pelo jogador em MAIUSCULAS
                for (size_t  j = 0; j < strlen(todasTentativas[i]); j++) {
                    todasTentativas[i][j] = toupper(todasTentativas[i][j]);
                }
            }
        }

        // Printa as palvras chutadas pelo jogador
        for (int i = 0; i < contadorPreenchidas; i++) {
            printf("\n                                                          ");
            mostrarCores(todasTentativas[i], palavraSorteada);
        }

        printf("\033[0;32m");
        printf("\n                                                  Precione ENTER para continuar!");
        while (getchar() != '\n');

        printf("\033[0;32m");
        printf("\n                                                            TENTATIVA: %d/%d\n", contadorPreenchidas + 1, maxPalavras);
        printf("                                                            DIGITE: ");
        // Leitura da tentaiva atuais
        fgets(tentativaAtual, sizeof(tentativaAtual), stdin);

        tentativaAtual[strcspn(tentativaAtual, "\n")] = 0;

        removerTodosAcentos(tentativaAtual);

        //  VALIDAÇÃO DO TAMANHO DA PALAVRA
        int tamanho = strlen(tentativaAtual);

        if (tamanho != TAMANHO_CORRETO) {
            printf(COR_VERMELHO "\n                                              ERRO: A palavra deve ter exatamente 5 letras!\n" COR_RESET);
            printf(COR_VERMELHO "                                              Você digitou %d letra(s). Tente novamente.\n\n" COR_RESET, tamanho);
            continue;  // Volta para o início do loop sem perder vida
        }


        // Insere a nova tentativa no array de todas as tenativas
        strcpy(todasTentativas[contadorPreenchidas], tentativaAtual);
        contadorPreenchidas++;

        printf("\n                                                          ");
        mostrarCores(tentativaAtual, palavraSorteada);

        if (strcmp(tentativaAtual, palavraSorteada) == 0) {
            vitoria = 1;
            printf("\033[0;32m");
            printf("\n                                                    Parabéns! Você acertou a palavra!\n");
            break;
        }

        vidasRestantes--;
    }
        if (vitoria == 0) {
            printf("\033[0;31m");
            printf("\n                                                           Você perdeu!\n");
            printf("                                                      A palavra correta era %s\n", palavraSorteada);
            coracoesVidas(0);
        }
    return vitoria;
}

//Antes de cada rodada é necessario reinicializar as variaveis, senão o jogo não permite digitar nasproximas fases (após a primiera fase)
void reinicializarJogo() {

    vidasRestantes = 6;
    vitoria = 0;
    
    palavraSorteada[0] = '\0';
    

    for(int i = 0; i < totalPalavras; i++) {
         palavras[i][0] = '\0';
    }
    totalPalavras = 0;
    contador = 0;
}