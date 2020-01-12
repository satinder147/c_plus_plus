/*
Program to demonstrate :
Dynamic Object Creation and Use

Refer : operator new and delete.txt
See : DynObjectAllocDealloc.png
*/

#include<iostream>
using namespace std;

class Myclass
{
private:
  int x, y;
public:
  Myclass();
  void display();
  void increment();
  ~Myclass();
};

Myclass :: Myclass()
{
  cout<<"\n Myclass()";
  x = 1;
  y = 2;
}

void Myclass ::display()
{
    cout<<"\n"<<x<<" "<<y;
}

void Myclass ::increment()
{
  x++;
  y++;
}

Myclass :: ~Myclass()
{
    cout<<"\n ~Myclass()";
}


void fx(Myclass *p)
{
  cout<<"\n in fx(), object is at location : "<<p;
  p->increment();
}

int main()
{
  cout<<"\n-----------------------";
  Myclass *ptr = new Myclass();
  cout<<"\n-----------------------";
  (*ptr).display();

  cout<<"\n====================";
  fx(ptr);//demonstrate use in other functions
  cout<<"\n====================";

  ptr->display();

  cout<<"\n_________________";
  delete ptr;//deallocation
  cout<<"\n_________________";

  return 0;
}
