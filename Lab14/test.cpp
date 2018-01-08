#include <iostream>
#include <cstdlib>
#include "OrderedSet.hpp"

using namespace std;

void Insert (OrderedSet <int> & S);
void TestDereference (OrderedSet <int>::Iterator itr);
void TestSubscript (OrderedSet <int> & S, int sub);
int main()
{
  // srand (0);
  int value;
  OrderedSet<int> S1, S2, S3, S4;
  for (int i = 0; i < 20; i++)
    {
      int rn = random()%100;
      if (i%3)
	S1.Insert(rn);
      if((i%3 == 0) || (i%3 ==1))
	S2.Insert(rn);
    }
  S1.Insert(26);
  cout << "S1 is: " << S1 << endl;
  cout << "S2 is: " << S2 << endl;
  S3 = S1 + S2;
  cout << "S3 is: " << S3 << endl;
  S4 = S1 * S2;
  cout << "S4 is: " << S4 << endl;
  TestDereference (S1.begin());
  TestDereference (S1.end());

  TestSubscript (S1, 1);
  TestSubscript(S1, -1);
  TestSubscript (S1, 1+S1.Size());
  //OrderedSet.Delete(int));
  cout << "S1 now is: " << S1 << endl;
  return 0;
}

void TestDereference (OrderedSet <int>::Iterator itr)
{
  try
    {
      cout << "Testing * operator:\n";
      int value = *itr;
      cout << "The value at the iterator is: ";
      cout << value << endl;
    }
  catch (OrderedSet<int>::Exception E)
    {
      cerr << "Exception: " << E.Message() << endl;
      return;
    }
}

void TestSubscript(OrderedSet <int> & S, int sub)
{
  try
    {
      cout << "Testing [] operator:\n";
      int value = S[sub];
      cout << "The value at S[" << sub << "] is: ";
      cout << value << endl;
    }
  catch (OrderedSet<int>::Exception E)
    {
      cerr << "EXxception: " << E.Message() << endl;
      return;
    }


}
