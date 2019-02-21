#include<iostream>
using namespace std;

void print(int n,int m,bool flag)
{

cout<<m<<" ";
if(n==m && flag==false)
return ;


if(flag)
{
if(m-5>0)
print(n,m-5,true);
else
print(n,m-5,false);
}
else
print(n,m+5,false);


}
int main()
{
print(16,16,true);
return 0;
}
