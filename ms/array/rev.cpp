#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
void revers(node *head);
node *reve(node *head,int x);

};

node *node ::create(node *head)
{
int n,x;
node *tail;
cout<<"enter the number of elements"<<endl;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>x;
node *newnode=new node();
newnode->data=x;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
tail=newnode;
}
else
{
tail->next=newnode;
tail=tail->next;
}
}
return head;
}
void node::print(node *head)
{
while(head)
{
cout<<head->data<<" ";
head=head->next;
}
}
void node::revers(node *head)
{
if(head==NULL)
return ;
revers(head->next);
cout<<head->data<<" ";
}

node *node::reve(node *head,int x)
{
node *cur,*nex,*prev;
prev=NULL;
cur=head;
int i=0;
while(cur!=NULL and i<x)
{
nex=cur->next;
cur->next=prev;
prev=cur;
cur=nex;
i++;
}



if(nex!=NULL)
head->next=reve(nex,3);
return prev;
}
int main()
{
node a;
node *head=NULL;
head=a.create(head);
//a.print(head);
//a.revers(head);
head=a.reve(head,3);// This can be achieved by using a stack. Push first 3 nodes in a stack. Pop them and make a list. then push the next 3 elements.
a.print(head);
return 0;
}
