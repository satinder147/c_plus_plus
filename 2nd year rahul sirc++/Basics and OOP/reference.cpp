/*
Study of Pass By Value and Pass By Reference
Refer : reference.txt
Refer : reference.png

*/

#include <iostream>
using namespace std;

void fx(int y)
{
    cout<<"\n in fx, y : "<<y<<" ( "<<&y<<" ) ";
    y++;
    cout<<"\n in fx, y : "<<y<<" ( "<<&y<<" ) ";
}

void rx(int &q)
{
    cout<<"\n in rx, q : "<<q<<" ( "<<&q<<" ) ";
    q++;
    cout<<"\n in rx, q : "<<q<<" ( "<<&q<<" ) ";
}

int main()
{
    int x;
    x = 10;
    cout<<"\n in main, x : "<<x<<" ( "<<&x<<" ) ";
    fx(x); //pass by value
    cout<<"\n in main, x : "<<x<<" ( "<<&x<<" ) ";
    rx(x); //pass by reference
    cout<<"\n in main, x : "<<x<<" ( "<<&x<<" ) ";

    int x1 = 100;
    rx(x1);
    //stand alone reference
    int &w = x;
    w = 99;
    cout<<"\n in main, x : "<<x<<" ( "<<&x<<" ) ";

    ostream &vout = cout;
    vout<<"\n References";
    return 0;
}
