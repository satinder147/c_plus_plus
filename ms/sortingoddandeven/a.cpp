#include<iostream>
using namespace std;
int main()

{

int n;
cin>>n;
int i=1;
while((i*i)<=n)
i++;
cout<<i-1;
/*
int a[9]={1,2,3,4,5,6,8,10,12};
int l=0,r=8;

for(int i=0;i<9;i++)
cout<<a[i]<<" ";

cout<<endl;
while(l<r)
{
while(a[l]%2!=0)
{
l++;
}
while(a[r]%2==0)
{
r--;
}
if(l<r)
swap(a[l],a[r]);
}

for(int i=0;i<9;i++)
cout<<a[i]<<" ";
*/
return 0;

}
