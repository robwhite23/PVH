// PlayerVSHunter.cpp : main project file.

#include "stdafx.h"
#include "PlayerVSHunter.h"

/*!
@brief Main application entry point. Instanciates the game and calls
the Game::Start function (starts the game main thread).

@returns N/A
*/
int main(array<System::String ^> ^args)
{
	Game PvH;
	PvH.start();
	
    return 0;
}


/*!
@brief Contains the high level control flow of the game. Uses a number of 
state machines to control the menu system and action the user inputs.

@returns N/A
*/
void Game::start(void)
{
	bool quit = false; //when true exit whole application
	this->menu.DisplayMainMenu();
	while (false == quit ){
		
		//top level state machine to switch to current menu 
		switch (menu.Getcurrentscreen()) 
		{
			case HOME:
				//wait for a key press
				this->Keyinput = this->keyboard.getkeypress();
				//action the key press
				switch (Keyinput)
				{
						case 'p':
							//display the Play screen
							this->menu.EnterPlayscreen();
							break;

						case 'l':
							//display the leaderboard screen;
							this->menu.EnterLeaderboardscreen();
							break;

						case 'q':
							//quit the application;
							quit = true;
							break;

						default :
							menu.pos(0, 9);
							cout << "incorrect key entry. Please press p,l or q" << endl;
							break;

				}
				break;       

			case LEADERBOARD: 
				//whilst in the leaderboard menu; wait for key press;
				this->Keyinput = this->keyboard.getkeypress();
				//action key press 
				switch (this->Keyinput)
				{
						case 'q':
							//display the home menu;
							this->menu.EnterHomescreen();
							break;

						default:
							menu.pos(0, 7);
							cout << "incorrect key entry. Please press q to enter Home screen" << endl;
							break;

				}
				break;

			case PLAY:
				//whilst in play menu wait for key press.
				this->Keyinput = this->keyboard.getkeypress();
				//action key press
				switch (this->Keyinput)
				{
						case 'p':
							// display the home menu;
							this->PlayLevel(5);
							break;

						case 'q':
							// display the home menu;
							this->menu.EnterHomescreen();
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


/*!
@brief implements the level functionality. 
@Input takes in the desired level to play. This value is used to dynamically create the
desired level and difficulty. For example, level 5 = 5 hunter etc.
@returns N/A
*/
void Game::PlayLevel(int Level){

	Board_Pos hunter_pos;

	//create hunters for level
	for (int idx = 0; idx < Level; idx++)
	{
		hunter_pos.x = (char)idx;
		hunter_pos.y = 0u;
		hunters.push_back(Hunter(hunter_pos,'H'));
	}
	
	for (Hunter &hunter: hunters)
	{
		//TO DO: Implement hunter get functions
		this->board.bvect[hunter.GetBoard_Pos().y][hunter.GetBoard_Pos().x] = hunter.GetIcon();
	}

	this->board.print_board();
		
}
