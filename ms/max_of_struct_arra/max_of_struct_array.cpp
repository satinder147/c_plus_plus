#include<bits/stdc++.h>
using namespace std;

struct height
{
int feet,inches;
};

int ma(height arr[],int n)
{
int mi=INT_MIN;
int i;
for(i=0;i<n;i++)
{
int temp=arr[i].feet*12+arr[i].inches;
if(temp>mi)
mi=temp;
}
return mi;
}
int main()

{
height arr[]={{10,2},{50,23},{33,11},{10,22}};
cout<<ma(arr,4);

return 0;
}
