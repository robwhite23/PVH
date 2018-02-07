#include "stdafx.h"
#include <iostream>
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