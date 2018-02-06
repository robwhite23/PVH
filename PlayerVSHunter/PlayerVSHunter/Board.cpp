#include "stdafx.h"
#include <iostream>
#include "Board.h"



Board::Board(char x, char y) : bx(x), by(y){
	//create board.
	for (int i = 0; i<by; i++)
	{
		vector <char> bRow;
		for (int j = 0; j<bx; j++)
		{
			bRow.push_back(' ');
		}
		this->bvect.push_back(bRow);
	}

}


void Board::print_board(void){
    
	for (int i = 0; i < (bx*2); i++) { cout << '_'; }
	cout << endl;
	for (int i = 0; i<by; i++)
	{
		cout << '|';
		for (int j = 0; j<bx; j++)
		{
			cout << this->bvect[i][j]<<'|';
		}
		cout << endl;
	}
	for (int i = 0; i < (bx * 2); i++) { cout << '_'; }
}