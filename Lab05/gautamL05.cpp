// Title: Lab 5 Driver program
// Author: Dr. Watts
// Modified by: Mahesh Gautam
// Description: This program is designed to test the WordData class.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Lab05.h"

using namespace std;

const int MINWORDS = 20;
const int BLOCKSIZE = 10;

int ReadFile (ifstream & input, WordData * & Words);
void WriteReport (ostream & output, WordData Words [], int count);
void Swap (WordData & a, WordData & b);
void WordSort (WordData W [], int count);

int main (int argc, char * argv [])
{ // This function will open the file when the file name is passed
  // as an argument. It will then call functions to read the file
  // and write a short report about the words read from the file.
	if (argc < 2)
	{
		cout << "Usage: " << argv[0] << " <filename>\n";
		exit (1);
	}
	ifstream fin (argv[1]);
	if (fin.fail())
	{
		cout << "File: " << argv[1] << " not found\n";
		exit (2);
	}
	int count = 0;
	WordData * W = NULL;
	count = ReadFile (fin, W);
	fin.close();
	WordSort(W, count);
	WriteReport (cout, W, count);
	return 0;
}
				
int ReadFile (ifstream & input, WordData * & Words)
{ // This function will read each of thewords from the file
  // passed to it into a temporary string. The string will be
  // stored in the next available space in the array. If more
  // space is needed, this function will resize the storage
  // array. After all of the words have been read and stored,
  // this function will return the count of the number of
  // words read from the file. 
	Words = new WordData [MINWORDS];
	int size = MINWORDS;
	int count = 0;
	string aword;
	while (input >> aword)
	{
		if (count >= size)
		{
			cout << "Expanding array; count = " << count << "\n";
			// Allocate larger array
			WordData * temp = new WordData [size + BLOCKSIZE];
			// Copy data from old array to new array
			for (int i = 0; i < size; i++)
				temp[i] = Words[i];
			// Delete old array
			delete [] Words;
			// Point to new array
			Words = temp;
			size += BLOCKSIZE;
		}
		// Store new word in arry
		Words[count].SetWord (aword);
		// Increment count
		count++;
	}
	return count;
}

void WriteReport (ostream & output, WordData Words [], int count)
{ // This function writes a short report about the words
  // in the array. The report will be written to the 
  // output stream passed to this function.
        // Print report header
  int totalvowels = 0, totalconsonants = 0;
  int totaldigits =0, totalspecialchars =0;
        cout << setw (12) << left << "Word";
        cout << setw (8) << right << "Vowels";
        cout << setw (8) << right << "Const.";
        cout << setw (8) << right << "Digits";
        cout << setw (8) << right << "Special";
        cout << endl;
        // Loop through all words in array
        for (int i = 0; i < count; i++)
        {
        // Print data for word
                Words[i].WriteData(cout);
                cout << endl;
		//count totals of vowels,consonents,digits,and speciachars
		totalvowels = totalvowels + Words[i].GetNumVowels();
		totalconsonants = totalconsonants + Words[i].GetNumConsonants();
		totaldigits = totaldigits + Words[i].GetNumDigits();
		totalspecialchars = totalspecialchars + Words[i].GetNumSpecialChars();
        }
	// Print the report summary -- put line line and totals after this 
	cout << setw(20) << right << "___";
	cout << setw(8) << right << "___";
	cout << setw(8) << right << "___";
	cout << setw(8) << right << "___" << endl;
	cout << setw(12) << left << "Totals";                                                                                                 
	cout << setw(8) << right << totalvowels;
	cout << setw(8) << totalconsonants;
	cout << setw(8) << totaldigits;
	cout << setw(8) << totalspecialchars;
	cout << endl;
}
 
void Swap (WordData & a, WordData & b)
{ // This function will swap the contents of 2 WordData objects
	WordData temp = a;
	a = b;
	b = temp;
}

void WordSort (WordData W [], int count)
{ // This function will sort the objects in the array W into
  // ascending order using the insertion sort.
	for (int i = 1; i < count; i++)
		for (int j = i; j > 0 && W[j] < W[j-1]; j--)
			Swap (W[j], W[j-1]);
 
}

