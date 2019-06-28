
#ifndef TRABALHO_H_INCLUDED
#define TRABALHO_H_INCLUDED

FILE *fp;
FILE *rp;
struct profissoes
{
    char profissao[51];
    char areadeconhecimento[51];
    char exigenciadeescolaridade[51];
    char regulamentacao[51];
    int jornadadetrabalho;
    char risco[51];
    double salariomedio;
};

typedef struct profissoes Profissoes;
void Abrirarquivo();
void Fecharsair();
Profissoes DigitarProfissao();
Profissoes DigitarProfissao2();
void MostrarTelaDig();
void MostrarTelaDig2();
void gotoxy(int x, int y);
void TextColor(int Cor);
void caixa(int x, int y, int x1, int y1);
int Menu();
void MostrarTela2();
void Listar();
void MostrarTelaList();
void Excluir();
void MostrarTelaExc();
void Alterar();
void MostrarTelaAlt();
void Pesquisar();
void MostrarTelaPesq();
void Relatorio();
void MostrarTelaRel();
void MostrarTela3();

#endif // TRABALHO_H_INCLUDED
