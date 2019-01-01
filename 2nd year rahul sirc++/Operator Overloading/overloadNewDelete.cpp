/*
Study of Operator Overloading
Overloading the new and delete operators

System provides operator new and delete
for dynamic memory allocation and deallocation.

The operators can be applied on primary and
secondary types.

Still the two can be overloaded for custom applications.

In case they are overloaded then they take up
following preset signatures.

operator new:
  void * operator new(size_t);
operator delete
  void operator delete(void *);

On dynamic object allocation and deallocation,
system automatically invokes the overloaded
definitions.
*/


#include<stdlib.h>
#include<iostream>

using namespace std;

class Myclass
{
  int x, y;
public:
  Myclass();
  void display();
  void operator delete(void *);
  void * operator new (size_t);

  ~Myclass();
};

Myclass :: Myclass()
{
  cout<<"\n Myclass() @ "<< this;
  x = 10;
  y = 20;
}

void Myclass :: display()
{
  cout<<"\n"<<x<<"  "<<y;
}

Myclass :: ~Myclass()
{
  cout<<"\n ~Myclass()";
}

void * Myclass ::operator new (size_t qty)
{
    cout<<"\n operator new, ";
    void * p;
    p = malloc(qty);
    cout<<" allocates the object at location "<<p;
    return p;
}

void Myclass :: operator delete(void *p)
{
  cout<<"\n operator delete, to deallocate : "<<p;
  free(p);
}

int main()
{
  Myclass *p ;//pointer of type Myclass
  p = new Myclass();//dynamic object allocation
  p->display();//usage
  delete p;//object deallocation
  return 0;
}
