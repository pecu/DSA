/* ----------------------------------------------------------------------- *
 * s c r e e n . h
 *
 * a class to manage a Windows NT console.  allows moving to
 * an x, y location and clearing the screen.
 *
 * Copyright 1996 by Interface Technologies, Inc. All Rights Reserved.
 * ----------------------------------------------------------------------- */

#ifndef __SCREEN_H
#define __SCREEN_H

#include <iostream>
#include <windows.h>

class Screen
{
public:
	void SetTextColor( int index );
    Screen();
    ~Screen();
    void GotoXY( int x, int y );
    void CharXY( int x, int y, char c);
    void Char( char c); // pyt
    void StrXY ( int x, int y, const char * str); // pyt
    void Clear();
private:
    COORD coord;
};

#endif