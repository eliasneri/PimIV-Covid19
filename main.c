#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#include "functions.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

main(){

    setlocale(LC_ALL, "Portuguese");
    validasenha();
    system("cls");
    gravarRegistro();
    cabecalho();

    int opcao=0;
    do {

        printf(ANSI_COLOR_YELLOW "\n\n****** MENU PRINCIPAL ****** \n" ANSI_COLOR_RESET);
        printf("** 1 - Cadastrar Paciente ** \n");
        printf("** 2 - Encerrar Programa  ** \n");
        asteriscos(28);
        espaco();
        printf("\n\nEscolha a sua opção: ");
        system("pause");

    } while (opcao !=2);

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



