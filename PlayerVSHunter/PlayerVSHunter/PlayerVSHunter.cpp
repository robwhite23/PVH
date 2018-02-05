// PlayerVSHunter.cpp : main project file.

#include "stdafx.h"
#include "PlayerVSHunter.h"

using namespace std;

int main(array<System::String ^> ^args)
{
	
	Game PvH;
	PvH.start();
	
    return 0;
}


void Game::start(void)
{
	bool quit = false;
	this->menu.DisplayMainMenu();
	while (false == quit ){
		
		menu.Getcurrentscreen();
		switch (menu.Getcurrentscreen()) 
		{
			case HOME:
				//cout << "your in the home menu" << endl;
				this->Keyinput = this->keyboard.getkeypress();
				switch (Keyinput)
				{
						case 'p':
							//cout << "you selected Play" << endl;
							this->menu.Setcurrentscreen(PLAY);
							menu.clear_lines(5, 5);
							cout << PLAY_MENU_TEXT << endl;
							cout << PLAY_USR_INSTRUCTIONS << endl;
							break;

						case 'l':
							//cout << "you selected Leaderboard" << endl;
							this->menu.Setcurrentscreen(LEADERBOARD);
							menu.clear_lines(5, 5);
							cout << LEADERBOARD_MENU_TEXT << endl;
							cout << LBOARD_USR_INSTRUCTIONS << endl;
							break;

						case 'q':
							//cout << "you selected Quit" << endl;
							quit = true;
							break;

						default :
							menu.pos(0, 9);
							cout << "incorrect key entry. Please press p,l or q" << endl;
							break;

				}
				break;       

			case LEADERBOARD: 
				//cout << "your in the leaderboard menu" << endl;
				this->Keyinput = this->keyboard.getkeypress();
				switch (this->Keyinput)
				{
						case 'q':
							//cout << "you selected Quit" << endl;
							this->menu.Setcurrentscreen(HOME);
							menu.clear_lines(5, 5);
							cout << HOME_MENU_TEXT << endl;
							cout << HOME_USR_INSTRUCTIONS << endl;
							break;

						default:
							menu.pos(0, 7);
							cout << "incorrect key entry. Please press q to enter Home screen" << endl;
							break;

				}
				break;

			case PLAY:
				//cout << "your in the play menu" << endl;
				this->Keyinput = this->keyboard.getkeypress();
				switch (this->Keyinput)
				{
						case 'q':
							cout << "you selected Quit" << endl;
							this->menu.Setcurrentscreen(HOME);
							menu.clear_lines(5, 5);
							cout << HOME_MENU_TEXT << endl;
							cout << HOME_USR_INSTRUCTIONS << endl;
							break;

						default:
							menu.pos(0, 7);
							cout << "incorrect key entry. Please press q to enter Home screen" << endl;
							break;
				}
				break;

			default:
				cout << ERROR_MSG << endl;
				break;
		}//end case
		
	}//end while
	cout << "you've exited the game." << endl;

	
}

