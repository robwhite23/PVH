#pragma once
#include "Board.h"

/*!
@brief Character class which contains all variables and functions which
are used in all playable(player), non playable(cpu) and consumable characters.
constructor overloading is used to enable different derived classes to instanciate
in different ways with different initialisor arguments.
@input Icon: this is the char character that will be displayed on the board to 
indicate the characters location. Starting_Pos : is the optional starting 
location for the character.
@returns N/A
*/
class Character{
public:
	Character(char icon) : Board_Icon(icon){};
	Character(Board_Pos starting_pos, char icon) : current_pos(starting_pos), Board_Icon(icon){};
	void SetIcon(char icon) { Board_Icon = icon; };
	char GetIcon(void) const { return Board_Icon; };
	Board_Pos GetBoard_Pos(void) const { return current_pos; };
	void MoveLeft(void);
	void MoveRight(void);
	void MoveUp(void);
	void MoveDown(void);
protected:

	char Board_Icon;
	Board_Pos current_pos;
};

/*!
@brief Player class derived from the character class. The Player
class does not need to initialise the starting position at instanciation
@Input Char icon.
*/
class Player : public Character{
public:
	Player(char icon) : Character(icon){};


private:
	const bool CPU_controlled = false;
};


/*!
@brief Hunter class derived from the character class. The Hunter class
needs to initialise the starting position of the character.
@Input Board_Pos starting_pos, Char icon.
*/
class Hunter : public Character{
public:
	Hunter(Board_Pos starting_pos, char icon) : Character(starting_pos, icon) {};
	void MoveRandom(void);

private:
	const bool CPU_controlled = true;
};