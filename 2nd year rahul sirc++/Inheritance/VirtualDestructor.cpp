//Program to study : virtual destructor
//See : virtualDestructor.png
//Refer : Inheritance.txt

#include <iostream>
using namespace std;

class A
{
private:
  int x;
protected:
  int y;
public :
  int z;

  A();
  int getX();
  virtual void display();
  virtual ~A();
};
A :: A()
{
  cout<<"\n A()";
  x = 10;
  y = 20;
  z = 30;
}

int A :: getX()
{
  return x;
}

void A::display()
{
  cout<<"\n"<<x<<"  "<<y <<"  "<<z;
}

A:: ~A()
{
  cout<<"\n ~A()";
}

class B : public A
{
protected:
  int sum;
public:
  B();
  void display();
  ~B();
};

B :: B()
{
  cout<<"\n B()";
  sum = getX() +y+z;
}

void B ::display()
{
  cout<<"\n"<<getX()<<" + "<<y <<" + "<<z<<" = "<<sum;
}


B :: ~B()
{
  cout<<"\n ~B()";
}

int main()
{
  A *ptr = new B();
  ptr->display();
  delete ptr;
  return 0;
}
