#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

int op=0;
char c,senha[50], nome_user[10];


void cabecalho(){
printf("\n                    Seja Bem Vindo (id): ");
printf(ANSI_COLOR_YELLOW "%s", nome_user);
printf(ANSI_COLOR_RESET "\n");
asteriscos(45,20);
printf("\n                    CADASTRO DE PACIENTES POSITIVOS PARA COVID-19\n");
asteriscos(45,20);
}

void asteriscos(int n, int s){
    for (int i=1; i<=s; i++){
        printf(" ");
    }
    for (int i=1; i<=n; i++)
        printf("*");
}

void linhas(){
    for (int j=1; j<=10; j++){
            printf("\n");
        }
}

void espaco(){
for (int i=1; i<=30; i++){
        printf(" ");
     }
}

void erroid(){
linhas();
espaco();
    for (int i=0; i<26; i++)
    printf("*");
printf("\n");
espaco();
printf(ANSI_COLOR_RED "*** ID/SENHA INCORRETA ***\n"ANSI_COLOR_RESET);
espaco();
for (int i=0; i<26; i++)
    printf("*");
}

int validasenha(){
do{

           linhas();
           int a=0;
           fflush(stdin);
           espaco();
           printf("Digite o Usuário (id): ");
           gets(nome_user);
           fflush(stdin);
           espaco();
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


// Trabalhando com Datas
#include <time.h>
void Validanascimento(){
    char dtNascimento[15];
    struct tm *data_hora_atual; //ponteiro para struct que armazena data e hora
    time_t segundos; //variável do tipo time_t para armazenar o tempo em segundos
    time(&segundos); //obtendo o tempo em segundos
    data_hora_atual = localtime(&segundos); //para converter de segundos para o tempo local utilizando a função localtime

  printf("\nHora ........: %d:",data_hora_atual->tm_hour);//hora
  printf("%d:",data_hora_atual->tm_min);//minuto
  printf("%d\n",data_hora_atual->tm_sec);//segundo


  printf("\nData ........: %d/", data_hora_atual->tm_mday);
  printf("%d/",data_hora_atual->tm_mon+1); //mês
  printf("%d\n\n",data_hora_atual->tm_year+1900); //ano


  char buffer[11]; // estava char *buffer
  char hora[10];

  snprintf (buffer, sizeof(buffer), "%d/%d/%d",data_hora_atual->tm_mday,data_hora_atual->tm_mon+1,data_hora_atual->tm_year+1900);
  snprintf (hora, sizeof(hora), "%d:%d:%d",data_hora_atual->tm_hour,data_hora_atual->tm_min,data_hora_atual->tm_sec);

  printf("%s", buffer);
  printf("\n%s", hora);

  printf("\n");
  puts("Digite a data de nascimento: (dd/mm/aaaa) ");
  int a=0;
  char c;
   fflush(stdin);
  do {
    c = getch();
      if (a!=10){
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

void menu(){
    cabecalho();
int opcao=0;
    do {
        printf("\n\n\n");
            asteriscos(0,20);
        printf(ANSI_COLOR_YELLOW "********** MENU PRINCIPAL ********** \n" ANSI_COLOR_RESET);
            asteriscos(0,20);
        printf("****** 1 - Cadastrar Paciente ****** \n");
            asteriscos(0,20);
        printf("****** 2 - Encerrar Programa  ****** \n");
        asteriscos(36,20);
        printf("\n\n\n");
            asteriscos(0,20);
        printf(ANSI_COLOR_RED "Escolha a sua opção e (Pressione ENTER): " ANSI_COLOR_YELLOW);
        scanf("%i", &opcao);
            if (opcao == 1){
                paciente();
            }

    } while (opcao !=2);

    system("cls");
    puts("ENCERRANDO O PROGRAMA!");

}

#endif // FUNCTIONS_H_INCLUDED
