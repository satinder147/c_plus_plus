#include<iostream>
#include<stdio.h>
using namespace std;

//program to implement : inline functions
//read the note below.
//see the diagram

class A
{
private :
    int x;
public:
    A()
    {
        cout<<"\n A()";
        x = 10;
    }
    
    inline void display();
};

void A:: display()
{
    cout<<"\n x :  "<<x;
}


int main()
{
    A objA;
    objA.display();
    return 0;
}

/*
 Inline Function
 
An inline function is a function for calls 
to which the compiler expands the definition 
at the place of call.   
 
This does expand the code size but marginally 
reduces execution time.

Syntax: 
C++ allows declaration of a function as 
inline, in 2 ways:
 * Declaring and defining the function in the class itself.
 * Applying inline keyword to the functions signature. 

Note: 
Declaring a function as inline is a request 
to the system to bring in the said behavior.
It may be granted or denied. 

If granted then calls to the function are 
replaced by the functions definition (Similar 
to a macro expansion).
 
If denied then the function calls behave 
like other normal function calls.
*/