//#include "SCREEN.h"
//#include"INTERFACE.h"
////void  resizeConsole(int _width, int _height)  // set the size
////{
////	HWND console = GetConsoleWindow();
////	RECT r;
////	GetWindowRect(console, &r);
////	MoveWindow(console, r.left, r.top, _width, _height, TRUE);
////}
////void fixConsoleWindow()			// prevent the player from resizing the screen
////{
////	HWND consoleWindow = GetConsoleWindow();
////	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
////	style = style & ~(WS_MAXIMIZEBOX)& ~(WS_THICKFRAME);
////	SetWindowLong(consoleWindow, GWL_STYLE, style);
////}
////void  gotoxy(int x, int y)	//position
////{
////	HANDLE a;
////	COORD position;
////	a = GetStdHandle(STD_OUTPUT_HANDLE);
////	position.X = x; position.Y = y;
////	SetConsoleCursorPosition(a, position);
////}
////void colortext(int x)		//color text
////{
////	HANDLE mau;
////	mau = GetStdHandle(STD_OUTPUT_HANDLE);
////	SetConsoleTextAttribute(mau, x);
////}
////void drawBoard()
////{
////	colortext(13);
////	for (int i = firstPos; i < width; i++)
////	{
////		gotoxy(i, firstPos);
////		cout << "x";
////		gotoxy(i, height);           //x
////		cout << "x";
////	}
////	for (int i = firstPos; i <= height; i++)
////	{
////		gotoxy(firstPos, i); cout << "x";
////		gotoxy(width, i); 	cout << "x"; //y	
////	}
////}
//void showCur(bool CursorVisibility)
//{
//	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
//	SetConsoleCursorInfo(handle, &cursor);
//}
//
