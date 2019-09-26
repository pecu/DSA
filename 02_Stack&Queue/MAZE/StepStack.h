// StepStack.h: interface for the CStepStack class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEPSTACK_H__0EF6A444_8E41_444F_AA7C_55A4B2D1F28D__INCLUDED_)
#define AFX_STEPSTACK_H__0EF6A444_8E41_444F_AA7C_55A4B2D1F28D__INCLUDED_

#include "StepRecord.h"	// Added by ClassView
#include "valdef.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CStepStack  
{
public:
	bool FindInHistory( int x, int y );
	void AddToHistory( int x, int y );
	void Dump();
	CStepRecord * GetStep( int x, int y );
	bool FindStep( int x, int y );
	void Pop( CStepRecord *red );
	void Push( CStepRecord red );
	CStepStack();
	virtual ~CStepStack();

private:
	void DeleteLink();
	int m_stepCount;
	void InitAllVariable();
	STEPPOS m_stepHistory[ 300 ];
	int m_historyCount;
	CStepRecord *m_stepStack;
};

#endif // !defined(AFX_STEPSTACK_H__0EF6A444_8E41_444F_AA7C_55A4B2D1F28D__INCLUDED_)
