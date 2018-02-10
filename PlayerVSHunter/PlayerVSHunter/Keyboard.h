#pragma once
#include <windows.h>
enum eArrowKey { UP, DOWN, LEFT, RIGHT, INCORRECTKEY };
class Keyboard{
public:
	Keyboard(){};
	char getkeypress();
	eArrowKey getarrowkeypress();
	eArrowKey ReadArrowKeyEvent();

private:

};