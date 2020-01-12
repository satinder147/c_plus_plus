#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
void printr(node *head);

node *rev(node *head);
};

node *node::rev(node *head)
{
node *prev,*cur,*nex;
prev=NULL;
cur=head;
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
node *node ::create(node *head)
{
node *tail;
cout<<"enter the number of elements"<<endl;
int n,x;
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
void node::printr(node *head)
{
if(head==NULL)
return ;
printr(head->next);
cout<<head->data<<" ";
}
void node::print(node *head)
{
while(head)
{
cout<<head->data<<" ";
head=head->next;
}
}
int main()
{
node *head=NULL;
node a;
head=a.create(head);
a.print(head);
cout<<endl;
//a.printr(head);
head=a.rev(head);
a.print(head);

return 0;
}
