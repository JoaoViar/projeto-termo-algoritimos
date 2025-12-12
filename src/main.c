#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <locale.h>

#include "..\\include\\interface.h"
#include "..\\include\\arquivos.h"
#include "..\\include\\manipulacao.h"
#include "..\\include\\menus.h" 
#include "..\\include\\jogar.h" 
#include "..\\include\\global.h"

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
                reinicializarJogo();
                carregarPalavras("src/temas/animais.txt");
                sorteio(palavras);
                jogar();
            }else if(opcaoTema == 2){
                reinicializarJogo();
                carregarPalavras("src/temas/musicas.txt");
                sorteio(palavras);
                jogar();
            }else if(opcaoTema == 3){
                reinicializarJogo();
                carregarPalavras("src/temas/comidas.txt");
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

}


