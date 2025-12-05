#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

#define TAMANHO_PALAVRAS 8
#define MAXIMO_PALAVRAS 100
int totalPalavras = 0;
char palavras[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS];

void painel();
void boasVindas();
void coracoesVidas(int vidasRestantes);
int menuInicial();
int menuTema();
void carregarPalavras(const char nomeArquivo);

int main(){

    int opcaoInicial = 0;
    int opcaoTema = 0;
    
    printf("\n\n\n");
    painel();
    printf("\n\n\n");
    boasVindas();

    do{
        opcaoInicial = menuInicial();
        if(opcaoInicial == 1){

            opcaoTema = menuTema();

            if(opcaoTema == 1){
                carregarPalavras("temas/animais.txt");
            }else if(opcaoTema == 2){
                carregarPalavras("temas/musicas.txt");
            }else if(opcaoTema == 3){

            }else{
                // opção não existe
            }

        }else if(opcaoInicial == 2){
            printf("\nESCREVER O TUTORIAL\n");
        }else if(opcaoInicial == 3){
            printf("\nESCREVER O SOBRE\n");
        }else if(opcaoInicial == 4){

        }else{
            // opção não existe
        }
    }while(opcaoInicial != 4);

    printf("\033[0;31m");
    printf("\n\n\n");
    coracoesVidas(5);

}

void painel(){

    printf("\033[0;32m");
    printf("          ||||||||||||||||       ||||||||||||||||    |||||||||||            |||||||        |||||||          ||||||||\n");   
    Sleep(100);
    printf("          ||||||||||||||||       ||||||||||||||||    |||||||||||||||        |||||||||    |||||||||        ||||   ||||\n");
    Sleep(100);
    printf("               ||||||            |||||               |||||       |||||      ||||| ||||  |||| |||||      ||||       ||||\n");
    Sleep(100);
    printf("               ||||||            |||||               |||||       |||||      |||||   ||||||   |||||    ||||           ||||\n");
    Sleep(100);
    printf("               ||||||            ||||||||||||||||    |||||     |||||        |||||    ||||    |||||  ||||               ||||\n");
    Sleep(100);
    printf("               ||||||            ||||||||||||||||    |||||   ||||||         |||||     ||     |||||  ||||               ||||\n");
    Sleep(100);
    printf("               ||||||            |||||               |||||||||||            |||||            |||||    ||||           ||||\n");
    Sleep(100);
    printf("               ||||||            |||||               ||||||||||             |||||            |||||      ||||       ||||\n");
    Sleep(100);
    printf("               ||||||            ||||||||||||||||    |||||  |||||           |||||            |||||        ||||   ||||\n");
    Sleep(100);
    printf("               ||||||            ||||||||||||||||    |||||    |||||         |||||            |||||          |||||||");
    Sleep(100);
}

void boasVindas(){

    printf("     |||||||     ||||||||   |||||    |||||             |||          |||     ||||     ||||||      |||    ||||||              |||         \n");
    Sleep(100);
    printf("     |||   |||   ||||||||   ||||||  ||||||              |||        |||               |||||||     |||    |||  |||          ||| |||       \n");
    Sleep(100);
    printf("     |||  |||    |||        |||  ||||  |||               |||      |||       ||||     ||| ||||    |||    |||    |||      |||     |||     \n");
    Sleep(100);
    printf("     ||||||      ||||||||   |||   ||   |||                |||    |||        ||||     |||   |||   |||    |||     |||   |||         |||   \n");
    Sleep(100);
    printf("     |||  |||    |||        |||        |||                 |||  |||         ||||     |||    |||  |||    |||    |||      |||     |||     \n");
    Sleep(100);
    printf("     |||   |||   ||||||||   |||        |||                  ||||||          ||||     |||     |||||||    |||  |||          ||| |||       \n");
    Sleep(100);
    printf("     |||||||     ||||||||   |||        |||                   |||            ||||     |||      ||||||    ||||||              |||         \n");
    Sleep(100);
}

void coracoesVidas(int vidasRestantes){

    switch (vidasRestantes)
    {
    case 0:
        
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                ||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  ||   ||           ||   ||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 1:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           ||   ||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 2:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 3:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 4:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 5:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           |||||||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    case 6:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           |||||||           |||||||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        break;
    default:
        break;
    }
}
    
int menuInicial(){

    int opcaoInicial = 0;

    printf("\n\n------------------------------------------------------------- MENU TERMO ------------------------------------------------------------\n\n");
    printf("                                                   ESSAS SÃO AS OPÇÕES DISPONIVEIS:\n");
    printf("                                                              1- JOGAR\n");
    printf("                                                              2- TUTORIAL\n");
    printf("                                                              3- SOBRE\n");
    printf("                                                              4- SAIR\n");
    printf("                                                    DIGITE O NÚMERO DA OPÇÃO DESEJADA: ");
    scanf("%d", &opcaoInicial);

    return opcaoInicial;
}

int menuTema(){

    int opcaoTema = 0;

    printf("------------------------------------------------------------ MENU DE TEMAS ------------------------------------------------------------\n\n");
    printf("                                                  DIGITE O NÚMERO DA OPÇÃO DESEJADA:\n");
    printf("                                                           1- TEMA ANIMAIS\n");
    printf("                                                           2- TEMA MÚSICAS\n");
    printf("                                                           3- TEMA 3 (NOME)\n");
    printf("                                                    DIGITE O NÚMERO DA OPÇÃO DESEJADA: ");
    scanf("%d", &opcaoTema);

    return opcaoTema;
}

void carregarPalavras(const char nomeArquivo) {
    FILE *arquivo;
    arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        printf("\nErro: Arquivo '%s' não encontrado!\n", nomeArquivo);
        return;
    }
    
    char linha[TAMANHO_PALAVRAS];
    totalPalavras = 0;
    
    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalPalavras < MAXIMO_PALAVRAS) {

        linha[strcspn(linha, "\n")] = 0;
        
        strcpy(palavras[totalPalavras], linha);
        totalPalavras++;
    }
    
    fclose(arquivo);
    
    Sleep(1000);

}
