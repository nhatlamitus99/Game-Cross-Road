#ifndef CGAME_H
#define CGAME_H

#include"CPEOPLE.h"
#include"CVEHICLE.h"
#include"CANIMAL.h"
#include"INTERFACE.h"
static int m;
class CGAME
{
	vector<CANIMAL*> ani;
	vector<CVEHICLE*> vehi;
	CPEOPLE nguoi;
	std::string lable_newGame;
	std::string lable_loadGame;
	std::string lable_setting;

	int m_timeStop;
	int m_trafficSize;
public:
	CGAME(int level);
	void setGame(int level);
	void startGame();
	void menu(char& key);
	void aniRun();
	void vehiRun();
	void run(bool &IS_RUNNING, char &presskey,int &level);
	void animateWhenDie();
	void playAgain();
	void askPlayAgain(int);
	bool continuePlay();
	void setting(bool &sound,int &level);
	void printLevel(int level);
	void menu_(char &key);
	bool loadGame(std::string filename,int &level);
	bool LoadGame(FILE *f, int &level);
	void saveAll(int level);
	void SaveAll(int level);
};
#endif 


