#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

//FILE *fp;
void Abrirarquivo()
{

    int *nullPointer;
    nullPointer = NULL;
    fp=fopen("Arquivo.txt", "rb+");
    if (fp==nullPointer)
    {
        fp=fopen("Arquivo.txt", "wb+");
        if (fp==nullPointer)
        {
            printf("Erro ao criar arquivo\n");
            exit(1);
        }
    }
}

void Fecharsair()
{
    fclose(fp);
}

void MostrarTela2()
{
    TextColor(3);
    caixa(18,3,62,5);
    caixa(5,2,75,18);
}

int Menu()
{

    char opcoes[7][15]= {"CADASTRAR", "ALTERAR", "EXCLUIR", "PESQUISAR", "LISTAR", "RELATORIO", "SAIR"};
    int cols[7] = {8, 19, 28, 37, 48, 56, 67};
    int opcao = 0, i, tecla;
    system("cls");
    MostrarTela2();
    TextColor(15);
    gotoxy(20,4);

    printf("SEJA BEM VINDO AO CADASTRO DE PROFISSOES!");


    for(i=0; i<7; i++)
    {
        gotoxy(cols[i], 10);
        TextColor(15);
        printf("%-8s", opcoes[i]);
    }
    while(1)
    {
        TextColor(3);
        gotoxy(cols[opcao], 10);
        printf("%-8s", opcoes[opcao]);
        tecla = getch();
        if (tecla == 27)
            break;
        TextColor(15);
        gotoxy(cols[opcao],10);
        printf("%-8s", opcoes[opcao]);
        TextColor(15);
        if (tecla == 77)
            opcao++;
        if (tecla == 75)
            opcao--;
        if (tecla == 13)
            return opcao;
        if (opcao < 0)
            opcao = 6;
        if (opcao > 6)
            opcao = 0;
    }
}
