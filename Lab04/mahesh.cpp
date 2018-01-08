// Assignment: Lab 04
// File: navasL04.cpp
// Author: Alex Navas
// Date: Sept. 10 2013
// Description: Takes info from an inputed file and prints it neatly in an output file, printing vowels,
// consonants, digits and special chars, and no matter how bit the word is, it keeps it all lined up.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;
struct worddata
{
  worddata ();
  string word;
  int vowels;
  int consonants;
  int digits;
  int specialchars;
};

int ReadFile (ifstream & input, worddata * & Words);  
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);

bool isvowel (char aletter);

int main(int argc, char * argv [])
{
  // Check to see if the user enterd an input file name
  // and an output file name. Exit if no file name
  if (argc < 3)
    {
      cout << "Usage: " << argv[0] << " <input-file> <filename>\n";
      exit(1);
    }

  // Open the input file
  ofstream output (argv[2]);

  // Check to see if the file was successfully opened
  // Exit if the file could not be opened.
  if (output.fail())
    {
      cout << "File: " << argv[2] << " could not be opened\n"; 
      exit (3);
    }



  // Declare an input file and open words.txt.
  ifstream input (argv[1]);
  if (input.fail())
    {
      cout << "File: " << argv[1] << " not found\n";
      exit (2);
    }
  
  // Declare an array of worddata objects to hold the words
  // and their vowel, consonant, digit, and special
  // character counts.
  worddata * WordArray;

  // Call the ReadFile function to read the file, store the
  // words in the array and return the number of words read
  // from the file.
  int count = ReadFile (input, WordArray);

  // Call the WordSort function to sort the words into
  // alphabetical order.
  WordSort (WordArray, count);

  // Call the WriteReport function to write the data
  // stored in the array in a formatted fashion.
  WriteReport (output, WordArray, count);
  
  // Close the output file
  output.close ();

  return 0;

}

worddata::worddata ()

{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

int ReadFile (ifstream & input, worddata * & Words)
{
  int count = 0;
  string oneword;
  // Read and count the words in the file
  while (input >> oneword)
    {
      count++;
    }
  // Allocate space for the number of words counted by the 
  // previous loop
  Words = new worddata [count];
  // Clear the fail flag
  input.clear();
  // Reposition the file pointer to the beginning of the file
  input.seekg (0, ios::beg);
  count = 0;
  while (input >> Words[count].word)
    {
      for (int i = 0; i < Words[count].word.length(); i++)
	{
	  if (isvowel(Words[count].word[i]))
	    Words[count].vowels++;
	  else if (isalpha(Words[count].word[i]))
	    Words[count].consonants++;
	  else if (isdigit(Words[count].word[i]))
	    Words[count].digits++;
	  else
	    Words[count].specialchars++;
	}
    
      count++;
    }
  input.close();
  return count;
}
void WriteReport (ostream & output, worddata Words [], int count)
{
  int totalvowels = 0, totalconsonants = 0;
  int totaldigits = 0, totalspecialchars = 0;
  output << setw (15) << left << "Word";
  output << setw (8) << right << "Vowels";
  output << setw (8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;;
  for (int i = 0; i < count; i++)
    { 
      output << setw (15) << left << Words[i].word;
      output << setw (8) << right << Words[i].vowels;
      output << setw (8) << Words[i].consonants;
      output << setw (8) << Words[i].digits;
      output << setw (8) << Words[i].specialchars << endl;;
      totalvowels = totalvowels + Words[i].vowels;
      totalconsonants = totalconsonants + Words[i].consonants;
      totaldigits = totaldigits + Words[i].digits;
      totalspecialchars = totalspecialchars + Words[i].specialchars;
    }
  output << setw (23) << right << "---"; 
  output << setw (8) << "---"; 
  output << setw (8) << "---";
  output << setw (8) << "---" << endl;;
   
  output << setw (15) << left << "Totals";
  output << setw (8) << right << totalvowels;
  output << setw (8) << totalconsonants;
  output << setw (8) << totaldigits;
  output << setw (8) << totalspecialchars << endl;;

 
}



void Swap (worddata & a, worddata & b)
{

  worddata t = a;
  a = b;
  b = t;

}
void WordSort (worddata W [], int N)
{
  for (int i = 1; i < N; i++)
    {
      for (int j = i; j > 0 && W[j- 1].word> W[j].word; j--)
	{
	  Swap(W[j], W[j - 1]);
	}
    }

}

bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I' || upcase == 'O' || upcase == 'U')
    return true;
  return false;
}
[anavas@cwolf Lab04]$ ^C
[anavas@cwolf Lab04]$ 
