#pragma once
#include "Keyboard.h"
#include "Menu.h"
#include "Board.h"
#include<vector>


typedef struct {
	char x;
	char y;
}Board_Pos;

class character{
public:
	character(Board_Pos starting_pos, char icon) : current_pos(starting_pos), Board_Icon(icon){};
	void SetIcon(char icon);
	char GetIcon(void) const;
	Board_Pos GetBoard_Pos(void) const;
	void MoveRandom(void);
	void MoveLeft(void);
	void MoveRight(void);
	void MoveUp(void);
	void MoveDown(void);
private:
	
	char Board_Icon;
	Board_Pos current_pos;
};

class player : public character{
public:
	player(Board_Pos starting_pos, char icon) : character(starting_pos, icon){};
	

private:
	const bool CPU_controlled = false;
};

class Hunter : public character{
public:
	Hunter(Board_Pos starting_pos, char icon) : Hunter(starting_pos, icon){};


private:
	const bool CPU_controlled = true;
};



class Game{
public:
	Game(){};
	void start();
		
private:
	Menu menu;
	Keyboard keyboard;
	Board board;
	char Keyinput;

};

