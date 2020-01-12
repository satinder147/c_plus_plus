#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
};

node *node::create(node *head)
{
cout<<"enter the number of elements"<<endl;
int n,x;
cin>>n;
node *tail;
for(int i=0;i<n;i++)
{
cin>>x;
node *newnode=new node();
newnode->data=x;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
if((newnode->data)<(head->data))
{
newnode->next=head;
head=newnode;
}
else
{
node *temp=head;
while(temp->next && temp->next->data<=newnode->data)
{
temp=temp->next;
}
newnode->next=temp->next;
temp->next=newnode;
}
}
}

return head;
}
void node::print(node *head)
{
node *cur=head;
while(cur)
{
cout<<cur->data<<" ";
cur=cur->next;
}
}
int main()

{
node a;
node *head=NULL;
head=a.create(head);
a.print(head);
return 0;
}
