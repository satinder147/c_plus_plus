#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;

node *create(node *head);
void print(node *head);
node *rever(node *head);
void printr(node *head);
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

void node::printr(node *head)
{
if(head==NULL)
return ;
printr(head->next);
cout<<head->data;
}

node *node ::rever(node *head)
{
node *prev,*cur,*nex;
cur=head;
prev=NULL;
while(cur!=NULL)
{
nex=cur->next;
cur->next=prev;
prev=cur;
cur=nex;
}
head=prev;

return head;
}
int main()

{
node *head=NULL;
node a;
head=a.create(head);
a.print(head);
cout<<endl;
//a.printr(head);
//head=a.rever(head);
//a.print(head);
return 0;
}
//reverse a linked list in groups of given size.

