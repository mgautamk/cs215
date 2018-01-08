//Assignment: Project 2 - Puzzle game
//Author: Mahesh Gautam
//Date: Fall 2013
//File : Puzzle.cpp
//Other required files : Proj2.cpp, and Puzzle.h
//Description: This file has the function definition for 
//all the prototypes in this project
#include <iostream>
#include "Puzzle.h"
#include <ctime>
#include <iomanip>
#include <stdlib.h>
#include<sstream>

using namespace std;
//default constructor
Puzzle::Puzzle ()
{
  int num = 1;
  for ( int r = 0; r < 4; r++)
    for (int c = 0; c <4; c++)
      {
	tiles [r][c] = num;
	num = (num +1)%16;
      }

}
//write a function to print out the display
void Puzzle::Display (ostream & outs) const
{
  outs << "+------+------+------+------+" << endl;
  outs << "|      |      |      |      |" << endl;
  outs << "|"<< setw(4) << Gettiles(0,0) << setw(3);
  outs << "|"<< setw(4) << Gettiles(0,1) << setw(3); 
  outs << "|"<< setw(4) << Gettiles(0,2) << setw(3); 
  outs << "|"<< setw(4) << Gettiles(0,3) << setw(3); 
  outs << "|"<< endl;
  outs << "|      |      |      |      |" << endl;
  outs << "+------+------+------+------+" << endl;
  outs << "|      |      |      |      |" << endl;
  outs << "|"<< setw(4) << Gettiles(1,0) << setw(3);
  outs << "|"<< setw(4) << Gettiles(1,1) << setw(3);
  outs << "|"<< setw(4) << Gettiles(1,2) << setw(3);
  outs << "|"<< setw(4) << Gettiles(1,3) << setw(3); 
  outs << "|"<< endl;
  outs << "|      |      |      |      |" << endl;
  outs << "+------+------+------+------+" << endl;
  outs << "|      |      |      |      |" << endl;
  outs << "|"<< setw(4) << Gettiles(2,0) << setw(3);
  outs << "|"<< setw(4) << Gettiles(2,1) << setw(3);
  outs << "|"<< setw(4) << Gettiles(2,2) << setw(3);
  outs << "|"<< setw(4) << Gettiles(2,3) << setw(3);
  outs << "|"<< endl;
  outs << "|      |      |      |      |" << endl;
  outs << "+------+------+------+------+" << endl;
  outs << "|      |      |      |      |" << endl;
  outs << "|"<< setw(4) << Gettiles(3,0) << setw(3);
  outs << "|"<< setw(4) << Gettiles(3,1) << setw(3);
  outs << "|"<< setw(4) << Gettiles(3,2) << setw(3);
  outs << "|"<< setw(4) << Gettiles(3,3) << setw(3);
  outs << "|" << endl;
  outs << "|      |      |      |      |" << endl;
  outs << "+------+------+------+------+" << endl;
}
//using a getline function to return an empty string 
//for zero
string Puzzle:: Gettiles (int r, int c) const
{
  if (tiles[r][c] == 0)
    return "";
  else
    {
      stringstream ss;
      ss << tiles[r][c];
      return ss.str();
    }
}
//write a scramble function to randomize the numbers
void Puzzle::Scramble ()
{
  srand(time(NULL));
  char a = 'a';
  char w = 'w';
  char s = 's';
  char d = 'd';
  for (int t = 0; t < 100; t++)
    {
      int rn = rand()%4;
        if (rn == 0)
	Move(a);
      if (rn == 1)
	Move(s);
      if (rn ==2)
	Move(w);
      if (rn == 3)
	Move(d);
    }
} 
//Equality operator- returns true if user assembled every
//number - else returns false
bool Puzzle::operator == (const Puzzle & P) const
{
  int game;
  for (int x = 0; x < 4; x++)
    for (int y = 0; y < 4; y++)
      {
	if (tiles[x][y] == P.tiles[x][y])
	  game += 1;
	if (game ==16)
	  return true;
      }
  return false;
}

//Move function moves the tiles to the empty space
//checks to see corners and end spaces for Invalid moves
bool Puzzle::Move (char direction)
{
  for (int startx = 0; startx < 4; startx++)
    for (int starty = 0; starty < 4; starty++)
      if (tiles[startx][starty] == 0)
	{
	  pointx = startx;
	  pointy = starty;
	}

  char directionlow = tolower(direction); //convert everthing to lower case
  switch(directionlow)
    {
    case 'w':
      if (tiles[pointx-1][pointy] != tiles[-1][pointy])
	{
	  swap(tiles[pointx][pointy], tiles[pointx-1][pointy]);
	  pointy -= 1; //move y as x moves so pointer is accurate
	  return true;
	}
      else
	return false;
      break;
      
    case 's':
      if (tiles[pointx+1][pointy] != tiles[4][pointy])
	{
	  swap(tiles[pointx][pointy], tiles[pointx+1][pointy]);
	  pointy += 1; //move y as x moves
	  return true;
	}
      else
	return false;
      break;

    case 'a':
      if (tiles[pointx][pointy-1] != tiles[pointx][-1])
	{
      swap(tiles[pointx][pointy], tiles[pointx][pointy-1]);
      pointx -= 1; //move x as y moves
      return true;
	}
      else
	return false;
      break;

    case 'd':
      if (tiles [pointx][pointy+1] != tiles[pointx][4])
	{
      swap(tiles[pointx][pointy], tiles[pointx][pointy+1]);
      pointx += 1; //move x as y moves
      return true;
	}
      else
	return false;
      break;
    case 'q': //quit program if Q or q
      exit(1);
    }
}
//print out Instruction to move the tiles around
void Puzzle:: Instructions()
{
  cout <<" choose a direction to swap the empty space." << endl;
  cout <<"          w: up" << endl;
  cout <<" a: left, s: down, d: right" << endl;
  cout <<"          q: quit" << endl;
  cout << endl;
}

