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


//*************************************************************************//
//finding loops in a linked list
//one way is to keep all the pointers in a hashmap and check if the the value for the key is empty or not. If not then there is a loop

// Another way is to keep a data member "visited" and when a new node is made we can make this variable true. So if there is a variable with "visited" already true this means there is a loop

// The best way is to use the floyd cycle finding algorithm
// the algorithm consists of 2 pointers a fast and a slow pointer.
//Slow pointer moves by 1 step and fast pointer moves by 2 steps. if they meet each other before anyone of them becomes null means there is a loop
// At this point keep the fast pointer where it and take back the slow pointer to the beginning. Now move both the pointers by 1
// step. Where these both will meet will the point where the lopp starts. Now keep 1 pointer at this point and move the other pointer
// unitil the next of it is not equal to the static node. Where this condition is satisfied stop make the next of this node as nulll.
//This is implemeted in floyd.cpp


return 0;
}


//to check whether a given singly list is a palindrome or not.
//1) push the elements in the stack. Pop the elements and compare with the linked list.
//2) reverse the lis from the mid position. and compare the alements from beginning and after mid using 2 pointers
//3) use a circular linked list and bring 1 pointer backwards and other towards end . compare the corresponding elmeents
//4)One more recursive technique on gfg


//removing duplicate elements from a sorted list
// check the consecutive elements. If same delete the next element other wise just iterate forwards

//removing duplicates from a unsorted list     refer sorting.cpp for this
//sort and then delete  --> try after coming
//use 2 loops
// use hashing


//Moving last element to front of linked list. Refer to swapper.cpp

//Segregating odd and even elements in the linked list
//move all the odd elements to the end of the list.
//loop till you reach the first odd


//reversring linked list refer reverse.cpp
