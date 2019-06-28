#include <stdio.h>
#include <stdlib.h>
#include "Profissoes.h"
int main()
{
    Abrirarquivo();
    int opcao, ent;
    while(1){
        opcao = Menu();
        if (opcao == 0)
        {
            system("cls");
            MostrarTelaDig();
            DigitarProfissao();
        }
        if (opcao == 1)
        {
            system ("cls");
            MostrarTelaAlt();
            Alterar();
        }
        if (opcao == 2)
        {
            system("cls");
            MostrarTelaExc();
            Excluir();
        }
        if (opcao == 3)
        {
            system("cls");
            MostrarTelaPesq();
            Pesquisar();
        }
        if (opcao == 4)
        {
            system("cls");
            MostrarTelaList();
            Listar();
        }
        if (opcao == 5)
        {
            system("cls");
            MostrarTelaRel();
            Relatorio();
        }
        if (opcao == 6)
        {
            Fecharsair();
            gotoxy(35,15);printf("TCHAU!\n\n\n\n\n\n");
            ent = getch();
            return 0;
        }
    }
}
