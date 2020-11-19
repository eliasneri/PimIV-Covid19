#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

void paciente(){


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
    memset (nome,'\0',80);
    functionFormataChar(nome,80);


    // CAMPO CPF
    fflush(stdin);
    gotoxy(10,11);
    printf(ANSI_COLOR_RESET"CPF : "ANSI_COLOR_YELLOW);
    memset (cpf,'\0',13);
    functionCPF(cpf);


    // CAMPO TELEFONE
    fflush(stdin);
    gotoxy(35,11);
    printf(ANSI_COLOR_RESET"Telefone: "ANSI_COLOR_YELLOW);
    memset (Telefone,'\0',13);
    functionTelefone(Telefone);


    //E-MAIL:
    gotoxy(10,12);
    printf(ANSI_COLOR_RESET "E-mail: " ANSI_COLOR_YELLOW);
    memset (email,'\0',13);
    functionEmail(email);

    // CAMPO ENDEREÇO
    fflush(stdin);
    gotoxy(10,14);
    printf(ANSI_COLOR_RESET"Endereço:");
    gotoxy(10,15);
    printf(ANSI_COLOR_RESET"Rua: "ANSI_COLOR_YELLOW);
    memset (rua,'\0',80);
    functionFormataChar(rua,80);

    fflush(stdin);
    printf(ANSI_COLOR_RESET" | Número: "ANSI_COLOR_YELLOW);
    memset (numero,'\0',4);
    functionFormataNumero(numero);



    gotoxy(10,16);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Bairro: "ANSI_COLOR_YELLOW);
    memset (bairro,'\0',30);
    functionFormataChar(bairro,30);

    gotoxy(10,17);
    fflush(stdin);
    printf(ANSI_COLOR_RESET"Cidade: "ANSI_COLOR_YELLOW);
    memset (cidade,'\0',30);
    functionFormataChar(cidade,30);

    fflush(stdin);
    printf(ANSI_COLOR_RESET"        Estado: "ANSI_COLOR_YELLOW);
    memset (estado,'\0',2);
    functionFormataCharEstado(estado);


    teste[0]=estado[0];
    teste[1]=estado[1];
    teste[2]='\0';

    fflush(stdin);
    printf(ANSI_COLOR_RESET"    CEP: "ANSI_COLOR_YELLOW);
    memset (cep,'\0',8);
    functionFormataCep(cep);


    //CAMPO DATA DE NASCIMENTO, VALIDAÇÃO DA DATA, E VERIFICAÇÃO SE É GRUPO DE RISCO!
    fflush(stdin);
    gotoxy(10,18);
    printf(ANSI_COLOR_RESET"Data de Nascimento: "ANSI_COLOR_YELLOW);
    memset (dtNasc,'\0',11);
    int idade=0;
    idade=validaIdade(dtNasc);
    gotoxy(45,18);
    printf(ANSI_COLOR_RESET"Idade do Paciente: ");
    grupoRisco(idade);


    //DATA DO DIAGNÓSTICO
    gotoxy(10,20);
    printf(ANSI_COLOR_RESET "Data do diagnóstico: " ANSI_COLOR_YELLOW);
    memset (dtDiag,'\0',11);
    functionFormataData(dtDiag);

    //COMORBIDADES
    fflush(stdin);
    gotoxy(10,21);
    printf(ANSI_COLOR_RESET "Comorbidades:" ANSI_COLOR_YELLOW);
    gotoxy(10,22);
    memset (comorb,'\0',240);
    functionComorbidades(comorb);





    // FIM DO CADASTRO!!!
    fflush(stdin);
    gotoxy(10,25);
    printf(ANSI_COLOR_RESET);
    tracoDecora(81,'=');
    gotoxy(37,26);
    printf(ANSI_COLOR_RESET "Gravar Registro? (s/n): " ANSI_COLOR_YELLOW);
    gotoxy(61,26);
    functionOpGravar(teste, idade);

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


#endif // PACIENTE_H_INCLUDED
