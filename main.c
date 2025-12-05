#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 

#define TAMANHO_PALAVRAS 8
#define MAXIMO_PALAVRAS 100
int totalPalavras = 0;
char palavras[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS];
int vidasRestantes = 6;
int contador = 0;

void painel();
void boasVindas();
void coracoesVidas(int vidasRestantes);
int menuInicial();
int menuTema();
void carregarPalavras(const char nomeArquivo);
int jogar(char palavrasJogar[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]);

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
        contador++;
    }
    
    fclose(arquivo);
}

void jogar(char *palavrasTemaAtual[]){

}

/*=======
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void painel();
void boasVindas();
void coracoesVidas(int vidasRestantes);
int menuInicial();
int menuTema();
void jogarTermo(int tema);

void tutorial();
void sobre();
void limparTela();
void exibirTentativa();
void normalizar();
int match();


const char* temaMusica[] = {"BAIXO"}; //so teste

#define MAX_TENTATIVAS 5
#define TAMANHO_PALAVRA 5

int main() {

    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");
    srand(time(NULL));

    int opcaoInicial = 0;
    int opcaoTema = 0;

    printf("\n\n\n");
    painel();
    printf("\n\n\n");
    boasVindas();

    do {
        opcaoInicial = menuInicial();

        if (opcaoInicial == 1) {
            opcaoTema = menuTema();

            if (opcaoTema == 1) {
                jogarTermo(1);
            } else if (opcaoTema == 2) {
                printf("\n\033[0;31mTema 2 !\033[0m\n");
                Sleep(2000);
            } else if (opcaoTema == 3) {
                printf("\n\033[0;31mTema 3 !\033[0m\n");
                Sleep(2000);
            } else {
                printf("\n\033[0;31mOpção inválida.\033[0m\n");
                Sleep(2000);
            }
        }
        else if (opcaoInicial == 2) {
            tutorial();
        }
        else if (opcaoInicial == 3) {
            sobre();
        }
        else if (opcaoInicial == 4) {
            printf("\n\033[0;36m");
            printf("=====================================================\n");
            printf("      OBRIGADO POR JOGAR! ATÉ A PRÓXIMA! :)\n");
            printf("=====================================================\n");
            printf("\033[0m\n");
            Sleep(2000);
        }
        else {
            printf("\n\033[0;31mOpção inválida.\033[0m\n");
            Sleep(2000);
        }

    } while (opcaoInicial != 4);

    return 0;
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
    printf("               ||||||            ||||||||||||||||    |||||    |||||         |||||            |||||          |||||||\n");
    Sleep(100);
    printf("\033[0m");
}

void boasVindas(){
    printf("\033[0;33m");
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
    printf("\033[0m");
}

void coracoesVidas(int vidasRestantes){
    printf("\033[0;31m");

    switch(vidasRestantes){
       

        case 0:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                ||       ||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  ||   ||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    case 1:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    case 2:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    case 3:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    case 4:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    case 5:
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           |||||||\n");
        printf("                    |||               |||               |||               |||               |||\n");
        break;
    }
    }

    printf("\033[0m");
}

int menuInicial(){
    int op;
    limparTela();
    printf("\n1 - Jogar\n2 - Tutorial\n3 - Sobre\n4 - Sair\nOpção: ");
    scanf("%d", &op);
    getchar();
    return op;
}

int menuTema(){
    int op;
    limparTela();
    printf("\n1 - Música\n2 - Tema 2\n3 - Tema 3\nTema: ");
    scanf("%d", &op);
    getchar();
    return op;
}



void jogarTermo(int tema){

    const char* palavraCorreta;
    char tentativas[MAX_TENTATIVAS][TAMANHO_PALAVRA + 1];
    char tentativaAtual[50];
    char palavraNormalizada[TAMANHO_PALAVRA + 1];
    int numTentativas = 0;
    int acertou = 0;

    int indice = rand() % 1; 
    palavraCorreta = temaMusica[indice];

    printf("\nJOGO TERMO — Tema Música!\n");

    while(numTentativas < MAX_TENTATIVAS && !acertou){

        printf("\n");
        coracoesVidas(MAX_TENTATIVAS - numTentativas);
        printf("\n");

        printf("Tentativa %d/%d: ", numTentativas+1, MAX_TENTATIVAS);
        fgets(tentativaAtual, sizeof(tentativaAtual), stdin);
        tentativaAtual[strcspn(tentativaAtual, "\n")] = 0;

        normalizar(palavraNormalizada, tentativaAtual);

        for(int i = 0; palavraNormalizada[i]; i++)
            palavraNormalizada[i] = toupper(palavraNormalizada[i]);

        if(strlen(palavraNormalizada) != TAMANHO_PALAVRA){
            printf("A palavra deve ter %d letras!\n", TAMANHO_PALAVRA);
            Sleep(1500);
            continue;
        }

        strcpy(tentativas[numTentativas], palavraNormalizada);
        numTentativas++;

        if(strcmp(palavraNormalizada, palavraCorreta) == 0){
            acertou = 1;
        }

        limparTela();
        printf("JOGO TERMO — Tema Música\n");
    }

    if(acertou){
        printf("\nPARABÉNS! Você acertou!\n");
    } else {
        printf("\nQue pena! Você perdeu! A palavra era: %s\n", palavraCorreta);
    }

    printf("\nPressione ENTER para voltar...");
    getchar();
}



void printLetter(char c){ //se precisar usar coloquei todas as letras
    case 'A':
        printf("  ██  \n");
        printf(" █  █ \n");
        printf("█████ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'B':
        printf("████  \n");
        printf("█   █ \n");
        printf("████  \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("████  \n");
        printf("      \n");
        break;

    case 'C':
        printf(" ████ \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf(" ████ \n");
        printf("      \n");
        break;

    case 'D':
        printf("████  \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("████  \n");
        printf("      \n");
        break;

    case 'E':
        printf("█████ \n");
        printf("█     \n");
        printf("████  \n");
        printf("█     \n");
        printf("█     \n");
        printf("█████ \n");
        printf("      \n");
        break;

    case 'F':
        printf("█████ \n");
        printf("█     \n");
        printf("████  \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("      \n");
        break;

    case 'G':
        printf(" ████ \n");
        printf("█     \n");
        printf("█     \n");
        printf("█  ██ \n");
        printf("█   █ \n");
        printf(" ████ \n");
        printf("      \n");
        break;

    case 'H':
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█████ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'I':
        printf("█████ \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("█████ \n");
        printf("      \n");
        break;

    case 'J':
        printf("█████ \n");
        printf("   █  \n");
        printf("   █  \n");
        printf("   █  \n");
        printf("█  █  \n");
        printf(" ██   \n");
        printf("      \n");
        break;

    case 'K':
        printf("█   █ \n");
        printf("█  █  \n");
        printf("███   \n");
        printf("█  █  \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'L':
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("█████ \n");
        printf("      \n");
        break;

    case 'M':
        printf("█   █ \n");
        printf("██ ██ \n");
        printf("█ █ █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'N':
        printf("█   █ \n");
        printf("██  █ \n");
        printf("█ █ █ \n");
        printf("█  ██ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'O':
        printf(" ████ \n");
        printf("█    █\n");
        printf("█    █\n");
        printf("█    █\n");
        printf("█    █\n");
        printf(" ████ \n");
        printf("      \n");
        break;

    case 'P':
        printf("████  \n");
        printf("█   █ \n");
        printf("████  \n");
        printf("█     \n");
        printf("█     \n");
        printf("█     \n");
        printf("      \n");
        break;

    case 'Q':
        printf(" ████ \n");
        printf("█    █\n");
        printf("█    █\n");
        printf("█  █ █\n");
        printf("█   █ \n");
        printf(" ████ \n");
        printf("      \n");
        break;

    case 'R':
        printf("████  \n");
        printf("█   █ \n");
        printf("████  \n");
        printf("█  █  \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'S':
        printf(" ████ \n");
        printf("█     \n");
        printf(" ███  \n");
        printf("    █ \n");
        printf("    █ \n");
        printf("████  \n");
        printf("      \n");
        break;

    case 'T':
        printf("█████ \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("      \n");
        break;

    case 'U':
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf(" ███  \n");
        printf("      \n");
        break;

    case 'V':
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf(" █ █  \n");
        printf("  █   \n");
        printf("      \n");
        break;

    case 'W':
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█   █ \n");
        printf("█ █ █ \n");
        printf("██ ██ \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'X':
        printf("█   █ \n");
        printf(" █ █  \n");
        printf("  █   \n");
        printf("  █   \n");
        printf(" █ █  \n");
        printf("█   █ \n");
        printf("      \n");
        break;

    case 'Y':
        printf("█   █ \n");
        printf(" █ █  \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("  █   \n");
        printf("      \n");
        break;

    case 'Z':
        printf("█████ \n");
        printf("    █ \n");
        printf("   █  \n");
        printf("  █   \n");
        printf(" █    \n");
        printf("█████ \n");
        printf("      \n");
        break;

    default:
        printf("(caractere inválido)\n");
        break;
}



void tutorial() { }
void sobre() { }
void limparTela() { }
void exibirTentativa() { }
void normalizar() { ); }
int match() {  }
>>>>>>> 16152120e5de26c1cfcdc68422848613f1184221
*/