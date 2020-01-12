
#include<iostream>
#include<vector>
using namespace std;
class observer;
class subject
{
    public:
    virtual void reg(observer *o)=0;
    virtual void unreg(observer *o)=0;
    virtual void notify()=0;
};
class observer
{
    public:
    virtual void update(int a,int b)=0;
    virtual int getId()=0;
};
class client;
class graber:public subject
{
    int a,b;
    vector<observer *> vec;

    public:
    void reg(observer *o)
    {
        vec.push_back(o);
    }
    void unreg(observer *o)
    {
        vector<observer *>:: iterator l;
        for(l=vec.begin();l!=vec.end();l++)
        {
            if(o->getId()==(*l)->getId())
            {
                vec.erase(l);
                break;
            }
                
        }
    }
    void notify()
    {
        for(int i=0;i<vec.size();i++)
        {
            vec[i]->update(a,b);
        }
    }
    void setA(int a)
    {
        this->a=a;
        notify();
    }
    void setB(int b)
    {
        this->b=b;
        notify();
    }
};
class client:public observer
{
    int a,b;
    static int id_tracker;
    int id;
    subject *obj;
    public:
    int getId()
    {
        return id;
    }
    client(subject *o)
    {
        obj=o;
        id=id_tracker;
        id_tracker++;
        o->reg(this);
        
    }
    void update(int a,int b)
    {
        this->a=a;
        this->b=b;
        print();
    }
    void print()
    {
        cout<<id<<" "<<"A "<<a<<" B "<<b<<endl;
    }
};
int client::id_tracker=0;

int main()
{
    graber *obj=new graber();
    client *c1=new client(obj);
    obj->setA(4);
    obj->setB(5);
    cout<<"hell"<<endl;
    client *c2=new client(obj);
    obj->setA(5);
    obj->setB(6);

    obj->unreg(c1);
    cout<<"------------"<<endl;
    obj->setA(-1);
    obj->setB(-1);



    return 0;
}


