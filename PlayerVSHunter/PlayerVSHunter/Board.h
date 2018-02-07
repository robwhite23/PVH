#pragma once
#include <vector>
using namespace std;

/*!
@brief defines a 2d x and y board
@input Optional x and y dimensions to overide the games board default
@returns N/A
*/
class Board{
public:
	
	Board(char x = 10, char y = 10);
	void print_board(void);
	vector< vector <char> > bvect;		//2d char vector to contain board locations
	
private:
	char bx;			
	char by;
};