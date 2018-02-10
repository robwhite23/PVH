#include "stdafx.h"
#include "Menu.h"

using namespace std;

/*!
@brief Prints out the games menu art then displays the home menu. 

@returns N/A
*/
void Menu::DisplayMainMenu(){
	string art = MenuART;
	cout << art << endl;
	cout << HOME_MENU_TEXT << endl;
	cout << HOME_USR_INSTRUCTIONS << endl;
}


/*!
@brief sets the console curser position to a specific location

@returns N/A
*/
void Menu::pos(short C, short R)
{
	COORD xy;
	xy.X = C;
	xy.Y = R;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

/*!
@brief Clears the console from a specific line to the number of
lines specified in the input arguments. Sets the console back to
the start line.

@returns N/A
*/
void Menu::clear_lines(short start_line, short no_of_lines)
{
	//set curser to start position
	pos(0, start_line);
	//write out blank lines for the number of lines required
	for (int j = 0; j <= no_of_lines; j++){
		cout << BLANK_LINE;
	}
	//set line back to start position
	pos(0, start_line);
}


/*!
@brief Completes the required menu functions to enter the play screen

@returns N/A
*/
void Menu::EnterPlayscreen(){
	Setcurrentscreen(PLAY);
	clear_lines(5, 5);
	cout << PLAY_MENU_TEXT << endl;
	cout << PLAY_USR_INSTRUCTIONS << endl;
}


/*!
@brief Completes the required menu functions to enter the LeaderBoard screen

@returns N/A
*/
void Menu::EnterLeaderboardscreen(){
	Setcurrentscreen(LEADERBOARD);
	clear_lines(5, 5);
	cout << LEADERBOARD_MENU_TEXT << endl;
	cout << LBOARD_USR_INSTRUCTIONS << endl;
}


/*!
@brief Completes the required menu functions to enter the Home screen

@returns N/A
*/
void Menu::EnterHomescreen(){
	Setcurrentscreen(HOME);
	clear_lines(5, 5);
	cout << HOME_MENU_TEXT << endl;
	cout << HOME_USR_INSTRUCTIONS << endl;
}


