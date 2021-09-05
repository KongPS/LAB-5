#define _CRT_SECURE_NO_WARNINGS 1
#include <windows.h>
#include <stdio.h>
#include <conio.h>

void draw_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf(" <-O-> ");
}
void erase_ship(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("                 ");
}

int main()
{
	char ch = ' ';
	int x = 38,y=20;
	draw_ship(x,20);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') 
			{
				if (x >= 1 && x <= 81)
				{
					draw_ship(--x, y);
				}
			}
			if (ch == 'w')
			{
				if (x >= 0 && x <= 81 && y>=1)
				{
					erase_ship(x, y);
					draw_ship(x, --y);
				}
			}
			if (ch == 's')
			{
				if (x >= 0 && x <= 81&& y<23)
				{
					erase_ship(x, y);
					draw_ship(x, ++y);
				}
			}
			if (ch == 'd')
			{
				if (x >= 0 && x <= 80)
				{
					draw_ship(++x, y);
				}
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}