// Title: Driver Program for Lab 7
// File id: Lab07app.cpp
// Author:Mahesh Gautam
// Description: This program will instantiate a vector of Coordinate Points.
// The program will then read points from a file and store them in the
// vector. The program will then print the contents of the vector.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "CoordPt.h"

using namespace std;

void ReadPoints (int argc, char * argv [], vector <CoordinatePoint> & PV);
void WritePoints (ostream & outs, const vector <CoordinatePoint> & PV);

int main (int argc, char * argv [])
{
	vector <CoordinatePoint> points;
	cout << "\nReading points from the file\n";
	ReadPoints (argc, argv, points);
	cout << "\nWriting points to standard output\n";
	WritePoints (cout, points);
	cout << "\nFinding the sum of all of the points in the vector\n";
	CoordinatePoint sum;
	for (int p = 0; p < points.size(); p++)
	  sum = sum + points[p];
	cout << "The sum of the points is " << sum << endl;
	cout << "\nSorting points vector\n";
	sort (points.begin(), points.end());
	cout << "\nWriting sorted points to standard output\n";
	WritePoints (cout, points);
	cout << "\nErasing first point from the vector\n";
	points.erase (points.begin());
	cout << "\nWriting modified points to standard output\n";
	WritePoints (cout, points);
	cout << "\nInserting first point into the vector\n";
	points.insert (points.begin(), CoordinatePoint (6, 5));
	cout << "\nWriting modified points to the standard output\n";
	WritePoints (cout, points);
	cout << "\nPopping last point from the vector\n";
	points.pop_back ();
	cout << "\nWriting modified points to standard output\n";
	WritePoints (cout, points);
	cout << "\nClearing remaining points from the vector\n";
	points.clear ();
	cout << "\nWriting modified points to standard output\n";
	WritePoints (cout, points);
	return 0;
}

void ReadPoints (int argc, char * argv [], vector <CoordinatePoint> & PV)
{
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <filename>\n";
		exit (1);
	}
	ifstream ins (argv[1]);
	if (ins.fail())
	{
		cout << "File " << argv[1] << " not found\n";
		exit (2);
	}
	CoordinatePoint apoint;
	while (ins >> apoint)
	{
	  //	cout << "\nReading and doing a push_back of a single point\n";
		PV.push_back (apoint);
	}
	ins.close ();
}

void WritePoints (ostream & outs, const vector <CoordinatePoint> & PV)
{
	outs << "The points are:";
	for (int p = 0; p < PV.size(); p++)
		outs << ' ' << PV[p];
	outs << endl;
}