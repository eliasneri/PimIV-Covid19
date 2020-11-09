#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <locale.h>
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_YELLOW "\033[1;33m"

int op=0;
char c,senha[50], nome_user[10];
main(){
    setlocale(LC_ALL, "Portuguese");
    validasenha();
    system("cls");

    printf("\nSeja Bem Vindo (id): ");
    printf(ANSI_COLOR_YELLOW "%s", nome_user);
    printf(ANSI_COLOR_RESET " - CADASTRO DE PACIENTES POSITIVOS PARA COVID-19\n");
    asteriscos();
    printf("\n\n ESCOLHA A SUA OPÇÃO: ");




}

void (gravarRegistro){
    FILE *PTRARQ;
    char PALAVRA[20];
    PTRARQ = fopen("ARQTXT01.txt", "a");
    printf("\n\nEscreva uma palavra: ");
    scanf("%s", PALAVRA);
    fprintf(PTRARQ, "\n%s", PALAVRA);
    fclose(PTRARQ);
    return 0;
}


void asteriscos(){
    for (int i=1; i<=80; i++)
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

