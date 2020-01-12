/*
Program to demonstarte :
1) Access Specifiers
2) friend functions
3) Destructor
4) Scope Resolution

Refer :
1) Access Specifiers.txt
2) friend functions.txt
3) Destructor.txt
4) Scope Resolution.txt

See : life of object.png
*/
#include<iostream>
using namespace std;

class Myclass
{
private:
  int x;
  int y;
public:
  //a non member function declared as a friend
  friend void fx();

  //members of the class
  Myclass();
  Myclass(int,int);
  ~Myclass();
  void display();
};

//member defined outside the class
Myclass :: ~Myclass()
{
  cout<<"\n Destructor";
}

//member defined outside the class
Myclass :: Myclass()
{
  cout<<"\n Myclass()";
  x = 10;//preset data
  y = 20;
}

//member defined outside the class
Myclass :: Myclass(int a, int b)//parameterized constructor
{
  cout<<"\n Myclass(int,int)";
  x = a;//parameter data
  y = b;
}

//member function defined outside class
void Myclass :: display()
{
  cout<<"\n"<<x<<" "<<y;
}

//non member function
void fx()
{
  Myclass m2;
  m2.x++;//can access private members because it is declared as a friend function
  m2.y++;
  m2.display();
}

//non member function
int main()
{

  Myclass m(11,22);
  //m.x= 99;//cannot access as x is private member and main is not a friend function

  cout<<"\n------fx---------";
  fx();
  cout<<"\n------fx---------";

  m.display();//public members of class are accessible to non member functions

  return 0;
}
