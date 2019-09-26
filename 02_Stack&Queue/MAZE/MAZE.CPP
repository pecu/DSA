#include <stdio.h>

//#include "..\MyProj~1\Maze\MapView.h"
//#include "..\MyProj~1\Maze\Mouse.h"
#include "MapView.h"
#include "Mouse.h"

void main()
{
    CMapView m_mapView;
	CMouse   m_mouse;

	m_mapView.Create();

	m_mouse.SetMap( &m_mapView );
	m_mouse.SetStartPos( 1, 1 );
	m_mouse.SetGoalPos( m_mapView.GetMapWidth(), m_mapView.GetMapHeight() );

	m_mouse.Go();
}