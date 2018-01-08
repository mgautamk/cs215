//Author: Mahesh Gautam
//Class: CS215 Fall 2013
//File : L12app.cpp
//Description : The purpose of this file is to input the list from a 
//input file, read it into into different list, and suffle the list 

#include<iostream>
#include<fstream>
#include "card.h"
#include "LList2.hpp"


using namespace std;

int main ()
{

  //Create Linked Lists
  card one; // card variable
  int count = 0; //setting counter to zero
  int i = 0;
  LList2<card> L1;
  LList2<card> L2;
  LList2<card> L3;
  LList2<card> L4;
  ifstream input ("cards.in"); //Input from file

  //while loop to populate lists L1, L2, and L3
  while (input >> one)
    {
      if (i == 0)
	{
	  L1.InsertFirst(one);
	  L2.InsertFirst(one);
	}
      else if (i <= 7)
	{
	L1.InsertLast(one);
	L2.InsertLast(one);
	}
      else if (i == 8)
	{
	  L1.InsertLast(one);
	  L3.InsertFirst(one);
	}
      else 
	{
	  L1.InsertLast(one);
	  L3.InsertLast(one);	  
	}
      i++;
      count++;
    }

  //Define iterators
  LList2<card>::Iterator itr;
  LList2<card>::Iterator itr2;
  

  //for loop to populate List L4 i.e Scrambled list
  for (int j = 0; j < count; j++)
    {
      if (j == 0)
	{
	  itr = L3.begin();
	  L4.InsertFirst(*itr);
	}
      else if (j == 1)
	{
	  itr2 = L2.begin();
	  L4.InsertLast(*itr2);
	}
      else if (j % 2 == 0)
	L4.InsertLast(*++itr);
      else
	L4.InsertLast(*++itr2);
    }
 
  //display the output
  cout <<"The cards:" << '\t' << L1 << endl;
  cout <<"First half:" << '\t'<< L2 << endl;
  cout <<"Second half:" << '\t' << L3 << endl;
  cout <<"Shuffled List:" << '\t' << L4 << endl;
  
	 
  return 0;

}
