#include<iostream>
using namespace std;
int distinct(int a[],int n)
{
int c=0;
int j;
for(int i=0;i<n;i++)
{

for(j=0;j<i;j++)
{
if(a[i]==a[j])
break;
}
if(i==j)
c++;

}
return c;
}

int main()

{
int a[10]={1,2,3,1,5,6,7,8,9,10};
int n=10;


for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
cout<<distinct(a,4);
return 0;

}
