#pragma once
#include<iostream>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<thread>
#include<stdio.h>
#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<ctime> 
#include<string>
#include<vector>
#include"Windows.h"
#include<fstream>
using namespace std;

#define width 84
#define firstPos 9
#define height 23
#define sleepTime 10
#define white 7
#define blueWhite 20
#define greenb 160
#define yellow 216
#define greenb1 120
#define redt 9
#define red 196
#define timeRedLight 40

void gotoxy(int x, int y);
void FixConsoleWindow();
void colortext(int x);
void draw_menu();
void usage();
void loading();
void board();
void delay(int);
void score(int i);
void levell(int i);
void showCur(bool CursorVisibility);
void draw_menu_();