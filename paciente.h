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
    char comorb [240];
};

struct Paciente NPaciente;

// ACRESCENTAR OPÇÃO PARA VOLTAR AO MENU!!! USANDO A TECLA ESC !!!

void paciente(){

    char *p;
    p=&NPaciente;

    system("cls");
    gotoxy(10,0);
    cabecalho();
    gotoxy(40,1);
    printf(ANSI_COLOR_RED "PRESSIONE ESC P/ VOLTAR!" ANSI_COLOR_RESET);
    gotoxy(37,6);
    printf(ANSI_COLOR_RED "Inclusão de Novo Registro!!" ANSI_COLOR_RESET);

    // FORMATAÇÃO DE DADOS!!!

    gotoxy(10,07);
    tracoDecora(81,'=');
    gotoxy(42,8);
    printf(ANSI_COLOR_YELLOW "DADOS DO PACIENTE" ANSI_COLOR_RESET);
    gotoxy(10,9);
    tracoDecora(81,'=');


    // CAMPO NOME! PREENCHE E FORMATA!
    fflush(stdin);
    gotoxy(10,10);
    printf("Nome : "ANSI_COLOR_YELLOW);

    functionFormataChar(NPaciente.nome,80);

    // CAMPO CPF
    fflush(stdin);
    gotoxy(10,11);
    printf(ANSI_COLOR_RESET"CPF : "ANSI_COLOR_YELLOW);
    //functionCPF(NPaciente.cpf);

    // CAMPO TELEFONE
    fflush(stdin);
    gotoxy(35,11);
    printf(ANSI_COLOR_RESET"Telefone: "ANSI_COLOR_YELLOW);
    //functionTelefone(NPaciente.Telefone);

    //E-MAIL:
    gotoxy(10,12);
    printf(ANSI_COLOR_RESET "E-mail: " ANSI_COLOR_YELLOW);
    //functionEmail(NPaciente.email);

    // CAMPO ENDEREÇO
    fflush(stdin);
    gotoxy(10,14);
    printf(ANSI_COLOR_RESET"Endereço:");
    gotoxy(10,15);
    printf(ANSI_COLOR_RESET"Rua: "ANSI_COLOR_YELLOW);
    //functionFormataChar(NPaciente.rua,80);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" | Número: "ANSI_COLOR_YELLOW);
    //functionFormataChar(NPaciente.numero,4);

    gotoxy(10,16);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Bairro: "ANSI_COLOR_YELLOW);
   // functionFormataChar(NPaciente.bairro,30);

    gotoxy(10,17);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Cidade: "ANSI_COLOR_YELLOW);
    //functionFormataChar(NPaciente.cidade,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" Estado: "ANSI_COLOR_YELLOW);
    //functionFormataCharEstado(NPaciente.estado);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" CEP: "ANSI_COLOR_YELLOW);
    //functionFormataCep(NPaciente.cep);

    // CAMPO DATA DE NASCIMENTO, VALIDAÇÃO DA DATA, E VERIFICAÇÃO SE É GRUPO DE RISCO!
    fflush(stdin);
    gotoxy(10,18);
    printf(ANSI_COLOR_RESET"Data de Nascimento: "ANSI_COLOR_YELLOW);
    int idade=0;
    //idade=validaIdade(NPaciente.dtNasc);
    gotoxy(43,18);
    printf(ANSI_COLOR_RESET"Idade do Paciente: ");
    //grupoRisco(idade);


    //DATA DO DIAGNÓSTICO
    gotoxy(10,20);
    printf(ANSI_COLOR_RESET "Data do diagnóstico: " ANSI_COLOR_YELLOW);
    //functionFormataData(NPaciente.dtDiag);

    //COMORBIDADES
    fflush(stdin);
    gotoxy(10,21);
    printf(ANSI_COLOR_RESET "Comorbidades:" ANSI_COLOR_YELLOW);
    gotoxy(10,22);
    functionComorbidades(NPaciente.comorb);

    // FIM DO CADASTRO!!!
    gotoxy(10,25);
    printf(ANSI_COLOR_RESET);
    tracoDecora(81,'=');
    gotoxy(37,26);
    printf(ANSI_COLOR_RESET "Gravar Registro? (s/n): " ANSI_COLOR_YELLOW);

    gotoxy(61,26);
    functionOpGravar(NPaciente, idade, p);
//    functionNovoPaciente();

    gotoxy(37,27);
    printf(ANSI_COLOR_RED "Continuar Cadastrando (s/n): " ANSI_COLOR_YELLOW);
    printf("\n");
    system("pause");
    system("cls");
    printf("%s", NPaciente.nome);
    system("pause");
    menu();
}





#endif // PACIENTE_H_INCLUDED
