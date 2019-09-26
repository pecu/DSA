// StepRecord.cpp: implementation of the CStepRecord class.
//
//////////////////////////////////////////////////////////////////////

#include "StepRecord.h"
#include "valdef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStepRecord::CStepRecord()
{
	CStepRecord::InitAllVariable();
}

CStepRecord::~CStepRecord()
{

}

void CStepRecord::InitAllVariable()
{
	m_redPosX = m_redPosY = 0;

	m_moveFlag[ 0 ][ 0 ] = false; m_moveFlag[ 1 ][ 0 ] = false; m_moveFlag[ 2 ][ 0 ] = false;
	m_moveFlag[ 0 ][ 1 ] = false; m_moveFlag[ 1 ][ 1 ] = false; m_moveFlag[ 2 ][ 1 ] = false;
	m_moveFlag[ 0 ][ 2 ] = false; m_moveFlag[ 1 ][ 2 ] = false; m_moveFlag[ 2 ][ 2 ] = false;

	m_isBranch = false;

	m_direction = 0;

	m_next = 0;
}

CStepRecord * CStepRecord::GetNext()
{
	return m_next;
}

void CStepRecord::SetNext(CStepRecord *pt)
{
	m_next = pt;
}

bool CStepRecord::IsBranch()
{
	return m_isBranch;
}

void CStepRecord::SetMoveFlag(int pos)
{
	switch( pos )
	{
		case NORTH:
			m_moveFlag[ 1 ][ 0 ] = true;
			break;
		case NORTHEAST:
			m_moveFlag[ 2 ][ 0 ] = true;
			break;
		case EAST:
			m_moveFlag[ 2 ][ 1 ] = true;
			break;
		case SOUTHEAST:
			m_moveFlag[ 2 ][ 2 ] = true;
			break;
		case SOUTH:
			m_moveFlag[ 1 ][ 2 ] = true;
			break;
		case SOUTHWEST:
			m_moveFlag[ 0 ][ 2 ] = true;
			break;
		case WEST:
			m_moveFlag[ 0 ][ 1 ] = true;
			break;
		case NORTHWEST:
			m_moveFlag[ 0 ][ 0 ] = true;
			break;
	}

}

int CStepRecord::FindDirection()
{
	// serching by CW from NORTH

	if( m_moveFlag[ 1 ][ 0 ] == false )
	{
		return NORTH;
	}

	if( m_moveFlag[ 2 ][ 0 ] == false )
	{
		return NORTHEAST;
	}

	if( m_moveFlag[ 2 ][ 1 ] == false )
	{
		return EAST;
	}

	if( m_moveFlag[ 2 ][ 2 ] == false )
	{
		return SOUTHEAST;
	}

	if( m_moveFlag[ 1 ][ 2 ] == false )
	{
		return SOUTH;
	}

	if( m_moveFlag[ 0 ][ 2 ] == false )
	{
		return SOUTHWEST;
	}
	if( m_moveFlag[ 0 ][ 1 ] == false )
	{
		return WEST;
	}
	if( m_moveFlag[ 0 ][ 0 ] == false )
	{
		return NORTHWEST;
	}

	// nop !!
	return 0;
}

void CStepRecord::SetDirection(int dir)
{
	m_direction = dir;
}

void CStepRecord::CoverDirToXYOffset(int dir, int *x, int *y)
{
	switch( dir )
	{
		case NORTH:
			*x =  0;
			*y = -1;
			break;
		case NORTHEAST:
			*x =  1;
			*y = -1;
			break;
		case EAST:
			*x =  1;
			*y =  0;
			break;
		case SOUTHEAST:
			*x =  1;
			*y =  1;
			break;
		case SOUTH:
			*x =  0;
			*y =  1;
			break;
		case SOUTHWEST:
			*x = -1;
			*y =  1;
			break;
		case WEST:
			*x = -1;
			*y =  0;
			break;
		case NORTHWEST:
			*x = -1;
			*y = -1;
			break;
	}
}

void CStepRecord::Reset()
{
	InitAllVariable();
}

int CStepRecord::GetX()
{
	return m_redPosX;
}

int CStepRecord::GetY()
{
	return m_redPosY;
}

void CStepRecord::SetRedPos(int x, int y)
{
	m_redPosX = x;
	m_redPosY = y;
}

int CStepRecord::GetInvDirectio()
{
	switch( m_direction )
	{
		case NORTH:
			return SOUTH;
			break;
		case NORTHEAST:
			return SOUTHWEST;
			break;
		case EAST:
			return WEST;
			break;
		case SOUTHEAST:
			return NORTHWEST;
			break;
		case SOUTH:
			return NORTH;
			break;
		case SOUTHWEST:
			return NORTHEAST;
			break;
		case WEST:
			return EAST;
			break;
		case NORTHWEST:
			return SOUTHEAST;
			break;
	}

}

int CStepRecord::GetDirection()
{
	return m_direction;
}

void CStepRecord::SetBranch()
{
	m_isBranch = true;
}
