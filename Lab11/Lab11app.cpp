//Author: Mahesh Gautam
//Assignment: Lab11
//File: Lab11app.cpp
//Other Files required: LList2.hpp
//Description : This is a application file for the fraction program. 
//It takes fractions from a list, adds it up, and displays the total.

#include <iostream>
#include <fstream>
#include "LList2.hpp"
#include "Fraction.h"

using namespace std;


fraction sumall;
 
//function prototype for sum function
void sum(const fraction & addit);


int main ()
{
        ifstream input ("Lab11.in");
        fraction one;
        LList2 <fraction> FL;

        while (input >> one)
	  FL.InsertLast (one);
	cout << "The fractions are: ";
	cout << FL << endl; //Display the fraction
	FL.Forward(sum);
	cout << sumall << endl; //Display the sum
        return 0;
}

// function implementation for sum function
void sum(const fraction & addit)
{
  sumall = sumall + addit;
}

