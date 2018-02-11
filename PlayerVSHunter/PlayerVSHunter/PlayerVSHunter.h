#pragma once
#include "Keyboard.h"
#include "Menu.h"
#include "Board.h"
#include "Character.h"
#include<vector>

using namespace std;
#define BOARD_DIMENSION 10				//used to control the x and y dimensions of the instanciated board

/*!
@brief Top level class of the Player vs Hunter game.
@input Optional x and y dimensions to overide the games board default
@returns N/A
*/
class Game{
public:
	Game() : board(BOARD_DIMENSION, BOARD_DIMENSION), score(0), P1('P'), level_turns(30) {}; 
	void start(void);
	void PlayLevel(int level);
	void PlayerMove(void);
	int Get_level_turns(void) const { return level_turns; };
	void Set_level_turns(int turns){ this->level_turns = turns; };
		
private:
	Menu menu;							//the console menu 
	Keyboard keyboard;					//enables key press reads without the need for a return character
	Board board;						//the 2d board in which the game is played.  
	Player P1;							//the player controlled character
	vector <Hunter> hunters;			//Dynamically stores the required amount of hunter characters.
	char Keyinput;						//Stores the most recent keyboard input
	eArrowKey ArrowKeyinput;			//stores the most recent arrow key input
	int score;							//contains the current player score
	int level_turns;					//the amount of turns required to complete current level.
};

