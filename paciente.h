#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

typedef struct Paciente{
    char nome[80];
    char cpf [13];
    char Telefone[13];
    char rua[80];
    int numero;
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
    printf(ANSI_COLOR_RED "Inclus�o de Novo Registro!" ANSI_COLOR_RESET);

    // FORMATA��O DE DADOS!!!

    printf("\n\n");
    printf("          ==================================================================\n");
    printf(ANSI_COLOR_YELLOW "                                DADOS DO PACIENTE" ANSI_COLOR_RESET);
    printf("\n");
    printf("          Nome : ");
    gets(NPaciente.nome);
    alteraNome();




    printf("\n\n          CPF :");
    printf("          Telefone: ");
    printf("\n\n          Endere�o:");
    printf("\n\n          Rua: ");
    printf("          N�mero: ");
    printf("\n\n          Bairro: ");
    printf("          Cidade: ");
    printf("          Estado: ");
    printf("          CEP: ");
    printf("\n\n          Data de nascimento: ");
    printf("          E-mail: ");
    printf("\n\n          Data do diagn�stico: ");
    printf("\n\n          Comorbidades (s/n)? Quais: ");
    printf("\n\n          ==================================================================\n");
    printf("\n");
    printf("                                 Gravar Registro? (s/n) ");

    printf("\n");
    system("pause");
    system("cls");
    menu();
}

void alteraNome(){
// Valida��o do Campo Nome!
    for (int i=0; i<=strlen(NPaciente.nome);i++){
            if (i==0) {
                NPaciente.nome[i]=toupper(NPaciente.nome[i]);

            } else if (NPaciente.nome[i] == ' '){
                      NPaciente.nome[i]=NPaciente.nome[i];
                      i++;
                      NPaciente.nome[i]=toupper(NPaciente.nome[i]);
            } else
                {
                  NPaciente.nome[i]=NPaciente.nome[i];
                }

        }
}
#endif // PACIENTE_H_INCLUDED
