#include <afxwin.h>
#include "CPuzzle.h"
#include <string>
#include <sstream>
using namespace std;
/****************************************************************/
/*                                                              */
/*  Course:	CS 215				                                */
/*  Date: FALL 2013				                                */
/*  Project: 3 (Puzzle)				                            */
/*  Author:	Mahesh Gautam				                        */
/*  Description: This is a Visual C++ MFC Puzzle Slider Game.   */	 
/*  The level of difficulty increases each time user solves the */
/*  Puzzle.                                                     */
/****************************************************************/

/****************************************************************/
/*                                                              */
/*  This function is the default constructor for TileInfo       */
/*                                                              */
/****************************************************************/

CPuzzle::TileInfo::TileInfo ()
{

Number = 0;	

}

/****************************************************************/
/*                                                              */
/*  This function will put a picture to the Tiles in the rectangle  */
/*  and draw the Text(number) in the middle of the Tile         */
/****************************************************************/

void CPuzzle::TileInfo::Display (CPaintDC & dc, int Size)
{
	string ImageName;
	
	CBitmap Image;
	BITMAP btmp;
	int res = Image.LoadBitmapA("GRN_BMP");
	Image.GetObject(sizeof(BITMAP), &btmp);
	CDC memDC;
	memDC.CreateCompatibleDC(&dc);
	memDC.SelectObject(&Image);

	int width = btmp.bmWidth/Size;
	int height = btmp.bmHeight/Size;
	int outs = width * ((Number -1) % Size);
	int upper = height * ((Number -1)/Size);
	dc.TransparentBlt(TileRect.left, TileRect.top, TileRect.Width(), TileRect.Height(), &memDC, outs, upper, width, height, SRCCOPY);
	stringstream ss;
	ss << Number;
	SetBkMode (dc, TRANSPARENT);
	COLORREF TextColor = RGB(100,100,100);
	SetTextColor (dc, TextColor);
	dc.DrawText((LPCTSTR)ss.str().c_str(), -1, TileRect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}

/****************************************************************/
/*  Default Construcor                                           */
/*  This function will polulate the Grid with numerical values.  */
/*                                                              */
/****************************************************************/

CPuzzle::CPuzzle ()
{
	int num = 1;
    for ( int r = 0; r < Size; r++)
		for (int c = 0; c < Size; c++)
			{
				Grid [r][c].Number = num;
				num = (num +1)%(Size * Size);
			}	
}

/****************************************************************/
/*                                                              */
/*  This function is a copy constructor, It creates an Identical*/
/*  copy of the Puzzle                                          */
/****************************************************************/

CPuzzle::CPuzzle (const CPuzzle & other)
{

}

/****************************************************************/
/*                                                              */
/*  This is the De-constructor function                            */
/*                                                              */
/****************************************************************/

CPuzzle::~CPuzzle ()
{
	for (int r = 0; r < Size; r++)
		delete[] Grid[r];
	delete[]Grid;
}

/****************************************************************/
/*  Equal operator                                               */
/*  This function returns the point referenced by "this"        */
/*                                                              */
/****************************************************************/

CPuzzle & CPuzzle::operator = (const CPuzzle & other)
{
	return * this;
}

/****************************************************************/
/*                                                              */
/*  This function contains the Intro Message in the MessageBox   */
/*                                                              */
/****************************************************************/

void CPuzzle::Intro (CFrameWnd * window)
{
	string intro = "Use Arrow Keys or Left Mouse Click to Organize the Puzzle\n"
	                "in a numerical order; the Puzzile resolution will increase\n"
	                 "every time you win. Simply close the window to exit when done";
	window->MessageBox (intro.c_str());
}

/****************************************************************/
/*This function creates and populates the Grid of the rectangele */
/*and displays an empty tile for the one containing zero.        */
/****************************************************************/

void CPuzzle::Display (CPaintDC & dc)
{
	CRect rect;
	dc.GetWindow() -> GetClientRect(rect); 
	int TotalHeight = rect.Height();
	int TotalWidth = rect.Width();
	int height = TotalHeight/Size;
	int width = TotalWidth/Size;
	for	( int r = 0; r < Size; r++)
		for (int c = 0; c < Size; c++)
		{
			Grid[r][c].TileRect = CRect(width * c,height * r, width * (c+1), height * (r+1));
		}
	for (int r = 0; r < Size; r++)
		for (int c = 0; c < Size; c++)
		{
			if (Grid[r][c].Number != 0)
				Grid[r][c].Display(dc, Size);
	
		}
}

/****************************************************************/
/* This function will initialize the Puzzle initially with      */
/* numbrical values                                             */
/****************************************************************/

void CPuzzle::Init (int size)
{
	int num = 1;
	Size = size;
	Grid = new TileInfo * [Size];
	for (int r = 0; r < Size; r++)
	{
		Grid[r] = new TileInfo[Size];
		for (int c = 0; c < Size; c++)
			Grid[r][c].Number = num++;
	}
	Grid[Size-1][Size-1].Number = 0;
}

/****************************************************************/
/* This function randomizes the tiles in the Puzzle             */
/****************************************************************/

void CPuzzle::Scramble ()
{
	srand(time(NULL));
	char a = 'a';
	char w = 'w';
	char s = 's';
	char d = 'd';
	for(int t = 0; t < 255; t++)
	{
		int rn = rand()%4;
		if (rn ==0)
			Move(a);
		if (rn ==1)
			Move(s);
		if (rn ==2)
			Move(w);
		if (rn ==3)
			Move(d);
	}
}

/****************************************************************/
/*                                                              */
/*  This function moves the tiles when a user clicks around     */
/*  the empty tile                                              */
/****************************************************************/

CRect CPuzzle::Move (CPoint point)
{

	CRect from, to;
	for (int r = 0; r < Size; r++)
	{
		for (int c = 0; c < Size; c++)
		{
			if (Grid[r][c].TileRect.PtInRect(point))
			{
				if (r -1 >= 0 && Grid[r-1][c].Number == 0) // w
				{
					 from = Grid[r][c].TileRect;
					 swap(Grid[r][c].Number, Grid[r-1][c].Number);
					 r--;
					 to = Grid[r][c].TileRect;
				}
				else if (c-1 >= 0 && Grid[r][c-1].Number == 0) //s
				{
					from = Grid[r][c].TileRect;
					swap(Grid[r][c].Number, Grid[r][c-1].Number);
					c--;
					to = Grid[r][c].TileRect;
				}
				else if (r + 1 < Size && Grid[r+1][c].Number == 0) // a
				{
					 from = Grid[r][c].TileRect;
					 swap(Grid[r][c].Number, Grid[r+1][c].Number);
					 r++;
					 to = Grid[r][c].TileRect;
				}
				else if (c+1 < Size && Grid[r][c+1].Number == 0) //d
				{
					from = Grid[r][c].TileRect;
					swap(Grid[r][c].Number, Grid[r][c+1].Number);
					c++;
					to = Grid[r][c].TileRect;
				}
			}
		}
	}


	return from | to;

	

}

/****************************************************************/
/*                                                              */
/*  This function will moves the tiles when user pushes arrow keys */
/*                                                              */
/****************************************************************/

CRect CPuzzle::Move (char direction)
{
	CRect from, to;
		
int pointx;
int pointy;
	for (int startx = 0; startx < Size; startx++)
		for (int starty = 0; starty < Size; starty++)
			if (Grid[startx][starty].Number == 0)
				{
					pointx = startx;
					pointy = starty;
				}

  from = Grid[pointx][pointy].TileRect;
			char directionlow = tolower(direction); //convert everthing to lower case
  switch(directionlow)
    {
    case 's': //Move down
      if (pointx != 0)
        {
          swap(Grid[pointx][pointy].Number, Grid[pointx-1][pointy].Number);
          pointx--; //move y as x moves so pointer is accurate
        }
      break;

    case 'w': //Move up
      if (pointx!= Size-1)
        {
          swap(Grid[pointx][pointy].Number, Grid[pointx+1][pointy].Number);
          pointx++; //move y as x moves
       //   return true;	  
        }
      break;

	 case 'd': //Move right
      if (pointy != 0)
        {
      swap(Grid[pointx][pointy].Number, Grid[pointx][pointy-1].Number);
      pointy--; 
        }
      break;

    case 'a'://Move left
      if (pointy != Size-1)
        {
      swap(Grid[pointx][pointy].Number, Grid[pointx][pointy+1].Number);
      pointy++; 
        }
      break;
    case 'q': //quit program if Q or q
      exit(1);
    }
  to = Grid[pointx][pointy].TileRect;
  return from | to;

}

/****************************************************************/
/*  Equality Operator                                           */
/*  This function wiill check if the Puzzle looks like the one  */
/*  at the begening to determine if user won                    */
/****************************************************************/

bool CPuzzle::operator == (const CPuzzle & other) const
{
	 int win = 0;
	 for (int x = 0; x < Size; x++)
		for (int y = 0; y < Size; y++)
		 {
			if (Grid[x][y].Number == other.Grid[x][y].Number)
				win += 1;
			if (win == Size * Size)
				return true;
		 }
	return false;
}

