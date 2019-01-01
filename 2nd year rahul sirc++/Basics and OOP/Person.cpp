/*
Program to Study Object Creation Proces
Refer: Note Below
See: Person.png
*/

#include<iostream>
#include<string.h>
using namespace std;

class Person
{
public:// discuss later
    int age;
    char name[20];


    Person()//default constructor
    {
        cout<<"\n Person()";
        age = 0;//preset value
        strcpy(name, "baby");//preset value
    }
    
    Person(int q, char w[])//parameterized constructor
    {
        cout<<"\n Person(int, char[])";
        age = q;//param value
        strcpy(name, w);//param value
    }

    void display()
    {
        cout<<"\n [ "<<name<<", "<<age<< " ]";
    }
};

int main()
{
    Person p;//object
    Person p1(10, "Anil");//object

    p.display();
    p1.display();
    return 0;
}


/*
Object Creation Process

Object creation is a two step process.
1) Memory Allocation.
2) Execution of the Constructor.


Memory Allocation
-----------------------
In memory, an object is a composite block defined
by a collection of non static data members of
the class.

Constructor
--------------
Constructor is a special member function.
It takes :
 a) Same name as of the class.
 b) No return type specification.
It is automatically invoked to execute as object of the class is created.
It is used to initialize the object.

Note:
If a class doesnt define any constructor then
by compilation system defines a default parameterless
constructor with empty body. It aids object creation
only, doesnt initialize the object.
*/
