#include<iostream>
using namespace std;

class node
{
public:
int data;
node *next;

node()
{
next=NULL;
}
node *create(node *head);
node *print(node *head);
};

node* node::print(node *head)
{
while(head)
{
cout<<head->data;
cout<<" ";
head=head->next;
}
}
node* node::create(node *head)
{
cout<<"enter the number of elements you want to enter"<<endl;
int n;
cin>>n;
int e;
node *tail=new node();
for(int i=0;i<n;i++)
{
cin>>e;
node *newnode=new node();

newnode->data=e;
newnode->next=NULL;
if(head==NULL)
{

head=newnode;
tail=newnode;

cout<<"in head"<<endl;;
}
else
{
cout<<"in else"<<endl;;

tail->next=newnode;
tail=tail->next;
}
}
return head;
};

int main()
{
 node *head=NULL;
node b;
head=b.create(head);
b.print(head);
return 0;
}
