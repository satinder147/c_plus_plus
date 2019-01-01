//Study of void pointers
/*
void pointers
--------------
A void pointer is a generic pointer.
It can be used to refer to a variable
or an array or any object of any
data type.

i.e. It provides generic referencing support.

But it cannot be directly :
1) dereferenced 
2) used in pointer arithmetic

Because for the above operations
data type of pointer plays an important
role.

As for the system the size of
void is unknown or zero for the
above operations there is no support
datatype wise.


Solution: 
If a void pointer is typecasted
into a pointer of a particular type
then it can be dereferenced and
used in arithmetic.

*/

#include<stdio.h>

int main()
{
    int i;
    char c;
    double d;
    
    void *vp;//a generic pointer
    
    i = 10;
    c = 'x';
    d = 1.2345;
    
    vp = &i;//refers to an int
    printf("\n i : %d ", *(int*)vp);
    
    vp = &c;//refers to a char
    printf("\n c : %c ", *(char*)vp);
    
    vp = &d;//refers to a double
    printf("\n d : %f ", *(double *)vp);
    
    return 0;
}
