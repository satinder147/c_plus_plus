//Program to demonstrate : 
//virtual base class used to resolve ambiguity due to hybrid inheritance

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

class B : virtual public A
{
protected:
  int y;
public:
  B();
  B(int);
  B(int, int);
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

B :: B(int q, int w) : A(q)
{
  cout<<"\n B(int, int)";
  y = w;
}

void B ::display()
{
  cout<<"\n"<<x<<"  "<< y;
}

B :: ~B()
{
  cout<<"\n ~B()";
}

class C : virtual public A
{
protected:
  int z;
public:
  C();
  C(int);
  C(int, int);
  virtual void display();
  ~C();
};

C :: C()
{
  cout<<"\n C()";
  z = 30;
}

C :: C(int q)
{
  cout<<"\n C( int)";
  z = q;
}

C :: C(int q, int w) : A(q)
{
  cout<<"\n C(int, int)";
  z = w;
}

void C ::display()
{
  cout<<"\n"<<x<<"  "<< z;
}

C :: ~C()
{
  cout<<"\n ~C()";
}


//hybrid inheritance
class D : public B, public C
{
protected:
  int sum;
public:
  D();
  D(int,int,int);
  //this override clears the ambiguity caused on calls to display
  void display();//automatically virtual
  ~D();
};

D :: D() //: A(), B(), C()
{
  cout<<"\n D()";
  sum = x+ y + z;
}

//D(int,int,int) sharing values with A(int), B(int) ,C(int)
D :: D(int q, int w, int e) : A(q), B(w), C(e)
{
  cout<<"\n D(int,int,int)";
  sum = x + y +  z;
}

void D ::display()
{
  cout<<"\n"<<x <<" + "<< y  << " + "<<z <<" = "<<sum;
}

D :: ~D()
{
  cout<<"\n ~D()";
}

int main()
{
  D objD(1,2,3);
  objD.display();
  return 0;
}
