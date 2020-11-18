#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

int op=0;
char c,senha[50], nome_user[10];
char dataHora[20];

void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);
    //Y é a Linha!
}

void tracoDecora(int quant, char c){
    for (int i=1; i<=quant; i++)
        printf("%c",c);
}

void finalizaProgram(){

    system("cls");
    gotoxy(30,14);
    printf(ANSI_COLOR_RED);
    tracoDecora(40,'*');
    gotoxy(69,15);
    printf("*");
    gotoxy(30,15);
    printf("*");
    gotoxy(30,16);
    tracoDecora(40,'*');
    gotoxy(41,15);
    printf(ANSI_COLOR_YELLOW "PROGRAMA  ENCERRADO!!!" ANSI_COLOR_RESET);

    gotoxy(30,20);
    exit(0);

}
void erroid(){

system("cls");

    gotoxy(30,14);
    printf(ANSI_COLOR_RED);
    tracoDecora(39,'*');
    gotoxy(68,15);
    printf("*");
    gotoxy(30,15);
    printf("*");
    gotoxy(30,16);
    tracoDecora(39,'*');
    gotoxy(32,15);
    printf(ANSI_COLOR_YELLOW "ID/SENHA INVÁLIDO!! ACESSO NEGADO!!" ANSI_COLOR_RESET);

    gotoxy(30,20);
    system("pause");
    validasenha();
}

void validasenha(){
system("cls");


    do{

        // MONTAGEM DA TELA DE LOGIN
        gotoxy(30,14);
        tracoDecora(37,'=');

        gotoxy(66,15);
        printf("=");
        gotoxy(30,15);
        printf("= Digite o Usuário (id): ");

        gotoxy(66,16);
        printf("=");
        gotoxy(30,16);
        printf("= Digite a SENHA: ");

        gotoxy(30,17);
        tracoDecora(37,'=');

        // CAMPO ID!
        int a=0;
        fflush(stdin);
        c='\0';
        gotoxy(55,15);
        printf(ANSI_COLOR_YELLOW);
           do{
              if (a!=11){
                 c=getch();
                 if (c==27){
                    fflush(stdin);
                    finalizaProgram();
                 }

                 if (isprint(c)){
                    nome_user[a]=c;
                    a++;
                    printf("%c",c);
                 } else if (c==8&&a){
                    nome_user[a]='\0';
                    a--;
                    printf("\b \b");
                 }

            } else {
                    nome_user[a]='\0';
                    a--;
                    printf("\b \b");
              }

           } while(c!=13);

        // CAMPO SENHA!
        printf(ANSI_COLOR_RED);
        gotoxy(48,16);
        c='\0';
        fflush(stdin);
        a=0;
        do{
            if(a!=11){
                c=getch();
                if (c==27){
                    fflush(stdin);
                    finalizaProgram();
                }
                if(isprint(c)){
                    senha[a]=c;
                    a++;
                    printf("*");
                } else if(c==8&&a){
                        senha[a]='\0';
                        a--;
                        printf("\b \b");
                    }
            } else {
                senha[a]='\0';
                a--;
                printf("\b \b");
            }

           }while(c!=13);

    printf(ANSI_COLOR_RESET);
    senha[a]='\0';
    system("cls");
    char scorreta[]="covid19";
    char user[]="admin";

    if (!strcmp(senha,scorreta) && (nome_user, user)) {
        op=1;
        break;
                }
    else {
        erroid();
         }

    } while (op==0);

return 0;
}

void datahora(){

  struct tm *data_hora_atual;
  time_t segundos;
  time(&segundos);
  data_hora_atual = localtime(&segundos);

  sprintf(dataHora, "%d/%d/%d - %1.2d:%1.2d", data_hora_atual->tm_mday,
          data_hora_atual->tm_mon+1,
          data_hora_atual->tm_year+1900,
          data_hora_atual->tm_hour,
          data_hora_atual->tm_min);
}
void cabecalho(){

gotoxy(10,1);
printf(ANSI_COLOR_RESET "Seja Bem Vindo (id): ");
printf(ANSI_COLOR_YELLOW "%s", nome_user);
printf(ANSI_COLOR_RESET);
gotoxy(73,1);
datahora();
printf(ANSI_COLOR_YELLOW "%s" ANSI_COLOR_RESET, dataHora );
gotoxy(10,2);
tracoDecora(81,'*');
gotoxy(28,3);
printf(ANSI_COLOR_RESET "CADASTRO DE PACIENTES POSITIVOS PARA COVID-19");
gotoxy(10,4);
tracoDecora(81,'*');

}

void menu(){
    system("cls");
    cabecalho();

int opcao=0;

        gotoxy(10,8);
        tracoDecora(81,'-');
        gotoxy(43,9);
        printf(ANSI_COLOR_YELLOW " MENU  PRINCIPAL " ANSI_COLOR_RESET);
        gotoxy(40,11);
        printf(ANSI_COLOR_YELLOW"1 -");
        printf(ANSI_COLOR_RESET" NOVO CADASTRO ");
        gotoxy(40,12);
        printf(ANSI_COLOR_YELLOW"2 -");
        printf(ANSI_COLOR_RESET" ENCERRAR O SISTEMA");
        gotoxy(10,13);
        tracoDecora(81,'-');
        gotoxy(30,17);
        printf(ANSI_COLOR_RED "Escolha a sua opção e (Pressione ENTER): " ANSI_COLOR_YELLOW);

do {
            gotoxy(71,17);
            printf(" ");
            int a=0;
            char c;
            char buffer[0];
            gotoxy(71,17);
            do{

              if (a!=2){
                 c=getch();

                 if (c==27){
                    buffer[a]='2';
                    break;
                 }
                 if (isprint(c) && isdigit(c)){
                     buffer[a]=tolower(c);
                     a++;
                     printf("%c",c);
                 } else if (c==8&&a){
                    buffer[a]='/0';
                    a--;
                    printf("\b \b");
                    }
              } else {
                    buffer[a]='/0';
                    a--;
                    printf("\b \b");
              }
            } while(c!=13);

            opcao=atoi(buffer);

            if (opcao==1){
                paciente();
            }


} while (opcao !=2);
 finalizaProgram();
    //ENCERRANDO O PROGRAMA!
}

void functionFormataChar(char container[80], int limite){
int a=0;
char c;
int aux=0;

do {
  if (a!=limite+1) {
    c=getch();
    if (c==27){
        menu();
    }
    if (isprint(c)){
        if (a==0 && c==' '){
            a=0;

        } else {
        if (a==0){
            container[a]=toupper(c);
            a++;
            printf("%c",toupper(c));

        } else
            if (c == ' '){
                container[a]=c;
                aux = a;
                a++;
                printf("%c",c);
                aux=a;

            } else
                if (aux == a){
                    container[a]=toupper(c);
                    a++;
                    printf("%c",toupper(c));
                } else
                    {
                     container[a]=c;
                     a++;
                     printf("%c",c);
                   }
        }
    } else if (c==8&&a){
        container[a]='\0';
        a--;
        printf("\b \b");
        }

  } else {
    container[0]='\0';
    a--;
    printf("\b \b");
  }
} while(c!=13);


}

void functionCPF(char container[15]){
char c;
int a=0;

    do{
       c=getch();
        if (a!=14){
            if (c==27){
                menu();
            }
            if (isprint(c) && isdigit(c)){
                container[a]=c;
                a++;
                printf("%c",c);
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
                }

            if (a==3 && c!=8 || a==7 && c!=8){
                container[a]='.';
                a++;
                printf(".");
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

            if (a==11 && c!=8){
                container[a]='-';
                a++;
                printf("-");
            } else if(c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

        } else if(c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

    } while(c != 13);

}

void functionTelefone(char container[15]){
char c;
int a=0;

do{
       c=getch();
        if (a!=14){
            if (c==27){
                menu();
            }
            if (a==0){
                container[a]='(';
                a++;
                printf("(");
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

            if (isprint(c) && isdigit(c)){
                container[a]=c;
                a++;
                printf("%c",c);

            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
                }

            if (a==3 && c!=8){
                container[a]=')';
                a++;
                printf(")");

            }else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

            if (a==8 && c!=8){
                container[a]='.';
                a++;
                printf(".");

            }else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }



        } else if (a>=13 && c==8){
            container[a]='\0';
            a--;
            printf("\b \b");
        }

    } while(c!=13);
 }

void functionFormataCharEstado(char container[1]){
int a=0;
char c;
    do{
        if (a !=3){
        c=getch();
            if (c==27){
                menu();
            }
            if (isprint(c)){
                container[a]=toupper(c);
                a++;
                printf("%c",toupper(c));
            } else if(c==8&&a){
                    container[a]='\0';
                    a--;
                    printf("\b \b");
            }
        } else {
          container[0]='\0';
          a--;
          printf("\b \b");
        }
    } while (c!=13);


}

void functionFormataCep(char container[8]){
char c;
int a=0;

do {
    if (a!=10){
            c=getch();
            if (c==27){
                menu();
            }
            if (isprint(c) && isdigit(c)){
                container[a]=c;
                a++;
                printf("%c", c);
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

            if (a==5){
                container[a]='-';
                a++;
                printf("-");
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }
    } else {
        container[a]='\0';
        a--;
        printf("\b \b");
    }


} while(c!=13);

}

int validaIdade(char container[9]){

int operador =0, idade=0;
fflush(stdin);
struct tm *data_hora_atual;
time_t segundos;
time(&segundos);
data_hora_atual = localtime(&segundos);

int anoAtual = data_hora_atual->tm_year+1900;

do {
    gotoxy(10,18);
    printf(ANSI_COLOR_RESET"Data de Nascimento: "ANSI_COLOR_YELLOW);
    char c;
    int a=0;
    do{
        if (a!=11){
            c=getch();
            if (isprint(c) && isdigit(c)){
                container[a]=c;
                a++;
                printf("%c", c);
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }

            if (a==2 && c!=8 || a==5 && c!=8){
                container[a]='/';
                a++;
                printf("/");
            } else if (c==8&&a){
                container[a]='\0';
                a--;
                printf("\b \b");
            }
        } else {
          container[a]='\0';
          a--;
          printf("\b \b");
        }

    } while (c!=13);

  if (strlen(container)==0){
    break;
    return 0;
  } else {

        // APÓS PRESSIONAR O ENTER, VERIFICA SE A DATA É VÁLIDA!!!

        char dia[1], mes[1];

        dia[0] = container[0];
        dia[1] = container[1];
        dia[2] = '\0';

        int diaI;
        diaI= atoi(dia);
        mes[0] = container[3];
        mes[1] = container[4];
        mes[2] = '\0';

        int mesI;
        mesI= atoi(mes);

        char pegaano[4];
        pegaano[0] = container[6];
        pegaano[1] = container[7];
        pegaano[2] = container[8];
        pegaano[3] = container[9];
        pegaano[4] = '\0';
        int anoI= atoi(pegaano);


            if ((diaI >1 && diaI <=31) && (mesI>=1 && mesI<=12) && (anoAtual-anoI <=120 && anoAtual-anoI !=0)){
                idade=anoAtual-anoI;
                operador=30;
             } else
                {
                    gotoxy(40,18);
                    printf("DATA INVALIDA                      ");
                    operador=0;
                    idade=0;
                }

  }

} while(operador==0);
  return idade;

}

void grupoRisco(int idade){
if (idade>=65) {
     printf(ANSI_COLOR_YELLOW "%d ANOS!!!", idade);
     printf(ANSI_COLOR_RED " GRUPO DE RISCO!!!!!" ANSI_COLOR_RESET);
     }
else
    printf("%d Anos", idade);
}

void functionEmail(char container[30]){
    int a=0;
    char c;
    int verifica=0;
    fflush(stdin);

    do{
        if (a!=31){
           c=getch();
            if (c==27){
                menu();
            }
            if (isprint(c)){
                container[a]=tolower(c);
                a++;
                printf("%c", tolower(c));
            } else if (c==8&&a){
                container[a]='/0';
                a--;
                printf("\b \b");
            }
        } else {
          container[a]='\0';
          a--;
          printf("\b \b");
        }

   } while(c!=13);
}

void functionFormataData(char container[9]){
    int a=0;
    char c;

  do {
     if (a!=10){
        c = getch();
        if (c==27){
            return 0;
        }
        if (isprint(c) && isdigit(c)){
            container[a]=c;
            a++;
            printf("%c",c);
         } else if (c==8&&a){
           container[a]='\0';
           a--;
           printf("\b \b");
        }
        if (a==2 && c!=8 || a==5 && c!=8){
            container[a] ='/';
            a++;
            printf("/");
        } else if (c==8&&a){
            container[a]='\0';
            a--;
           printf("\b \b");
        }
      }
    }while (c!=13);
return 0;
}

void functionComorbidades(char container[240]){
int a=0;
int linha=22;
int coluna=10;
char c;
    fflush(stdin);
do {
    if (a!=241){
        gotoxy(83,21);
        printf(" %d/240 ",a);
        gotoxy(coluna,linha);
        c=getch();
        if (c==27){
            menu();
        }
        if (a==80 && c!=8&&a){
            linha++;
            coluna=9;
        }

         if (a==161 && c!=8&&a){
            linha++;
            coluna=9;
        }

        if (isprint(c)){
            container[a]=c;
            a++;
            coluna++;
            printf("%c",c);

            } else if (c==8&&a){
                if (a==81){
                    linha=linha-1;
                    coluna=10+a;  // ultima posição do cursor na primeira linha!
                }
                if (a==162){
                    linha=linha-1;
                    coluna=9+(a-80); // para saber em qual coluna devo mandar o cursor!
                   }
                gotoxy(coluna,linha);
                container[a]='/0';
                printf("\b \b");
                a--;
                coluna--;



           }

    } else {
       container[a]='/0';
       a--;
       coluna--;
       printf("\b \b");
    }
 } while(c!=13);
}

void functionOpGravar(char cep[8], int idade){
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
        gravarDados();
        printf("DADOS GRAVADOS!!!");
        system("PAUSE");
        return 0;
        }
    if (op==2){
     return 0;
    } else {
        functionOpGravar(cep, idade);
    }

 }

  void gravarDados(char cep[8], int idade){
    FILE *PTRARQ;
    PTRARQ = fopen("GRiscoC19.txt", "a");
    printf("Paciente Cadastrado em: %s \n", dataHora);
    fprintf(PTRARQ, "CEP do Paciente: %s \n", cep);
    fprintf(PTRARQ, "Idade do Paciente: %s \n",idade);
    fprintf(PTRARQ, "***************************************************");
    fclose(PTRARQ);
    return 0;
}


#endif // FUNCTIONS_H_INCLUDED
