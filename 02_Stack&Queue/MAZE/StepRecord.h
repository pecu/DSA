// StepRecord.h: interface for the CStepRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STEPRECORD_H__EA556FB4_5977_4D4F_9551_205A446744E5__INCLUDED_)
#define AFX_STEPRECORD_H__EA556FB4_5977_4D4F_9551_205A446744E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/*enum bool
{
	FALSE = 0,
	TRUE = 1	
} boolean;*/

class CStepRecord  
{
public:
	void SetBranch();
	int GetDirection();
	int GetInvDirectio();
	void SetRedPos( int x, int y );
	int GetY();
	int GetX();
	void Reset();
	void CoverDirToXYOffset( int dir, int *x, int *y );
	void SetDirection( int dir );
	int FindDirection();
	void SetMoveFlag( int pos );
	bool IsBranch();
	void SetNext( CStepRecord *pt );
	CStepRecord * GetNext();
	CStepRecord();
	virtual ~CStepRecord();

private:
	int m_direction;
	CStepRecord *m_next;
	int m_stepIndex;
	bool m_isBranch;
	bool m_moveFlag[ 3 ][ 3 ];
	int m_redPosY;
	int m_redPosX;
	void InitAllVariable();
};

#endif // !defined(AFX_STEPRECORD_H__EA556FB4_5977_4D4F_9551_205A446744E5__INCLUDED_)
