#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
node *sw(node *head);
};
node *node::create(node *head)
{
int x,n;
cout<<"enter the number of elements "<<endl;
cin>>n;
node *tail;
for(int i=0;i<n;i++)
{
cin>>x;
node* newnode=new node();
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
node *node::sw(node *head)
{
node *prev=head;
node *cur=head->next;
while(cur->next!=NULL)
{
prev=prev->next;
cur=cur->next;
}
prev->next=NULL;
cur->next=head;
//cur->next=NULL;
head=cur;

return head;
}
int main()
{
node a;
node *head=NULL;
head=a.create(head);
a.print(head);
cout<<endl;
head=a.sw(head);
a.print(head);
return 0;
}
