#pragma once
#include <vector>
using namespace std;

//struct used to hold x and y coordinates
typedef struct {
	int x;
	int y;
}Board_Pos;

/*!
@brief defines a 2d x and y board
@input Optional x and y dimensions to overide the games board default
@returns N/A
*/
class Board{
public:
	
	Board(char x = 10, char y = 10);
	void print_board(void);
	Board_Pos Rand_board_pos();
	Board_Pos Rand_board_pos(int xMax, int xMin, int yMax, int yMin);
	bool Check_Board_Pos(Board_Pos pos);
	
	vector< vector <char> > bvect;		//2d char vector to contain board locations

	Board_Pos GetBoardDimensions() const;
private:
	int bx;			
	int by;
};