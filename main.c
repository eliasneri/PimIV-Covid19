#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#include "functions.h"
#include "paciente.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

main(){

    setlocale(LC_ALL, "Portuguese");
    validasenha();
    system("cls");
    cabecalho();

    int opcao=0;
    do {

        printf(ANSI_COLOR_YELLOW "\n\n****** MENU PRINCIPAL ****** \n" ANSI_COLOR_RESET);
        printf("** 1 - Cadastrar Paciente ** \n");
        printf("** 2 - Encerrar Programa  ** \n");
        asteriscos(28);
        espaco();
        printf("\n\nEscolha a sua opção: ");
        scanf("%i", &opcao);
            if (opcao == 1){
                system("cls");
                cabecalho();
                puts("Inclusão de Novo Registro!");
                incluiRegistro();
                system("cls");
                cabecalho();
            }

    } while (opcao !=2);

    system("cls");
    puts("ENCERRANDO O PROGRAMA!");
    // destruir variáveis!

}



void gravarRegistro(){
    FILE *PTRARQ;
    char PALAVRA[20];
    PTRARQ = fopen("ARQTXT01.txt", "a");
    printf("\n\nEscreva uma palavra: ");
    scanf("%s", PALAVRA);
    fprintf(PTRARQ, "\n\n");
    fprintf(PTRARQ, "***************************************************\n");
    fprintf(PTRARQ, "%s\n", PALAVRA);
    fprintf(PTRARQ, "***************************************************");
    fclose(PTRARQ);
    return 0;
}



