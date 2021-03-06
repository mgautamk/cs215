#include <iostream>
#include <cstdlib>
#include "OrderedSet.hpp"
using namespace std;

void Insert (OrderedSet <int> & S);
void TestDereference (OrderedSet <int>::Iterator itr);
void TestSubscript(OrderedSet <int> & S, int sub);
void TestIteratorOperators(OrderedSet <int> & S, char a);
void TestIsIn(OrderedSet <int> & S, int value);
void TestIsEmpty(OrderedSet <int> & S);
void TestDelete(OrderedSet <int> & S, int value);


int main ()
{
  srand (0);
  OrderedSet <int> S1;
  OrderedSet <int> S2;
  //Insert (S1);
  //Insert (S2);

  // temp asignments
  S1.Insert (-10);
  S1.Insert (-7);
  S1.Insert (-4);
  S1.Insert (3);
  S1.Insert (4);
  S1.Insert (2);
  S1.Insert (7);
  S1.Insert (5);

  S2.Insert (-6);
  S2.Insert (-4);
  S2.Insert (-2);
  S2.Insert (1);
  S2.Insert (-9);
  S2.Insert (-1);
  S2.Insert (5);
  S2.Insert (7);
  S2.Insert (9);

  cout << "Elements in S: " << S1 << endl;
  cout << "Elements in S: " << S2 << endl;

  cout << endl;
  TestDereference (S1.begin());
  TestDereference (S1.end());

  cout << endl;
  TestIteratorOperators(S1, 'p');
  cout << endl;
  TestIteratorOperators(S1, 'm');

  cout << endl;
  TestSubscript (S1, 1);
  TestSubscript (S1, -1);
  TestSubscript (S1, 1+S1.Size());

  cout << "Testing OrderedSet union (+) operator:" << endl;
  OrderedSet <int> S3 = S1 + S2;
  cout << "The union of " << S1 << " and " << S2 << "is" << S3 << endl;
  cout << "Testing OrderedSet intersection (*) operator:" << endl;
  OrderedSet <int> S4 = S1 * S2;
  cout << "The intersection of " << S1 << " and " << S2 << " is " << S4 << endl;

  cout << endl;
  cout << "Testing IsIn using set " << S1 << endl;
  TestIsIn (S1, -2);
  TestIsIn (S1, -1);
  TestIsIn (S1, 0);
  TestIsIn (S1, 1);
  TestIsIn (S1, 2);
  cout << "Testing IsEmpty using set " << S1 << ":" << endl;
  TestIsEmpty (S1);
  cout << "Testing Clear using set " << S1 << ":" << endl;
  S1.Clear();
  cout << "Testing IsEmpty using set " << S1 << ":" << endl;
  TestIsEmpty (S1);

  cout << endl;
  cout << "Delete values from set " << S2 << ":" << endl;
  S2.Delete(-1);
  S2.Delete(-9);
  S2.Delete(-6);
  S2.Delete(9);
  S2.Delete(7);
  cout << "After deleting -1, -9, -6, 9, and 7, the set is: " << S2 << endl;

  return 0;
}

void Insert (OrderedSet <int> & S)
{
  cout << "Insert values in set:\n";
  for (int i = 0; i < 10; i++)
    S.Insert (-10 + rand() % 21);
  cout << "Elements in S: " << S << endl;
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
	    cout << "Testing OrderedSet indexing ([]) operator:\n";
	    int value = S[sub];
	    cout << "The value at S[" << sub << "] is: ";
	    cout << value << endl;
	  }
        catch (OrderedSet<int>::Exception E)
	  {
	    cerr << "Exception: " << E.Message() << endl;
	    return;
	  }
}

void TestIteratorOperators(OrderedSet <int> & S, char a)
{
        try
	  {
	    if (a == 'p')
	      {
		cout << "Testing ++ Iterator operator:\n";
		for (OrderedSet<int>::Iterator itr = S.begin(); itr != S.end(); itr++)
		  {
		    cout << "Number " << *itr << endl;
		  }
	      }
	    if (a == 'm')
	      {
		cout << "Testing -- Iterator operator:\n";
		for (OrderedSet<int>::Iterator itr = S.rbegin(); itr != S.rend(); itr--)
		  {
		    cout << "Number " << *itr << endl;
		  }
	      }
	  }
        catch (OrderedSet<int>::Exception E)
	  {
	    cerr << "Exception: " << E.Message() << endl;
	    return;
	  }
}

void TestIsIn(OrderedSet <int> & S, int value)
{
  if (S.IsIn(value))
    cout << value << " is not in the set" << endl;
  else
    cout << value << " is in the set" << endl;
}

void TestIsEmpty(OrderedSet <int> & S)
{
  if (S.IsEmpty())
    cout << "The set " << S << " is empty" << endl;
  else
    cout << "The set " << S << " is not empty" << endl;
}
