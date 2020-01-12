#include<iostream>
using namespace std;
struct a {
int feet, inches;
};
int m(a arr[],int n)
{
int index=0;
int v=arr[0].feet*12 +arr[0].inches;
for(int i=0;i<n;i++)
{
if((arr[i].feet*12+arr[i].inches)>v)
{
v=arr[i].feet*12+arr[i].inches;
index=i;
}
}
return index;
}
int main()
{
a arr[5]={{5,1},{4,3},{7,5},{8,7},{6,5}};
cout<<m(arr,5);
return 0;
}
