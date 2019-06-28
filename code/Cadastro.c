#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

//FILE *fp;

void MostrarTelaDig()
{
    TextColor(15);
    gotoxy(35,4);
    printf("CADASTRO");
    TextColor(3);
    caixa(5,2,75,30);
    caixa(18,3,62,5);
}

Profissoes DigitarProfissao()
{
    Profissoes A;
    int i,ent;

    TextColor(15);
    gotoxy(8,8);
    printf("PROFISSAO");
    TextColor(3);
    caixa(18,7,62,9);
    TextColor(15);
    gotoxy(19,8);
    scanf("%s", A.profissao);

    TextColor(15);
    gotoxy(7,11);
    printf("REGULAMENTACAO");
    TextColor(3);
    caixa(22,10,62,12);
    TextColor(15);
    gotoxy(23,11);
    scanf("%s", A.regulamentacao);

    TextColor(15);
    gotoxy(12,14);
    printf("RISCO");
    TextColor(3);
    caixa(18,13,62,15);
    TextColor(15);
    gotoxy(19,14);
    scanf("%s", A.risco);

    TextColor(15);
    gotoxy(7,17);
    printf("AREA DE CONHECIMENTO");
    TextColor(3);
    caixa(28,16,62,18);
    TextColor(15);
    gotoxy(29,17);
    scanf("%s", A.areadeconhecimento);

    TextColor(15);
    gotoxy(7,20);
    printf("NIVEL DE ESCOLARIDADE EXIGIDO");
    TextColor(3);
    caixa(37,19,62,21);
    TextColor(15);
    gotoxy(38,20);
    scanf("%s", A.exigenciadeescolaridade);
    gotoxy(28,23);

    TextColor(15);
    gotoxy(7,23);
    printf("JORNADA DE TRABALHO");
    TextColor(3);
    caixa(27,22,62,24);
    TextColor(15);
    gotoxy(28,23);
    scanf("%d", &A.jornadadetrabalho);

    TextColor(15);
    gotoxy(7,26);
    printf("SALARIO MEDIO");
    TextColor(3);
    caixa(21,25,62,27);
    TextColor(15);
    gotoxy(22,26);
    scanf("%lf", &A.salariomedio);

    fseek(fp,0,SEEK_END);
    fwrite(&A, sizeof(Profissoes), 1, fp);

    TextColor(15);
    gotoxy(31,29);
    printf("CADASTRO SALVO!");
    ent = getch();
    return A;
}
void MostrarTelaDig2()
{
    TextColor(15);
    gotoxy(31,4);
    printf("ALTERAR CADASTRO");
    gotoxy(23,7);
    printf("DIGITE OS NOVOS DADOS DO CADASTRO!");
    TextColor(3);
    caixa(5,2,75,31);
    caixa(18,3,62,5);
}

Profissoes DigitarProfissao2()
{
    Profissoes A;
    int i,ent;


    TextColor(15);
    gotoxy(8,10);
    printf("PROFISSAO");
    TextColor(3);
    caixa(18,9,62,11);
    TextColor(15);
    gotoxy(19,10);
    scanf("%s", A.profissao);

    TextColor(15);
    gotoxy(7,13);
    printf("REGULAMENTACAO");
    TextColor(3);
    caixa(22,12,62,14);
    TextColor(15);
    gotoxy(23,13);
    scanf("%s", A.regulamentacao);

    TextColor(15);
    gotoxy(12,16);
    printf("RISCO");
    TextColor(3);
    caixa(18,15,62,17);
    TextColor(15);
    gotoxy(19,16);
    scanf("%s", A.risco);

    TextColor(15);
    gotoxy(7,19);
    printf("AREA DE CONHECIMENTO");
    TextColor(3);
    caixa(28,18,62,20);
    TextColor(15);
    gotoxy(29,19);
    scanf("%s", A.areadeconhecimento);

    TextColor(15);
    gotoxy(7,22);
    printf("NIVEL DE ESCOLARIDADE EXIGIDO");
    TextColor(3);
    caixa(37,21,62,23);
    TextColor(15);
    gotoxy(38,22);
    scanf("%s", A.exigenciadeescolaridade);


    TextColor(15);
    gotoxy(7,25);
    printf("JORNADA DE TRABALHO");
    TextColor(3);
    caixa(27,24,62,26);
    TextColor(15);
    gotoxy(28,25);
    scanf("%d", &A.jornadadetrabalho);

    TextColor(15);
    gotoxy(7,28);
    printf("SALARIO MEDIO");
    TextColor(3);
    caixa(21,27,62,29);
    TextColor(15);
    gotoxy(22,28);
    scanf("%lf", &A.salariomedio);

    fseek(fp,-sizeof(Profissoes),SEEK_CUR);
    fwrite(&A, sizeof(Profissoes), 1, fp);

    TextColor(15);
    gotoxy(31,30);
    printf("CADASTRO ALTERADO!");
    ent = getch();
    return A;
}
