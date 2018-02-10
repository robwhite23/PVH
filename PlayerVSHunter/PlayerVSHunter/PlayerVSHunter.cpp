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

	//seed the random number generator with system tick count
	srand((int)GetTickCount()); 

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
	
	//TO DO: add protection so you cant create monsters without deleting the previous set.

	//create hunters for level
	for (int idx = 0; idx < Level ; idx++)
	{
		hunter_pos.x = idx;
		hunter_pos.y = 0u;
		//push hunter into vector pre-loaded with random board pos
		hunters.push_back(Hunter(this->board.Rand_board_pos(), 'H'));
		//Add hunters to the board in their respective locations
		this->board.bvect[hunters.at(idx).GetBoard_Pos().y][hunters.at(idx).GetBoard_Pos().x] = 
			hunters.at(idx).GetIcon();
	}

	//set P1 start pos to random position
	this->P1.Set_Board_Pos(this->board.Rand_board_pos());
	this->board.bvect[this->P1.GetBoard_Pos().y][this->P1.GetBoard_Pos().x] =
		this->P1.GetIcon();

	//print the board and the contents to the console.
	this->board.print_board();

	for (int idx = 0; idx < Get_level_turns(); idx++)
	{
		PlayerMove();
		//print the board and the contents to the console.
		this->menu.pos(0, 7);
		this->board.print_board();
		Sleep(100);
	}		
}


/*!
@brief waits for the user to press an arrow key to move the player.

@return n/a
*/
void Game::PlayerMove(void){
	
	//wait for an arrow key press
	this->ArrowKeyinput = this->keyboard.getarrowkeypress();
	switch (ArrowKeyinput)
	{
		case UP:
			P1.MoveUp(this->board);
			break;

		case DOWN:
			P1.MoveDown(this->board);
			break;

		case LEFT:
			P1.MoveLeft(this->board);
			break;

		case RIGHT:
			P1.MoveRight(this->board);
			break;

		default:
			menu.pos(0, 9);
			cout << ERROR_MSG << endl;
			break;
	}
}




