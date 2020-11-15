#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

    int idade;
    char dia[1];
    char mes[1];
    char dtNascimento[10];

void main(){
printf("hoe");
outromain();
if (idade==0){
    system("pause");
    outromain();
}
else
printf("\n\n\nRetorno %i", idade);

}



int outromain(){

    struct tm *data_hora_atual; //ponteiro para struct que armazena data e hora
    time_t segundos; //variável do tipo time_t para armazenar o tempo em segundos
    time(&segundos); //obtendo o tempo em segundos
    data_hora_atual = localtime(&segundos); //para converter de segundos para o tempo local utilizando a função localtime
    char buffer[11]; // estava char *buffer
    int anoAtual = data_hora_atual->tm_year+1900;
    printf("\n%i", anoAtual);

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
           fflush(stdin);
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
      fflush(stdin);
    }while (c!=13);

fflush(stdin);
printf("\n");


dia[0] = dtNascimento[0];
dia[1] = dtNascimento[1];

int diaI;
diaI= atoi(dia);
mes[0] = dtNascimento[3];
mes[1] = dtNascimento[4];

int mesI;
mesI= atoi(mes);

char pegaano[3];
pegaano[0] = dtNascimento[6];
pegaano[1] = dtNascimento[7];
pegaano[2] = dtNascimento[8];
pegaano[3] = dtNascimento[9];
int anoI= atoi(pegaano);

if (diaI >1 && diaI <=31){
    if (mesI >1 && mesI <=12){
        if (anoAtual-anoI <=120 && anoAtual-anoI !=0){
            printf("DATA VÁLIDA!!! sua idade é: %i anos", anoAtual-anoI);
            idade=anoAtual-anoI;}
        else
            printf("ANO INVÁlido!");
    }
     else
        printf("MÊS INVÁLIDO");
} else{
    printf("Data Inválida!");
    memset (&dtNascimento, 0, sizeof (dtNascimento) );
    memset (&dia, 0, sizeof (dia) );
    memset (&mes, 0, sizeof (mes) );

    }

}







