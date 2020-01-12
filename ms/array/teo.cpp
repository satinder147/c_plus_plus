#include<iostream>
using namespace std;
int main()

{
int n;
cin>>n;
int a[n][n];
int f;
cin>>f;

int o=n-f+1;
int mat[o*o][n*n];


for(int i=0;i<o*o;i++)
{
for(int j=0;j<n*n;j++)
{
mat[i][j]=1;
}

}

for(int i=0;i<o*o;i++)
{
for(int j=0;j<n*n;j++)
{
if(j==0)
{
for(int k=0;k<i;k++)
{

mat[i][j]=0;
j++;
}
}
}
}

for(int i=0;i<o*o;i++)
{
for(int j=0;j<n*n;j++)
{
cout<<mat[i][j]<<"  ";
}
cout<<endl;
}





return 0;
}
