#include <iostream>
#include <fstream>
#include"LList2.hpp"

using namespace std;

void PrintValue (const int & V);

int main ()
{
  LList2 <int> LT;
  // LList2 <char> LV;
  LT.InsertFirst (5);
  LT.InsertLast (9);
  cout << LT << endl;
  //  LT.DeleteFirst ();
  //  cout << LT << endl;
  // LT.DeleteFirst ();
  // cout << LT << endl;
  // LT.DeleteFirst ();
  //  cout << LT << endl;
  LT.InsertLast (1);
  cout << LT << endl;
  LT.InsertLast (2);
  cout << LT << endl;
  // LT.DeleteLast ();
  // cout << LT << endl;
  // LT.DeleteLast ();
  // cout << LT << endl;
  //  LT.DeleteLast ();
  //  cout << LT << endl;
  cout << "The size is " << LT.Size() << endl;
  LT.DeleteLast ();
  cout << LT << endl;
  cout << "The size is " << LT.Size() << endl;
  LT.DeleteFirst ();
  cout << LT << endl;
  cout << "The size is " << LT.Size() << endl;  

  LT.Forward(PrintValue);
  LT.Backward(PrintValue);

  return 0;
}

void PrintValue (const int & V)
{
  cout << "V is " << V << endl;
}

