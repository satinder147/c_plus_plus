/*
Default Values To Arguments (Formal Parameters)

C++ allows application of default values to
formal parameters of a function.
By this the function may be invoked with
equal or less number of actual parameters.

When for a call, the number of actual and formal 
parameters match then the default values are not 
used.

But if the function is invoked with less number
of actual parameters then for the missing actual
parameters the formal parameters take the default
values.

TIP :
Default value should be such that doesnt affect
the result of the function, in case actual parameter
is missing.

RULE :
If a formal parameter is applied a default value
then all following formal parameters must also be 
applied default values.

*/

#include <iostream>
using namespace std;

int x= 0;
void add(int a, int b, int c=0, int d=x)
{
    int sum;
    sum = a + b +  c+ d;
    cout<<"\n Addition : "<<sum;
}//add

int main()
{
    add(1,2);//function call
    add(10,20,30);//function call
    add(11,22,33,44);//function call

    return 0;
}
