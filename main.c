#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "functions.h"
#include "paciente.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"


/* FUN��ES E VALIDA��ES DO SISTEMA EST�O ORGANIZADAS
/  EM FUNCTIONS.H BEM COMO TODAS AS REGRAS DE CADASTRO DOS PACIENTES!
/
/
/  TODA PARTE DE CADASTRO DE PACIENTES, VERIFIQUE
/  PACIENTE.H
/
/  DESENVOLVIDO POR ELIAS A. NERI EM NOVEMBRO/2020
/  PROJETO INTEGRADO MULTIDISCIPLINAR - AN�LISE E DESENVOLVIMENTO DE SISTEMAS
/  (PIM IV) - UNIP 2020 - ORIENTADOR:
*/




void main(){
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    validasenha();
    menu();
    paciente();
    finalizaProgram();
    return 0;
}


