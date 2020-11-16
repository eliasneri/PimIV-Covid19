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
    char dtNascOk[11];
    char email[30];
    char dtDiag [11];
    char comorb [400];
};

struct Paciente NPaciente;


void paciente(){
    fflush(stdin);
    system("cls");

    espaco();
    cabecalho();
    printf("\n\n");
    espaco();
    printf(ANSI_COLOR_RED "    Inclusão de Novo Registro!" ANSI_COLOR_RESET);

    // FORMATAÇÃO DE DADOS!!!

    printf("\n");
    printf("          ==============================================================================\n");
    printf(ANSI_COLOR_YELLOW "                                        DADOS DO PACIENTE" ANSI_COLOR_RESET);
    printf("\n");
    printf("          ==============================================================================\n");

    // CAMPO NOME! PREENCHE E FORMATA!
    printf("          Nome : "ANSI_COLOR_YELLOW);
    NPaciente.nome;
    functionFormataChar(NPaciente.nome,80);

    // CAMPO CPF
    fflush(stdin);
    printf(ANSI_COLOR_RESET"\n          CPF : "ANSI_COLOR_YELLOW);
    functionCPF(NPaciente.cpf);

    // CAMPO TELEFONE
    fflush(stdin);
    printf(ANSI_COLOR_RESET" Telefone: "ANSI_COLOR_YELLOW);
    functionTelefone(NPaciente.Telefone);

    // CAMPO ENDEREÇO
    fflush(stdin);
    printf(ANSI_COLOR_RESET"\n\n          Endereço:");
    printf(ANSI_COLOR_RESET"\n          Rua: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.rua,80);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" | Número: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.numero,4);

    fflush(stdin);
    printf(ANSI_COLOR_RESET"\n          Bairro: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.bairro,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" Cidade: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.cidade,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" Estado: "ANSI_COLOR_YELLOW);
    functionFormataCharEstado(NPaciente.estado);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" CEP: "ANSI_COLOR_YELLOW);
    functionFormataCep(NPaciente.cep);

    // CAMPO DATA DE NASCIMENTO E VALIDAÇÃO DA DATA!!!
    printf("\n\n          Data de nascimento: ");
    fflush(stdin);

    printf("          E-mail: ");
    printf("\n\n          Data do diagnóstico: ");
    printf("\n\n          Comorbidades (s/n)? Quais: ");
    printf("\n\n          ==============================================================================\n");
    printf("\n");
    printf("                                 Gravar Registro? (s/n) ");

    printf("\n");
    system("pause");
    system("cls");

    printf("%s", NPaciente);
    system("pause");
    menu();
}





#endif // PACIENTE_H_INCLUDED
