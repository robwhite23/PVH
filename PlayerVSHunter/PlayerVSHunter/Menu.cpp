#include "stdafx.h"
#include "Menu.h"

using namespace std;

void Menu::DisplayMainMenu(){
	string art = MenuART;
	cout << art << endl;
	cout << HOME_MENU_TEXT << endl;
	cout << HOME_USR_INSTRUCTIONS << endl;
}
void Menu::pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}
void Menu::clear_lines(short start_line, short no_of_lines)
{
	pos(0, start_line);
	for (int j = 0; j <= no_of_lines; j++)
		cout << BLANK_LINE;
	pos(0, start_line);
}

void Menu::Setcurrentscreen(eScreen val){ this->current_screen = val; }
eScreen Menu::Getcurrentscreen() const{ return this->current_screen; }