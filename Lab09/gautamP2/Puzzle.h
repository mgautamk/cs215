#include <iostream>
//Author: Mahesh Gautam
//Dexcription: Header file for project2 - Puzzle game
//This is a header file containing the class Puzzle
//that has all the dunctions  


using namespace std;

class Puzzle
{
	public:
		Puzzle ();
		void Display (ostream & outs) const;
		void Scramble ();
		string Gettiles (int r, int c) const;
		bool operator == (const Puzzle & P) const;
		bool Move (char direction);
                void Instructions ();
	private:
		int tiles [4][4];
		int pointx;
		int pointy;
};
