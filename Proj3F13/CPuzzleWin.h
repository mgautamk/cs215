#include <afxwin.h>
#include "CPuzzle.h"

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

      private:
		    int CurrentSize;
			bool Ready;
			CPuzzle Puzzle;
			CPuzzle Done;
            DECLARE_MESSAGE_MAP ()
};

 