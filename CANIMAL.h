#ifndef CANIMAL_H
#define CANIMAL_H
#include"INTERFACE.h"

class CANIMAL
{
protected:
	int m_x, m_y;
	int m_x1;			//position front
	std::string m_body;

	int m_timeStop;
	bool m_isRedLight;
public:
	CANIMAL();


	virtual void move() = 0;
	virtual void move_() = 0;
	int getX();
	int getX1();
	int getY();
	void setPos();

	int size() { return m_body.size(); }

	void SaveData(FILE *f);

	void saveData(ofstream &ou);
	void loadData(int,int,int,int,bool);

	void RedLight(bool isRed);
	void printTrafficLight();
};

class CBIRD :public CANIMAL
{
public:
	void move();
	void move_();
	CBIRD(int,int);
	void tell();
};

class CDINAUSOR :public CANIMAL
{

public:
	void move();
	void move_();
	CDINAUSOR(int,int);
	void tell();
};
#endif