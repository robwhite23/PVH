#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "Board.h"


/*!
@brief Board Constructor which creates the board.
@input x and y dimensions to overide the games board default. 
These are passed to parent class construcor via initialiser list
@returns N/A
*/
Board::Board(char x, char y) : bx(x), by(y)
{
	//create board filled with empty characters.
	for (int i = 0; i<by; i++)
	{
		vector <char> bRow;
		for (int j = 0; j<bx; j++)
		{
			//add column (x)
			bRow.push_back(' ');
		}
		//add row (y)
		this->bvect.push_back(bRow);
	}
}


/*!
@brief prints the board and its content to the console
starting at the current curser position.
@returns N/A
*/
void Board::print_board(){
    //print line of underscores indicating top of board
	for (int i = 0; i < (bx*2); i++) { cout << '_'; }
	cout << endl;
	for (int i = 0; i<by; i++)
	{
		cout << '|';
		for (int j = 0; j<bx; j++)
		{
			//print board location content
			cout << this->bvect[i][j]<<'|';
		}
		cout << endl;
	}
	//print line of underscores indicating bottom of board
	for (int i = 0; i < (bx * 2); i++) { cout << '_'; }
}


/*!
@brief Generates a Random board position between the max and min input arguments.

@returns random Board_Pos
*/
Board_Pos Board::Rand_board_pos(int xMax, int xMin, int yMax, int yMin)
{
	Board_Pos RandPos;
	int Xrand, Yrand;
	int tries = 0;

	//try to find a random position thats not taken until the try count is exceeeded
	do
	{
		//Generate random number between min and max
		Xrand = rand() % (xMax - xMin + 1) + xMin;
		//Generate random number between 0 and yseed
		Yrand = rand() % (yMax - yMin + 1) + yMin;

		RandPos.x = Xrand;
		RandPos.y = Yrand;
		tries++;
	} while ((Check_Board_Pos(RandPos) != 0u) && (tries < 10));

	//TO DO: Handle fail conditions i.e. if board pos can not be found.

	return RandPos;
}


/*!
@brief Generates a Random board position using the current board dimensions
as the min and max values. Uses the system time as seed.  
@returns random Board_Pos
*/
Board_Pos Board::Rand_board_pos()
{
	Board_Pos RandPos;
	int Xrand, Yrand;
	int tries = 0;

	//try to find a random position thats not taken until the try count is exceeeded
	do 
	{
		//Generate random number between 0 and current board x dimension
		//it is bx - 1 because the vector is 0 indexed
		Xrand = rand() % (bx);
		//Generate random number between 0 and current board y dimension
		Yrand = rand() % (by);

		RandPos.x = Xrand;
		RandPos.y = Yrand;
		tries++;
	} while ((Check_Board_Pos(RandPos) != 0u) && (tries < 10));

	//TO DO: Handle fail conditions i.e. if board pos can not be found.

	return RandPos;
}


/*!
@brief Checks the board to see if the input position is free.
@returns if position is free returns 0u. if position is taken,
it returns the icon of what character is in the position. i.e 'H' or 'P'
*/
char Board::Check_Board_Pos(Board_Pos pos)
{
	//check if the input position contains either a hunter or a player
	if (this->bvect[pos.y][pos.x] == ' ' )
	{
		return 0u;
	}
	else
	{
		return this->bvect[pos.y][pos.x];
	}
}


/*!
@brief getter function to return the board dimension

@return board dimension.
*/
Board_Pos Board::GetBoardDimensions() const 
{
	Board_Pos dimension; 
	dimension.x = bx;
	dimension.y = by; 
	return dimension;
}