#include<iostream>
using namespace std;
class welcome
{
    public:
    welcome()
    {
        cout<<"Welcome to SBI"<<endl;
    }
};
class passwordCheck
{
    int pass;
    public:
    passwordCheck()
    {
        pass=1234;
    }
    bool check(int c)
    {
        return c==pass;
    }
};
class withdrawl
{
    int amount;
    public:
    withdrawl()
    {
        amount=1000;
    }
    bool isPossible(int c)
    {
        return amount>=c;
    }
    void withdraw(int x)
    {
        if(isPossible(x))
            amount-=x;
        else
        {
            cout<<"Insufficent funds,unable to transcat"<<endl;
        }
        
    }
    void desposit(int x)
    {
        if(x>=0)
        amount+=x;
    }
    void showBalance()
    {
        cout<<"Balance is "<<amount<<endl;
    }
};

class exitt
{
    public:
    exitt()
    {
        cout<<"Have a good day"<<endl;
    }
};
class facade
{
    welcome *o1;
    passwordCheck *o2;
    withdrawl *o3;

    public:
    facade(welcome *a,passwordCheck *b,withdrawl *c)
    {
        o1=a,o2=b,o3=c;
    }
    void withdrawMoney()
    {
        cout<<"enter pass"<<endl;
        int y;
        cin>>y;
        if(o2->check(y))
        {
        cout<<"enter withdrawl amount"<<endl;
        int x;
        cin>>x;
        o3->withdraw(x);
        o3->showBalance();
        }
    }
    void deposit()
    {
        cout<<"enter pass"<<endl;
        int y;
        cin>>y;
        if(o2->check(y))
        {
        cout<<"enter deposit amount"<<endl;
        int x;
        cin>>x;
        o3->desposit(x);
        o3->showBalance();
        }
    }
    void passwordChange()
    {
            //other functions that can be implemented;
    }
    void mobileNoChange()
    {

    }
    
};
int main()
{
    
    welcome *o1=new welcome();
    passwordCheck *o2=new passwordCheck();
    withdrawl *o3=new withdrawl();
    facade *fi=new facade(o1,o2,o3);
    fi->withdrawMoney();
    fi->deposit();

     //I have to perform the below code every time. I can provide the user more abstract functionality using the facade class

    /*
    while(1)
    {
        cout<<"enter pass"<<endl;
        int y;
        cin>>y;
        if(o2->check(y))
        {
        cout<<"enter withdrawl amount"<<endl;
        int x;
        cin>>x;
        o3->withdraw(x);
        o3->showBalance();
        o3->desposit(100);
        o3->showBalance();
        }
        else
        {
            cout<<"incorrect password"<<endl;
        }
        
 
    }
    exitt *o4=new exitt();

*/

    return 0;
}