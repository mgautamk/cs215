//Author: Mahesh gautam
//Assignment : Lab11
//Date: Fall 2013
//File: LList2.hpp
//Other Files required: Lab11app.cpp
//Description: This file contains function definations, prototypes, and holds all
//required informations and function implementations to run basic linked list 


#ifndef LLIST2_HPP
#define LLIST2_HPP

#include <iostream>
#include <cstdlib>

using namespace std;

template <class LT> class LList2;
template <class LT> ostream & operator << (ostream & outs, const LList2<LT> & L);


template <class LT>
class LList2
{
private:
  struct LNode
  {
  public:
    LNode ();
    LT data;
    LNode * next;
    LNode * prev;
  };
public:
  class Iterator
  {
  public:
    Iterator ();
    Iterator (LNode * NP);
    LT & operator * () const;
    Iterator operator ++ ();
    Iterator operator ++ (int);
    Iterator operator -- ();
    Iterator operator -- (int);
    bool operator == (const Iterator & other) const;
    bool operator != (const Iterator & other) const;
  private:
    LNode * current;
  };
  LList2 ();
  LList2 (const LList2 & other);
  ~LList2 ();
  LList2 & operator = (const LList2 & other);
  bool operator == (const LList2 & other);
  int Size () const;
  friend ostream & operator << <> (ostream & outs, const LList2<LT> & L);
  bool InsertFirst (const LT & value);
  bool InsertLast (const LT & value);
  bool DeleteFirst ();
  bool DeleteLast ();
  void Forward (void function (const LT & param));
  void Backward (void function (const LT & param));
  LT & operator [] (const int & index) const;
 
  Iterator begin () const;
  Iterator rbegin () const;
  Iterator end () const;
  Iterator rend () const;
private:
  LNode * first;
  LNode * last;
  int size;
};
template <class LT>
LList2<LT>::LNode::LNode ()
{
  // This function initializes the Nodes to zero and points the
  //next node to NULL
  next = NULL;
  prev = NULL;
}

template <class LT>
LList2<LT>::LList2 ()
{ 
  // This function empties the list not pointing to anything
  first = NULL;
  last = NULL;
  size = 0;
}

template <class LT>
LList2<LT>::LList2 (const LList2 & other)
{
  // This function sets the value of size to zero, sets the 
  //value of first to NULL and while pointer is not null, it calls
  //the InsertLast function to put the data into the last space
  first = NULL;
  size = 0;
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast (n->data);
}

template <class LT>
LList2<LT>::~LList2 ()
{ // This is a deconstructor, it will delete the first if its
  //not empty
  while (first)
    // if (first != NULL)
    DeleteFirst();
}

template <class LT>
LList2<LT> & LList2<LT>::operator = (const LList2<LT> & other)
{ // This function checks to see if two nodes are equal, if they
  //are not equal remove the data in the first and move the list
  if (this == & other)
    return * this;
  while (first)
    DeleteFirst();
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast(n->data);
  return * this;
}

template <class LT>
bool LList2<LT>::operator == (const LList2 & other)
{ // This function returns false if sizes of two nodes aren't equal,
  //compares corresponding nodes, and if any pair are different, returns false,
  //else returns true
  if (size != other.size)
    return false;
  LNode * n = first;
  LNode * m = other.first;
  while (n != NULL)
    {
      if (n->data != m->data)
	return false;
      n = n->next;
      m = m->next;
    }
  return true;
}

template <class LT>
int LList2<LT>::Size () const
{ // Returns the size value
  return size;
}

template <class LT>
ostream & operator << (ostream & outs, const LList2<LT> & L)
{ // This stub outputs the pointer data and pushes the pointer to next node
  // if current node not empty
  if (L.first == NULL)
    return outs;
  outs << L.first->data;
  typename LList2<LT>::LNode * n;
  for (n= L.first->next; n != NULL; n = n->next)
    outs << ' ' << n->data;
  return outs;
}

template <class LT>
bool LList2<LT>::InsertFirst (const LT & value)
{ // This function Inserts the value to the front of the list
  LNode * np = new LNode;
  if (np == NULL)
    return false;
  np->data = value;
  if (size == 0)
    first = last = np;
  else
    {
      first->prev = np;
      np->next = first;
      first = np;
    }
  size++;
  return true;
}

template <class LT>
bool LList2<LT>::InsertLast (const LT & value)
{ // This function Inserts the value to the end of the list
  LNode * np = new LNode;
  if (np == NULL)
    return false;
  np->data = value;
  if (size == 0)
    first = last = np;
  else
    {
      last->next = np;
      np->prev = last;
      last = np;
    }
  size++;
  return true;
}


template <class LT>
bool LList2<LT>::DeleteFirst() 
{ // This function deletes the first value from the list
  if (size == 0)
    return false;
  if (size == 1)
    {
      delete first;
      first = NULL;
      last = NULL;
      size = 0;
      return true;
    }
  LNode * n = first;
  first = n -> next;
  first -> prev = NULL;
  delete n;
  size--;
  return true;
}

template <class LT>
bool LList2<LT>::DeleteLast ()
{ // This function deletes the last value from the list
  if (size == 0)
    return false;
  if (size == 1)
    return DeleteFirst();
  LNode * n, * p;
  for (n = first; n -> next != NULL; n = n -> next)
    p = n;
  p -> next = NULL;
  last = p;
  delete n;
  size--;
  return true;
}

template <class LT>
void LList2<LT>::Forward (void function (const LT & param))
{// This function moves through the data from left to right
  for (LNode * n = first; n; n = n->next)
    function (n->data);
}

template <class LT>
void LList2<LT>::Backward (void function (const LT & param))
{//This frunction moves through the data from right to left
  for (LNode * n = last; n; n = n->prev)
    function (n->data);
}

template <class LT>
LT & LList2<LT>::operator [] (const int & index) const
{//This function finds a distinct location of Information
  //and throws error if the size is empty or greater than the
  //given size
  try
    {
      if (index < 0 || index >= size)
	throw ("Subscript out of bounds : index is too large");
      LList2<LT>::LNode * n = first;
      for (int i = 0; i < index; i++)
	n = n -> next;
      return n -> data;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit(1);
    }
}

template <class LT>
LT & LList2<LT>::Iterator::operator * () const
{//Deferencing operator
  try 
    {
      if (current == NULL)
	throw ("Cannot deference a NULL pointer");
      return current->data;
    }
  catch (const char * message)
    {
      cerr << message << endl;
      exit(1);
    }
}

template <class LT>
LList2<LT>::Iterator::Iterator ()
{// Default Iterator constructor
  current = NULL;
}

template <class LT>
LList2<LT>::Iterator::Iterator (LNode * NP)
{//Default Iterator Node constructor
  current= NP;
}


template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++ ()
{//The Increment Iterator operator
try
  {
    if (current == NULL)
      throw ("Cannot post-increment a NULL pointer");
    current= current->next;
    return * this;
  }
 catch (const char * message)
   {
     cerr << message << endl;
     exit(1);
   }
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator ++ (int)
{//Increment Iterator operator with integer reference
try
  {
    if (current == NULL)
      throw ("Cannot post-increment a NULL pointer");
    Iterator temp;
    current= current->next;
    return temp;
  }
 catch (const char * message)
   {
     cerr << message << endl;
     exit(1);
   }
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator -- ()
{//Decrement Iterator operator 
try
  {
    if (current == NULL)
      throw ("Cannot post-decrement a NULL pointer");
    Iterator temp;
    current= current->prev;
    return temp;
  }
 catch (const char * message)
   {
     cerr << message << endl;
     exit(1);
   }
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::Iterator::operator -- (int)
{//Decrement Iterator operator with integer reference
try
  {
    if (current == NULL)
      throw ("Cannot post-decrement a NULL pointer");
    Iterator temp = * this;
    current= current->prev;
    return temp;
  }
 catch (const char * message)
   {
     cerr << message << endl;
     exit(1);
   }
}

template <class LT>
bool LList2<LT>::Iterator::operator == (const Iterator & other) const
{//Equality Iterator operator
  return current == other.current;
}

template <class LT>
bool LList2<LT>::Iterator::operator != (const Iterator & other)const
{//Enwquality Iterator operator
  return current != other.current;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::begin () const
{////Public member function to access first element 
  Iterator temp (first);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rbegin () const
{//Public member function to return reverse iterator to reverse begening  
  Iterator temp (last);
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::end () const
{//public member function - Reverse Iterator operator    
  Iterator temp;
  return temp;
}

template <class LT>
typename LList2<LT>::Iterator LList2<LT>::rend () const
{//Return reverse Iterator to reverse end   
  Iterator temp;
  return temp;
}


#endif
