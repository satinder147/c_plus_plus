//Program to study :
//pure virtual function
//abstract class

#include <iostream>
using namespace std;

//abstract class
class Timetable
{
public:
  void period();
 //pure virtual function
  virtual void practical() = 0;
};

void Timetable:: period()
{
  cout<<"\n Lets Learn CO ";
}

class Group1 : public Timetable
{
public:
  void practical();//overridden code
  void project();//extended code
};

void Group1 :: practical()
{
  cout<<"\n Group1 : OOP ";
  project();
}

void Group1 :: project()
{
  cout<<"\n Project Analysis";
}

class Group2: public Timetable
{
public:
  void practical();//overridden code
};

void Group2 :: practical()
{
  cout<<"\n Group2 : DS ";
}

void workForTheDay(Timetable * p)
{
  cout<<"\n ---- Day Begins ---- ";
  p->period(); //inherited code (compile time bound)
  p->practical();//overridden code (run time bound)
  cout<<"\n ---- Day Ends ---- ";
}

int main()
{
  Group1 g1;
  Group2 g2;
  workForTheDay(&g1);
  workForTheDay(&g2);

  return 0;
}
