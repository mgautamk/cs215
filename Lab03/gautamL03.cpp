//Assignment : Lab03
//file: words.txt
//Author : Mahesh Gautam
//Date : Fall 2013
//Description :This program reads strings from a file, counts them seperately as vowels, consonamts
//digits, and special characters, sorts and swapss them, and display the sorted version with number
//of each word, vowels, digits, consonants, special characters and their totals 


//Use include statements to use liabraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const int MAXWORDS = 100;

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
int ReadFile (ifstream & input, worddata Words []);
void WriteReport (ostream & output, worddata Words [], int count);
void Swap (worddata & a, worddata & b);
void WordSort (worddata W [], int N);
bool isvowel (char aletter);

int main ()
{
  //Declare an input file and open .words.txt
  ifstream input ("words.txt");
  if (input.fail())
    {
      cout << "File: words.txt not found\n";
    }
  //Declare an array of wordata objects to hold the words 
  //and their vowel, consonant, digit, and special 
  //character counts.
  worddata WordArray [MAXWORDS];

  //call the readfile function to read the file, store the
  //words in the array and return the number of words read
  //from the file
  int count = ReadFile (input, WordArray);

  //call the WordSort function to sort the words into 
  //alphabeical order.
  WordSort (WordArray, count);

  //Call the WriteReport function to write the data
  //stored in the array in a formatted fashion.
  WriteReport (cout, WordArray, count);



  return 0;
}

worddata::worddata ()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars = 0;
}

int ReadFile (ifstream & input, worddata Words [])
{
  int count = 0;
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
  output << setw (12) << left << "Word";
  output << setw (8) << right << "Vowels";
  output << setw (8) << "Const.";
  output << setw (8) << "Digits";
  output << setw (8) << "Special" << endl;;

  //print the words, vowels, consonants, digits, and special chars
  for (int i=0; i < count; i++)
    {
      output << setw (12) << left << Words[i].word;
      output << setw (8) << right << Words[i].vowels;
      output << setw (8) << Words[i].consonants;
      output << setw (8) << Words[i].digits;
      output << setw (8) << Words[i].specialchars << endl;;
    }
  //print out a line before printing out the totals
  output << setw (12) <<left << "             ";
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
  output << setw(12) << left << "Totals";
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
    for (int j = i; j > 0 & W[j-1].word > W[j].word; j--)
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
