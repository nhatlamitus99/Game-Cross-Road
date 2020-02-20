#include "CPEOPLE.h"
#include"INTERFACE.h"
#pragma comment (lib, "winmm.lib")
CPEOPLE::CPEOPLE()
{
	m_score = 0;
	m_state = 1;
	m_y = height - 1;
	m_finish = 0;
	srand(time(NULL));
	m_x = rand() % (width - 4) + (firstPos + 3);
	drawPeople();
}
CPEOPLE CPEOPLE::operator=(const CPEOPLE& pp)
{
	if (isDead())
		m_score = 0;
	else m_score = pp.m_score;
	m_state = 1;
	m_y = height - 1;
	m_finish = 0;
	srand(time(NULL));
	m_x = pp.m_x;
	drawPeople();
	return *this;
}
void CPEOPLE::up()
{
	m_y-=1;
	if (m_y <= firstPos-6)
	{
		m_score += 8;
		drawScore();
		gotoxy(93, 15);
		cout << "Excellent";
		delay(500);
		colortext(0);
		gotoxy(93, 15);
		cout << "Excellent";
		colortext(10);
		m_y = 23;
	}
}
void CPEOPLE::down()
{
	m_y+=1;
	if (m_y >= height)
		m_y = height-1;
}
void CPEOPLE::left()
{
	m_x-=1;
	if (m_x <= firstPos)
		m_x = firstPos+1;
}
void CPEOPLE::right()
{
	m_x+=1;
	if (m_x >= width-1)
		m_x = width-2;
}
bool CPEOPLE::isDead()
{
	return !m_state;
}
bool CPEOPLE::isFinish()
{
	return m_finish;
}

void CPEOPLE::catchKey(char presskey)
{

	int x = m_x, y = m_y;
	gotoxy(m_x,m_y);
	colortext(white);
	cout << "  ";						
	if (presskey == 75 || presskey == 'A')
		left();
	else 
		if(presskey == 77 || presskey == 'D')
			right() ;
		else
			if(presskey == 72 || presskey == 'W')
				up();
			else 
				if(presskey == 80 || presskey == 'S')
					down();
	drawPeople();
}
void CPEOPLE::drawPeople()
{
	gotoxy(m_x,m_y);
	colortext(red);
	cout << "  ";
}

bool  CPEOPLE::isImpact(int x,int y,int size,int m)
{
	if (m_y <4)
	{
		Sleep(30);
		colortext(white);
		gotoxy(m_x, m_y);
		cout <<"  ";
		m_finish = 1;
		m_score++;
		return 0;
	}
	if (m_y == y)
	{
		if (x + size < width&&(m==1||x>firstPos&&m==-1))
		{
			if(m_x>=x-1&&m_x<=x+size)
			{
				m_state = 0;
				return 1;
			}
		}
		else
		{
			if (m_x >= x-1 || m_x <= firstPos + size - (width - x))
			{
				m_state = 0; return 1;
			}
		}
	}
	return 0;
}
int CPEOPLE::isCheck()
{
	if (m_y % 4 == 0)
		return 0;
	else if (m_y % 4 == 2)
			return 2;
	return -1;
}

vector<int> color = { 160,196,202 };
void CPEOPLE::animation()
{
	srand(time(NULL));
	gotoxy(m_x, m_y);
	int temp = rand() % (color.size() - 1) + 0;
	Beep(523, 500);
	colortext(color[temp]);
	cout << " ";
}

void Shape(int x, int y)
{
	gotoxy(x, y);
	colortext(10);
	for (int i = 0; i < 6; i++)
		printf("%c", 176);
	printf("%c", 127);
}

void Del(int x, int y)
{
	gotoxy(x, y);
	colortext(0);
	for (int i = 0; i < 6; i++)
		printf("%c", 176);
	printf("%c", 127);
}

void CPEOPLE::rescue()
{
	int start = firstPos;
	while (start <= m_x)
	{
		Shape(start, m_y);
		delay(100);
		Del(start, m_y);
		start++;
	}
}

void CPEOPLE::SaveData(FILE *f)
{
	fwrite(&m_x, sizeof(int), 1, f);
	fwrite(&m_y, sizeof(int), 1, f);
	fwrite(&m_state, sizeof(bool), 1, f);
	fwrite(&m_finish, sizeof(bool), 1, f);
	fwrite(&m_score, sizeof(bool), 1, f);
}

void CPEOPLE::saveData(ofstream &ou)
{
	/*ou.write(reinterpret_cast<char *>(&m_x), sizeof(m_x));
	ou.write(reinterpret_cast<char *>(&m_y), sizeof(m_y));
	ou.write(reinterpret_cast<char *>(&m_state), sizeof(m_state));
	ou.write(reinterpret_cast<char *>(&m_finish), sizeof(m_finish));
	ou.write(reinterpret_cast<char *>(&m_score), sizeof(m_score));*/
	ou << m_x << " " << m_y << " " << m_state << " " << m_finish << " " << m_score << endl;
}
void CPEOPLE::loadData(int x, int y, bool state, bool finish,int score)
{
	m_x = x; m_y = y; m_state = state; m_finish = finish; m_score = score;
}
void CPEOPLE::drawScore()
{
	colortext(10);
	gotoxy(92, 5);
	cout << "Score : " << m_score << endl;
}


