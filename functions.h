#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

int op=0;
char c,senha[50], nome_user[10];


void gotoxy(int x, int y) {
    COORD c = {x, y};
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE), c);
    //Y é a Linha!
}
void asteriscos(int n){
    for (int i=1; i<=n; i++)
        printf("*");
}

void tracoIgual(int quant){
    for (int i=1; i<=quant; i++)
        printf("=");
}


void erroid(){
//linhas();
//espaco();
    for (int i=0; i<26; i++)
    printf("*");
printf("\n");
//espaco();
printf(ANSI_COLOR_RED "*** ID/SENHA INCORRETA ***\n"ANSI_COLOR_RESET);
//espaco();
for (int i=0; i<26; i++)
    printf("*");
}

int validasenha(){
do{

//           linhas();
           int a=0;
           fflush(stdin);
//           espaco();
           printf("Digite o Usuário (id): ");
           gets(nome_user);
           fflush(stdin);
//           espaco();
           printf("Digite a senha: ");
           do{
               c=getch();
               if(isprint(c)){
                    senha[a]=c;
                    a++;
                    printf("*");
               }
               else if(c==8&&a){
                    senha[a]='\0';
                    a--;
                    printf("\b \b");
                    }
           }while(c!=13);


           senha[a]='\0';
           system("cls");
           char scorreta[]="abcd";
           char user[]="admin";


           if (!strcmp(senha,scorreta) && (nome_user, user)) {
                op=1;
                break;
                }
           else {
                erroid();
                printf("\n\n");
                system("pause");
                system("cls");
           }

    } while (op==0);

     return op;
}

void cabecalho(){
gotoxy(10,1);
printf("Seja Bem Vindo (id): ");
printf(ANSI_COLOR_YELLOW "%s", nome_user);
printf(ANSI_COLOR_RESET);
gotoxy(10,2);
asteriscos(81);
gotoxy(28,3);
printf(ANSI_COLOR_RESET "CADASTRO DE PACIENTES POSITIVOS PARA COVID-19");
gotoxy(10,4);
asteriscos(81);
}

void menu(){
    cabecalho();
int opcao=0;
    do {
        gotoxy(10,8);
        asteriscos(20);
        gotoxy(10,9);
        printf(ANSI_COLOR_YELLOW "********** MENU PRINCIPAL **********" ANSI_COLOR_RESET);
        gotoxy(10,10);
        asteriscos(20);
        gotoxy(10,11);
        printf("****** 1 - Cadastrar Paciente ******");
            asteriscos(20);
        printf("****** 2 - Encerrar Programa  ****** \n");
        asteriscos(20);
        printf("\n\n\n");
            asteriscos(20);
        printf(ANSI_COLOR_RED "Escolha a sua opção e (Pressione ENTER): " ANSI_COLOR_YELLOW);
        scanf("%i", &opcao);
            if (opcao == 1){
                paciente();
            }

    } while (opcao !=2);

    system("cls");
    puts("ENCERRANDO O PROGRAMA!");

}

// Trabalhando com Datas

void Validanascimento(char dtNascimento[15]){
    struct tm *data_hora_atual;
    time_t segundos;
    time(&segundos);
    data_hora_atual = localtime(&segundos);
    int a=0;
    char c;


  do {
     if (a!=10){
        c = getch();
        if (isprint(c) && isdigit(c)){
            dtNascimento[a]=c;
            a++;
            printf("%c",c);
         } else if (c==8&&a){
           dtNascimento[a]='\0';
           a--;
           printf("\b \b");
        }
        if (a==2 && c!=8 || a==5 && c!=8){
            dtNascimento[a] ='/';
            a++;
            printf("/");
        } else if (c==8&&a){
            dtNascimento[a]='\0';
            a--;
           printf("\b \b");
        }
      }
    }while (c!=13);


printf("\n");
puts(dtNascimento);

char vano[4];
char vmes[2];
char vdia[2];
int j=5;
int v=0;


        for (int i=1; i<=4; i++){
            j++;
            vano[i] = dtNascimento[j];
            printf("%c", vano[i]);
        }

        for (int i=1; i<=2; i++){
                vmes[i] = dtNascimento[2+i];
             }

        for (int i=1; i<=2; i++){
                vdia[i] = dtNascimento[i-1];
             }

printf("\n");
puts(vano);

}

void functionFormataChar(char container[80], int limite){
int a=0;
char c;
int aux=0;

do {
  if (a!=limite+1) {
    c=getch();
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
            } else if (c==8&a){
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

void functionDataNascimento(char container[9]){

do{
    char c;
    int a=0;
    printf(ANSI_COLOR_RESET"\n\n          Data de nascimento: "ANSI_COLOR_YELLOW);
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
    gotoxy(10,16);
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
                    gotoxy(10,16);
                    printf("data inválida                      ");
                    operador=0;
                    idade=0;
                }
} while(operador==0);

return idade;

}



#endif // FUNCTIONS_H_INCLUDED
