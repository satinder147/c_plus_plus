//Program to study unit increment 
//see UnitIncrement.png

#include<stdio.h>//to get the definition of printf and many other functions

int main()//program begins here
{
    int x, y, z;
    
    x = 10;//assignment
    y = 15;//assignment
    
    z = ++x * y++;
    
    printf("\n x: %d ", x);//11
    printf("\n y : %d ", y);//16
    printf("\n z : %d ", z);//165
    return 0;//status representing successful completion
}

