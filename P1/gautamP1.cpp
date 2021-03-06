//Title: Project1
//Author: Mahesh Gautam
//Description : This Program reads received points and total points for labs, homeworks,
// quizes, Assignemnts, and test  from a file, computes them and outputs the current
// grade to the console
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

//Declare a Class gradedata 
class gradedata
{
public:
  gradedata();
  char GetType () const;
  int GetYear () const;
  string GetDate () const;
  float GetReceived () const;
  int GetPossible () const;
  string GetName () const;
  void SetType (const char & c);
  void SetYear (const int & dy);
  void SetDate(const string & d);
  void SetPossible (const int & p);
  void SetReceived (const float & r);
  void SetName (const string & n);
private:
  char type;
  int year;
  string date;
  float received; // lab received
  int possible; // lab possible
  string name;
};

//Declare functions
void WriteReport (ostream & output, vector<gradedata> GradeVector, int count);
void Swap (gradedata & a, gradedata & b);
void SortDate (vector <gradedata> & GradeVector, int count);

//main function
int main()
{
  //Declare a input file and open grades.txt
  ifstream input ("grades.txt");
  if (input.fail())
    {
      cout << "File: grades.txt wasn't found\n";
    }

  //Declare an array of gradedata objects to hold the possible points
  //from each assignment,labs,projects, quiz, and test
  vector <gradedata> GradeVector;
  gradedata onescore;
  int count;
  char c;
  //Read the file into variables and push them to the vector
  while ( input >> c)
    {
      int dy;
      char garbage;
      string d;
      int p;
      float r;
      string n;
      input >> dy;
      input >> garbage;
      input >> d;
      input >> p;
      input >> r;
      ws(input);
      getline (input, n);
      onescore.SetType(c);
      onescore.SetYear(dy);
      onescore.SetDate(d);
      onescore.SetPossible(p);
      onescore.SetReceived(r);
      onescore.SetName(n);
      GradeVector.push_back(onescore);
      count++;
    }

  //sort the file
  SortDate(GradeVector, count);

  //call the writereport function
  WriteReport (cout, GradeVector, count);
  return 0;
} 

//Initialize the variables
gradedata::gradedata()
{
  year = 0;  
  possible = 0;
  received = 0.0;
  date  = "";
  type = ' ';
  name = "";
}

//Write the Report
void WriteReport (ostream & output, vector<gradedata> GradeVector, int count)
{
  //initialize totals for each variable and print the structure
  float labhwreceived = 0; int labhwpossible = 0; float labhwpercentage = 0;
  output << setw (18) << left << "Labs and Homework";
  output << setw (9) << right << "Date";
  output << setw (16) << right << "Received";
  output << setw (10) << right << "Possible";
  output << endl;

  //Set the precision to one decimal point fixed
  output << setprecision (1);
  cout << fixed;

  //print out the lab/homework type date received and possible
  for (int i = 0; i < count; i++)
    if (GradeVector[i].GetType() == 'H' || GradeVector[i].GetType() == 'L')
    {
      output << setw (18) << left << GradeVector[i].GetName();
      output << setw (10) << right << GradeVector[i].GetDate() << "/" << GradeVector[i].GetYear();
      output << setw (10) << right << GradeVector[i].GetReceived();
      output << setw (10) << right << GradeVector[i].GetPossible() << endl;

      labhwreceived += GradeVector[i].GetReceived();
      labhwpossible += GradeVector[i].GetPossible();
    }
  //calculae the lab and hw percentage
  labhwpercentage = (labhwreceived/labhwpossible)*100;

  output << setw (18) << left << "Labs and Homework Totals";
  output << setw (19) << right << labhwreceived;
  output << setw  (10) << right << labhwpossible;
  output << setw (11) << right <<labhwpercentage << "%";
  output << endl;
  output << endl;

  //initialize tota ls for each variables again and print structure for Projects
  float projectreceived = 0; int projectpossible = 0; float projectpercentage = 0;
  output << setw (18) << left << "Projects";
  output << setw (9) << right << "Date";
  output << setw (16) << right << "Received";
  output << setw (10) << right << "Possible";
  output << endl;
  for (int i = 0; i < count; i++)
    if (GradeVector[i].GetType() == 'P')  
    {
      output << setw (18) << left << GradeVector[i].GetName();
      output << setw (10) << right << GradeVector[i].GetDate() << "/" << GradeVector[i].GetYear();
      output << setw (10) << right << GradeVector[i].GetReceived();
      output << setw (10) << right << GradeVector[i].GetPossible() << endl;

      projectreceived += GradeVector[i].GetReceived();
      projectpossible += GradeVector[i].GetPossible();
    }
  //calculate the project percentage
  projectpercentage = (projectreceived/projectpossible)*100;

  //Display project totals and percentage
  output << setw (18) << left << "Project Totals";
  output << setw (25) << right << projectreceived;
  output << setw (10) << right << projectpossible;
  output << setw (11) << right << projectpercentage << "%";
  output << endl;
  output << endl;

  //initialize totals for Quizzes and Exams and print the structure
  float qtreceived = 0; int qtpossible = 0; float qtpercentage = 0;
  output << setw (18) << left << "Quizes and Exams";
  output << setw (9) << right << "Date";
  output << setw (16) << right << "Received";
  output << setw (10) << right << "Possible";
  cout << endl;
  
  for (int i = 0; i < count; i++)
    if(GradeVector[i].GetType() == 'Q' || GradeVector[i].GetType() == 'T')
    {
      output << setw (18) << left << GradeVector[i].GetName();
      output << setw (10) << right << GradeVector[i].GetDate() << "/" << GradeVector[i].GetYear();      
      output << setw (10) << right << GradeVector[i].GetReceived();
      output << setw (10) << right << GradeVector[i].GetPossible() << endl;

      qtreceived += GradeVector[i].GetReceived();
      qtpossible += GradeVector[i].GetPossible();
    }
  //calculate the percentage for quiz and test
  qtpercentage = (qtreceived/qtpossible)*100;

  //Display the quiz and test totals and percentage
  output << setw (18) << left << "Quizzes and Exams Totals";
  output << setw (19) << right << qtreceived;
  output << setw (10) << right << qtpossible;
  output << setw (11) << right << qtpercentage <<"%";
  output << endl;
  output << endl;
  
  //Calculate the Overall  percentage
  float totalpercentage = 0;
  totalpercentage = (0.20 * labhwpercentage) + (0.30 * projectpercentage) + (0.50 * qtpercentage);
  
  //Calculate the Final Grade
  char Grade;
  if (totalpercentage < 60)
    Grade = 'F';
  else if (totalpercentage >= 60 && totalpercentage < 70)
    Grade = 'D';
  else if (totalpercentage >= 70 && totalpercentage < 80)
    Grade = 'C';
  else if (totalpercentage >= 80 && totalpercentage < 90)
    Grade = 'B';
  else if (totalpercentage >=90 && totalpercentage < 100)
    Grade = 'A';
  else
    output << "Grade Error";

  //Display Overall percentage and the final Grade
  output << "Overall percentage:    " << totalpercentage << "%" << "   Grade:" << " " << Grade;
  output << endl;
  output << endl;    
}

//Write a function to swap the data
void Swap (gradedata & a, gradedata & b)
{
  gradedata t = a;
  a = b;
  b = t;
}

//Function to Sort by Date and by Type
void SortDate (vector<gradedata> & GradeVector, int count)
{
  int i =1;
  while (i < count)
    {
      int j = i;
      while ((j > 0 && GradeVector[j].GetDate() < GradeVector[j-1].GetDate()) ||
	     (j > 0 && GradeVector[j].GetType() < GradeVector[j-1].GetType()))
	{
	  Swap(GradeVector[j], GradeVector[j-1]);
	  j--;
	} 
      i++;
      for (int l = 1; GradeVector[l].GetType() < GradeVector[l-1].GetType(); l++)
	Swap(GradeVector[l], GradeVector[l-1]);
    }
}
//Implemenataion of accessor function GetChar
char gradedata::GetType () const
{
  return type;
}

//Implementation of accessor function for Year
int gradedata::GetYear () const
{
  return year;
}

//Implementation of accessor function GetDate
 string gradedata::GetDate () const
 {
   return date;
 }

 //Implementation of accessor function GetReceived
 float gradedata::GetReceived () const
 {
   return received;
 }

 //Implementation of accessor function GetPossible
 int gradedata::GetPossible () const
 {
   return possible;
 }

 //Implementation of GetName - Assignment/Lab name
 string gradedata::GetName () const
 {
   return name;
 }

//Implementation of the mutator function for SetType
void gradedata::SetType (const char & c)
{
  type = c;
}

//Implementation of mutator function SetYear
void gradedata::SetYear (const int & dy)
{
  year = dy;
}

//Implementation of mutator function for month and day 
void gradedata::SetDate (const string & d)
{
  date = d;
}

//Implementation of mutator function for Possible 
void gradedata::SetPossible (const int & p)
{
  possible = p;
}

//Implementation of mutator function for Received
void gradedata::SetReceived (const float & r)
{
  received = r;
}

//Implementation of mutator function for name of Assignment
void gradedata::SetName (const string & n)
{
  name = n;
}

