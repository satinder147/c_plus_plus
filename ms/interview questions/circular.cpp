#include<iostream>
using namespace std;

class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
bool check(node *head);
};
node *node ::create(node *head)
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
tail->next=head;
return head;
}

void node::print(node *head)
{
node *cur=head;
do
{
cout<<head->data;
head=head->next;
}while(head!=cur);
}

bool node::check(node *head)
{
node *cur=head;
do
{
cur=cur->next;
if(cur==head)
return true;
}while(cur);
return false;
}
int main()

{
node a ;
node *head=NULL;
head=a.create(head);
a.print(head);
cout<<'\n';
cout<<a.check(head);
return 0;
}
