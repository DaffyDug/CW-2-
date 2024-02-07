#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;
class ConsoleController
{
public:
    void SetColor(WORD wAttributes)
    {
        // функция для смена цвета
        HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hOUTPUT, wAttributes);
    }
    void SetPos(COORD dwCursorPosition) 
    {
        // функция для установки позиции каретки по координатам
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
    }
    void SetPos(int y, int x) 
    {
        COORD cd;
        cd.X = x;
        cd.Y = y;
        SetPos(cd);
    }
};

