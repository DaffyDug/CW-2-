#include <iostream>
#include <time.h>
#include <conio.h>
#include "MENU.h"
using namespace std;

int main()
{
	MENU menu;
	menu.AddItem("Start Game");
	menu.AddItem("Load Game");
	menu.AddItem("Settings");
	menu.AddItem("Exit");
	menu.setSelectedColor(12);

	while (true)
	{
		menu.drawramka(25, 7);
		while (!_kbhit);
		{
			int key = _getch();

			if (key == 72)
				menu.PrevItem();
			else if (key == 80)
				menu.NEXTITEM();
			else if (key == 13)
			{
				if (menu.getselectItrem() == 2)
				{
					bool exit = false;

					MENU settings;
					settings.AddItem("Change color");
					settings.AddItem("Change Selected Color");
					settings.AddItem("Change Border Color");
					settings.AddItem("Change Arrow");
					settings.AddItem("Change color");
					settings.AddItem("Exit");
					settings.NEXTITEM();
					settings.Show();
					cin.get();
					while (!exit)
					{
						while (!_kbhit)
						{
							int key = _getch();
							if (key == 72)
								settings.PrevItem();
							else if (key == 80)
								settings.NEXTITEM();
							else if (key == 13)
							{
								switch (settings.getselectItrem())
								{
								case 4: exit = true; break;
								}
							}
							settings.Show();
						}
					}
				}
			}
			menu.Show();
		}
	}
}