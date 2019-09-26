//#include "..\MyProj~1\Maze\MapView.h"
#include "screen.h"
#include "MapView.h"
#include <io.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

Screen sc;

void GoToXY( int x, int y )
{
	sc.GotoXY( x, y );
}

void SetTextColor( int index )
{
	sc.SetTextColor( index );
}

////////////////////////////////////////////////////


CMapView::CMapView()
{
	strcpy( m_mapName, "map.txt" );

	SetGoForward();

	m_mouseX = m_oldMouseX = 0;
	m_mouseY = m_oldMouseY = 0;
}

void CMapView::LoadMap()
{
	FILE *mapFile;

	while( ( mapFile = fopen( m_mapName, "r" ) ) == NULL )
	{
		puts( "please input map file name : " );
		gets( m_mapName );
		mapFile = fopen( m_mapName, "r" );

		system( "cls" );
	}

	fclose( mapFile );
}

void CMapView::SetOrigin( int x, int y )
{


}

char* CMapView::GetMapName()
{
	return m_mapName;
}

void CMapView::SetMousePos(int x, int y)
{
	m_oldMouseX = m_mouseX;
	m_oldMouseY = m_mouseY;

	m_mouseX = x;
	m_mouseY = y;

	ShowMouse();
}

void CMapView::ShowMap()
{
	int i, j;
	char tmp[ 60 ];

	GoToXY( 0, 0 );
	
	for( i = 0; i < m_mapY + 2; i ++ )
	{
		strcpy( tmp, "" );

		for( j = 0; j < m_mapX + 2; j ++ )
		{
			if( m_map[ j ][ i ] == 0 )
			{
				strcat( tmp, "  " );
			} 
			else if( m_map[ j ][ i ] == 1 )
			{
				strcat( tmp, "◇" );
			}
			else if( m_map[ j ][ i ] == 2 )
			{
				strcat( tmp, "█" );
			}
		}
		tmp[ strlen( tmp ) ] = '\0';

		printf( "%s\n", tmp );
	}
}

void CMapView::InitMap()
{
	int i, j;

	for( i = 0; i < 30; i ++ )
	{
		for( j = 0; j < 30; j ++ )
		{
			m_map[ i ][ j ] = 2;
		}
	}
}

void CMapView::DecodeMapFile()
{
	char tmp[ 30 ];
	int  posXFlag = 0; 
	int  posYFlag = 0;
	int  i;
	FILE *mapFile;
	

	if( ( mapFile = fopen( m_mapName, "r" ) ) == NULL )
	{
		printf( "Open %s fail!\n", m_mapName );

		return;
	}
	
	// 讀地圖的長寬 ////////////////////////
	fgets( tmp, 20, mapFile );
	sscanf( tmp, "%d,%d", &m_mapX, &m_mapY );
	
	// 載入地圖     ////////////////////////
	for( i = 0; i < m_mapY; i ++ )
	{
		fgets( tmp, 25, mapFile );
				
		while( tmp[ posXFlag ] != '\0' && tmp[ posXFlag ] != '\n' )
		{
			// 由 1, 1開始放地圖，可以告造成牆的效果。
			m_map[ posXFlag + 1 ][ posYFlag + 1 ] = (int)( tmp[ posXFlag ] - '0' );
			posXFlag ++;
		}

		posXFlag = 0;
		posYFlag ++;			
	}


	fclose( mapFile );
}

void CMapView::Create()
{
	InitMap();

	LoadMap();

	DecodeMapFile();

	ShowMap();
}

int CMapView::IsWall(int x, int y)
{
	if( m_map[ x ][ y ] == 0 )
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void CMapView::ShowMouse()
{
	if( m_oldMouseX != 0 && m_oldMouseY != 0 )
	{
		if( m_bForward )
		{
			GoToXY( m_oldMouseX * 2 + 1, m_oldMouseY + 1 );

			SetTextColor( BACKGROUND_INTENSITY | BACKGROUND_GREEN );
			printf( "%s", "  " );
			SetTextColor( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
		}
		else
		{
			GoToXY( m_oldMouseX * 2 + 1, m_oldMouseY + 1 );

			//SetTextColor( BACKGROUND_INTENSITY | BACKGROUND_RED );
			printf( "%s", "  " );
			//SetTextColor( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
		}
	}

	GoToXY( m_mouseX * 2 + 1, m_mouseY + 1 );
	
	SetTextColor( FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_RED );
	printf( "%s", "Μ" );
	SetTextColor( FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE );
}


int CMapView::GetMapWidth()
{
	return m_mapX;
}

int CMapView::GetMapHeight()
{
	return m_mapY;
}

void CMapView::SetGoForward()
{
	m_bForward = true;
}

void CMapView::SetGoBackward()
{
	m_bForward = false;
}
