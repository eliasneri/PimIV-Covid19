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
}Paciente;
Paciente NPaciente;



// ACRESCENTAR OPÇÃO PARA VOLTAR AO MENU!!! USANDO A TECLA ESC !!!

void paciente(){

    memset (NPaciente.nome,'\0',80);
    memset (NPaciente.cpf, '\0',13);
    memset (NPaciente.Telefone,'\0',13);
    memset (NPaciente.rua,'\0',80);
    memset (NPaciente.numero,'\0',4);
    memset (NPaciente.bairro,'\0',30);
    memset (NPaciente.cidade,'\0',30);
    memset (NPaciente.estado,'\0',2);
    memset (NPaciente.cep,'\0', 8);
    memset (NPaciente.dtNasc,'\0',11);
    memset (NPaciente.email,'\0',30);
    memset (NPaciente.dtDiag,'\0',11);
    memset (NPaciente.comorb,'\0',240);

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
    functionCPF(NPaciente.cpf);

    // CAMPO TELEFONE
    fflush(stdin);
    gotoxy(35,11);
    printf(ANSI_COLOR_RESET"Telefone: "ANSI_COLOR_YELLOW);
    functionTelefone(NPaciente.Telefone);

    //E-MAIL:
    gotoxy(10,12);
    printf(ANSI_COLOR_RESET "E-mail: " ANSI_COLOR_YELLOW);
    functionEmail(NPaciente.email);

    // CAMPO ENDEREÇO
    fflush(stdin);
    gotoxy(10,14);
    printf(ANSI_COLOR_RESET"Endereço:");
    gotoxy(10,15);
    printf(ANSI_COLOR_RESET"Rua: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.rua,80);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" | Número: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.numero,4);

    gotoxy(10,16);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Bairro: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.bairro,30);

    gotoxy(10,17);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Cidade: "ANSI_COLOR_YELLOW);
    functionFormataChar(NPaciente.cidade,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET"        Estado: "ANSI_COLOR_YELLOW);
    functionFormataCharEstado(NPaciente.estado);

    fflush(stdin);
    printf(ANSI_COLOR_RESET"    CEP: "ANSI_COLOR_YELLOW);
    functionFormataCep(NPaciente.cep);

    //CAMPO DATA DE NASCIMENTO, VALIDAÇÃO DA DATA, E VERIFICAÇÃO SE É GRUPO DE RISCO!
    fflush(stdin);
    gotoxy(10,18);
    printf(ANSI_COLOR_RESET"Data de Nascimento: "ANSI_COLOR_YELLOW);
    int idade=0;
    idade=validaIdade(NPaciente.dtNasc);
    gotoxy(45,18);
    printf(ANSI_COLOR_RESET"Idade do Paciente: ");
    grupoRisco(idade);


    //DATA DO DIAGNÓSTICO
    gotoxy(10,20);
    printf(ANSI_COLOR_RESET "Data do diagnóstico: " ANSI_COLOR_YELLOW);
    functionFormataData(NPaciente.dtDiag);

    //COMORBIDADES
    fflush(stdin);
    gotoxy(10,21);
    printf(ANSI_COLOR_RESET "Comorbidades:" ANSI_COLOR_YELLOW);
    gotoxy(10,22);
    functionComorbidades(NPaciente.comorb);

    // FIM DO CADASTRO!!!
    fflush(stdin);
    gotoxy(10,25);
    printf(ANSI_COLOR_RESET);
    tracoDecora(81,'=');
    gotoxy(37,26);
    printf(ANSI_COLOR_RESET "Gravar Registro? (s/n): " ANSI_COLOR_YELLOW);
    gotoxy(61,26);
    functionOpGravar(idade);

    // GRAVAR NOVO REGISTRO ???
    fflush(stdin);
    gotoxy(37,26);
    printf(ANSI_COLOR_RESET "                        " ANSI_COLOR_YELLOW);
    gotoxy(37,26);
    printf(ANSI_COLOR_RED "Continuar Cadastrando (s/n): " ANSI_COLOR_YELLOW);
    gotoxy(66,26);
    functionNovoPaciente();
}
//****************************************************************************************************************************
// ********* FUNÇÕES INPLICITAS DO PACIENTE!!!

void functionOpGravar(int idade){
char c;
int a=0, op=0;
fflush(stdin);
do{
    c=getch();
    if (a!=2){
        if (isprint(c)){
            if (c=='s' || c== 'S'){
                op=1;
            }
            if (c=='n' || c=='N'){
                op=2;
            }
            a++;
            printf("%c",c);
        } else if (c==8&&a){
            op=0;
            a--;
            printf("\b \b");
            }
    } else {
        op=0;
        a--;
        printf("\b \b");
    }

}while(c!=13);

    if (op==1){
        gravarDados(idade);
        return 0;
       }
    if (op==2){
     return 0;
    } else {
        functionOpGravar(idade);
    }

 }

  void gravarDados(int idade){
       gotoxy(37,26);
       printf(ANSI_COLOR_RESET "                        " ANSI_COLOR_YELLOW);
       gotoxy(37,26);
       printf(ANSI_COLOR_RED "SALVANDO DADOS EM ARQUIVO" ANSI_COLOR_YELLOW);
       fflush(stdin);
       FILE *ponteiro;
        ponteiro = fopen("CadastroGeral.txt","a");
        fprintf(ponteiro, "\n\n***************************************************\n");
        fprintf(ponteiro, "Paciente Cadastrado em: %s \n", dataHora);
        fprintf(ponteiro, "Cadastro gerado pelo ID: %s \n\n", nome_user);
        fprintf(ponteiro, "Nome: %s\n",NPaciente.nome);
        fprintf(ponteiro, "CPF: %s       -      Telefone: %s\n",NPaciente.cpf, NPaciente.Telefone);
        fprintf(ponteiro, "E-mail: %s \n\n", NPaciente.email);
        fprintf(ponteiro, "Endereço: \n");
        fprintf(ponteiro, "Rua: %s - Nº(complemento) %s\n",NPaciente.rua, NPaciente.numero);
        fprintf(ponteiro, "Bairro: %s - Cidade: %s - Estado: %s - CEP: %s", NPaciente.bairro, NPaciente.cidade, NPaciente.estado, NPaciente.cep);
        fprintf(ponteiro, "\nData de Nascimento: %s      -      Idade do Paciente: %d\n\n", NPaciente.dtNasc, idade);
        fprintf(ponteiro, "Data do Diagnóstico: %s \n", NPaciente.dtDiag);
        fprintf(ponteiro, "Comorbidades: %s \n", NPaciente.comorb);
        fprintf(ponteiro, "**********************************************************************\n");
        fclose(ponteiro);
        if (idade>=65){
            ponteiro = fopen("GRiscoC19.txt", "a");
            fprintf(ponteiro, "Paciente Cadastrado em: %s \n", dataHora);
            fprintf(ponteiro, "Cadastro gerado pelo ID: %s \n", nome_user);
            fprintf(ponteiro, "\nCEP do Paciente: %s", NPaciente.cep);
            fprintf(ponteiro, "\nIdade do Paciente: %d \n",idade);
            fprintf(ponteiro, "***************************************************\n\n");
            fclose(ponteiro);
        }

       gotoxy(37,26);
       printf(ANSI_COLOR_RESET "                        " ANSI_COLOR_YELLOW);

    return 0;
}



#endif // PACIENTE_H_INCLUDED
