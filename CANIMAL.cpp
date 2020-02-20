#include "CANIMAL.h"
CANIMAL::CANIMAL()
{
	m_x = rand() % 40 + 3;
	m_y = 12;				//tam thoi
	m_body = "";
	m_timeStop = 0;
	m_isRedLight = 0;
}
int CANIMAL::getX() { return m_x; }
int CANIMAL::getY() { return m_y; }
int CANIMAL::getX1() { return m_x1; }
void CANIMAL::setPos()
{
	gotoxy(m_x, m_y);
}
void CANIMAL::RedLight(bool isRed)
{
	if (isRed)
		m_isRedLight = 1;
}
void CANIMAL::printTrafficLight()
{
	gotoxy(width + 2, m_y);
	if (m_isRedLight)
	{
		colortext(red);
		cout << "  ";
	}
	else {
		colortext(greenb);
		cout << "  ";
	}
}
//bird

CBIRD::CBIRD(int y,int x) :CANIMAL()
{
	m_y = y;
	if (x <= firstPos)
		m_x = firstPos + 2;
	else m_x = x;
	m_body += char(247);
	m_body += char(248);
	m_body += char(236);
	m_body += char(247);

}

void b_tell(CBIRD p)
{
	p.tell();
}

void CBIRD::move()
{
	colortext(11);
	setPos();
	cout << " ";
	if (m_isRedLight)
	{
		m_timeStop++;
		if (m_timeStop == timeRedLight)
		{
			m_timeStop = 0;
			m_isRedLight = 0;
		}
	}
	else m_x--;
	if (m_x == firstPos)
		m_x = width-1;
	m_x1 = m_x - m_body.size();
	if (m_x1 >firstPos)
	{
		gotoxy(m_x1, m_y);
		cout << m_body;
	}
	else
	{
		int k = m_x - firstPos;
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(0,k);
		m_x1 = width - m_body.size()+ k;
		gotoxy(m_x1,m_y);
		cout << m_body.substr(0,m_body.size()-k);
	}
}

void CBIRD::move_()
{
	colortext(11);
	setPos();
	cout << " ";
	if (m_isRedLight)
	{
		m_timeStop++;
		if (m_timeStop == timeRedLight)
		{
			m_timeStop = 0;
			m_isRedLight = 0;
		}
	}
	else m_x++;
	if (m_x == firstPos)
		m_x = width - 1;
	m_x1 = m_x - m_body.size();
	if (m_x1 >firstPos)
	{
		gotoxy(m_x1, m_y);
		cout << m_body;
	}
	else
	{
		int k = m_x - firstPos;
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(0, k);
		m_x1 = width - m_body.size() + k;
		gotoxy(m_x1, m_y);
		cout << m_body.substr(0, m_body.size() - k);
	}
}

//dinausor
CDINAUSOR::CDINAUSOR(int y,int x) :CANIMAL()
{	m_y = y;
	if (x <= firstPos)
		m_x = firstPos + 2;
	else m_x = x;
	m_body += char(252);
	m_body += char(251);
	m_body += char(250);
}

void d_tell(CDINAUSOR p)
{
	p.tell();
}

void CDINAUSOR::move()
{
	colortext(10);
	setPos();
	cout << " ";
	if (m_isRedLight)
	{
		m_timeStop++;
		if (m_timeStop == timeRedLight)
		{
			m_timeStop = 0;
			m_isRedLight = 0;
		}
	}
	else m_x--;
	if (m_x == firstPos)
		m_x = width - 1;
	m_x1 = m_x - m_body.size();
	if (m_x1 >firstPos)
	{
		gotoxy(m_x1, m_y);
		cout << m_body;
	}
	else
	{
		int k = m_x - firstPos;
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(m_body.size()-k,k);
		m_x1 = width - m_body.size() + k;
		gotoxy(m_x1, m_y);
		cout << m_body.substr(0,m_body.size()-k);
	}
}

void CDINAUSOR::move_()
{
	colortext(10);
	setPos();
	cout << " ";
	if (m_isRedLight)
	{
		m_timeStop++;
		if (m_timeStop == timeRedLight)
		{
			m_timeStop = 0;
			m_isRedLight = 0;
		}
	}
	else m_x++;
	if (m_x == firstPos)
		m_x = width - 1;
	m_x1 = m_x - m_body.size();
	if (m_x1 >firstPos)
	{
		gotoxy(m_x1, m_y);
		cout << m_body;
	}
	else
	{
		int k = m_x - firstPos;
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(0, k);
		m_x1 = width - m_body.size() + k;
		gotoxy(m_x1, m_y);
		cout << m_body.substr(0, m_body.size() - k);
	}
}

void CANIMAL::SaveData(FILE *f)
{
	fwrite(&m_x, sizeof(int), 1, f);
	fwrite(&m_y, sizeof(int), 1, f);
	fwrite(&m_x1, sizeof(int), 1, f);
	fwrite(&m_timeStop, sizeof(int), 1, f);
	fwrite(&m_isRedLight, sizeof(bool), 1, f);
}

void CANIMAL::saveData(ofstream &os)
{
	os << m_x << " " << m_y << " " << m_x1 <<" "<< m_timeStop << " " << m_isRedLight << endl;
	bool x = m_isRedLight;
}
void CANIMAL::loadData(int x, int y, int x1,int timeStop,bool isRed)
{
	m_x = x; m_y = y; m_x1 = x1, m_timeStop = timeStop, m_isRedLight = isRed;
}

void CBIRD::tell()
{
	PlaySound("BIRD.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void CDINAUSOR::tell()
{
	PlaySound("DINAUSOR.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}