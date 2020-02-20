#include"Interface.h"
#include<math.h>

HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void FixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

BOOL WINAPI SetConsoleTextAttribute
(
	_In_ HANDLE hConsoleOutput,
	_In_ WORD   wAttributes
);

void delay(int n)
{
	Sleep(n);
}

void draw_menu_()
{
	FixConsoleWindow();
	gotoxy(40, 5);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", 219);
	}
	gotoxy(40, 15);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", 219);
	}
	for (int i = 0; i <= 10; i++)
	{
		gotoxy(40, i + 5);
		printf("%c", 219);
	}
	for (int i = 0; i <= 10; i++)
	{
		gotoxy(70, i + 5);
		printf("%c", 219);
	}
	SetConsoleTextAttribute(consoleHandle, 3);
	gotoxy(50, 9);
	cout << "1.New game";
	gotoxy(50, 10);
	cout << "2.Load game";
	gotoxy(50, 11);
	cout << "3.Settings";
	delay(500);
	gotoxy(50, 15);
}

void draw_menu()
{
	FixConsoleWindow();
	gotoxy(40, 10);
	if (1)
		SetConsoleTextAttribute(consoleHandle, 10);
	cout << "WELCOME TO GAME ROAD CROSSING";
	for (int i = 0; i < 101; i += 10)
	{
		delay(300);
		gotoxy(53, 12);
		cout << i << "%";
	}
	delay(300);
	system("cls");
	gotoxy(40, 5);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", 219);
	}
	gotoxy(40, 15);
	for (int i = 0; i < 30; i++)
	{
		printf("%c", 219);
	}
	for (int i = 0; i <= 10; i++)
	{
		gotoxy(40, i + 5);
		printf("%c", 219);
	}
	for (int i = 0; i <= 10; i++)
	{
		gotoxy(70, i + 5);
		printf("%c", 219);
	}
	SetConsoleTextAttribute(consoleHandle, 3);
	gotoxy(50, 9);
	cout << "1.New game";
	gotoxy(50, 10);
	cout << "2.Load game";
	gotoxy(50, 11);
	cout << "3.Settings";
	delay(500);
	gotoxy(50, 15);
}

void colortext(int x)	
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

void usage()
{
	system("cls");
	SetConsoleTextAttribute(consoleHandle, 6);
	gotoxy(51, 8);
	cout << "-Control Key-";
	gotoxy(50, 10);
	cout << "Press W to Up";
	gotoxy(50, 11);
	cout << "Press S to Down";
	gotoxy(50, 12);
	cout << "Press A to Left";
	gotoxy(50, 13);
	cout << "Press D to Right";
	cout << "\n";
	delay(900);
	system("cls");
}

void loading()
{
	gotoxy(52, 10);
	cout << "Loading...";
	gotoxy(44, 12);
	for (int i = 0; i < 26; i++)
	{
		delay(200);
		printf("%c", 177);
	}
	system("cls");
}

void board()
{
	FixConsoleWindow();
	gotoxy(8, 3);
	for (int i = 0; i < 80; i++)
	{
		printf("%c", 219);
	}
	gotoxy(8, 25);
	for (int i = 0; i < 80; i++)
	{
		printf("%c", 219);
	}
	for (int i = 0; i <= 22; i++)
	{
		gotoxy(8, i + 3);
		printf("%c", 219);
	}
	for (int i = 0; i <= 22; i++)
	{
		gotoxy(88, i + 3);
		printf("%c", 219);
	}
	gotoxy(90, 3);
	for (int i = 0; i < 15; i++)
	{
		printf("%c", 219);
	}
	gotoxy(90, 9);
	for (int i = 0; i < 15; i++)
	{
		printf("%c", 219);
	}
	for (int i = 0; i <= 6; i++)
	{
		gotoxy(90, i + 3);
		printf("%c", 219);
	}
	for (int i = 0; i <= 6; i++)
	{
		gotoxy(105, i + 3);
		printf("%c", 219);
	}
	SetConsoleTextAttribute(consoleHandle, 10);
	gotoxy(95, 18);
	cout << "GAME";
	gotoxy(91, 19);
	cout << "ROAD CROSSING";
	gotoxy(93, 5);
	SetConsoleTextAttribute(consoleHandle, 3);
	SetConsoleTextAttribute(consoleHandle, 0);
}

void showCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}





