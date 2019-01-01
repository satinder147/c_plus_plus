//Studying namespaces
#include<iostream>
using namespace std;

namespace my
{
    int x = 10;
    void fx()
    {
        cout<<"\n fx of my ";
    }

    namespace nestedMy
    {
        int x = 100;
    }
}

int x = 1000;

void fx()
{
    cout<<"\n fx global ";
}

int main()
{
    int x = 10000;
    cout<<"\n local x : "<<x;
    cout<<"\n global  x : "<<::x;//belongs to the no name global namespace
    cout<<"\n nested my x : "<<my::nestedMy::x;
    cout<<"\n my x : "<<my::x;

    my::fx();
    ::fx();
    //fx(); //as above
    return 0;
}