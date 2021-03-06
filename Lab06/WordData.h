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
  void SetWord (string InWord);
  string GetWord () const;
  bool operator < (const WordData & OtherWord) const;
  void WriteData (ostream & outs) const;
  int GetNumVowels () const;
  int GetNumConsonants () const;
  int GetNumDigits () const;
  int GetNumSpecialChars () const;
  WordData & operator = (const WordData & OtherWord);
  bool operator == (const WordData & OtherWord) const;
  friend istream & operator >> (istream & ins, WordData & w);
  friend ostream & operator << (ostream & outs, const WordData & w);
 private:
  char * word; //C++ string to hold the word
  int vowels; //vowels counter
  int consonants; //consonant counter
  int digits; //digit counter
  int specialchars; //special character counter

};

#endif
