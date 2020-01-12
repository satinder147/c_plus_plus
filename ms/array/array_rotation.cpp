#include<iostream>
using namespace std;
void rotat(int a[],int n,int d)
{
while(d)
{
int temp=a[0];
int i;
for( i=0;i<n-1;i++)
{
a[i]=a[i+1];
}
a[i]=temp;

d--;
}
}
int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
rotat(a,10,2);
for(int i=0;i<10;i++)
cout<<a[i]<<" ";
return 0;
}
