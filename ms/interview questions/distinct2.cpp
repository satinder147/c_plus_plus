#include<iostream>
#include<map>
using namespace std;

void distinct(int a[],int k,int n)
{
int d=0;
map<int,int> hm;
for(int i=0;i<k;i++)
{
if(hm[a[i]]==0)
{
d++;
}
hm[a[i]]+=1;
}
cout<<d;

for(int i=k;i<n;i++)
{
if(hm[a[i-k]]==1)
{
d--;
}
hm[a[i-k]]--;

if(hm[a[i]]==0)
{
d++;
}
hm[a[i]]++;

cout<<" "<<d;
}

}
int main()
{
int a[10]={1,1,3,4,5,6,7,8,9,10};
distinct(a,4,10);
return 0;
}
