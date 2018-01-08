#include <afxwin.h>
#include "CPuzzleWin.h"

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

CPuzzleWin::CPuzzleWin ()
{
	CurrentSize = 3;
	Puzzle.Init (CurrentSize);
	Done.Init (CurrentSize);
	Puzzle.Scramble ();
	Ready = false;
	Create (NULL, "My Puzzle", WS_OVERLAPPEDWINDOW, CRect(300, 300, 700, 700));
}
 
/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

afx_msg void CPuzzleWin::OnPaint ()
{
	CPaintDC dc (this);
	Puzzle.Display (dc);
	if (!Ready)
	{
		Puzzle.Intro (this);
		Ready = true;
	}
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

afx_msg void CPuzzleWin::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
      switch (nChar)
      {
      case 37: // Left arrow key
 		       // move tile to left from right of space if possible
				  
				  break;
      case 38: // Up arrow key
		       // move tile up from below space if possible
				  break;
      case 39: // Right arrow key
		       // move tile to right from left of space if possible
				  break;
      case 40: // Down arrow key
		       // move tile down from above space if possible
 				  break;
      default:
            MessageBox ("Key not recognized");
      }
	  if (Puzzle == Done)
	  {
			CurrentSize++;
			Puzzle.Init (CurrentSize);
			Done.Init (CurrentSize);
			Puzzle.Scramble ();
	  }
}

/****************************************************************/
/*                                                              */
/*  This function will                                          */
/*                                                              */
/****************************************************************/

afx_msg void CPuzzleWin::OnLButtonDown( UINT nFlags, CPoint point )
{
}

/****************************************************************/
/*                                                              */
/*  This message map will										*/
/*                                                              */
/****************************************************************/

BEGIN_MESSAGE_MAP (CPuzzleWin, CFrameWnd)
      ON_WM_PAINT ()
	  ON_WM_KEYDOWN ()
	  ON_WM_LBUTTONDOWN ()
END_MESSAGE_MAP ()