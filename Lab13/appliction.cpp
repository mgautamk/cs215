#include<iostream>
#include "LList2.hpp"

using namespace std;

#define MAX 10

int main ()
{

  LList2 <int> L1;
  LList2 <int> L2;

  //  LList2 <int> L3;
  for (int i = 0; i < MAX; i++)
  if (i % 2)
    L1.InsertFirst(i);
  else
    L1.InsertLast(i);
  cout << "L1 in order:";
  cout << L1 << endl;
 
  cout << "L2 is " <<  L2 << endl;
  cout << "Testing the [] operatr\n";
  cout << "First to last: \n";
  for (int i = 0; i <= L2.Size(); i++)
    cout << "L2[] is " << L2[i] << endl;

  L1[3] = 7;
  cout << "Last to first:\n";
  for (int i = L1.Size()-1; i >= 0; i--)
    //  cout << "L1[" << i << "] is " << L1[i] << endl;
  
  //Testing the lhs and rhs 
    // cout << "Testing the * operator\n";

  LList2<int>::Iterator itr = L1.begin();
  /* cout << *itr << endl;
  * itr = 7;
  cout << *itr << endl;*/
  return 0;
}
