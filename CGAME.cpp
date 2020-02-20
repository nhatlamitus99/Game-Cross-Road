#include "CGAME.h"
#include"INTERFACE.h"

CGAME::CGAME(int level)
{
	m_trafficSize = level;
	int t = 2, t1 = 6, t2 = 8, t3 = 11, t4 = 5;
	int kc = 23;
	for (int i = 0; i < m_trafficSize; i++)
	{
		vehi.push_back(new CTRUCK(4, t + kc*i));
		vehi.push_back(new CCAR(8, t1 + kc*i));
		vehi.push_back(new CTRUCK(12, t2 + kc*i));
		vehi.push_back(new CCAR(16, t3 + kc*i));
		vehi.push_back(new CTRUCK(20, t4 + kc*i));

		ani.push_back(new CBIRD(6, t + kc*i));
		ani.push_back(new CDINAUSOR(10, t + kc*i));
		ani.push_back(new CBIRD(14, t + kc*i));
		ani.push_back(new CDINAUSOR(18, t + kc*i));
	}
	lable_newGame = "1. New game";
	lable_loadGame = "2. Load game";
	lable_setting = "3. Settings";

	m_timeStop = 0;
}
void CGAME::setGame(int level)
{
	this->ani.clear();
	this->vehi.clear();
	m_trafficSize = level;
	int t = 2, t1 = 6, t2 = 8, t3 = 11, t4 = 5;
	int kc = 23;
	for (int i = 0; i<m_trafficSize; i++)
	{
		vehi.push_back(new CTRUCK(4, t + kc*i));
		vehi.push_back(new CCAR(8, t1 + kc*i));
		vehi.push_back(new CTRUCK(12, t2 + kc*i));
		vehi.push_back(new CCAR(16, t3 + kc*i));
		vehi.push_back(new CTRUCK(20, t4 + kc*i));

		ani.push_back(new CBIRD(6, t + kc*i));
		ani.push_back(new CDINAUSOR(10, t + kc*i));
		ani.push_back(new CBIRD(14, t + kc*i));
		ani.push_back(new CDINAUSOR(18, t + kc*i));
	}
}

void CGAME::startGame()
{
	board();
	nguoi.drawScore();
}

void CGAME::setting(bool &sound,int &level)
{
	LOOP:system("cls");
	gotoxy(width / 2, height / 2);
	cout << "Do you want to turn on sound ? (Y/N)";
	gotoxy(width / 2+7, height / 2+2);
	char key = toupper(_getch());
	if (key == 'Y')
		sound = 1;
	else
		if (key == 'N')
		sound = 0;
		else
		{
			goto LOOP;
		}
	again:gotoxy(width / 2, height / 2 + 4);
	cout << "Set level";
	gotoxy(width / 2, height / 2 + 6);
	cout << "1 - Easy";
	gotoxy(width / 2, height / 2 + 8);
	cout << "2 - Medium";
	gotoxy(width / 2, height / 2 + 10);
	cout << "3 - Hard";
	gotoxy(width / 2 + 5, height / 2 + 12);
	key = toupper(_getch());
	if (key == '1')
		level = 2;
	else
	{
		if (key == '2')
			level = 3;
		else if (key == '3')
			level = 4;
		else goto again;
	}
}
void CGAME::menu(char &key)
{
	draw_menu();
	cout << "Your Option: ";
	cin >> key;
	usage();
	loading();
}

void CGAME::menu_(char &key)
{
	draw_menu_();
	cout << "Your Option: ";
	cin >> key;
}

void CGAME::vehiRun()
{
	for (int i = 0; i < vehi.size(); i++)
	{
		vehi[i]->move();
		vehi[i]->printTrafficLight();
	}
}
void CGAME::aniRun()
{
	for (int i = 0; i < ani.size(); i++)
	{
			ani[i]->move();
			ani[i]->printTrafficLight();
	}
}
void CGAME::run(bool &IS_RUNNING, char &presskey, int &level)
{
	printLevel(level);
	while (IS_RUNNING)
	{
		if (presskey != ' ')
			nguoi.catchKey(presskey), presskey = ' ';
		else
			Sleep(sleepTime),vehiRun(), aniRun();

		if (nguoi.isCheck() == 0)
		{
			m = 1;
			for (int i = 0; i < vehi.size(); i++)
				if (nguoi.isImpact(vehi[i]->getX(), vehi[i]->getY(), vehi[i]->size(), m))
					break;
		}
		else if (nguoi.isCheck() == 2)
		{
			m = -1;
			for (int i = 0; i < ani.size(); i++)
				if (nguoi.isImpact(ani[i]->getX1(), ani[i]->getY(), ani[i]->size(), m))
					break;
		}

		if (nguoi.isDead())
			IS_RUNNING = 0;
		if (nguoi.isFinish())
		{
			level++, nguoi.drawScore(), nguoi = nguoi;

		}

		//stop car
		int x = rand() % 200 + 1;
		if (x <= 10)
		{
			if (x % 2 == 0)
			{
				int t= vehi.size() / m_trafficSize;
				int y = rand() % (t-1) + 0;
				for (int i = 1; i <= m_trafficSize; i++)
				{
					vehi[y]->RedLight(1);
					y += t;
				}
			
			}
			else
			{
				int t= ani.size() / m_trafficSize;
				int y = rand() % (t-1) + 0;
				for (int i = 1; i <= m_trafficSize; i++)
				{
					ani[y]->RedLight(1);
					y += t;
				}
			}
		}
	}
}
void CGAME::animateWhenDie()
{
	nguoi.rescue();
	nguoi.animation();
}
void CGAME::playAgain()
{
	CPEOPLE nguoi1;
	nguoi = nguoi1;
	nguoi.drawScore();
}
void CGAME::askPlayAgain(int key)
{
	if (key == 1)
	{
		colortext(10);
		gotoxy(width / 2 - 10, height + 2);
		cout << "Press Enter to play again ";
		char c = _getch();
		if (c == 13)
			startGame();
		else return;
	}
	else
	{
		colortext(white);
		gotoxy(width / 2 - 10, height + 2);
		cout << "                           ";
	}
}
bool CGAME::continuePlay()
{
LOOP:system("cls");
	colortext(15);
	gotoxy(width / 2 - 10, height / 2);
	cout << "Do you want continue ? ";
	gotoxy(width / 2 - 10, height / 2+2);
	cout << "1  Yes";
	gotoxy(width / 2 - 10, height / 2+4);
	cout << "2  No(exit)";
	char key = toupper(_getch());
	if (key == '1')
	{
		system("cls");
		return 1;
	}
	else if (key == '2')
			exit(0);
	else goto LOOP;
}

bool CGAME::LoadGame(FILE *f, int &level)
{
	char loadFile[255];
	colortext(15);
LOOP:system("cls");
	gotoxy(width / 2 - 10, firstPos + 2);
	gotoxy(width / 2 - 10, height / 2);
	fflush(stdin);
	cout << "File name was saved : ";
	cin >> loadFile;
	fopen_s(&f, loadFile, "rb");
	if (!f)
	{
		system("cls");
		gotoxy(width / 2 - 10, height / 2);
		cout << "File not found !!!!!";
		Sleep(1000);
		colortext(0);
		gotoxy(width / 2 - 10, height / 2);
		cout << "File not found !!!!!";
		colortext(10);
		return 0;
	}
	int x, y, x1, score, timeStop;
	bool state, finish, isRed;
	fread(&x, sizeof(int), 1, f);
	fread(&y, sizeof(int), 1, f);
	fread(&state, sizeof(bool), 1, f);
	fread(&finish, sizeof(bool), 1, f);
	fread(&score, sizeof(int), 1, f);
	string body;
	for (int i = 0; i < ani.size(); i++)
	{
		fread(&x, sizeof(int), 1, f);
		fread(&y, sizeof(int), 1, f);
		fread(&x1, sizeof(bool), 1, f);
		fread(&timeStop, sizeof(int), 1, f);
		fread(&isRed, sizeof(bool), 1, f);
		ani[i]->loadData(x, y, x1, timeStop, isRed);
	}
	for (int i = 0; i < vehi.size(); i++)
	{
		fread(&x, sizeof(int), 1, f);
		fread(&y, sizeof(int), 1, f);
		fread(&x1, sizeof(bool), 1, f);
		fread(&timeStop, sizeof(int), 1, f);
		fread(&isRed, sizeof(bool), 1, f);
		vehi[i]->loadData(x, y, timeStop, isRed, body);
	}
	fread(&level, sizeof(int), 1, f);
	fclose(f);
	return 1;
}

bool CGAME::loadGame(std::string filename,int &level)
{
	colortext(15);
	LOOP:system("cls");
	gotoxy(width / 2 - 10, firstPos+2);
	gotoxy(width / 2 - 10, height / 2);
	fflush(stdin);
	cout << "File name was saved : ";
	std::getline(std::cin, filename);
	ifstream in;
	in.open(filename, ios::in|ios::binary);
	if (!in)
	{
		system("cls");
		gotoxy(width / 2 - 10, height/2);
		cout << "File not found !!!!!";
		Sleep(1000);
		colortext(0);
		gotoxy(width / 2 - 10, height / 2);
		cout << "File not found !!!!!";
		colortext(10);
		return 0;
	}

	/*int x=0, y=0, x1=0, score=0, timeStop=0;
	bool state=true, finish=true, isRed=true;
	in.read(reinterpret_cast<char *>(x), sizeof(x));
	in.read(reinterpret_cast<char *>(y), sizeof(y));
	in.read(reinterpret_cast<char *>(state), sizeof(state));
	in.read(reinterpret_cast<char *>(finish), sizeof(finish));
	in.read(reinterpret_cast<char *>(score), sizeof(score));
	nguoi.loadData(x, y, state, finish,score);
	string body;
		for (int i = 0; i < ani.size(); i++)
		{
			in.read(reinterpret_cast<char *>(x), sizeof(x));
			in.read(reinterpret_cast<char *>(y), sizeof(y));
			in.read(reinterpret_cast<char *>(x1), sizeof(x1));
			in.read(reinterpret_cast<char *>(timeStop), sizeof(timeStop));
			in.read(reinterpret_cast<char *>(isRed), sizeof(isRed));
			ani[i]->loadData(x, y, x1,timeStop,isRed);
		}
		for (int i = 0; i < vehi.size(); i++)
		{
			in.read(reinterpret_cast<char *>(x), sizeof(x));
			in.read(reinterpret_cast<char *>(y), sizeof(y));
			in.read(reinterpret_cast<char *>(x1), sizeof(x1));
			in.read(reinterpret_cast<char *>(timeStop), sizeof(timeStop));
			in.read(reinterpret_cast<char *>(isRed), sizeof(isRed));
			vehi[i]->loadData(x, y,timeStop, isRed,body);
		}
		in.read(reinterpret_cast<char *>(level), sizeof(level));*/
	int x, y, x1, score, timeStop;
	bool state, finish, isRed;
	in >> x >> y >> state >> finish >> score;
	nguoi.loadData(x, y, state, finish, score);
	string body;
	for (int i = 0; i < ani.size(); i++)
	{
		in >> x >> y >> x1 >> timeStop >> isRed;
		ani[i]->loadData(x, y, x1, timeStop, isRed);
	}

	for (int i = 0; i < vehi.size(); i++)
	{
		in >> x >> y >> timeStop >> isRed >> body;
		vehi[i]->loadData(x, y, timeStop, isRed, body);
	}
	in >> level;
	in.close();
	return 1;
}

void CGAME::SaveAll(int level)
{
	system("cls");
	char saveFile[255];
	gotoxy(width / 2 - 10, height - 10);
	cout << "Enter file name you want to save : ";
	cin >> saveFile;
	FILE *f;
	fopen_s(&f, saveFile, "wb");
	nguoi.SaveData(f);
	for (auto i : ani)
		i->SaveData(f);
	for (auto i : vehi)
		i->SaveData(f);
	fwrite(&level, sizeof(int), 1, f);
	fclose(f);
}

void CGAME::saveAll(int level)
{
	system("cls");
	string filename;
	gotoxy(width / 2 - 10, height - 10);
	cout << "Enter file name you want to save : ";
	cin >> filename;
	ofstream ou; 
	ou.open(filename, ios::out|ios::binary);
	nguoi.saveData(ou);
	for (auto i : ani)
		i->saveData(ou);
	for (auto i : vehi)
		i->saveData(ou);
	//ou.write(reinterpret_cast<char *>(&level), sizeof(level));
	ou << level << endl;
	ou.close();
}

void CGAME::printLevel(int level)
{
	string label = "";
	if (level == 2)
		label = "Easy";
	else {
		if (level == 3)
			label = "Medium";
		else
		{
			label = "Hard";
		}
	}
	colortext(10);
	gotoxy(92, 7);
	cout << "Level: " << label;
}

