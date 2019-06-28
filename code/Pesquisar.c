#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

void MostrarTelaPesq()
{
    TextColor(15);
    gotoxy(35,4);
    printf("PESQUISAR");
    gotoxy(30,7);
    printf("DIGITE A PROFFISAO!");
    gotoxy(8,10);
    printf("PROFISSAO");
    TextColor(3);
    caixa(5,2,75,20);
    caixa(18,3,62,5);
    caixa(18,9,62,11);

}

void Pesquisar()
{
    char pesq[51];
    int ent,cont=0,t;
    Profissoes A;
    fseek(fp,0, SEEK_SET);
    if (fread(&A, sizeof(Profissoes), 1, fp)==0)
    {
        TextColor(15);
        gotoxy(30,12);
        printf("O ARQUIVO ESTA VAZIO!");
        gotoxy(18,15);
        printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
        ent = getch();
        fseek(fp,0, SEEK_SET);
        printf("\n");
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


    TextColor(15);
    gotoxy(19,10);
    scanf("%s", pesq);

    while(!feof(fp))
    {
        if (fread(&A, sizeof(Profissoes), 1, fp))
        {

            if (strcmp(A.profissao, pesq) == 0)
            {
                system("cls");
                TextColor(15);
                gotoxy(34,4);
                printf("ENCONTRADO!");
                gotoxy(8,8);
                printf("PROFISSAO");
                gotoxy(7,11);
                printf("REGULAMENTACAO");
                gotoxy(12,14);
                printf("RISCO");
                gotoxy(7,17);
                printf("AREA DE CONHECIMENTO");
                gotoxy(7,20);
                printf("NIVEL DE ESCOLARIDADE EXIGIDO");
                gotoxy(7,23);
                printf("JORNADA DE TRABALHO");
                gotoxy(7,26);
                printf("SALARIO MEDIO");

                TextColor(3);
                caixa(5,2,75,30);
                caixa(18,3,62,5);
                caixa(18,7,62,9);
                caixa(22,10,62,12);
                caixa(18,13,62,15);
                caixa(28,16,62,18);
                caixa(37,19,62,21);
                caixa(27,22,62,24);
                caixa(21,25,62,27);

                TextColor(15);
                gotoxy(19,8);
                printf("%s", A.profissao);
                gotoxy(23,11);
                printf("%s", A.regulamentacao);
                gotoxy(19,14);
                printf("%s", A.risco);
                gotoxy(29,17);
                printf("%s", A.areadeconhecimento);
                gotoxy(38,20);
                printf("%s", A.exigenciadeescolaridade);
                gotoxy(28,23);
                printf("%d", A.jornadadetrabalho);
                gotoxy(22,26);
                printf("%.2lf", A.salariomedio);
                gotoxy(16,29);
                fseek(fp,0, SEEK_SET);
                printf("PRESSIONE QUALQUER TECLA PARA VOLTAR AO MENU.");
                ent = getch();
                return;
            }
        }
        else
        {
            TextColor(15);
            gotoxy(23,13);
            printf("OPS... PROFISSAO NAO ENCONTRADA.");

            char opcoes[3][25]= {"PESQUISAR NOVAMENTE", "CADASTRAR", "VOLTAR"};
            int cols[3] = {12,37,54};
            int opcao = 0, i, tecla;
            TextColor(15);
            for(i=0; i<3; i++)
            {
                gotoxy(cols[i],16);
                printf("%-8s", opcoes[i]);
            }
            while(1)
            {
                TextColor(3);
                gotoxy(cols[opcao],16);
                printf("%-8s", opcoes[opcao]);
                tecla = getch();
                if (tecla == 27)
                    return;
                TextColor(15);
                gotoxy(cols[opcao],16);
                printf("%-8s", opcoes[opcao]);
                TextColor(15);
                if (tecla == 77)
                    opcao++;
                if (tecla == 75)
                    opcao--;
                if (tecla == 13)
                {
                    if (opcao==0)
                    {
                        system("cls");
                        MostrarTelaPesq();
                        Pesquisar();
                        return;
                    }
                    if (opcao==1)
                    {
                        system("cls");
                        MostrarTelaDig();
                        A=DigitarProfissao();
                        return;

                    }
                    if (opcao==2)
                    {
//                        Menu();
                        return;

                    }

                }

                if (opcao < 0)
                    opcao = 2;
                if (opcao > 2)
                    opcao = 0;
            }

            fseek(fp,0, SEEK_SET);
            ent = getch();
        }
    }
}
