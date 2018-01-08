#include <afxwin.h>
#include "CPuzzleWin.h"

/****************************************************************/
/*                                                              */
/*  Course:	CS 215				                                */
/*  Date: FALL 2013	- 12/1/2013			                        */
/*  Project: Project 3 (Puzzle)				                    */
/*  Author:	Mahesh Gautam				                        */
/*  Description:		                                        */
/*                                                              */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This function sets the begening size to 3 * 3, Initializes  */                                       
/*  the Puzzle and calls the Scrable function                   */
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
/*  This function checks to see if the user won the game, it    */
/*  reinitializes and rebuilds the Puzzle upon winning the Game */
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
	if (Puzzle == Done)
	{
		Puzzle.Init (CurrentSize);
		Done.Init (CurrentSize);
	}
}

/****************************************************************/
/*  This function reads the arrow key pressed by user and calls */ 
/*  the move function accordingly.                              */
/****************************************************************/

afx_msg void CPuzzleWin::OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags )
{
	  CRect modified;
	  char a = 'a';
	  char w = 'w';
	  char s = 's';
	  char d = 'd';

      switch (nChar)
      {
      case 37: // Left arrow key
 		       // move tile to left from right of space if possible
		          modified = Puzzle.Move(a);
		          InvalidateRect (modified);
				  break;
      case 38: // Up arrow key
		       // move tile up from below space if possible
		          modified = Puzzle.Move(w);
		          InvalidateRect (modified);
				  break;
      case 39: // Right arrow key
		       // move tile to right from left of space if possible
		          modified = Puzzle.Move(d);
		          InvalidateRect (modified);
		          break;
      case 40: // Down arrow key
		       // move tile down from above space if possible
		          modified = Puzzle.Move(s);
		          InvalidateRect (modified);
 				  break;
      default:
            MessageBox ("Key not recognized");
      }
	 // Invalidate (true);
	  if (Puzzle == Done)
	  {
		    MessageBox("You Win!");
			Puzzle.~CPuzzle();
			CurrentSize++;
			Puzzle.Init (CurrentSize);
			Done.Init (CurrentSize);
			Puzzle.Scramble ();
			Invalidate (true);
	  }   
}

/****************************************************************/
/*  This function calls the Move function sending it exct point */
/* where user clicks when the left Mouse button is clicked      */
/****************************************************************/

afx_msg void CPuzzleWin::OnLButtonDown( UINT nFlags, CPoint point )
{
	CRect selected = Puzzle.Move(CPoint(point));
	current = point;
	InvalidateRect (selected);
	 if (Puzzle == Done)
	  {
		    MessageBox("You Win!");
			Puzzle.~CPuzzle();
			CurrentSize++;
			Puzzle.Init (CurrentSize);
			Done.Init (CurrentSize);
			Puzzle.Scramble ();
			Invalidate (true);
	  }   
}

/****************************************************************/
/*                                                              */
/*  This message map will create a window to display the Message*/
/*                                                              */
/****************************************************************/

BEGIN_MESSAGE_MAP (CPuzzleWin, CFrameWnd)
      ON_WM_PAINT ()
	  ON_WM_KEYDOWN ()
	  ON_WM_LBUTTONDOWN ()
END_MESSAGE_MAP ()