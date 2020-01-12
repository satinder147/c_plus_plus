#include<iostream>
using namespace std;
int main()

{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int b[6]={2,4,5,8,9,10};
int c[5]={2,4,6,8,0};

int n1=10;
int n2=6;
int n3=5;
int x=0,y=0,z=0;

while((x<n1) && (y<n2) && (z<n3))
{
if((a[x]==b[y] )&& (b[y]==c[z]))
{cout<<a[x]<<" "<<b[y]<<" "<<c[z];
x++,y++,z++;
//cout<<"hello"<<endl;
}
else if(a[x]<b[y])
x++;
else if(b[y]<c[z])
y++;
else
z++;
}
return 0;
}
