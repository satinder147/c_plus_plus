//Demonstration of 2 possible usages of operator ++

#include<iostream>
using namespace std;

int main()
{
    int x, y;
    int z;

    x = y = 10;

    z = x++; //increment operand and return the original value
    cout<<"\n"<<x<<" "<<z;//11 10

    z = ++y;//increment operand and return the updated value
    cout<<"\n"<<y<<" "<<z;//11 11
    return 0;
}
