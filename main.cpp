#include"INTERFACE.h"
#include"CPEOPLE.h"
#include"CANIMAL.h"
#include"CGAME.h"
#include "windows.h"

ofstream ou;
int level = 3;
static CGAME game(level);
string filename = "inp.txt";
FILE *f;
static bool IS_RUNNING = 1;
char presskey;
bool flag = 1, sound = 1;
void selection();
void subThread()
{
	game.run(IS_RUNNING,presskey,level);
}
void soundThread()
{
	if (sound)
	{
		PlaySound("sound.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	}
}

void play()
{
	thread t(subThread);
	thread t1(soundThread);
	while (1)
	{
		if (_kbhit())
		{
			presskey = toupper(_getch());
			if (presskey == 27)
			{
				IS_RUNNING = 0;
				t.join();
				exit(0);
			}
			else
				if (presskey == 13 && !IS_RUNNING)
				{
					t.join();
					game.askPlayAgain(0);
					IS_RUNNING = 1, game.playAgain(), play();
				}
				else
					if (presskey == 'T')
					{
						IS_RUNNING = 0,t.join();
						game.loadGame(filename,level);
						IS_RUNNING = 1;
						system("cls");
						game.startGame();
						play();
					}
					else
						if (presskey == 'L')
						{
							IS_RUNNING = 0, t.join(), flag = 0;
							game.saveAll(level);
							if (game.continuePlay())
								IS_RUNNING = 1,game.startGame(), play();
						}
		}
		else if (!IS_RUNNING)
		{
			PlaySound("Boom.wav", NULL, SND_FILENAME);
			if (t1.joinable())
			{
				t1.join(); 
			}
			if (flag)
			{
				gotoxy(40, 23);
				cout << "-YOU LOSE-";
				game.animateWhenDie();
				colortext(0);
				gotoxy(40, 23);
				cout << "-YOU LOSE-";
				game.askPlayAgain(1);
			}
		}
	}
	t.join();
}
void selection()
{
	char select;
	game.menu(select); goto L;
LOOP: game.menu_(select);
	L: system("cls");
	switch (select)
	{
		case '1':
		{
			IS_RUNNING = 1;
			game.startGame();
			play();
		} break;
		case '2':
		{
			showCur(0);
			game.loadGame(filename, level);
			int j = game.loadGame(filename, level);
			if (j == 1)
			{
				IS_RUNNING = 1;
				system("cls");
				game.startGame();
				play();
			}
			else goto LOOP;
		} break;
		case '3':
		{
			game.setting(sound,level);
			system("cls");
			game.setGame(level);
			goto LOOP;
		}break;
	default: goto LOOP; break;
	}
}
int main()
{
	ou.open(filename);
	selection();
	system("pause");
	ou.close(); 
	return 0;
}