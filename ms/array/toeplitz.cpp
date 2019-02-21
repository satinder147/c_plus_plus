#include<iostream>
using namespace std;
int main()

{
int n,m;
n=3,m=4;
int a[n][m]={{1,2,3,4},{5,1,2,3},{9,5,1,2}};
for(int i=0;i<n;i++)
{
for(int j=0;j<m;j++)
{
if(i>0 && j>0 && a[i][j]!=a[i-1][j-1])
{
cout<<"not a teoplitz"<<endl;
break;

}
}

}

return 0;
}
