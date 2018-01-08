#include <iostream>
#include <string>
#include "LList.hpp"
#include "CoordPt.h"


using namespace std;


int main()
{
  LList <string> L1;
  LList <CoordinatePoint> L2;
  LList <int> L3;
  LList <float> L4;
  LList <char> L5;
  L1.InsertFirst ("Hello");
  L1.InsertLast (" Mahesh");
  cout << L1 << endl;
  L1.DeleteFirst();
  cout << L1 <<endl;
  L2.InsertLast (CoordinatePoint (1,2));
  L2.InsertFirst (CoordinatePoint (3,4));
  cout << L2 << endl;
  LList<string>L9= L1;
  cout << L1.Size() << endl;
  cout << L2.Size() << endl;
  cout << "This is L9 " << L9 << endl;
  cout << "This is the size of L9 " << L9.Size() << endl;
  return 0;

}
