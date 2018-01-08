#include <afxwin.h>
#include "CPuzzleApp.h"
 
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

BOOL CPuzzleApp::InitInstance ()
{
      m_pMainWnd = new CPuzzleWin();
      m_pMainWnd->ShowWindow (m_nCmdShow);
      m_pMainWnd->UpdateWindow ();

      return TRUE;
}
 
CPuzzleApp PuzzleApp;