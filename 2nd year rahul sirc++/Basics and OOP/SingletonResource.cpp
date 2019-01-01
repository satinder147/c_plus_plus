/*
Program to :
* Study Object Creation By Allocation
* Study static member functions.
* Study static member variables.
* Demonstrate Singleton Design Pattern

Refer :
* object allocation and deallocation.txt
* static and non static members.txt
* singleton.txt

See :
* Object Creation and Use.png
* static and non static members.png
* singleton.png

*/

#include<iostream>
using namespace std;

//implemented as a Singleton class
class Resource
{
private:
  int x, y;
  static Resource * flag;

  Resource();

public:
  void increment();
  void display();
  static Resource* getObject();
};

//memory allocation for flag
Resource * Resource :: flag = NULL;

Resource * Resource :: getObject()
{
  cout<<"\n In getObject()";
  if(flag == NULL)
  {
    flag = new Resource();
  }
  return flag;
}

void Resource :: increment()
{
  x++;
  y++;
}

void Resource :: display()
{
  cout<<"\n"<<x<<" "<<y;
}

Resource :: Resource()
{
  cout<<"\n Resource()";
  x = 10;
  y = 20;
}


void fx()
{
  Resource * r2 ;
  r2 = Resource:: getObject();
  r2->increment();
  r2->display();
}

int main()
{
  Resource *r1;
  r1 = Resource::getObject();
  r1->display();
  fx();
  r1->display();
  return 0;
}
