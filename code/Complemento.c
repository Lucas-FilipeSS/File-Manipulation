#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Profissoes.h"
#include <string.h>

//FILE*fp;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void TextColor(int Cor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),Cor);
}
void caixa(int x, int y, int x1, int y1)
{
    int i;
    gotoxy(x,y);
    printf("\xDA");
    for (i=x+1; i<x1; i++)
    {
        gotoxy(i,y);
        printf("\xC4");
        gotoxy(i,y1);
        printf("\xC4");
    }
    gotoxy(x1,y);
    printf("\xBF");
    for(i=y+1; i<y1; i++)
    {
        gotoxy(x,i);
        printf("\xB3");
        gotoxy(x1,i);
        printf("\xB3");
    }
    gotoxy(x,y1);
    printf("\xC0");
    gotoxy(x1,y1);
    printf("\xD9");
}




