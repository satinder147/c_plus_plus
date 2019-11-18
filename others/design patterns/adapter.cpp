#include<iostream>
using namespace std;
class subject
{
    public:
    virtual void func1()=0;
    virtual void func2()=0;
};
class adaptee
{
    public:
    void method1()
    {
        cout<<"method1"<<endl;
    }
    void method2()
    {
        cout<<"method2"<<endl;
    }
};
class client: public subject
{
    public:
    void func1()
    {
        cout<<"func1"<<endl;
    }
    void func2()
    {
        cout<<"func2"<<endl;
    }
};

class adapter:public subject
{
    adaptee *obj;
    public:
    adapter(adaptee *o)
    {
        obj=o;
    }
    void func1()
    {
        obj->method1();
    }
    void func2()
    {
        obj->method2();
    }
};

class adapter2:public client,public adaptee
{
    public:
    void func1()
    {
        method1();
    }
    void func2()
    {
        method2();
    }

};
int main()
{
    /*
    adaptee *a=new adaptee();
    client *o1=new client();
    adapter *o2=new adapter(a);
    o1->func1();
    o1->func2();
    o2->func1();
    o2->func2();
    */
   adapter2 *o=new adapter2();
   o->func1();
   o->func2();


    return 0;
}