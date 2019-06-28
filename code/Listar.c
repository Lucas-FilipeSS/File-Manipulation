#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

//FILE *fp;

void MostrarTelaList()
{
    Profissoes A;
    int i=0;
    i=0;
    fseek(fp,0, SEEK_SET);
    while(fread(&A, sizeof(Profissoes), 1, fp))
    {
        if(strcmp(A.profissao, "0") != 0)
        {
            i++;
        }
    }
    fseek(fp,0, SEEK_SET);
    if (i==1 || i==0)
    {
        i=18;
    }
    else if (i==2)
    {
        i=18+i*4;
    }
    else
    {
        i=18+(i-1)*8;
    }
    fseek(fp,0, SEEK_SET);
    if (fread(&A, sizeof(Profissoes), 1, fp)==0)
    {
        i=18;
    }
    fseek(fp,0, SEEK_SET);

    TextColor(15);
    gotoxy(37,4);
    printf("LISTA");
    TextColor(3);
    caixa(5,2,75,i);
    caixa(18,3,62,5);

}
void Listar()
{
    Profissoes A;
    int ent,t,total=0,cont=0,a=10,b=11,c=12,d=13,e=14,f=15,g=16;
    fseek(fp,0, SEEK_SET);

    if (fread(&A, sizeof(Profissoes), 1, fp)==0)
    {
        TextColor(15);
        gotoxy(21,10);
        printf("NAO HA NADA NO ARQUIVO PARA LISTAR!");
        gotoxy(17,15);
        printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
        ent=getch();
        fseek(fp,0, SEEK_SET);
        return;
    }
    fseek(fp,0, SEEK_SET);

    while(fread(&A, sizeof(Profissoes), 1, fp))
    {
        if(strcmp(A.profissao, "0") != 0)
        {
            TextColor(15);
            gotoxy(7,a);
            printf("PROFISSAO: %s\n", A.profissao);
            gotoxy(7,b);
            printf("REGULAMENTACAO: %s\n", A.regulamentacao);
            gotoxy(7,c);
            printf("RISCO: %s\n", A.risco);
            gotoxy(7,d);
            printf("AREA DE CONHECIMENTO: %s\n", A.areadeconhecimento);
            gotoxy(7,e);
            printf("NIVEL DE ESCOLARIDADE EXIGIDO: %s\n", A.exigenciadeescolaridade);
            gotoxy(7,f);
            printf("JORNADA DE TRABALHO: %d\n", A.jornadadetrabalho);
            gotoxy(7,g);
            printf("SALARIO MEDIO %.2lf\n", A.salariomedio);
            total++;
            a+=8;
            b+=8;
            c+=8;
            d+=8;
            e+=8;
            f+=8;
            g+=8;

        }
        else
        {
            cont++;
        }
    }
    TextColor(15);
    gotoxy(7,8);
    printf("EXISTEM %d PROFISSAO(OES) LISTADA(S)!", total);
    fseek(fp,0, SEEK_END);
    t=ftell(fp);
    if ((cont*272)==t)
    {
        TextColor(15);
        gotoxy(7,10);
        printf("OS REGISTROS JA FORAM APAGADOS!");
        cont=0;
        fseek(fp,0, SEEK_SET);
        ent=getch();
        return;
    }
    ent=getch();
}
