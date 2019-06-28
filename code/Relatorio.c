#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

void MostrarTelaRel()
{
    int ent;
    TextColor(15);
    gotoxy(35,4);
    printf("RELATORIO");
    TextColor(3);
    caixa(5,2,75,20);
    caixa(18,3,62,5);
}

void Relatorio()
{
    int ent,cont=0,t;
    rp=fopen("Relatorio.txt", "w");
    Profissoes A;

    fseek(fp,0, SEEK_SET);

    if (fread(&A, sizeof(Profissoes), 1, fp)==0)
    {
        TextColor(15);
        gotoxy(21,10);
        printf("NAO HA NADA NO ARQUIVO PARA RELATAR!");
        gotoxy(17,15);
        printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
        ent=getch();
        fseek(fp,0, SEEK_SET);
        return;
    }
    fseek(fp,0, SEEK_SET);

    while(fread(&A, sizeof(Profissoes), 1, fp))
    {
        if(strcmp(A.profissao, "0") == 0)
        {
            cont++;
        }
    }
    t=ftell(fp);
    if ((cont*272)==t)
    {
        TextColor(15);
        gotoxy(23,10);
        printf("OS REGISTROS JA FORAM APAGADOS!");
        cont=0;
        fseek(fp,0, SEEK_SET);
        ent=getch();
        return;
    }
    fseek(fp,0, SEEK_SET);

    fprintf(rp,"RELATÓRIO DE PROFISSÕES\n");

    while(fread(&A, sizeof(Profissoes), 1, fp))
    {
        if(strcmp(A.profissao, "0") != 0)
        {
            fprintf(rp,"\n");
            fprintf(rp,"Profissão: ");
            fprintf(rp,A.profissao);
            fprintf(rp,"\n");
            fprintf(rp,"A Profissão é Regulamentada?: ");
            fprintf(rp,A.regulamentacao);
            fprintf(rp,"\n");
            fprintf(rp,"O Tipo de Tarefa Exercída Envolve Riscos?: ");
            fprintf(rp,A.risco);
            fprintf(rp,"\n");
            fprintf(rp,"Área de Conhecimento: ");
            fprintf(rp,A.areadeconhecimento);
            fprintf(rp,"\n");
            fprintf(rp,"Exigência de Escolaridade: ");
            fprintf(rp,A.exigenciadeescolaridade);
            fprintf(rp,"\n");
            fprintf(rp,"Jornada de Trabalho em Horas: ");
            fprintf(rp, "%d", A.jornadadetrabalho);
            fprintf(rp,"\n");
            fprintf(rp,"Salário Médio :");
            fprintf(rp, "%.2lf", A.salariomedio);
            fprintf(rp,"\n");

        }

    }
    TextColor(15);
    gotoxy(25,10);
    printf("RELATORIO CRIADO COM SUCESSO!");
    ent=getch();
}
