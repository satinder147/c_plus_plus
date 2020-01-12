#include<iostream>
using namespace std;
int sum=0;
void r(int n)
{
if(n>1)
r(n/2);
cout<<n%2;
}

void i(int n)
{
cout<<(n>>1);
}
int main()

{
int n;
cin>>n;
i(n);
//r(n);
return 0;
}
