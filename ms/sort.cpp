#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node *create(node *head);
void print(node *head);
node * sortt(node *head);
};
node * node ::sortt(node *head)
{
node *ptr1=head;
node *ptr2;
node *ptr3;
while(ptr1)
{
ptr2=head;
while(ptr2 && ptr2->next)
{
if(ptr2->data>ptr2->next->data)
{
//int temp=ptr2->data;
//ptr2->data=ptr2->next->data;
//ptr2->next->data=temp;
ptr3=head;
while(ptr3->next!=ptr2)
ptr3=ptr3->next;

ptr3->next=ptr2->next;
ptr2->next=ptr2->next->next;
ptr3->next->next=ptr2;
}
ptr2=ptr2->next;
}
ptr1=ptr1->next;

}
return head;
}
node *node ::create(node *head)
{
node *tail=new node();
cout<<"enter the number of elements"<<endl;
int n;
int x;
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
int main()
{
node *head=NULL;
node a;
head=a.create(head);
a.print(head);
cout<<endl;
head=a.sortt(head);
a.print(head);
return 0;
}


//in conclusion is can be said that sorting can be done by sorting the data itself.
// but data can contain many fields which can create an overhead and it is efficient to traverse the linked list instead of
//swapping so much data. SO we swap the links.
