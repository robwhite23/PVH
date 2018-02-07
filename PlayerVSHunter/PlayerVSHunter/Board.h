#pragma once
#include <vector>
using namespace std;

#define BOARD_DIMENSION 10
class Board{
public:
	
	Board(char x = 10, char y = 10);
	void print_board(void);
	vector< vector <char> > bvect;
	

private:

	char bx;
	char by;
	void create_board(void);
};