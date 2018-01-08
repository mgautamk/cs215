//Assignment/Project - Project 2
//Name of files - Proj2.cpp,Puzzle.h, and puzzle.cpp
//Author: Mahesh Gautam
//Date: Fall 2013(cs 215)
//Description: This files needs two other files(mentioned above) to compile
//when complied - this displays a puzzle game with ramdom numbers everytime.
//Number zero is returned by a empty space - I have focused on the empty space for
//movements in the game-
//example - 'a'/'A' will move the empty space to the left swaping the value present
//in the left.

#include <iostream>
#include "Puzzle.h"
#include <stdlib.h>

using namespace std;

//main function that calls Puzzle scramble, display, and move functions.
int main ()
{
  char direction;
  Puzzle Play, Done;
  Play.Scramble ();
  system("clear");//clear the screen
  cout << "Welcome to the sliding puzzle game " << endl;
  cout << "Follow Instructions below to move tiles " << endl;
  Play.Display (cout); // Display the puzzle
  while (!(Play == Done)) //keep playing until not done
    {
      Play.Instructions(); // Display the instructions
      cout << "Enter a letter to move the empty space" << endl;
      cin >> direction;
      system("clear");  // clear the screen 
      if (!Play.Move(direction))
	cout << "Invalid Move " << endl;
      Play.Display(cout);
    }
  cout << "You win\n";
  return 0;
}
