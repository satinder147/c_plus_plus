
#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
node *divide(node *head);
void print2(node *head);
node *push(node *head,int data);
node *rev(node *head);
node *deletr(node *head);
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
node *node ::push(node *head,int data)
{
node *newnode=new node();
newnode->data=data;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
}
else
{
node *temp=head;
while(temp->next!=NULL)
{
temp=temp->next;
}
temp->next=newnode;
}
return head;
}



node * node::divide(node *head)
{
node *cur=head;
while(cur->next!=NULL && cur->next->next!=NULL)
{
cur->next=cur->next->next;
cur=cur->next;
}
cur->next=NULL;
return head;
}

void node::print2(node *head)
{
node a;
node *one=NULL;
node *two=NULL;
while(head &&head->next)
{
one=a.push(one,head->data);
head=head->next;
two=a.push(two,head->data);
head=head->next;
}
one=a.push(one,head->data);
a.print(one);
cout<<endl;
a.print(two);
}

node *node:: rev(node *head)
{
node *prev,*cur,*nex;
prev=NULL;
cur=head;
while(cur)
{
nex=cur->next;
cur->next=prev;
prev=cur;
cur=nex;
}
return prev;
}
node *node::deletr(node *head)
{
node *head2=head;
int m=head->data;
while(head)
{
if((head->data)>m)
m=head->data;
if(head->next)
{
if((head->next->data)<m)
{
head->next=head->next->next;
}
}
head=head->next;
}
return head2;
}


int main()
{
node a;
node *head=NULL;
head=a.create(head);
a.print(head);
cout<<endl;
head=a.rev(head);
head=a.deletr(head);
head=a.rev(head);
a.print(head);
//head=a.divide(head);
//sa.print(head);
//a.print2(head);
return 0;
}
