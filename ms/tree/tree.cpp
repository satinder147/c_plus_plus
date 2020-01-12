#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

vector <int> cx;
class node
{
public:
int data;
node *left,*right;
node()
{
left=NULL;
right=NULL;
}
node *create(node *head,int x);
void inorder(node *head,int n);
void preorder(node *head);
void postorder(node *head);
void searc(node *head, int x);
node *delet(node *head, int x);
node *mi(node *head);
void stackprint(node *head);
int height(node *head);
node *build(int in[],int pr[],int st,int en);
void printi(node *head,int i);
//void printspiral(node *head,int i,int x);
void printspiral(node *head,int i,bool x);
void queuelevel(node *head);
bool printpath(node *head,int x);
};


void node::stackprint(node *head)
{
stack <node *> a;
node *cur=head;
while(cur!=NULL || a.empty()==false)
{
while(cur!=NULL)
{                          //read about how to use binary threaded tree for this traversal

a.push(cur);
cur=cur->left;
}
cur=a.top();
cout<<cur->data<<" ";
a.pop();
cur=cur->right;


}

}

int s(int a[],int s,int e,int x)
{
for(int i=s;i<=e;i++)
{
if(a[i]==x)
return i;
}
return -1;
}
node *node::build(int in[],int pr[],int st,int en)
{
node *x=NULL;
if(st>en)
    return x;

static int pre=0;
node *head=new node();
head->data=pr[pre++];

int i=s(in,st,en,head->data);
head->left=build(in,pr,st,i-1);
head->right=build(in,pr,i+1,en);
return head;
}
node *node::mi(node *head)
{

while(head->left!=NULL)
head=head->left;

return head;
}
node *node :: delet(node *head, int x)
{
if(head==NULL)
return head;
if(head->data<x)
head->right=delet(head->right,x);

else if(head->data>x)
head->left=delet(head->left,x);

else{
if(head->right==NULL)
return head->left;
else if(head->left==NULL)
return head->right;

node *temp=mi(head->right);
head->data=temp->data;

head->right=delet(head->right,temp->data);



}
return head;
}
node *node::create(node *head,int x)
{

node *newnode=new node();
newnode->left=newnode->right=NULL;
newnode->data=x;


if(head==NULL)
{
head=newnode;
}

else
{
if(newnode->data>head->data)
head->right=create(head->right,x);
else
head->left=create(head->left,x);
}



return head;
}

void node::inorder(node *head,int n)
{
if(head!=NULL)
{
static int c=0;
inorder(head->left,n);
//cout<<head->data<<" ";
c++;
if(c==n)
cout<<head->data;
inorder(head->right,n);
}
}

void node::preorder(node *head)
{
if(head!=NULL)
{

cout<<head->data<<" ";
preorder(head->left);
preorder(head->right);
}
}
int node :: height(node *head)
{
if(head==NULL)
return 0;

int l=height(head->left);
int r=height(head->right);
return max(l,r)+1;
}
void node::postorder(node *head)
{
if(head!=NULL)
{
postorder(head->left);
postorder(head->right);
cout<<head->data<<" ";
}
}


void node::printi(node *head,int i)
{
if(head==NULL)
return;
if(i==1)
cout<<head->data<<" ";
if(i>1)
{
printi(head->left,i-1);
printi(head->right,i-1);
}
}
void  node::searc(node *head,int x)
{

if(head==NULL)
return ;
if(head->data==x)
{
cout<<"node found"<<endl;
return ;
}
else if(x<head->data)
searc(head->left,x);
else
searc(head->right,x);
}

void node::printspiral(node *head,int i,bool x)
{
if(head==NULL)
return ;
if(i==1)
cout<<head->data;
if(i>1)
{
if(x)
{
printspiral(head->left,i-1,x);
printspiral(head->right,i-1,x);
}
else
{
printspiral(head->right,i-1,x);
printspiral(head->left,i-1,x);
}
}

}

bool node::printpath(node *head,int x)
{

if(head==NULL)
return false;

cx.push_back(head->data);

if(head->data==x)
return true;

if(printpath(head->left,x)||printpath(head->right,x))
return true;
cx.pop_back();
return false;

}
void node::queuelevel(node *head)
{
if(head==NULL)
return ;
queue <node *> q;
q.push(head);
while(!q.empty())
{
int data=q.front()->data;
cout<<data<<" ";
if(q.front()->left !=NULL)
q.push(q.front()->left);
if(q.front()->right!=NULL)
q.push(q.front()->right);
q.pop();

}
}
int main()
{
node a;
node *head=NULL;
head=a.create(head,5);
head=a.create(head,4);
head=a.create(head,8);
head=a.create(head,3);
head=a.create(head,9);
head=a.create(head,7);
head=a.create(head,6);

//a.inorder()
//head=a.create(head,5);
//cout<<a.height(head);

int h=a.height(head);
/*
for(int i=1;i<=h;i++)  // level order traversal
{a.printi(head,i);
cout<<endl;}

*/

/*
bool x=false;
for(int i=1;i<=h;i++)
{
a.printspiral(head,i,x);  //spiral level order
cout<<endl;
x=!x;
}

*/
//a.queuelevel(head);


a.printpath(head,7);
for(int i=0;i<cx.size();i++)
cout<<" "<<cx[i];

//inorder, postorder, preorder are types of depth first traversals and
//one depth first traversal and their time complexities are o(n)
/*
Extra Space required for Level Order Traversal is O(w) where w is maximum width of Binary Tree.
In level order traversal, queue one by one stores nodes of different level.
Extra Space required for Depth First Traversals is O(h) where h is maximum height of Binary Tree.
In Depth First Traversals, stack (or function call stack) stores all ancestors of a node.
*/
cout<<endl;
//a.searc(head,5);
//a.delet(head,5);
cout<<endl;
//a.stackprint(head);
int in[6]={4,2,5,1,6,3};
int pr[6]={1,2,4,5,3,6};

//node *head1=a.build(in,pr,0,5);
//to check whether a tree is a bst or not we do inorder traversal and check if the inorder traversal is sorted or not
//We can avoid the use of Auxiliary Array. While doing In-Order traversal,
// we can keep track of previously visited node. If the value of the currently visited node
//nn is less than the previous value, then tree is not BST. Thanks to ygos for this space optimization.
//a.inorder(head1);
}
