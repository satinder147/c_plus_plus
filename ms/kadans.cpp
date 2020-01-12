#include<iostream>
using namespace std;
int main()
{
int n=8;
int a[n]={-1,-5,-7,-10,-6,-9,-10,-15};
int maxsofar=a[0];
int sumtillnow=0;
int st=0,en=0,s=0;
for(int i=0;i<n;i++)
{
sumtillnow+=a[i];
if(maxsofar<sumtillnow)
{
maxsofar=sumtillnow;
st=s;
en=i;
}
if(sumtillnow<0)
{sumtillnow=0;
s=i+1;}
}
cout<<st<<" "<<en;
//cout<<maxsofar;
return 0;
}
