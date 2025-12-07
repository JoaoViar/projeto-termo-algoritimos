#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h> 
#include <time.h>
#include <ctype.h>

#define TAMANHO_PALAVRAS 7                            // Tamanho maxmo de palavras igual a 7 para ter margem de erro
#define MAXIMO_PALAVRAS 100                           // Limitação de palavras por arquivo de tema
int totalPalavras = 0;                                // Durante a leitura do arquivo txt o numero de palavras é contado, número necessario durante o projeto
char palavras[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS];     // 
int vidasRestantes = 6;                               
int contador = 0;                                     //
int vitoria = 0;                                      // Varaivel para identificar quando o jogador vence (Não é contador de vitórias)

void painel();                                        // Imprime o TERMO em Ascii text art
void boasVindas();                                    // Imprime boas vindas em Asci text art
void coracoesVidas(int vidasRestantes);               // Imprime corações em Ascii text art preenchidos dependendo do numero da tentativa do jogador
int menuInicial();                                    // Disponibiliza para o jogador as seguintes opções: Jogar, Tutorial, Sobre e Sair
int menuTema();                                       // Disponibiliza três temas, cada tema foi selecionado por um desenvolvedor diferente
int carregarPalavras(const char* nomeArquivo);
int sorteio(char palavrasJogar[MAXIMO_PALAVRAS][TAMANHO_PALAVRAS]);        // Funcção responsavel por sortear a palavra dentro do arquivo txt
int jogar();                                          // Função principal do jogo

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
            }else if(opcaoTema == 3){
                carregarPalavras("temas/comidas.txt");
            }else{
                printf("Opção não exixte!");
            }

        }else if(opcaoInicial == 2){
            printf("\nESCREVER O TUTORIAL\n");
        }else if(opcaoInicial == 3){
            printf("\nESCREVER O SOBRE\n");
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

// Funcao que recebe o nome do arquivo dependendo do tema e copia as palavras do arquivo para uma matriz
int carregarPalavras(const char* nomeArquivo) {   

    // Leitura do arquivo
    FILE *arquivo = fopen("temas/animais.txt", "r");   
    
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
    char palavraSorteada[TAMANHO_PALAVRAS];
    strcpy(palavraSorteada, palavrasTemaAtual[indiceSorteado]);

    return 0;
}


// FUnção principal para o jogo
int jogar() {

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
                // contador de palavras chutadas pelo jogador
                contadorPreenchidas++;
                //Transforma as palvras chutadas pelo jogador em MAIUSCULAS
                for (int j = 0; j < strlen(todasTentativas[i]); j++) {
                    todasTentativas[i][j] = toupper(todasTentativas[i][j]);
                }
            } 
        }

        // Printa as palvras chutadas pelo jogador
        for (int i = 0; i < contadorPreenchidas; i++) {
            printf("\n                                                               %s", todasTentativas[i]);
        }

        printf("\n                                                                   TENTATIVA: %d/%d\n", contadorPreenchidas + 1, maxPalavras);
        printf("                                                                     DIGITE: ");
        // Leitura da tentaiva atuais
        fgets(tentativaAtual, sizeof(tentativaAtual), stdin);
        
        tentativaAtual[strcspn(tentativaAtual, "\n")] = 0;
        
        // Insere a nova tentativa no array de todas as tenativas
        strcpy(todasTentativas[contadorPreenchidas], tentativaAtual);

        

        vidasRestantes--;
    }
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
        printf("  |||  \n");
        printf(" || || \n");
        printf("|||||||\n");
        printf("||   ||\n");
        printf("||   ||\n");
        printf("||   ||\n");
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