#include <afxwin.h>

/****************************************************************/
/*                                                              */
/*  Course:	CS 215				                                */
/*  Date: FALL 2013				                                */
/*  Project: 3 (Puzzle)				                            */
/*  Author:	Mahesh Gautam				                        */
/*  Description:This is a Visual C++ MFC Puzzle Slider Game		*/
/*                                                              */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This class will hold the information about the puzzle game. */ 
/*  The inner struct will hold the information about an         */
/*  individual puzzle tile.                                     */
/*                                                              */
/****************************************************************/

class CPuzzle
{
	private:
		struct TileInfo
		{
			TileInfo ();
			void Display (CPaintDC & dc, int Size);
			int Number;
			CRect TileRect;
		};
	public:
		CPuzzle ();
		CPuzzle (const CPuzzle & other);
		~CPuzzle ();
		CPuzzle & operator = (const CPuzzle & other);
		void Intro (CFrameWnd * window);
		void Display (CPaintDC & dc);
		void Init (int size);
		void Scramble ();
		int CurrentSize () const;
		CRect Move (CPoint point);
		CRect Move (char direction);
		bool operator == (const CPuzzle & other) const;
    private:
	    int Size;
        TileInfo ** Grid;
};
