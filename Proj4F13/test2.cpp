#include <iostream>
#include <cstdlib>
#include "OrderedSet.hpp"
#include "WordData.h"

using namespace std;



int main()
{
  // srand (0);
  int value;
  OrderedSet<WordData> S1, S2, S3, S4;
  for (int i = 0; i < 20; i++)
    {
      int rn = random()%100;
      if (i%3)
	S1.Insert(rn);
      if((i%3 == 0) || (i%3 ==1))
	S2.Insert(rn);
	

  return 0;
}

