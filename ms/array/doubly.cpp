#include<iostream>
using namespace std;

class node
{
public:
int data;
node *next;
node *prev;
node * create(node *head);
void print(node *head);
node * inser(node *head,int x,int e);
node *delet(node *head,int x);
node *revers(node *head);
};
node *node::revers(node *head)
{
node *temp;
node *cur=head;
while(cur!=NULL)
{
temp=cur->prev;
cur->prev=cur->next;
cur->next=temp;
cur=cur->prev;
}
head=temp->prev;
return head;

}

node *node::delet(node *head,int x)
{
int c=1;
node *cur=head;
while(c<x-1)
{
cur=cur->next;
c++;
}
cout<<cur->data<<endl;
node *nex=cur->next->next;

cur->next=nex;
nex->prev=cur;
while(head->next)
head=head->next;
return head;

}
//node *head=NULL
node * node::create(node *head)
{
cout<<"enter nymber of elements"<<endl;
int n,x;
node *tail;
cin>>n;

// *head = &head
for(int i=0;i<n;i++)
{
cin>>x;
node *newnode=new node();
newnode->data=x;
newnode->next=NULL;
newnode->prev=NULL;

if(head==NULL)
{
head=newnode;
tail=newnode;
tail->prev=NULL;
}
else
{
tail->next=newnode;
newnode->prev=tail;
tail=tail->next;
}
}
return head;
}
void node::print(node *head)
{
node *head2=head;
while(head2)
{
cout<<head2->data<<" ";
head2=head2->next;

}
}

node * node::inser(node *head,int x,int e)
{
node *cur=head;
int c=1;
while(c<x-1)
{
cur=cur->next;
c++;
}
node *newnode=new node();
newnode->data=e;
node *a=cur->next;
newnode->next=cur->next;
cur->next=newnode;
newnode->prev=cur;
a->prev=newnode;
while(head->next)
head=head->next;
return head;
}
int main()
{
node a;
node *head=NULL;
cout<<head;
head=a.create(head);
a.print(head);
head=a.revers(head);
//head=a.delet(head,3);
//head=a.inser(head,3,9);
cout<<endl;
a.print(head);
return 0;
}
