#include <iostream>
#include<cstring>
#define SIZE 10
using namespace std;

template <class X> class Stack
{
  X data[SIZE];//generic data member
  int top;//non generic data member

public:
  //all methods be generic methods
  Stack();
  inline bool isEmpty();

  //inline
  bool isFull()
  {
      return top == SIZE -1;
  }

  void push(X);
  X pop();
  X peek();
  void display();
};

  template<class X>    Stack<X> :: Stack()
  {
    top = -1;
  }

  //inline
  template<class X> bool Stack<X>:: isEmpty()
  {
    return top == -1;
  }

  template <class X> void Stack<X> :: push(X val)//add a value at the top
  {
    if(! isFull())
    {
        top++;
        data[top] = val;
    }
    else
      cerr<<"\n Data Overflow";
  }

  template<class X> X Stack<X> :: pop()//remove the topmost value
  {
    static X temp;//by default garbage free
    X val = temp;//garbage free data assigned to val

    if(! isEmpty())
    {
        val = data[top];
        top--;
    }
    else
      cerr<<"\n Data not available ";
    return val;
  }

  template<class X> X Stack <X> :: peek()//fetch the topmost value
  {
    static X temp;//by default garbage free
    X val = temp;//garbage free data assigned to val

    if(! isEmpty())
        val = data[top];
    else
      cerr<<"\n Data not available ";
    return val;
  }

  template <class X> void Stack<X> :: display()
  {
    int i;
    for(i = top; i >=0; i--)
      cout<<"\n "<<data[i];
  }


template<class X> menu(X param)
{
  param = param;//to remove the warning : param is never used
  //Stack<int>s1;
  //Stack<char>s2;
  //Stack<double>s3;

  Stack <X> s;
  X val;
  int ch;
  do
  {
      cout<<"\n 1. push";
      cout<<"\n 2. pop";
      cout<<"\n 3. peek";
      cout<<"\n 4. display";
      cout<<"\n 5. exit";

      cout<<"\n enter choice ";
      cin>>ch;

      switch(ch)
      {
          case 1:
                cout<<"\n enter val to push ";
                cin>>val;
                s.push(val);
                break;
            case 2:
                val = s.pop();
                cout<<val<< " removed  ";
                break;
            case 3:
                val = s.peek();
                cout<<val<< " at the top of stack";
                break;
            case 4:
                s.display();
                break;
            case 5:
                break;
            default:
                cout<<"\n wrong choice ";
                break;
        }

    }while(ch != 5);

}

int main()
{
    int i;
    char c;
    double d;

    int ch;
    cout<<"\n 1. int stack ";
    cout<<"\n 2. char stack ";
    cout<<"\n 3. double stack ";
    cout<<"\n Enter choice : ";
    cin>> ch;
    if(ch == 1)
      menu(i);
    else if(ch == 2)
        menu(c);
    else if(ch == 3)
      menu(d);
    else
      cout<<"\n Invalid Choice ";

    return 0;
}
