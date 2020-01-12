//Program to demonstrate : template functions

#include <iostream>
#include<cstring>

using namespace std;

class Student
{
  int rno;
  char name[20];
public:
  Student();
  Student(int,char[]);

  //for > support
  bool operator >(Student & r);
  //for << support
  friend ostream & operator <<(ostream & out, Student & r);

};

Student :: Student()
{
  rno = 1;
  strcpy(name ,"anand");
}

Student :: Student(int r, char n[])
{
  rno = r;
  strcpy(name ,n );
}


bool Student :: operator >(Student & r)
{
    return rno > r.rno;
}

ostream & operator <<(ostream & out, Student & r)
{
  out<<"{ "<<r.rno<<", "<<r.name<<" }";
  return out;
}

template <class X> void bubbleSort( X arr[], int size)
{
  int i,j;//loop control
  X temp;
  for(i = size -1; i >0; i--)
  {
    for(j =0; j < i ; j++)
    {
      if(arr[j] > arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }//if
    }//for(j
  }//for(i
}//bubbleSort

template <class X> void display(X arr[], int size)
{
  int i;
  cout<<"\n";
  for(i =0; i < size; i++)
    cout<<arr[i]<<"  ";
}

int main()
{
    int iarr[] = {7,4, 12, 8, 1};
    char carr[] = {'a', 's', 'd', 'f', 'g', 'h'};
    double darr[] = {0.5, 0.4999, 0.501, 0.50099};
    Student sarr[] = { Student(9,"vikas"), Student(), Student(12, "anil")} ;

    display(iarr, 5);
    display(carr, 6);
    display(darr, 4);
    display(sarr, 3);


    bubbleSort(iarr, 5);
    bubbleSort(carr, 6);
    bubbleSort(darr, 4);
    bubbleSort(sarr, 3);


    display(iarr, 5);
    display(carr, 6);
    display(darr, 4);
    display(sarr, 3);

    return 0;
}
