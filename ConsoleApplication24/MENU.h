#define _CRT_SECURE_NO_WARNINGS
#include "ConsoleController.h"
class MENU
{
	char menu[10][100];
	int selectedItem;
	int Lenght;
	char arrow;
	WORD selectColor;
	WORD color;
	WORD backColor;
	ConsoleController consolecontroller;
public:
	MENU()
	{
		Lenght = 0;
		selectColor = 5;
		color = 7;
		backColor = 5;
		arrow = '>';
		selectedItem = -1;
	}

	void setARROW()
	{
		this->arrow = arrow;
	}
	void setBackColor(WORD col)
	{
		backColor = col;
	}
	void setColor(WORD col)
	{
		color = col;
	}
	void setSelectedColor(WORD col)
	{
		selectColor = col;
	}
	int getselectItrem()
	{
		return selectedItem;
	}




	void AddItem(const char item[])
	{
		strcpy_s(menu[Lenght], item);
		Lenght++;
	}

	void PrevItem()
	{
		selectedItem -= 1;
		if (selectedItem < 0)
			selectedItem = Lenght - 1;
	}
	void NEXTITEM()
	{
		selectedItem += 1;
		if (selectedItem == Lenght)
		{
			selectedItem = 0;
		}
	}

	void Show()
	{
		system("cls");

		for (int i = 0; i < Lenght; i++)
		{
			consolecontroller.SetPos(3 + i, 17);
			consolecontroller.SetColor(color);
			if (i == selectedItem)
			{
				consolecontroller.SetColor(selectColor);
				cout << arrow;

			}
			cout << menu[i] << endl;
		}
	}
	void drawramka(int width, int height)
	{
		consolecontroller.SetColor(backColor);
		consolecontroller.SetPos(2, 10);
		cout << char(201);
		for (int i = 0; i < width; i++)
		{
			cout << char(205);
		}
		cout << char(187);
		for (int i = 0; i < height; i++)
		{
			consolecontroller.SetPos(3 + i, 10);
			cout << char(186);
			consolecontroller.SetPos(3 + i, 11 + width);
			cout << char(186);
		}
		consolecontroller.SetPos(3 + height, 10);
		cout << char(200);
		for (int i = 0; i < width; i++)
		{
			cout << char(205);
		}
		cout << char(188);
	}

};

