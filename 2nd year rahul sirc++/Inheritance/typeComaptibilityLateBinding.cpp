//Program to study :
//1) Type Compatibility
//2) Binding (Compile time and Run time)
//Refer : Inheritance.txt

#include <iostream>
using namespace std;

class A
{
public:
  void fx1();
  virtual void fx2();
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

void testCompatibility(A * p)
{
  cout<<"\n ---- Test Begins ---- ";
  p->fx1(); //inherited code (compile time bound)
  p->fx2();//overridden code (run time bound)
  cout<<"\n ---- Test Ends ---- ";
}

int main()
{
  A objA;
  B objB;
  testCompatibility(&objA);
  testCompatibility(&objB);


  return 0;
}
