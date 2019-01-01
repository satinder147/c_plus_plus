/*
Program to demonstrate :
Dynamic Object Creation and Use

See : ShallowCopy, DeepCopy, CopyConstructor.png
*/

#include<iostream>
using namespace std;

class DynArray
{
private:
  int *ptr;
  int size;
public:
  DynArray(int);
  DynArray(DynArray &);
  void display();
  void increment();
  ~DynArray();
};

DynArray :: DynArray(int s = 5)
{
    cout<<"\n DynArray(int)";
    size = s;
    ptr = new int[size]; //dynamic allocation for an array

    cout<<"\n Enter "<<size<<" numbers ";
    int i;
    for(i =0 ; i < size; i++)
      cin>>ptr[i];
}//DynArray(int)

DynArray :: DynArray(DynArray &ref)
{
    cout<<"\n DynArray(DynArray&)";
    size = ref.size;
    ptr = new int[size]; //dynamic allocation for an array

    int i;
    for(i =0 ; i < size; i++)
      ptr[i] = ref.ptr[i];
}//DynArray(DynArray &)

void DynArray :: display()
{
  cout<<"\n this : "<<this;
  cout<<"\n ptr : "<<ptr;
  cout<<"\n";
  int i;
  for(i =0; i < size; i++)
    cout<<ptr[i]<<"  ";

}

void DynArray :: increment()
{
  int i;
  for(i =0; i< size; i++)
    ptr[i]++;
}

DynArray :: ~DynArray()
{
  cout<<"\n ~DynArray()";
  cout<<"\n About to deallocate : "<<ptr;
  delete ptr;
}

void fx(DynArray obj)
{
  obj.display();
  obj.increment();
  obj.display();
}

int main()
{
  DynArray da;
  da.display();
  cout<<"\n--------------";
  fx(da);
  cout<<"\n--------------";
  da.display();
  return 0;
}
