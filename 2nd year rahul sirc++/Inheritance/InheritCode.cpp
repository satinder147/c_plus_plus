//Program to demonstrate : Inheritance of Code
//Refer : Inheritance.txt
//See InheritCode.png

#include <iostream>
using namespace std;

class A
{
public:
  void fx1();
  void fx2();
};

void A :: fx1()
{
  cout<<"\n A fx1() ";
}

void A :: fx2()
{
  cout<<"\n A fx2() ";
}

class B : public A
{
public:
  void fx2();//overridden code
  void fx3();//extended code
};

void B :: fx2()
{
  cout<<"\n B fx2() ";
}

void B :: fx3()
{
  cout<<"\n B fx3() ";
}


int main()
{
  B objB;
  objB.fx1();//inherited code
  objB.fx2();//overridden code
  objB.fx3();//extended code

  return 0;
}
