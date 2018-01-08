#include <afxwin.h>
#include "CPuzzle.h"

/****************************************************************/
/*  Course:	CS 215				                                */
/*  Date: FALL 2013				                                */
/*  Project: 3 (Puzzle)				                            */
/*  Author:	Mahesh Gautam				                        */
/*  Description: This is a Visual C++ MFC Puzzle Slider Game    */	                                  
/*                                                              */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This class will hold the information about the puzzle game  */ 
/*  window.		                                                */
/*                                                              */
/****************************************************************/

class CPuzzleWin : public CFrameWnd
{
      public:
            CPuzzleWin ();
            afx_msg void OnPaint ();
			afx_msg void OnKeyDown( UINT nChar, UINT nRepCnt, UINT nFlags );
			afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
			CPoint current;
      private:
		    int CurrentSize;
			bool Ready;
			CPuzzle Puzzle;
			CPuzzle Done;
            DECLARE_MESSAGE_MAP ()
			CPuzzle design;
};

 