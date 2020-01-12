#include<iostream>
using namespace std;
int main()
{

int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
//cout<<a[8]<<endl;
bool flag=true;
for(int i=0;i<3;i++)
{
if(flag)
{
for(int j=0;j<3;j++)
{
cout<<a[i][j]<<" ";
}
}
else
{
for(int j=2;j>-1;j--)
{
cout<<a[i][j]<<" ";
}
}
flag=!flag;
cout<<endl;
}
return 0;
}
