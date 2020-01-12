#include<bits/stdc++.h>
using namespace std;

void re(int a)
{
if(a>1)
re(a/2);
cout<<a%2;
}

void bin(int n)
{
    if (n > 1)
    bin(n>>1);

cout<<(n&1);}

int main()


{
int n=10;
bin(7);
/*
re(24);

int n=25;
int i=0;
while(n!=0)
{
n=n/2;
i++;
}
int a[i];
cout<<i<<endl;
n=24;
int k=0;
while(n!=0)
{
a[k]=n%2;
n=n/2;
k++;
}

for(int k=i-1;k>=0;k--)
cout<<a[k];

return 0;
*/
}
