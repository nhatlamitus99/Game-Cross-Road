#ifndef CVEHICLE_H
#define CVEHICLE_H
#include"INTERFACE.h"

class CVEHICLE
{
protected:
	int m_x, m_y;
	std::string m_body;

	int m_timeStop;
	bool m_isRedLight;
public:
	CVEHICLE();

	virtual void move() =0;
	void setPos();
	int getX();
	int getY();
	int size() { return m_body.size(); }
	
	void SaveData(FILE *f);

	void saveData(ofstream &ou);
	void loadData(int, int,int,bool,string);

	void RedLight(bool isRed);
	void printTrafficLight();
};


//truck
class CTRUCK :public CVEHICLE
{

public:
	void move();
	CTRUCK(int,int);
	void tell();
};


//car
class CCAR :public CVEHICLE
{
	
public:
	void move();
	CCAR(int,int);
	void tell();
};
#endif




