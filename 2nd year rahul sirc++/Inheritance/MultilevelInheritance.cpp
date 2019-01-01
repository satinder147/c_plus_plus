//Program to study : multilevel inheritance
//Refer : Inheritance.txt
//See : MultilevelInheritance.png

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

class B : public A
{
protected:
  int y;
public:
  B();
  B(int,int);
  void display();//automatically virtual
  ~B();
};

B :: B() //: A()
{
  cout<<"\n B()";
  y = 20;
}

//B(int,int) sharing a value with A(int)
B :: B(int q, int w) : A(q)
{
  cout<<"\n B(int,int)";
  y = w;
}

void B ::display()
{
  cout<<"\n"<<x<<" "<<y;
}


B :: ~B()
{
  cout<<"\n ~B()";
}

class C : public B
{
protected:
  int z;
public:
  C();
  C(int,int,int);
  void display();//automatically virtual
  ~C();
};

C :: C() //: B()
{
  cout<<"\n C()";
  z = 30;
}

//C(int,int,int) sharing 2 values with B(int,int)
C :: C(int q, int w, int e) : B(q,w)
{
  cout<<"\n C(int,int,int)";
  z = e;
}

void C ::display()
{
  cout<<"\n"<<x<<" "<<y<<" "<<z;
}


C :: ~C()
{
  cout<<"\n ~C()";
}

void test1(A *ptrA)
{
    ptrA->display();
}


void test2(B *ptrB)
{
    ptrB->display();
}

int main()
{
  C objC(1,2,3);
  test1(&objC);
  test2(&objC);

  return 0;
}
