
/* ----------------------------------------------------------------------- *
 * s c r e e n . c p p
 *
 * a class to manage an Windows NT console.  allows moving to
 * an x, y location and clearing the screen.
 *
 * Copyright 1996 by Interface Technologies, Inc. All Rights Reserved.
 * ----------------------------------------------------------------------- */

// for NT Screen Console functions
#include <windows.h>
#include "screen.h"

static HANDLE hConsole = 0;
static int instanceCount = 0;

Screen::Screen()
{
    coord.X = coord.Y = 0; // pyt
    if( instanceCount == 0 )
    {
        hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    }

    instanceCount++;

    Clear();
}


Screen::~Screen()
{
    instanceCount--;

    if( instanceCount == 0 )
    {
//		  CloseHandle( hConsole );
    }
}


void Screen::GotoXY( int x, int y )
{
//    COORD coord;  // pyt

    coord.X = x - 1;
    coord.Y = y - 1;
	
    SetConsoleCursorPosition( hConsole, coord );
}


void Screen::CharXY( int x, int y, char c)
{
//    COORD coord;  // pyt
    DWORD numWritten;

    coord.X = x - 1;
    coord.Y = y - 1;
	
    SetConsoleCursorPosition( hConsole, coord );
    WriteConsoleOutputCharacter( hConsole, &c, 1, coord, &numWritten );
}


void Screen::Char( char c) // pyt
{
    DWORD numWritten;

    coord.X++;
    coord.Y;
	
    SetConsoleCursorPosition( hConsole, coord );
    WriteConsoleOutputCharacter( hConsole, &c, 1, coord, &numWritten );
}


void Screen::StrXY( int x, int y, const char *str) // pyt
{
//    COORD coord;  // pyt
    DWORD numWritten;

    coord.X = x - 1;
    coord.Y = y - 1;

    SetConsoleCursorPosition( hConsole, coord );
    WriteConsoleOutputCharacter( hConsole, str, strlen(str), coord, &numWritten );

    coord.X += (int)numWritten;
}


void Screen::Clear()
{
  COORD coordScreen = { 0, 0 }; /* here's where we'll home the cursor */
  BOOL bSuccess;
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */
  DWORD dwConSize; /* number of character cells in the current buffer */

  /* get the number of character cells in the current buffer */
  bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);

  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
  /* fill the entire screen with blanks */
  bSuccess = FillConsoleOutputCharacter(hConsole, (TCHAR) ' ',
      dwConSize, coordScreen, &cCharsWritten);

  /* get the current text attribute */
  bSuccess = GetConsoleScreenBufferInfo(hConsole, &csbi);

  /* now set the buffer's attributes accordingly */
  bSuccess = FillConsoleOutputAttribute(hConsole, csbi.wAttributes,
      dwConSize, coordScreen, &cCharsWritten);

  /* put the cursor at (0, 0) */
  bSuccess = SetConsoleCursorPosition(hConsole, coordScreen);

  return;
}

void Screen::SetTextColor(int index)
{
	SetConsoleTextAttribute( hConsole, index );
}
