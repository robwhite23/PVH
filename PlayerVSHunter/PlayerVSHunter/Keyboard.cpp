#pragma once
#include "stdafx.h"
#include "Keyboard.h"

char Keyboard::getkeypress()
{
	TCHAR c = 0;
	DWORD mode, count;
	char ch;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);
	if (h == NULL) return 0;  // not a console
	GetConsoleMode(h, &mode);
	SetConsoleMode(h, mode & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
	ReadConsole(h, &c, 1, &count, NULL);
	SetConsoleMode(h, mode);
	ch = (char)c;
	
	return ch;
}
