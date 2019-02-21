#include<iostream>
using namespace std;

class node
{
public:
int data;
node * next;

node *create(node *head);
void print(node *head);
int floyd(node *head);
};

node * node::create(node * head)
{
int n;
cout<<"enter the number of elements you have "<<endl;
cin>>n;
int x;
node *tail=new node();
for(int i=0;i<n;i++)
{

cin>>x;
node * newnode=new node();
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
node *newhead=head->next->next;
node *mov=head;
while(mov->next!=NULL)
mov=mov->next;
mov->next=newhead;


return head;
}
int node:: floyd(node *head)
{
node *slow=head;
node *fast=head;
slow=slow->next;
fast=fast->next;
fast=fast->next;

while(slow!=fast)
{
slow=slow->next;
fast=fast->next;
fast=fast->next;
}
slow=head;
while(slow!=fast)
{
slow=slow->next;
fast=fast->next;
}
while(fast->next!=slow)
{
fast=fast->next;
}
fast->next=NULL;

return slow->data;
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
node *head;
head=NULL;
node a;
head=a.create(head);
int n=a.floyd(head);
cout<<"problem at "<<n<<endl;
a.print(head);
return 0;
}
