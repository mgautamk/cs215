//Author: Mahesh gautam
//Project : 04
//Date: Fall 2013
//File: OrderedSet.hpp
//Description: This file contains function definations, prototypes, and holds all
//required informations and function implementations to run a Ordered linked list 


#ifndef OrderedSet_HPP
#define OrderedSet_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <sstream>

using namespace std;

//Defining template class OrderedSet
template <class ST> class OrderedSet;
template <class ST> ostream & operator << (ostream & outs, const OrderedSet<ST> & L);

//creating a template class ST
template <class ST>
class OrderedSet
{
private:
  struct LNode
  {
  public:
    LNode ();
    ST data;
    LNode * next;
    LNode * prev;
  };
public:
  class Iterator
  {
  public:
    Iterator ();
    Iterator (LNode * NP);
    ST & operator * () const;
    Iterator operator ++ ();
    Iterator operator ++ (int);
    Iterator operator -- ();
    Iterator operator -- (int);
    bool operator == (const Iterator & other) const;
    bool operator != (const Iterator & other) const;
  private:
    LNode * current;
  };
  class Exception
  {
  public:
    Exception ();
    Exception (string msg);
    Exception (int idx);
    string Message () const;
  private:
    string message;
  };
  OrderedSet ();
  OrderedSet (const OrderedSet & other);
  OrderedSet operator + (const OrderedSet & other) const;
  OrderedSet operator * (const OrderedSet & other) const;
  ~OrderedSet ();
  OrderedSet & operator = (const OrderedSet & other);
  bool operator == (const OrderedSet & other);
  int Size () const;
  friend ostream & operator << <> (ostream & outs, const OrderedSet<ST> & L);
  void Forward (void function (const ST & param));
  void Backward (void function (const ST & param));
  void Clear();
  bool IsEmpty () const;
  bool IsIn (const ST & value) const;
  bool Insert (const ST & value);
  bool Delete (const ST & value);
  ST & operator [] (const int & index) const;
  Iterator begin () const;
  Iterator rbegin () const;
  Iterator end () const;
  Iterator rend () const;
private:
  bool InsertFirst (const ST & value);
  bool InsertLast (const ST & value);
  bool DeleteFirst ();
  bool DeleteLast ();
  LNode * first;
  LNode * last;
  int size;
};

template <class ST>
OrderedSet<ST>::LNode::LNode ()
{
  // This function initializes the Nodes to zero and points the
  //next node to NULL
  next = NULL;
  prev = NULL;
}

template <class ST>
OrderedSet<ST>::OrderedSet ()
{ 
  // This function empties the list not pointing to anything
  first = NULL;
  last = NULL;
  size = 0;
}

template <class ST>
OrderedSet<ST>::OrderedSet (const OrderedSet & other)
{
  // This function sets the value of size to zero, sets the 
  //value of first to NULL and while pointer is not null, it calls
  //the InsertLast function to put the data into the last space
  first = NULL;
  size = 0;
  for (LNode * n = other.first; n != NULL; n = n->next)
    InsertLast (n->data);
}

template <class ST>
OrderedSet<ST>::~OrderedSet ()
{ // This is a deconstructor, it will delete the first if its
  //not empty
  while (first)
    DeleteFirst();
}

template <class ST>
OrderedSet<ST> & OrderedSet<ST>::operator = (const OrderedSet<ST> & other)
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

template <class ST>
bool OrderedSet<ST>::operator == (const OrderedSet & other)
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

template <class ST>
int OrderedSet<ST>::Size () const
{ // Returns the size value
  return size;
}

template <class ST>
ostream & operator << (ostream & outs, const OrderedSet<ST> & L)
{ // This stub outputs the pointer data and pushes the pointer to next node
  // if current node not empty
  if (L.first == NULL)
    return outs;
  outs << '{';
  outs << L.first->data;
  typename OrderedSet<ST>::LNode * n;
  for (n = L.first->next; n != NULL; n = n->next)
    outs << ',' << n->data;
  outs << '}';
  return outs;
}

template <class ST>
bool OrderedSet<ST>::InsertFirst (const ST & value)
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

template <class ST>
bool OrderedSet<ST>::InsertLast (const ST & value)
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


template <class ST>
bool OrderedSet<ST>::DeleteFirst() 
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

template <class ST>
bool OrderedSet<ST>::DeleteLast ()
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

template <class ST>
void OrderedSet<ST>::Forward (void function (const ST & param))
{// This function moves through the data from left to right
  for (LNode * n = first; n; n = n->next)
    function (n->data);
}

template <class ST>
void OrderedSet<ST>::Backward (void function (const ST & param))
{//This frunction moves through the data from right to left
  for (LNode * n = last; n; n = n->prev)
    function (n->data);
}

//This function clears the OrderedSet
template <class ST>
void OrderedSet<ST>::Clear()
{
  while (size > 0)
    DeleteLast();
}
//This function checks to see if the OrderedSet is Empty
template <class ST>
bool OrderedSet<ST>::IsEmpty () const
{
  if (size == 0)
    return true;
  return false;
}

//This function checks to see if the specified Item thats being
//passed as 'value' is in the list
template <class ST>
bool OrderedSet<ST>::IsIn (const ST & value) const
{
  if (size == 0)
    return false;
  LNode * n;
  for (n = first; n -> next != NULL; n = n -> next)
    if ( n -> data == value)
      return true;
  if ( n -> data == value)
     return true;
  return false;
}

//This function inerts a value into a list if the value isn't there
//already, the values are inserted in an ascending order
template <class ST>
bool OrderedSet<ST>::Insert (const ST & value)
{
  if ((size == 0) || (value < first -> data))
    return InsertFirst(value);
  if (IsIn(value))
    return false;
  if (value > last -> data)
    return InsertLast(value);
  LNode * nn = new LNode;
  if (nn == NULL)
    return false;
  nn -> data = value;
  LNode * p, * n;
  for (n = first; n -> data < value; n = n -> next)
    p = n -> next;

  n = n -> prev;
  nn -> data = value;
  nn -> prev = n;
  nn -> next = p;
  n -> next = nn;
  p -> prev = nn;
  size++;
  return true;
}

//This function removes the specified data entry from the set
//using DeleteFirst and/or DeleteLast functions
template <class ST>
bool OrderedSet<ST>::Delete (const ST & value)
{
  if ((size == 0) || (IsIn(value) != true))
    return false;
  if (IsIn(value) == true)
    {
      if (size == 1)
	DeleteFirst();
      if (size > 1)
	{
	  LNode * NN;
	  for (NN = first; NN -> data < value; NN = NN -> next);
	  if (NN == first)
	    return DeleteFirst ();
	  if (NN == last)
	    return DeleteLast ();
	  LNode * before = NN -> prev;
	  LNode * after = NN -> next;
	  before -> next = after;
	  after -> prev = before;
	  delete NN;
	  size --;
	  return true;
	}
    }
}

//This is a union Operator, this functon returns a new set combining values 
//from two differen sets
template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator + (const OrderedSet & other) const
{
  OrderedSet<ST> Union;
  Union = * this;
  for (LNode * n = other.first; n != NULL; n = n -> next)
    Union.Insert(n -> data);
  return Union;
}

//This is s Intersection operator, this combines common values from 
//two different list and puts them together
template <class ST>
OrderedSet<ST> OrderedSet<ST>::operator * (const OrderedSet & other) const
{
  OrderedSet<ST> Common;
  for (LNode * n = other.first; n != NULL; n = n -> next)
    for (LNode * p = first; p != NULL; p = p -> next)
      if (n -> data == p -> data)
	Common.Insert(n -> data);
  return Common;
}

template <class ST>
ST & OrderedSet<ST>::operator [] (const int & index) const
{//This function finds a distinct location of Information
  //and throws error if the size is empty or greater than the
  //given size
      if (index < 0 || index >= size)
	throw (Exception(index));
      typename OrderedSet<ST>::LNode * n = first;
      for (int i = 0; i < index; i++)
	n = n -> next;
      return n -> data;
}

template <class ST>
ST & OrderedSet<ST>::Iterator::operator * () const
{//Deferencing operator
  if (current == NULL)
    throw (Exception("Cannot deference a NULL pointer"));
  return current->data;
}

template <class ST>
OrderedSet<ST>::Iterator::Iterator ()
{// Default Iterator constructor
  current = NULL;
}

template <class ST>
OrderedSet<ST>::Iterator::Iterator (LNode * NP)
{//Default Iterator Node constructor
  current= NP;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++ ()
{//The Increment Iterator operator
    if (current == NULL)
      throw (Exception("Cannot post increment a NULL pointer"));
    current= current->next;
    return * this;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator ++ (int)
{//Increment Iterator operator with integer reference
    if (current == NULL)
      throw (Exception("Cannot post increment a NULL pointer"));
    Iterator temp = *this;
    current= current->next;
    return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- ()
{//Decrement Iterator operator 
    if (current == NULL)
      throw (Exception("Cannot post increment a NULL pointer"));
    // Iterator temp;
    current= current->prev;
    return *this;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::Iterator::operator -- (int)
{//Decrement Iterator operator with integer reference
    if (current == NULL)
      throw (Exception("Cannot post increment a NULL pointer"));
    Iterator temp = * this;
    current= current->prev;
    return temp;
}

template <class ST>
bool OrderedSet<ST>::Iterator::operator == (const Iterator & other) const
{//Equality Iterator operator
  return current == other.current;
}

template <class ST>
bool OrderedSet<ST>::Iterator::operator != (const Iterator & other)const
{//Enwquality Iterator operator
  return current != other.current;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::begin () const
{////Public member function to access first element 
  Iterator temp (first);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rbegin () const
{//Public member function to return reverse iterator to reverse begening  
  Iterator temp (last);
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::end () const
{//public member function - Reverse Iterator operator    
  Iterator temp;
  return temp;
}

template <class ST>
typename OrderedSet<ST>::Iterator OrderedSet<ST>::rend () const
{//Return reverse Iterator to reverse end   
  Iterator temp;
  return temp;
}

//Implementation for Default Constructor for Exception Handler
template <class ST>
OrderedSet<ST>::Exception::Exception ()
{
  message = " ";
}

//This functions sets the message for Excectin
template <class ST>
OrderedSet<ST>::Exception::Exception (string msg)
{
  message = msg;

}

//This function displays the Exception Message
template <class ST>
OrderedSet<ST>::Exception::Exception (int idx)
{
  stringstream ss (stringstream::in | stringstream::out);
  ss << "Subscript [" << idx << "] out of range";
  getline(ss, message);
}

//This fucntion returns the Exception Message
template <class ST>
string OrderedSet<ST>::Exception::Message () const
{
  return message;
}




#endif
