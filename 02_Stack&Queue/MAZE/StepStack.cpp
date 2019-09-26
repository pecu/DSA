// StepStack.cpp: implementation of the CStepStack class.
//
//////////////////////////////////////////////////////////////////////

#include "StepStack.h"
#include <stdio.h>
#include "StepRecord.h"
#include "valdef.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#define null 0;


CStepStack::CStepStack()
{
	InitAllVariable();
}

CStepStack::~CStepStack()
{
	DeleteLink();
}

void CStepStack::InitAllVariable()
{
	int i;

	m_stepStack = null;
	m_stepCount = 0;
	m_historyCount = 0;

	for( i = 0; i ++; i < 300 )
	{
		m_stepHistory[ i ].x = m_stepHistory[ i ].y = 0;
	}
}

void CStepStack::Push(CStepRecord red)
{
	CStepRecord **pt = &m_stepStack, *tmp, popVal;

	m_stepCount ++;

	AddToHistory( red.GetX(), red.GetY() );

	if( *pt == 0 )  //??????
	{
		*pt = new CStepRecord;
		**pt = red;

		return;		
	}

	tmp = *pt;

	while( tmp->GetNext() != 0 )
	{
		tmp = tmp->GetNext();	
	}

	tmp->SetNext( new CStepRecord );
	tmp = tmp->GetNext();
	*tmp = red;
}

void CStepStack::Pop( CStepRecord *red )
{
	CStepRecord **pt = &m_stepStack, *tmp, *lastTmp;

	if( *pt == 0 )  //??????
	{
		red = 0;

		return;
	}

	tmp = *pt;

	while( tmp->GetNext() != 0 )
	{
		lastTmp = tmp;
		tmp = tmp->GetNext();
	}

	if( tmp == *pt )
	{
		*red = *tmp;
		m_stepCount --;
		
		delete *pt;
		*pt = 0;

		return;	
	}

	*red = *tmp;

	delete lastTmp->GetNext();
	lastTmp->SetNext( 0 );

	m_stepCount --;
}

bool CStepStack::FindStep(int x, int y)
{
	CStepRecord **pt = &m_stepStack, *tmp;

	if( *pt == 0 )  //??????
	{
		return false;
	}

	tmp = *pt;

	
	do{
		if( tmp->GetX() == x && tmp->GetY() == y )
		{
			return true;		
		}

		tmp = tmp->GetNext();
	}while( tmp != 0 );

	return false;
}

CStepRecord * CStepStack::GetStep( int x, int y )
{
	CStepRecord **pt = &m_stepStack, *tmp;

	if( *pt == 0 )  //??????
	{
		return 0;
	}

	tmp = *pt;

	do{
		if( tmp->GetX() == x && tmp->GetY() == y )
		{
			return tmp;
		}
		
		tmp = tmp->GetNext();

	}while( tmp != 0 );
	
	return 0;
}

void CStepStack::Dump()
{
	int i = 1;
	CStepRecord *red = m_stepStack;

	printf( "== Trace Dump ==================\n" );

	while( red != 0 )
	{
		printf( "%2d'th. pos = ( %2d, %2d )\n", i++, red->GetX(), red->GetY() );

		red = red->GetNext();
	}

	printf( "================================\n\a\a" );
}

void CStepStack::DeleteLink()
{
	CStepRecord *pt = m_stepStack, *tmp, *lastRed;

	while( true )
	{
		tmp = pt;

		while( tmp->GetNext() != 0 )
		{
			lastRed = tmp;
			tmp = tmp->GetNext();		
		}

		if( tmp == pt )
		{
			break;
		}
		else
		{
			lastRed->SetNext( 0 );
			delete tmp;
		}
	}

	delete m_stepStack;
}

void CStepStack::AddToHistory(int x, int y)
{
	if( !FindInHistory( x, y ) )
	{
		m_stepHistory[ m_historyCount ].x = x;
		m_stepHistory[ m_historyCount ].y = y;

		m_historyCount ++;
	}
}

bool CStepStack::FindInHistory(int x, int y)
{
	int i;

	for( i = 0; i < m_historyCount; i ++ )
	{
		if( m_stepHistory[ i ].x == x && m_stepHistory[ i ].y == y)
		{
			return true;
		}	
	}

	return false;
}
