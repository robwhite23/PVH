#include "stdafx.h"
#include "character.h"

/*!
@brief checks if there is space on the referenced board before moving
the characters position left and emptying the previous position
@returns bool true if character moved. False if player could 
not move
*/
bool Character::MoveLeft(Board &board)
{
	Board_Pos pos, newpos;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos left
	if (pos.x != 0) 
	{
		newpos.x = pos.x - 1;
		//check new position is free
		if (board.Check_Board_Pos(newpos))
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return true;
		}
	}
	//new board pos not free or does not exist
	return false;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position right and emptying the previous position
@returns bool true if character moved. False if player could
not move
*/
bool Character::MoveRight(Board &board)
{
	Board_Pos pos, newpos;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos right
	if (pos.x != board.GetBoardDimensions().x -1)
	{
		newpos.x = pos.x + 1;
		//check new position is free
		if (board.Check_Board_Pos(newpos))
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return true;
		}
	}
	//new board pos not free or does not exist
	return false;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position up and emptying the previous position
@returns bool true if character moved. False if player could
not move
*/
bool Character::MoveUp(Board &board)
{
	Board_Pos pos, newpos;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos up
	if (pos.y != 0)
	{
		newpos.y = pos.y -1;
		//check new position is free
		if (board.Check_Board_Pos(newpos))
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return true;
		}
	}
	//new board pos not free or does not exist
	return false;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position down and emptying the previous position
@returns bool true if character moved. False if player could
not move
*/
bool Character::MoveDown(Board &board)
{
	Board_Pos pos, newpos;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos down
	if (pos.y != board.GetBoardDimensions().y - 1)
	{
		newpos.y = pos.y + 1;
		//check new position is free
		if (board.Check_Board_Pos(newpos))
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return true;
		}
	}
	//new board pos not free or does not exist
	return false;
}

