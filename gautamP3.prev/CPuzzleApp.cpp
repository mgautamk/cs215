#include <afxwin.h>
#include "CPuzzleApp.h"
 
/****************************************************************/
/*  Course:	CS 215				                                */
/*  Date: FALL 2013				                                */
/*  Project: 3 (Puzzle)				                            */
/*  Author:	Mahesh Gautam				                        */
/*  Description:This is a Visual C++ MFC Puzzle Slider Game		*/
/*                                                              */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This function will refresh/update the window                */
/*                                                              */
/****************************************************************/

BOOL CPuzzleApp::InitInstance ()
{
      m_pMainWnd = new CPuzzleWin();
      m_pMainWnd->ShowWindow (m_nCmdShow);
      m_pMainWnd->UpdateWindow ();

      return TRUE;
}
 
CPuzzleApp PuzzleApp;