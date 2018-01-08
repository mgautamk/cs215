//Title: Lab 5 Worddata class and Implementation
//Author: Mahesh Gautam
//Description: This is the header file for Lab05.cpp, It defines the WORDDARA Class,
//copies everything to a new array and retruns values using accessor and mutator
//functions

#ifndef WORDDATA
#define WORDDATA
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>


using namespace std;

class WordData
//Defininitions of constructors, functions
{
 public :
  WordData ();
  WordData (const WordData & OtherWord);
  ~WordData ();
  void SetWord (const string & InWord);
  string GetWord () const;
  bool operator < (const WordData & OtherWord) const;
  void WriteData (ostream & outs) const;
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
 private:
  string word; //C++ string to hold the word
  int vowels; //vowels counter
  int consonants; //consonant counter
  int digits; //digit counter
  int specialchars; //special character counter
};

//Function Implementations will be placed after this line
WordData::WordData()
{
  vowels = 0;
  consonants = 0;
  digits = 0;
  specialchars =0;
}

//Implementation of the copy constructor
WordData::WordData (const WordData & OtherWord)
{
  word = OtherWord.word;
  vowels = OtherWord.vowels;
  consonants = OtherWord.consonants;
  digits = OtherWord.digits;
  specialchars = OtherWord.specialchars;
}

//Implementation of ~Worddata
WordData::~WordData()
{
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

//Implement the mutator function
void WordData::SetWord (const string & InWord)
{
  word = InWord;
  for (int i = 0; i < InWord.length(); i++)
    {
      if (isalpha(InWord[i]))
	{
	  if (isvowel(InWord[i]))
	    vowels++;
	  else if (!isvowel(InWord[i]))
	    consonants++;
	}
      else if(isdigit(InWord[i]))
	digits++;
      else   
	specialchars++;
    }
}
//Implement the accessor function
string WordData::GetWord () const
{
  return word;
}

//Implement the accessor function GetVowels
int WordData::GetNumVowels () const
{
  return vowels;
}
//Implement the accessor function GetConsonants
int WordData::GetNumConsonants () const
{
  return consonants;
}
//Implementthe accessor function GetNumDigits
int WordData::GetNumDigits () const
{
  return digits;
}
//Implement the accessor function GetNumSpecialCharacters
int WordData::GetNumSpecialChars () const
{
  return specialchars;
}
//Implementation of the less than operator
bool WordData::operator < (const WordData & OtherWord) const
{
  if (word.length() < OtherWord.word.length())
    return true;
  else if (word.length() > OtherWord.word.length())
    return false;
  else if (word.length() == OtherWord.word.length())
    {
      if (word < OtherWord.word)
	return true;
      else
	return false;
    }
}

//Implement the output function
void WordData::WriteData (ostream & outs) const
{
  outs << setw (12) << left << word;
  outs << setw (8) << right << vowels;
  outs << setw (8)<< consonants;
  outs <<setw (8) << digits;
  outs << setw (8)<< specialchars;
}

#endif
