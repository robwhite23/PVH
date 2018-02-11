#include "stdafx.h"
#include "character.h"

/*!
@brief checks if there is space on the referenced board before moving
the characters position left and emptying the previous position
@returns char. If board pos is taken it returns the icon of the character 
in it. if it is empty it returns 0u, if it doesnt exist it returns -1.
*/
char Character::MoveLeft(Board &board)
{
	Board_Pos pos, newpos;
	char checkresult;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos left
	if (pos.x != 0) 
	{
		newpos.x = pos.x - 1;
		//check new position is free
		checkresult = board.Check_Board_Pos(newpos);
		if (checkresult == 0u)
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return 0u;
		}
		else
		{
			//something already in new position. return its icon
			return checkresult;
		}
	}
	//new board pos does not exist
	return -1;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position right and emptying the previous position
@returns char. If board pos is taken it returns the icon of the character
in it. if it is empty it returns 0u, if it doesnt exist it returns -1.
*/
char Character::MoveRight(Board &board)
{
	Board_Pos pos, newpos;
	char checkresult;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos right
	if (pos.x != board.GetBoardDimensions().x -1)
	{
		newpos.x = pos.x + 1;
		//check new position is free
		checkresult = board.Check_Board_Pos(newpos);
		if (checkresult == 0u)
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return 0u;
		}
		else
		{
			//something already in new position. return its icon
			return checkresult;
		}
	}
	//new board pos does not exist
	return -1;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position up and emptying the previous position
@returns char. If board pos is taken it returns the icon of the character
in it. if it is empty it returns 0u, if it doesnt exist it returns -1.
*/
char Character::MoveUp(Board &board)
{
	Board_Pos pos, newpos;
	char checkresult;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos up
	if (pos.y != 0)
	{
		newpos.y = pos.y -1;
		//check new position is free
		checkresult = board.Check_Board_Pos(newpos);
		if (checkresult == 0u)
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return 0u;
		}
		else
		{
			//something already in new position. return its icon
			return checkresult;
		}
	}
	//new board pos does not exist
	return -1;
}


/*!
@brief checks if there is space on the referenced board before moving
the characters position down and emptying the previous position
@returns char. If board pos is taken it returns the icon of the character
in it. if it is empty it returns 0u, if it doesnt exist it returns -1.
*/
char Character::MoveDown(Board &board)
{
	Board_Pos pos, newpos;
	char checkresult;

	//get current position of character
	pos = this->GetBoard_Pos();
	newpos = pos;
	//if space move new pos down
	if (pos.y != board.GetBoardDimensions().y - 1)
	{
		newpos.y = pos.y + 1;
		//check new position is free
		checkresult = board.Check_Board_Pos(newpos);
		if (checkresult == 0u)
		{
			//set character to new position and clear old position on board
			this->Set_Board_Pos(newpos);
			board.bvect[this->current_pos.y][this->current_pos.x] = this->Board_Icon;
			board.bvect[pos.y][pos.x] = ' ';
			return 0u;
		}
		else
		{
			//something already in new position. return its icon
			return checkresult;
		}
	}
	//new board pos does not exist
	return -1;
}


/*!
@brief Moves the hunter up, down, left or right depending on the result
of a random number generator.
@returns a char. -1 if the random position doesnt exist. The icon of 
the character if the random position was taken. 0 if the Hunter moved
sucessfully.
*/
char Hunter::MoveRandom(Board &board)
{
	Board_Pos pos, newpos;
	int randmove;
	char tryResult;
	
	//Generate random number between 0 and 4
	randmove = rand() % (4);
	switch (randmove)
	{
		case 0 :
			//try moving Up
			tryResult = this->MoveUp(board);
			break;

		case 1:
			//try moving Down
			tryResult = this->MoveDown(board);
			break;

		case 2:
			//try moving left
			tryResult = this->MoveLeft(board);
			break;

		case 3:
			//try moving Right
			tryResult = this->MoveRight(board);
			break;

		default :
			//indicate that we could not move as pos didnt exist
			return -1;
	}
	return tryResult;
}

