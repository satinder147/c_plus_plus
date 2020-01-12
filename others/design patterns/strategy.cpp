#include<iostream>
using namespace std;
class flyBehavior
{
    public:
    virtual void flyy()=0;
};
class flying:public flyBehavior
{
    public:
    void flyy()
    {
        cout<<"I can fly"<<endl;
    }
};
class noFly:public flyBehavior
{
    public:
    void flyy()
    {
        cout<<"I can't fly"<<endl;
    }
};

class duck
{
    
    public:
    void quack()
    {
        cout<<"I can quack as all others can"<<endl;
    }
};
class type1:public duck
{
    flyBehavior *obj;
    public:
    type1()
    {
        obj=new flying();
    }
    void fly()
    {
        obj->flyy();
    }
};

class type2:public duck
{
    flyBehavior *obj;
    public:
    type2()
    {
        obj=new noFly();
    }
    void fly()
    {
        obj->flyy();
    }
};

int main()
{
    type1 *t1=new type1();
    type2 *t2=new type2();
    t1->quack();
    t1->fly();
    t2->quack();
    t2->fly();

    return 0;
}