#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Keyboard.h"

/*!
@brief waits for a keyboard event and returns the a char of the
character pressed. It ignores special keys such as escape and arrow keys.
@returns char of key pressed.
*/
char Keyboard::getkeypress()
{
	TCHAR c = 0;
	DWORD mode, count;
	char ch;
	//create handle to console input buffer
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
	if (h != NULL) {
		GetConsoleMode(h, &mode);
		//set console to not echo key presses onto console output
		SetConsoleMode(h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
		//read key input
		ReadConsole(h, &c, 1, &count, NULL);
		//return console original mode
		SetConsoleMode(h, mode);
		ch = (char)c;
		return ch;
	}
	else
	{
		return 0;  // not a console
	}
}


/*!
@brief calls the ReadArrowKeyEvent function until the key detected is either
up, down, left or right arrow key. The reason it has to be called a number of times
using the do while loop is because a key event is also written to the console 
input buffer when the arrow key is released. Therefore a single arrow button press 
registers twice. To overcome this the ReadarrowkeyPress function is written so that
a button release event returns incorrectkey and this function calls the getarrowkeyevent
until a valid arrow detection is made. The benefit of writing it this way is that the
arrow keys can be held to constantly move in the same direction.
@returns ArrowKey 
*/
eArrowKey Keyboard::getarrowkeypress(){
	eArrowKey key;
	do { 
		key = this->ReadArrowKeyEvent();
	} while (key == INCORRECTKEY);
	return key;
}


/*!
@brief Reads the an arrow key button event.  
@returns If the button event is a button press, then the button val is returned.
If the button event is a button release event, then incorrectkey is returned.
*/
eArrowKey Keyboard::ReadArrowKeyEvent()
{
	//create a handle to the console input buffer.
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD NumInputs = 0;
	DWORD InputsRead = 0;

	INPUT_RECORD irInput;
	eArrowKey Key;
	//read the console input event
	ReadConsoleInput(hInput, &irInput, 1, &InputsRead);

	if (irInput.EventType == KEY_EVENT && irInput.Event.KeyEvent.bKeyDown)
	{
		//the key event is a key event and not a button release event. So switch
		//on the result.
		switch (irInput.Event.KeyEvent.wVirtualKeyCode)
		{

		case VK_LEFT:
		case VK_NUMPAD4:
			Key = LEFT;
			break;

		case VK_UP:
		case VK_NUMPAD8:
			Key = UP;
						
			break;
		case VK_RIGHT:
		case VK_NUMPAD6:
			Key = RIGHT;
			break;

		case VK_DOWN:
		case VK_NUMPAD2:
			Key = DOWN;
			break;

		default:
			//not an arrow key
			Key = INCORRECTKEY;
		}	
	} 
	else {
		//not a key press or it is a button release event
		Key = INCORRECTKEY;	
	}

	return Key;
}

