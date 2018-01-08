#include <iostream>
#include "LList.hpp"

using namespace std;


int main()
{
  LList <int> L1;
  LList <char> L2;
  L1.InsertFirst (10);
  L2.InsertLast ('c');
  cout << L1 <<' ' <<  L2 << endl;
  cout << L1.Size() <<' ' << L2.Size() << endl;


  return 0;

}
