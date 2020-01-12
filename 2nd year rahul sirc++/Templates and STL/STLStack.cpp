//Program to implement : Template Stack

#include<iostream>
#include<stack>

using namespace std;

template <class X> void menu(X dummy)
{
    dummy = dummy;
    //stack <int>s1;
    //stack <double> s2;
    //stack <Student> s3;

    stack <X> s; //object of generic class
    X val;
    int ch;

    do
    {
        cout<<"\n 1. push";
        cout<<"\n 2. pop";
        cout<<"\n 3. exit";
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
                if(! s.empty())
                {
                    val = s.top();//get the topmost value
                    cout<<"\n"<<val<<" removed ";
                    s.pop();//remove the topmost element
                }
                else
                    cout<<"\n Stack Underflow";

                break;
            case 3:
                break;
            default:
                cout<<"\n wrong choice ";
                break;
        }

    }while(ch != 3);
}

int main()
{
    int a;
    char b;
    double c;
    int ch;

    cout<<"\n 1. int stack ";
    cout<<"\n 2. char stack ";
    cout<<"\n 3. double stack ";
    cout<<"\n enter choice ";
    cin>> ch;

    if(ch == 1)
        menu(a);
    else if(ch == 2)
        menu(b);
    else if(ch == 3)
        menu(c);
    else
        cout<<"\n Wrong choice ";

    return 0;
}
