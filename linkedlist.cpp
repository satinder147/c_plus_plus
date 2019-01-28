#include<iostream>
using namespace std;
class node
{
public:
int data;
node *next;
node()
{
next=NULL;
}
node* create(node *head);
void display(node *head);
node* del(node *head,int x);
void delet(node *head);
void len(node *head);
int lenr(node *head);
bool searc(node* head,int x);
int nth(node *head,int x);
int mid(node *head);
};

node *node::del(node *head,int x)
{

if(head->data=x)
{
head=head->next;
}

else
{
node *ne=head->next;
node *pr=head;
while(ne)
{
if(ne->data==x)
{
pr->next=ne->next;
}
ne=ne->next;
pr=pr->next;

}
}
return head;

}
node * node::create(node *head)
{
int n;
cout<<"enter the number of elements"<<endl;
cin>>n;
node *tail=new node();
int e;

for(int i=0;i<n;i++)
{
cin>>e;
node *newnode=new node();
newnode->data=e;
newnode->next=NULL;
if(head==NULL)
{
head=newnode;
tail=newnode;
}
else{
tail->next=newnode;
tail=tail->next;

}
}
return head;
}

void node ::display(node *head)
{
while(head)
{
cout<<head->data<<" ";
head=head->next;

}
}

void node::delet(node *head)
{
node *nxt=new node();
while(head)
{
nxt=head->next;
delete head;
head=nxt;
}
}

void node::len(node *head)
{
int x=0;
while(head)
{
head=head->next;
x++;
}
cout<<"length of linked list is: "<<x;
}

int node::lenr(node *head)
{
if(head==NULL)
return 0;
else return (1+lenr(head->next));
}

bool node ::searc(node *head,int x)
{
if(head==NULL)
return false;
if(head->data==x)
return true;
else
return (searc(head->next,x));
}

int node:: nth(node *head,int x)
{
node* m=head;node* n=head;
for(int i=0;i<x;i++)
m=m->next;
while(m)
{
m=m->next;
n=n->next;
}
return n->data;
}

int node::mid(node *head)
{
node *f=head;
node *s=head;
while(f!=NULL && f->next!=NULL)
{
f=f->next;
f=f->next;
s=s->next;
}
return s->data;
}
int main()
{

node *head=NULL;
node a;
head=a.create(head);
a.display(head);
cout<<endl;
//cout<<a.nth(head,4);
//node at nth position from the end --> find length and then (length -n+1) is the position of the node.
//cout<<a.searc(head,2);
//cout<<endl;
//head=a.del(head,4);
//a.display(head);
//a.len(head);

//cout<<"**************"<<endl;
//cout<<a.lenr(head);
//a.delet(head);
cout<<a.mid(head); //logic is to make two pointers, every iteration move slow pointer by 1 step and the fast pointer by two steps;
//another method is to increment the head pointer only when a increment variable is even or odd.
//counting the occurence of a int in a linked list--> recursive-->keep a global variable and if(head==NULL)return frequency
//if(head-->data==x)freq++, else search(head->next,element);
//OR
//return 1+count(head->next,element), if(head==NULL) return 0;
return 0;
}
