#include<iostream>
using namespace std;
class os
{
    public:
    virtual void tell()=0;
};
class android: public os
{
    public:
    void tell()
    {
       cout<<"android"<<endl;
    }
};
class windows: public os
{
    public:
    void tell()
    {
       cout<<"windows"<<endl;
    }
};
class mac: public os
{
    public:
    void tell()
    {
       cout<<"mac"<<endl;
    }
};

class factories
{
    public:
    virtual os *getInstance(int x)=0;
};
class factory:public factories
{

    public:
    os *getInstance(int x)
    {
        if(x==1)
            return new android();
        else if(x==2)
            return new windows();
        else
            return new mac();
    }
}; 
int main()
{
    factory *obj=new factory();
    obj->getInstance(1)->tell();
    obj->getInstance(2)->tell();
    obj->getInstance(7)->tell();
    return 0;
}