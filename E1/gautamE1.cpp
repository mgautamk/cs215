//Author: Mahesh Gautam
//Assignment: Exam 1 Score replacement Exerise
//File: gautamE1.cpp
//Date: Fall 2013
//Description: This program takes a number from user, adds 3 to the 
//previous number and stops when it reaches the user inputed number
//and displays the output in forward and reversed order. 
#include <iostream>
#include <vector>
using namespace std;

void Writeout (vector<int> NDV, const int N, ostream & output);
void Reverse (vector<int> & NDV, const int N);

int main ()
{
  vector<int> NDV; //Declare a vector
  int number;
  cout << "Enter the number of the value to be calculated: ";
  cin >> number;
  
  for (int i = 0; i < number; i++)
    {
      int result = 1 + 3 * i;
      //      cout << result << " added to values\n";
      NDV.push_back(result); //Push back to the Vector

    }
  //Call the functions
  Writeout (NDV, number, cout);
  Reverse (NDV, number);
  Writeout (NDV, number, cout);
  return 0;
}
//Function Implementaion for Writeout 
void Writeout (vector<int> NDV, const int N, ostream & output)
{
  for (int i = 0; i < N; i++)
    {
      cout << NDV[i] << "\t";
    }
  cout << endl;
}

//Function Implementation for Reverse 
void Reverse (vector<int> & NDV, const int N)
{
  int j;
  for (int i = 0, j = N-1; i < j; i++, j--)
    {
      int copy = NDV[i];
      NDV[i] = NDV[j];
      NDV[j] = copy;
    }
}

