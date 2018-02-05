#pragma once

class Board{
public:
	Board(char x = 10, char y = 10);
	void print_board(void);

private:

	char bx;
	char by;
	void create_board(void);
};