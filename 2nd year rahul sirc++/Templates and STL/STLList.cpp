#include<iostream>
#include<list>//from stl library
using namespace std;

//STL : List 

class MyList
{
    list <int> l;
    
public:
    void create();
    void insertNode();
    void deleteNode();
    void display();
};


void MyList :: create()
{
    char ch;
    int val;
    
    do
    {
        cout<<"\n Enter data to add in the list ";
        cin >> val;
        l.push_back(val);//append a node

        //cycle
        cout<<"\n Add More Nodes : ";
        cin>>ch;
    }while(ch == 'y' || ch == 'Y');
}

void MyList :: insertNode()
{
    int pos;
    cout<<"\n Enter position of the new node ";
    cin>>pos;
    
    if(pos < 1  || pos > (l.size() +1))
    {
        cout<<"\n Invalid Position ";
        return; //terminate the fn
    }
    
    //we have a valid position
    int val;
    cout<<"\n Enter val for new node ";
    cin>>val;
    
    if(pos == 1)
    {
        l.push_front(val);//adds a new node at head position
    }
    else
    {
        list <int>:: iterator itr;
        int i;
        
        itr = l.begin();//at head
        for(i = 1; i< pos; i++)
            itr++;
        
        l.insert(itr, val);
    }
}

void MyList :: deleteNode()
{
    int pos;
    cout<<"\n Enter position of the node to delete ";
    cin>>pos;
    
    if(pos < 1  || pos > l.size() )
    {
        cout<<"\n Invalid Position ";
        return; //terminate the fn
    }
    
    //we have a valid position

    if(pos == 1)
    {
        l.pop_front();//deletes at head position
    }
    else
    {
        list <int>:: iterator itr;
        int i;
        
        itr = l.begin();//at head
        for(i = 1; i< pos; i++)
            itr++;
        
        l.erase(itr);
    }

}

void MyList :: display()
{
    //a pointer to the list (iterator)
    list<int> ::iterator itr;
    
    itr = l.begin(); //point to the head node
    
    cout<<"\n";
    while(itr != l.end() )
    {
        cout<<*itr<<" ";
        itr++;//traverse to next node
    }
}//display

int main()
{   
    MyList ml;
    int ch, flag;
    flag =1 ;
    do
    {
        cout<<"\n 1. create list ";
        cout<<"\n 2. insert node ";
        cout<<"\n 3. delete node ";
        cout<<"\n 4. display list ";
        cout<<"\n 5. exit";
        cout<<"\n enter choice ";
        cin>>ch;
        
        switch(ch)
        {
            case 1:
                ml.create();
                break;
            case 2:
                ml.insertNode();
                break;
            case 3:
                ml.deleteNode();
                break;
            case 4:
                ml.display();
                break;
            case 5:
                flag =0 ;
                break;
            default:
                cout<<"\n Wrong Choice ";
                break;
        }//switch
    }while(flag == 1);
    return 0;
}
