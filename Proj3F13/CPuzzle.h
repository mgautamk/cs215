#include <afxwin.h>

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
			void Display (CPaintDC & dc);
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
		CRect Move (CPoint point);
		CRect Move (char direction);
		bool operator == (const CPuzzle & other) const;
    private:
	    int Size;
        TileInfo ** Grid;
};
