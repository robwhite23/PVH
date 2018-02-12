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
	PvH.StartMenu();
	
    return 0;
}


/*!
@brief Contains the high level control flow of the game. Uses a number of 
state machines to control the menu system and action the user inputs.

@returns N/A
*/
void Game::StartMenu(void)
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
							// Start the game
							this->StartGame();
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
@brief loops through each level in the game calling play level.
@return n/a
*/
void Game::StartGame(void)
{
	for (int idx = 1; idx <= MAX_LEVELS; idx++)
	{
		//To Do: Display level start menu
		this->Level = idx;
		this->PlayLevel(Level + DIFFICULTY);
	}
}

/*!
@brief implements the level functionality. 
@Input takes in the desired level to play. This value is used to dynamically create the
desired level and difficulty. For example, level 5 = 5 hunter etc.
TO DO: exit when player dead.
@returns N/A
*/
void Game::PlayLevel(int Level){

	Board_Pos hunter_pos; 

	//display Level start screen
	DisplayLevelStartScreen();
	
	//empty the hunter vector
	if (this->hunters.size() != 0) this->hunters.clear();
	
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
		HuntersMove();
		this->score += MOVE_SCORE_INCREMENT;
		//print the board and the contents to the console.
		this->menu.pos(0, 7);
		this->board.print_board();
		Sleep(100);
	}	
	//empty the hunter vector
	this->hunters.clear();

	//empty bvect
	this->board.Clear_board();

	//display level complete screen
}


/*!
@brief waits for the user to press an arrow key to move the player.
TO DO: return value when player dead

@return n/a
*/
void Game::PlayerMove(void){
	
	//wait for an arrow key press
	this->ArrowKeyinput = this->keyboard.getarrowkeypress();
	switch (ArrowKeyinput)
	{
		case UP:
			if (P1.MoveUp(this->board) == 'H'){
				this->menu.pos(0, 20);
				cout << "hunter killed you";
				this->menu.pos(0, 7);
			}
			break;

		case DOWN:
			if (P1.MoveDown(this->board) == 'H'){
				this->menu.pos(0, 20);
				cout << "hunter killed you";
				this->menu.pos(0, 7);
			}
			break;

		case LEFT:
			if (P1.MoveLeft(this->board) == 'H'){
				this->menu.pos(0, 20);
				cout << "hunter killed you";
				this->menu.pos(0, 7);
			}
			break;

		case RIGHT:
			if (P1.MoveRight(this->board) == 'H'){
				this->menu.pos(0, 20);
				cout << "hunter killed you";
				this->menu.pos(0, 7);
			}
			break;

		default:
			menu.pos(0, 9);
			cout << ERROR_MSG << endl;
			break;
	}
}


/*!
@brief iterates through each hunter and calls the move random function until
a sucessful move was completed or the number tries expires.
@return n/a
*/
void Game::HuntersMove(void){
	 
	int MoveFailTotal = 0;
	//iterate through hunters by reference so actual hunters value will change
	for (Hunter &idx: hunters)
	{
		char RandMoveResult;
		int tries = 0;
		//try to complete a random move until successful or tries exceeds limit
		do 
		{
			RandMoveResult = idx.MoveRandom(this->board);
			tries++;
					//(while pos doesnt exist			or hunter already in pos)	and max tries not exceeded
		} while (((RandMoveResult == POS_DID_NOT_EXIST) || (RandMoveResult == idx.GetIcon())) && tries <= 6);
		
		//keep a count of the number of times a hunter couldnt move
		if (tries > 5)
		{
			MoveFailTotal++;
		}
		if (RandMoveResult == 'P')
		{
			//debug output
			this->menu.pos(0, 20);
			cout << "Hunter has killed you";
			this->menu.pos(0, 7);
		}

	}
	//debug output
	this->menu.pos(0, 22);
	cout << "number of hunters not moved: " << MoveFailTotal;
	this->menu.pos(0, 7);
}


/*!
@brief Prints out a square with the current level number inside it. The square size 
is generated from the board size. It then waits for the user to press any key before continuing.
@return n/a
*/
void Game::DisplayLevelStartScreen()
{
	//set curser position to start of board
	this->menu.pos(0, 7);

	//print a square box the same size as the board
	for (int i = 0; i < (this->board.GetBoardDimensions().x ); i++) { cout << "* "; }
	cout << endl;
	for (int i = 0; i<this->board.GetBoardDimensions().y; i++)
	{
		cout << '*';
		for (int j = 0; j<board.GetBoardDimensions().x; j++)
		{
			if (j ==  board.GetBoardDimensions().x -1){
				//this is last x position
				cout << "*";
			}
			else{
				//print two spaces
				cout << "  ";
			}
			
		}
		cout << endl;
	}
	for (int i = 0; i < (this->board.GetBoardDimensions().x); i++) { cout << "* "; }

	//find a good approximate for text in the center of the box. The x is only divided by two because the box
	//is two spaces per x dimension. Therefore dividing by two is same as dividing by 4 in the Y dimension.
	this->menu.pos((this->board.GetBoardDimensions().x / 2), (7 + (this->board.GetBoardDimensions().y / 2)));

	cout << "LEVEL " << this->Level;
	
	//display instructions
	this->menu.pos(0, 20);
	cout << "Press any key to continue...";

	//wait for a key press before continuing
	this->Keyinput = this->keyboard.getkeypress();

	this->menu.clear_lines(20, 2);
	this->menu.pos(0, 7);

}


