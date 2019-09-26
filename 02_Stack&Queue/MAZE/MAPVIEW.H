#ifndef _CMAPVIEW_H_
#define _CMAPVIEW_H_

#include <stdio.h>
#include <conio.h>
#include "screen.h"	// Added by ClassView

class CMapView
{
    public:
	    void SetGoBackward();
	    void SetGoForward();
	    int GetMapHeight();
	    int GetMapWidth();
	    CMapView();
	    int  IsWall( int x, int y );
	    void Create();
	    void ShowMap();
	    void SetMousePos( int x, int y );
	    char* GetMapName();
	    void LoadMap();
	    void SetOrigin( int x, int y );

	private:
		bool m_bForward;
		void ShowMouse();
		void DecodeMapFile();
		void InitMap();
		int m_mouseY;
		int m_mouseX;
		int m_oldMouseY;
		int m_oldMouseX;
		int m_map[ 30 ][ 30 ];
		char m_mapName[ 20 ];
		int  m_mapX;
		int  m_mapY;
};

#endif