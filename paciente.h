#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED


typedef struct Paciente{
    char nome[80];
    char cpf [13];
    char Telefone[13];
    char rua[80];
    char numero[4];
    char bairro[30];
    char cidade[30];
    char estado[2];
    char cep [8];
    char dtNasc[11];
    char email[30];
    char dtDiag [11];
    char comorb [400];
};

struct Paciente NPaciente;

// ACRESCENTAR OP��O PARA VOLTAR AO MENU!!! USANDO A TECLA ESC !!!

void paciente(){
    system("cls");
    gotoxy(10,0);
    cabecalho();
    gotoxy(40,1);
    printf(ANSI_COLOR_RED "PRESSIONE ESC P/ VOLTAR!" ANSI_COLOR_RESET);
    gotoxy(37,6);
    printf(ANSI_COLOR_RED "Inclus�o de Novo Registro!!" ANSI_COLOR_RESET);

    // FORMATA��O DE DADOS!!!

    gotoxy(10,07);
    tracoDecora(81,'=');
    gotoxy(42,8);
    printf(ANSI_COLOR_YELLOW "DADOS DO PACIENTE" ANSI_COLOR_RESET);
    gotoxy(10,9);
    tracoDecora(81,'=');

    gotoxy(10,10);
    // CAMPO NOME! PREENCHE E FORMATA!
    printf("Nome : "ANSI_COLOR_YELLOW);
    NPaciente.nome;
    functionFormataChar(NPaciente.nome,80);

    // CAMPO CPF
    fflush(stdin);
    gotoxy(10,11);
    printf(ANSI_COLOR_RESET"CPF : "ANSI_COLOR_YELLOW);
  //  functionCPF(NPaciente.cpf);

    // CAMPO TELEFONE
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Telefone: "ANSI_COLOR_YELLOW);
  //  functionTelefone(NPaciente.Telefone);

    // CAMPO ENDERE�O
    fflush(stdin);
    gotoxy(10,13);
    printf(ANSI_COLOR_RESET"Endere�o:");
    gotoxy(10,14);
    printf(ANSI_COLOR_RESET"Rua: "ANSI_COLOR_YELLOW);
 //   functionFormataChar(NPaciente.rua,80);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" | N�mero: "ANSI_COLOR_YELLOW);
 //   functionFormataChar(NPaciente.numero,4);

    gotoxy(10,15);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Bairro: "ANSI_COLOR_YELLOW);
  //  functionFormataChar(NPaciente.bairro,30);

    gotoxy(10,16);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Cidade: "ANSI_COLOR_YELLOW);
  //  functionFormataChar(NPaciente.cidade,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" Estado: "ANSI_COLOR_YELLOW);
   // functionFormataCharEstado(NPaciente.estado);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" CEP: "ANSI_COLOR_YELLOW);
   // functionFormataCep(NPaciente.cep);

    // CAMPO DATA DE NASCIMENTO E VALIDA��O DA DATA!!!
    fflush(stdin);
    int idade=0;
   // idade=validaIdade(NPaciente.dtNasc);
    gotoxy(10,17);
    printf(ANSI_COLOR_RESET"Idade do Paciente: ");
    grupoRisco(idade);

    gotoxy(10,19);
    printf(ANSI_COLOR_RESET "E-mail: " ANSI_COLOR_YELLOW);
    gotoxy(10,20);
    printf(ANSI_COLOR_RESET "Data do diagn�stico: " ANSI_COLOR_YELLOW);
    gotoxy(10,21);
    printf(ANSI_COLOR_RESET "Comorbidades: " ANSI_COLOR_YELLOW);
    gotoxy(10,22);
    printf(ANSI_COLOR_RESET);
    tracoDecora(81,'=');
    gotoxy(37,24);
    printf(ANSI_COLOR_RESET "Gravar Registro? (s/n): " ANSI_COLOR_YELLOW);

    printf(ANSI_COLOR_RESET);
    gotoxy(27,26);
    system("pause");
    system("cls");

    printf("%s", NPaciente);
    system("pause");


    menu();
}





#endif // PACIENTE_H_INCLUDED
