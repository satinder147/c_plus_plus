#include<iostream>
using namespace std;
class singleton
{
    static singleton *instance;
    int data;
    public:
    singleton()
    {
        data=0;
    }
    void getData()
    {
        cout<<data<<endl;
    }
    void increment()
    {
        data++;
    }
    static singleton *getInstance()
    {
        if(instance==NULL)
        {
            instance=new singleton();
        }
        return instance;
    }
};
singleton *singleton::instance=NULL;
int main()
{
    singleton *obj=singleton::getInstance();
    obj->getData();
    obj->increment();
    singleton *obj2=singleton::getInstance();
    obj2->getData();

    return 0;
}