#ifndef _CMOUSE_H_
#define _CMOUSE_H_


//#include "..\MyProj~1\Maze\MAPVIEW.H"
#include "StepStack.h"	// Added by ClassView
#include "MAPVIEW.H"
class CMouse
{
public:
	void Go();
	void SetGoalPos( int x, int y );
	void InitAllVariable();
	void SetStartPos( int x, int y );
	void SetMap( CMapView *map );
	CMouse();
	virtual ~CMouse();

private:
	void CheckAround( CStepRecord *red );
	bool OnGoal();
	CStepStack m_stack;
	int m_yPos;
	int m_xPos;
	int m_goalYPos;
	int m_goalXPos;
	CMapView *m_map;
};

#endif 
