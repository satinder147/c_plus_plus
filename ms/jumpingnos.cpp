#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
cout<<(n&1);

//for making a que from stacks

/*for enque push in stack 1
for deque
if stack 2 is empty transfer everything to stack2
and and then pop

otherwise if stack 2 is not empty then pop from stack 2





push(s, x) // x is the element to be pushed and s is stack
  1) Enqueue x to q2
  2) One by one dequeue everything from q1 and enqueue to q2. till one element is left
  3) Swap the names of q1 and q2
// Swapping of names is done to avoid one more movement of all elements
// from q2 to q1.

pop(s)
  1) Dequeue an item from q1 and return it.
/*
while(n>0)
{
int cur=n%10;
n=n/10;
int cu=n%10;
if(n!=0)
{
if(abs(cu-cur)!=1)
{
cout<<n<<endl;
cout<<"not jumping"<<endl;
break;
exit(0);
}
}


}

*/
return 0;
}
