//Program to study : multiple inheritance, ambiguity and its resolution

#include <iostream>
using namespace std;

class A
{
protected:
  int x;
public:
  A();
  A(int);
  virtual void display();
  ~A();
};
A :: A()
{
  cout<<"\n A()";
  x = 10;
}

A :: A(int q)
{
  cout<<"\n A(int)";
  x = q;
}

void A::display()
{
  cout<<"\n"<<x;
}

A:: ~A()
{
  cout<<"\n ~A()";
}

class B
{
protected:
  int y;
public:
  B();
  B(int);
  virtual void display();
  ~B();
};

B :: B()
{
  cout<<"\n B()";
  y = 20;
}

B :: B(int q)
{
  cout<<"\n B(int)";
  y = q;
}

void B ::display()
{
  cout<<"\n"<<y;
}

B :: ~B()
{
  cout<<"\n ~B()";
}

//multiple inheritance
class C : public B, public A
{
protected:
  int z;
public:
  C();
  C(int,int,int);
  //this override clears the ambiguity caused on calls to display
  void display();//automatically virtual
  ~C();
};

C :: C() //: A(), B()
{
  cout<<"\n C()";
  z = 30;
}

//C(int,int,int) sharing values with A(int) ,B(int)
C :: C(int q, int w, int e) : A(q), B(w)
{
  cout<<"\n C(int,int,int)";
  z= e;
}

void C ::display()
{
  A::display();
  B::display();
  cout<<"\n"<<z;
}

C :: ~C()
{
  cout<<"\n ~C()";
}

int main()
{
  C objC(1,2,3);
  //objC.A::display();
  //objC.B::display();
  objC.display();
  return 0;
}
