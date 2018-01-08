//Assignment : Lab04
//file: gautamL04.cpp
//Author : Mahesh Gautam
//Date : Fall 2013 (Sept 10, 2013)
//Description :This program reads strings from a file, counts them seperately as vowels, consonants
//digits, and special characters, sorts and swapss them, and outputs  the sorted version with number
//of each word, vowels, digits, consonants, special characters and their totals to an external file
//using dynamic array. It aligns the words with its corresponding numbers/totals no matter how big
// the word is! 


//Use include statements to use liabraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;


struct worddata
{
  worddata();
  string word;
  int vowels;
  int consonants;
  int digits;
  int specialchars;
};

//Declare functions
int ReadFile (ifstream & input, worddata * & Words);
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);
bool isvowel (char aletter);

int main (int argc, char * argv [])
{
  //check to see if the user entered an input file name
  //and an output file name. Exit if no file name
  if (argc < 3)
    {
      cout << "Usage: " << argv[0] << " <filename>\n";
      exit (1);
    }

  //open the input file
  ifstream input (argv[1]);
  //check to see if the file was successfully opened
  //Exit if no file was found
  if (input.fail())
    {
      cout << "File: " << argv[1] << " not found\n";
      exit (2);
    }

  //open the output file
  ofstream output (argv[2]);

  //check to see if the output file was successfully opened 
  //Exit if the file could not be opened
  if (output.fail())
    {
      cout << "File: " << argv[2] << " could not be opened\n";
      exit(3);
    }

  //Declare a pointer to an array of worddata objects to
  //hold the words and their vowel, consonant, digit, and
  //special character counts.
  worddata * WordArray;

  //call the readfile function to read the file, store the
  //words in the array and return the number of words read
  //from the file
  int count = ReadFile (input, WordArray);

  //call the WordSort function to sort the words into 
  //alphabeical order.
  WordSort (WordArray, count);

  //Call the WriteReport function to write the data
  //stored in the array in a formatted fashion.
  WriteReport (output, WordArray, count);

  //close the input file
  input.close();

  //close the outputfile
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
  //Read and count the words in the file
  while (input >> oneword)
    {
      count++;
    }
  //Allocate space for the number of words counted by the
  //previous loop
  Words = new worddata[count];
  //Clear the fail flag
  input.clear();
  //Reposition the file pointer to the begening of the file 
  input.seekg (0, ios::beg);
  count = 0;
  //Read the words from the file into the array
  while (input >> Words[count].word)
    {
      //count the number of vowels, consonants, digits
      //and special characters in the word and store them
      //in the object Words[count]
      for (int i = 0; i < Words[count].word[i]; i++)
	{
	  if (isalpha(Words[count].word[i]))
	    {
	      if (isvowel(Words[count].word[i]))
		{
		Words[count].vowels++;
		}
	      else
		{
		 Words[count]. consonants++;
		}
	    }
	  else
	    {
	      if(isdigit(Words[count].word[i]))
		{
		 Words[count].digits++;
		}
	      else
		{
		  Words[count].specialchars++;
		}
	    }
	}


      count++;
    }
  input.close();
  return count;

}

void WriteReport (ostream & output, worddata Words [], int count)
{
  //initialize totals for each variable and print the structure
  int totalvowels =0, totalconsonants =0;
  int totaldigits =0, totalspecialchars =0;
  output << setw (15) << left << "Word";
  output << setw (8) << right << "Vowels";
  output << setw (8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;;

  //print the words, vowels, consonants, digits, and special chars
  for (int i=0; i < count; i++)
    {
      output << setw (15) << left << Words[i].word;
      output << setw (8) << right << Words[i].vowels;
      output << setw (8) << Words[i].consonants;
      output << setw (8) << Words[i].digits;
      output << setw (8) << Words[i].specialchars << endl;;
    }
  //print out a line before printing out the totals
  output << setw (15) <<left << "             ";
  output << setw (8) << right <<"___";
  output << setw (8) << right <<"___";
  output << setw (8) << right <<"___";
  output << setw (8) << right <<"___"<< endl;;

  //count the toatl number of vowels, consonants, digits,
  //and special characters
  int i = 0;
  while (i < count)
    {
      totalvowels += Words[i].vowels;
      totalconsonants += Words[i].consonants;
      totaldigits += Words[i].digits;
      totalspecialchars += Words[i].specialchars;
      i++;
    }
  //print the totals
  output << setw(15) << left << "Totals";
  output << setw(8) << right << totalvowels;
  output << setw(8) << totalconsonants;
  output << setw(8) << totaldigits;
  output << setw(8) << totalspecialchars <<endl;;
}

//write a function to swap the data and call this in sort function
void Swap (worddata & a, worddata & b)
{
  worddata t =a;
  a = b;
  b = t;
}

//Write a function to sort the data using insertion method
void WordSort (worddata W [], int N)
{
  for (int i = 1; i < N; i++)
    for (int j = i; j > 0 && W[j-1].word > W[j].word; j--)
      swap(W[j], W[j-1]);
}

//write a function to return true if vowels
bool isvowel (char aletter)
{
  char upcase = toupper (aletter);
  if (upcase == 'A' || upcase == 'E' || upcase == 'I'
      || upcase =='O' || upcase == 'U')
    return true;
  return false;
} 
