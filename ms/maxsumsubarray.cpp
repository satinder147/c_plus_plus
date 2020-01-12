#include<iostream>
using namespace std;
int main()

{
int n=8;
int a[n]={1,5,8,3,2,6,9,0};
for(int i=0;i<n;i++)
{
int sum=0;
for(int j=1;j<=n;j++)
{

if(i+j>n)
break;
sum=sum+a[i+j-1];

if(sum==16)
cout<<i<<" "<<j;
//cout<<sum<<endl;
}
}
return 0;
}
