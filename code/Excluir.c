#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

//FILE *fp;

void MostrarTelaExc()
{
    TextColor(15);
    gotoxy(35,4);
    printf("EXCLUIR");
    gotoxy(18,7);
    printf("DIGITE O NOME DO CADASTRO QUE DESEJA EXCLUIR!");
    gotoxy(8,10);
    printf("PROFISSAO");
    TextColor(3);
    caixa(5,2,75,27);
    caixa(18,3,62,5);
    caixa(18,9,62,11);

}
void Excluir()
{
    char pesq[51];
    int ent, cont=0,t;
    Profissoes A;
    fseek(fp,0, SEEK_SET);
    if (fread(&A, sizeof(Profissoes), 1, fp)==0)
    {
        TextColor(15);
        gotoxy(30,13);
        printf("O ARQUIVO ESTA VAZIO!");
        gotoxy(18,16);
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
        gotoxy(23,13);
        printf("OS REGISTROS JA FORAM APAGADOS!");
        cont=0;
        fseek(fp,0, SEEK_SET);
        ent=getch();
        return;
    }

    TextColor(15);
    gotoxy(19,10);
    scanf("%s", pesq);
    fseek(fp,0, SEEK_SET);
    while(!feof(fp))
    {
        if (fread(&A, sizeof(Profissoes), 1, fp))
        {
            if (strcmp(A.profissao, pesq) == 0)
            {
//            system("cls");
                TextColor(15);
                gotoxy(35,13);
                printf("ENCONTRADO!");
                TextColor(15);
                gotoxy(7,15);
                printf("PROFISSAO: %s\n", A.profissao);
                gotoxy(7,16);
                printf("REGULAMENTACAO: %s\n", A.regulamentacao);
                gotoxy(7,17);
                printf("RISCO: %s\n", A.risco);
                gotoxy(7,18);
                printf("AREA DE CONHECIMENTO: %s\n", A.areadeconhecimento);
                gotoxy(7,19);
                printf("NIVEL DE ESCOLARIDADE EXIGIDO: %s\n", A.exigenciadeescolaridade);
                gotoxy(7,20);
                printf("JORNADA DE TRABALHO: %d\n", A.jornadadetrabalho);
                gotoxy(7,21);
                printf("SALARIO MEDIO %.2lf\n", A.salariomedio);
                char opcoes[3][25]= {"EXCLUIR CADASTRO", "PESQUISAR", "VOLTAR"};
                int cols[3] = {15,37,54};
                int opcao = 0, i, tecla;
                TextColor(15);
                for(i=0; i<3; i++)
                {
                    gotoxy(cols[i],23);
                    printf("%-8s", opcoes[i]);
                }
                while(1)
                {
                    TextColor(3);
                    gotoxy(cols[opcao],23);
                    printf("%-8s", opcoes[opcao]);
                    tecla = getch();
                    if (tecla == 27)
                        break;
                    TextColor(15);
                    gotoxy(cols[opcao],23);
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
                                fseek(fp,-sizeof(Profissoes),SEEK_CUR);
                                strcpy(A.profissao,"0");
                                strcpy(A.regulamentacao,"0");
                                strcpy(A.risco,"0");
                                strcpy(A.areadeconhecimento,"0");
                                strcpy(A.exigenciadeescolaridade,"0");
                                A.jornadadetrabalho=0;
                                A.salariomedio=0;
                                fwrite(&A, sizeof(Profissoes), 1, fp);
                                fseek(fp,0, SEEK_SET);
                                TextColor(15);
                                gotoxy(24,25);
                                printf("DADOS EXCLUIDOS COM SUCESSO!");
                                ent=getch();
                                fseek(fp,0, SEEK_SET);
                                return;
                        }
                        if (opcao==1)
                        {
                            system("cls");
                            MostrarTelaAlt();
                            Alterar();
                            return;

                        }
                        if (opcao==2)
                        {
                            return;

                        }

                    }

                    if (opcao < 0)
                        opcao = 2;
                    if (opcao > 2)
                        opcao = 0;
                }


            }
        }
        else
        {
            TextColor(15);
            gotoxy(23,14);
            printf("OPS... PROFISSAO NAO ENCONTRADA.");

            char opcoes[3][25]= {"PESQUISAR NOVAMENTE", "CADASTRAR", "VOLTAR"};
            int cols[3] = {12,37,54};
            int opcao = 0, i, tecla;
            TextColor(15);
            for(i=0; i<3; i++)
            {
                gotoxy(cols[i],17);
                printf("%-8s", opcoes[i]);
            }
            while(1)
            {
                TextColor(3);
                gotoxy(cols[opcao],17);
                printf("%-8s", opcoes[opcao]);
                tecla = getch();
                if (tecla == 27)
                    break;
                TextColor(15);
                gotoxy(cols[opcao],17);
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
                        MostrarTelaExc();
                        Excluir();
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
