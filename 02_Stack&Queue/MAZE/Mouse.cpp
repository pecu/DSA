// Mouse.cpp: implementation of the CMouse class.
//
//////////////////////////////////////////////////////////////////////

#include "Mouse.h"
#include "valdef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#define DELAY 100

CMouse::CMouse()
{

}

CMouse::~CMouse()
{

}

void CMouse::SetMap(CMapView *map)
{
	m_map = map;
}

void CMouse::SetStartPos(int x, int y)
{
	m_xPos = x;
	m_yPos = y;
	

	m_map->SetMousePos( x, y );
}

void CMouse::InitAllVariable()
{
	m_xPos = m_yPos = 0;
}

void CMouse::SetGoalPos(int x, int y)
{
	m_goalYPos = y;
	m_goalXPos = x;
}

void CMouse::Go()
{
	CStepRecord red, tmpRed;
	int direction, xOffset, yOffset;

	Sleep( 1000 );

	while( !OnGoal() )
	{
		CheckAround( &red );
				
		direction = red.FindDirection();
		
		if( direction != 0 )
		// 有找到可以走的方向。
		{
			m_map->SetGoForward();

			red.SetDirection( direction );
			red.SetMoveFlag( direction );
			red.SetRedPos( m_xPos, m_yPos );

			red.CoverDirToXYOffset( direction, &xOffset, &yOffset );

			m_xPos += xOffset;
			m_yPos += yOffset;

			m_stack.Push( red );
			red.Reset();

			m_map->SetMousePos( m_xPos, m_yPos );

		}
		else
		// 走到死路。
		{
			m_map->SetGoBackward();

			if( m_xPos == 1 && m_yPos == 1 )
			{
				m_stack.Push( red );
				printf( "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nNo exit !!\a\a\n" );
				return;
			}

			m_stack.Pop( &red );
			
			direction = red.GetInvDirectio();

			red.CoverDirToXYOffset( direction, &xOffset, &yOffset );

			m_xPos += xOffset;
			m_yPos += yOffset;

			m_map->SetMousePos( m_xPos, m_yPos );			
		}

		Sleep( DELAY );
	}

	red.SetRedPos( m_goalXPos, m_goalYPos );
	m_stack.Push( red );
	m_map->SetMousePos( m_goalXPos, m_goalYPos );

	printf( "\n\n\n" );

	m_stack.Dump();
}

bool CMouse::OnGoal()
{
	if( m_xPos == m_goalXPos && m_yPos == m_goalYPos )
	{
		return true;
	}
	else
	{
		return false;
	}
}

void CMouse::CheckAround(CStepRecord *red)
{
	if( m_map->IsWall( m_xPos, m_yPos - 1 ) || m_stack.FindStep( m_xPos, m_yPos - 1 ) ||
		m_stack.FindInHistory( m_xPos, m_yPos - 1 ) )
	{
		red->SetMoveFlag( NORTH );
	}

	if( m_map->IsWall( m_xPos + 1, m_yPos - 1 ) || m_stack.FindStep( m_xPos + 1, m_yPos - 1 ) ||
		m_stack.FindInHistory( m_xPos + 1, m_yPos - 1 ) )
	{
		red->SetMoveFlag( NORTHEAST );
	}

	if( m_map->IsWall( m_xPos + 1, m_yPos ) || m_stack.FindStep( m_xPos + 1, m_yPos ) ||
		m_stack.FindInHistory( m_xPos + 1, m_yPos ) )
	{
		red->SetMoveFlag( EAST );
	}

	if( m_map->IsWall( m_xPos + 1, m_yPos + 1 ) || m_stack.FindStep( m_xPos + 1, m_yPos + 1 ) ||
		m_stack.FindInHistory( m_xPos + 1, m_yPos + 1 ) )
	{
		red->SetMoveFlag( SOUTHEAST );
	}

	if( m_map->IsWall( m_xPos, m_yPos + 1 ) || m_stack.FindStep( m_xPos, m_yPos + 1 ) ||
		m_stack.FindInHistory( m_xPos, m_yPos + 1 ) )
	{
		red->SetMoveFlag( SOUTH );
	}

	if( m_map->IsWall( m_xPos - 1, m_yPos + 1 ) || m_stack.FindStep( m_xPos - 1, m_yPos + 1 ) ||
		m_stack.FindInHistory( m_xPos - 1, m_yPos + 1 ) )
	{
		red->SetMoveFlag( SOUTHWEST );
	}

	if( m_map->IsWall( m_xPos - 1, m_yPos ) || m_stack.FindStep( m_xPos - 1, m_yPos ) ||
		m_stack.FindInHistory( m_xPos - 1, m_yPos ) )
	{
		red->SetMoveFlag( WEST );
	}

	if( m_map->IsWall( m_xPos - 1, m_yPos - 1 ) || m_stack.FindStep( m_xPos - 1, m_yPos - 1 ) ||
		m_stack.FindInHistory( m_xPos - 1, m_yPos - 1 ) )
	{
		red->SetMoveFlag( NORTHWEST );
	}
}