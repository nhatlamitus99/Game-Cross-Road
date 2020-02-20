
#include "CVEHICLE.h"

CVEHICLE::CVEHICLE()
{
	m_x = rand() % 50 + 3;
	m_y = 12;				
	m_body = "";
	m_timeStop = 0;
	m_isRedLight = 0;
}

void CVEHICLE::setPos()
{
	gotoxy(m_x, m_y);
}

int CVEHICLE::getX()
{
	return m_x;
}
int CVEHICLE::getY()
{
	return m_y;
}
void CVEHICLE::RedLight(bool redLight)
{
	if (redLight)
		m_isRedLight = 1;
	else redLight = 0;
}
void CVEHICLE::printTrafficLight()
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


CTRUCK::CTRUCK(int y,int x) :CVEHICLE()
{
	m_y = y;
	if (x <= firstPos)
		m_x = firstPos + 1;
	else m_x = x;
	for (int i = 0; i < 6; i++)
		m_body += char(176);
	m_body += char(127);
}

void CTRUCK::move()
{
	colortext(14);
	setPos();
	cout << " ";
	//colortext(greenb);
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
	if (m_x == width)
		m_x = firstPos + 1;
	setPos();
	if (m_x < width - m_body.size())
	{
		setPos();
		cout << m_body;
	}
	else
	{
		cout << m_body.substr(0, width - m_x);
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(m_body.length()-m_body.size() + (width - m_x),m_body.length());
	}
}

//CAR

CCAR::CCAR(int y,int x) :CVEHICLE()
{
	m_y = y;
	if (x != 0)
		m_x = x;
	else m_x = rand() % 50 + 3;
	m_body += char(174);
	for (int i = 0; i < 5; i++)
		m_body += char(127);
	m_body += char(175);
}

void CCAR::move()
{
	colortext(9);
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
	if (m_x == width)
		m_x = firstPos + 1;
	setPos();
	if (m_x < width - m_body.size())
	{
		setPos();
		cout << m_body;
	}
	else
	{
		cout << m_body.substr(0, width - m_x);
		gotoxy(firstPos + 1, m_y);
		cout << m_body.substr(m_body.length() - m_body.size() + (width - m_x), m_body.length());
	}
}

void CVEHICLE::SaveData(FILE *f)
{
	fwrite(&m_x, sizeof(int), 1, f);
	fwrite(&m_y, sizeof(int), 1, f);
	fwrite(&m_timeStop, sizeof(int), 1, f);
	fwrite(&m_isRedLight, sizeof(bool), 1, f);
	fwrite(m_body.c_str(), sizeof(char*), 1, f);
}

void CVEHICLE::saveData(ofstream &os)
{
	os << m_x << " " << m_y << " " << m_timeStop << " " << m_isRedLight << " " << m_body << endl;
}
void CVEHICLE::loadData(int x, int y, int timeStop,bool isRed,string body)
{
	m_x = x; m_y = y;  m_timeStop = timeStop, m_isRedLight = isRed;
	m_body = body;
}

void CCAR::tell()
{
	PlaySound("CAR.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

void CTRUCK::tell()
{
	PlaySound("TRUCK.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}