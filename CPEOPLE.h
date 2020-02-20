#ifndef CPEOPLE_H
#define CPEOPLE_H
#include"INTERFACE.h"

class CPEOPLE
{
	int m_x, m_y;
	bool m_state;
	bool m_finish;
	int m_score;
public:
	CPEOPLE();
	CPEOPLE operator=(const CPEOPLE&);

	void up();
	void down();
	void left();
	void right();

	bool isDead();
	bool isFinish();
	
	void catchKey(char);
	void drawPeople();
	void drawScore();

	bool  isImpact(int x,int y,int size,int thamSoGia);

	void animation();
	void rescue();
	int isCheck();
	void SaveData(FILE *f);
	void saveData(ofstream &ou);
	void loadData(int, int, bool, bool,int);
};

#endif // !CPEOPLE_H