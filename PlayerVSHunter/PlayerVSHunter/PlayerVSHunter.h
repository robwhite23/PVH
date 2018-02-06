#pragma once
#include "Keyboard.h"
#include "Menu.h"
#include "Board.h"
#include<vector>

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

