/*
Program to: 
* Demonstrate class, object and this pointer
* Implementing a Stack

Refer : Encapsulation, class, object and this.txt
See : Stack.png
*/

#include <iostream>
#define SIZE 5
using namespace std;

class Stack
{
public: //discuss later
    //data members
    int data[SIZE];
    int top;
    
    //functions
    void init() //void init(Stack *this)
    {
        top = -1; //this->top = -1;
    }
    
    void push(int val)//add a value
    {
        if(top == SIZE -1)
            cout<<"\n Stack Overflow, push failed";
        else
        {
            top++;//this->top++;
            data[top] = val;//this->data[this->top]= val;
        }
    }//push
    
    int pop()//remove a value from the stack
    {
        int x = 0;
        if(top == -1)
            cout<<"\n Stack Underflow, pop failed";
        else
        {
            x = data[top];
            data[top] = 0;//erase
            top--;
        }
        return x;
    }
    
    void display()
    {
        if(top == -1)
            cout<<"\n Stack is EMPTY";
        else
        {
            int i;
            for(i = top; i >-1; i--)
                cout<<"\n"<<data[i];
        }
    }//display
};//Stack

//non member function
int main()
{
    Stack s; //Instantiate Stack
    s.init();//init(&s);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    int q;
    q = s.pop();
    cout<<"\n"<<q<<" removed";

    return 0;
}
