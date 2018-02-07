#pragma once
#include "Keyboard.h"
#include "Menu.h"
#include "Board.h"
#include "Character.h"
#include<vector>

class Game{
public:
	Game() : board(BOARD_DIMENSION, BOARD_DIMENSION), score(0), P1('P') {};
	void start(void);
	void Initialise_Player(void);
	void PlayLevel(int level);
		
private:
	Menu menu;
	Keyboard keyboard;
	Board board;
	Player P1;
	vector <Hunter> hunters;
	char Keyinput;
	int score;

};

