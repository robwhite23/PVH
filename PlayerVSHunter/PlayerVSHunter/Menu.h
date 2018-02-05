#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#define MenuART R"(***************************************************************
*****                                                     *****
*****                   Player VS Hunter                  *****
*****                                                     *****
***************************************************************)"

#define PLAY_MENU_TEXT "                              PLAY"
#define LEADERBOARD_MENU_TEXT "                           LEADERBOARD"
#define HOME_MENU_TEXT "                              HOME"
#define PLAY_USR_INSTRUCTIONS "Exit (q)"
#define LBOARD_USR_INSTRUCTIONS "Exit (q)"
#define HOME_USR_INSTRUCTIONS "Play (p) \nLeaderboard (l) \nExit (q)"
#define BLANK_LINE "                                                                   "


#define ERROR_MSG "oops.. something went wrong \nbye."
enum eScreen { HOME, LEADERBOARD, PLAY };
class Menu {
public:
	Menu() : current_screen(HOME){};
	void DisplayMainMenu();
	void Setcurrentscreen(eScreen val);
	eScreen Getcurrentscreen() const;
	void pos(short C, short R);
	void clear_lines(short start_line, short no_of_lines);
private:
	eScreen current_screen;

};