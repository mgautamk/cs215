#include <afxwin.h>
#include "CPuzzle.h"
#include <string>
using namespace std;
/****************************************************************/
/*                                                              */
/*  Course:					                                    */
/*  Date:					                                    */
/*  Project:				                                    */
/*  Author:					                                    */
/*  Description:		                                        */
/*                                                              */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CPuzzle::TileInfo::TileInfo ()
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

void CPuzzle::TileInfo::Display (CPaintDC & dc)
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CPuzzle::CPuzzle ()
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CPuzzle::CPuzzle (const CPuzzle & other)
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CPuzzle::~CPuzzle ()
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CPuzzle & CPuzzle::operator = (const CPuzzle & other)
{
	return * this;
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

void CPuzzle::Intro (CFrameWnd * window)
{
	string intro = "Intro";
	window->MessageBox (intro.c_str());
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

void CPuzzle::Display (CPaintDC & dc)
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

void CPuzzle::Init (int size)
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

void CPuzzle::Scramble ()
{
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CRect CPuzzle::Move (CPoint point)
{
	CRect from, to;
	return from | to;
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

CRect CPuzzle::Move (char direction)
{
	CRect from, to;
	return from | to;
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

bool CPuzzle::operator == (const CPuzzle & other) const
{
	return false;
}