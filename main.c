#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAMANHO_PALAVRAS 7                            // Tamanho maxmo de palavras igual a 7 para ter margem de erro
#define MAXIMO_PALAVRAS 100                           // Limitação de palavras por arquivo de tema
#define COR_VERDE "\033[1;32m"
#define COR_AMARELO "\033[1;33m"
#define COR_CINZA "\033[1;90m"
#define COR_RESET "\033[0m"
int totalPalavras = 0;                                // Durante a leitura do arquivo txt o numero de palavras é contado, número necessario durante o projeto
char palavras[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS];     //
int vidasRestantes;
int contador = 0;                                     //
int vitoria;                                          // Varaivel para identificar quando o jogador vence (Não é contador de vitórias)
char palavraSorteada[TAMANHO_PALAVRAS];

void painel();                                        // Imprime o TERMO em Ascii text art
void boasVindas();                                    // Imprime boas vindas em Asci text art
void coracoesVidas(int vidasRestantes);               // Imprime corações em Ascii text art preenchidos dependendo do numero da tentativa do jogador
int menuInicial();                                    // Disponibiliza para o jogador as seguintes opções: Jogar, Tutorial, Sobre e Sair
int menuTema();                                       // Disponibiliza três temas, cada tema foi selecionado por um desenvolvedor diferente
int carregarPalavras(const char* nomeArquivo);
int sorteio(char palavrasJogar[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]);        // Funcção responsavel por sortear a palavra dentro do arquivo txt
int jogar();                                          // Função principal do jogo
void tutorial();
void sobre();

int main(){

    // Código que possibilita inserir acentuação nas palavras

    setlocale(LC_ALL, "pt_BR.UTF-8");
    system("chcp 65001 > nul");

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
                sorteio(palavras);
                jogar();
            }else if(opcaoTema == 2){
                carregarPalavras("temas/musicas.txt");
                sorteio(palavras);
                jogar();
            }else if(opcaoTema == 3){
                carregarPalavras("temas/comidas.txt");
                sorteio(palavras);
                jogar();
            }else{
                printf("Opção não existe!");
            }

        }else if(opcaoInicial == 2){
            tutorial();
        }else if(opcaoInicial == 3){
            sobre();
        }else if(opcaoInicial == 4){
            printf("\nOBRIGADO POR JOGAR, JOGO ENCERRADO\n");
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
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                ||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  ||   ||           ||   ||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 1:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       ||       ||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           ||   ||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 2:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       ||       ||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           ||   ||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 3:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       ||       ||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           ||   ||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 4:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       ||       ||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           ||   ||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 5:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     ||  || ||  ||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   ||     |     ||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||       ||       ||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           |||||||           ||   ||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
        break;
    case 6:
        printf("\n");
        printf("                ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||       ||||   ||||\n");
        printf("               |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||     |||||| ||||||\n");
        printf("              |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||   |||||||||||||||\n");
        printf("                |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||       |||||||||||\n");
        printf("                  |||||||           |||||||           |||||||           |||||||           |||||||           |||||||\n");
        printf("                    |||               |||               |||               |||               |||               |||\n");
        printf("\n");
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
    printf("                                                           3- TEMA COMIDAS\n");
    printf("                                                    DIGITE O NÚMERO DA OPÇÃO DESEJADA: ");
    scanf("%d", &opcaoTema);

    return opcaoTema;
}

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
    totalPalavras = 0;
    contador = 0;

    // while responsavel por armazenar as palavras do arquivo em um array char
    while (fgets(linha, sizeof(linha), arquivo) != NULL && totalPalavras < MAXIMO_PALAVRAS) {  // Roda enquanto o fgets não identificar uma linha nula ou enquanto o maximo de palavras não for atingido

        linha[strcspn(linha, "\n")] = 0;      // Remove o sinalizador de fim de string '\n' por 0, ou seja, caracter nulo '\0'

        strcpy(palavras[totalPalavras], linha);   // Atribui a palavra da linha a matriz palavras
        totalPalavras++;
        contador++;
    }

    fclose(arquivo);       // Fecha o arquivo

    return 1;
}

// Função responsável pelo sortei de um número, numero esse que equivale a posição da palavra no array
int sorteio(char palavrasTemaAtual[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]) {

    // Sorteio de um número
    srand(time(NULL));
    int indiceSorteado = rand() % contador;

    // Armazenar a palavra da posição do array que foi sorteada no vetor palavraSorteada
    strcpy(palavraSorteada, palavrasTemaAtual[indiceSorteado]);

    return 0;
}

// Função que compara e mostra as cores
void mostrarCores(char tentativa[], char correta[]) {
    for (int i = 0; i < strlen(tentativa); i++) {
        if (tentativa[i] == correta[i]) {
            printf(COR_VERDE "%c" COR_RESET, tentativa[i]);
        } else if (strchr(correta, tentativa[i]) != NULL) {
            printf(COR_AMARELO "%c" COR_RESET, tentativa[i]);
        } else {
            printf(COR_CINZA "%c" COR_RESET, tentativa[i]);
        }
    }
    printf("\n");
}

// FUnção principal para o jogo
int jogar() {

    vidasRestantes = 6;
    vitoria = 0;
    const int maxPalavras = 6;
    int tentativas = 0;
    char tentativaAtual[TAMANHO_PALAVRAS];
    char todasTentativas[maxPalavras][TAMANHO_PALAVRAS];     // Variavel responsável por armazenar todas as palvars tentadas pelo jogador
    int contadorPreenchidas = 0;
    int comparacao;

    // Inicialização da matriz todasTentativas
    for(int i = 0; i < maxPalavras; i++) {
        todasTentativas[i][0] = '\0';
    }

    // Essa linha precisou ser adicionada para esperar uma quebra de inhaquando o jogador precisar inserir uma palavra pois
    // sem ela o próximo while rodava duas vezes seguidas sem deixaro jogador inseriri a palavra
    while ((comparacao = getchar()) != '\n' && comparacao != EOF);

    while(vidasRestantes > 0 && vitoria == 0) {

        // Antes de cada tentativa os corações da vida do jogador são printados
        coracoesVidas(vidasRestantes);


        for (int i = 0; i < maxPalavras; i++) {
            // Se o jogador ja deu algum palpite
            if (strlen(todasTentativas[i]) > 0) {
                //Transforma as palvras chutadas pelo jogador em MAIUSCULAS
                for (int j = 0; j < strlen(todasTentativas[i]); j++) {
                    todasTentativas[i][j] = toupper(todasTentativas[i][j]);
                }
            }
        }

        // Printa as palvras chutadas pelo jogador
        for (int i = 0; i < contadorPreenchidas; i++) {
            printf("\n                                                                 ");
            mostrarCores(todasTentativas[i], palavraSorteada);
        }

        printf("\n                                                            TENTATIVA: %d/%d\n", contadorPreenchidas + 1, maxPalavras);
        printf("                                                            DIGITE: ");
        // Leitura da tentaiva atuais
        fgets(tentativaAtual, sizeof(tentativaAtual), stdin);

        tentativaAtual[strcspn(tentativaAtual, "\n")] = 0;

        // Insere a nova tentativa no array de todas as tenativas
        strcpy(todasTentativas[contadorPreenchidas], tentativaAtual);
        contadorPreenchidas++; 

        printf("                                                                 ");
        mostrarCores(tentativaAtual, palavraSorteada);

        if (strcmp(tentativaAtual, palavraSorteada) == 0) {
            vitoria = 1;
            printf("\n                                                    Parabéns! Você acertou a palavra!\n");
            break;
        }
        
        vidasRestantes--;
    }
        if (vitoria == 0) {
            printf("\n                                                           Você perdeu!\n");
            printf("                                                      A palavra correta era %s\n", palavraSorteada);
            coracoesVidas(0);
        }
}

void tutorial(){
     printf("---------------------------------------------------------------TUTORIAL----------------------------------------------------------------\n\n");
    printf("COMO JOGAR:\n\n");
    printf("Você tem 6 tentativas para adivinhar a palavra secreta\n");
    printf("Cada tentativa deve ser uma palavra válida com 5 letras\n");
    printf("Após cada tentativa, as cores das letras indicarão o quão perto você está:\n\n");
    printf("VERDE   - A letra está na posição correta\n");
    printf("AMARELO - A letra existe, mas em outra posição\n");
    printf("CINZA   - A letra não existe na palavra\n\n");
    printf("BOA SORTE E DIVIRTA-SE!\n\n");
    printf("Pressione ENTER para voltar ao menu...");
    getchar();
}

void sobre() {
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
    printf("\nPressione ENTER para voltar ao menu...");
    getchar();
}


