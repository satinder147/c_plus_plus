#include<iostream>
using namespace std;

void heapify(int a[],int n,int i)
{
int largest=i;
int l=2*i+1;
int r=2*i+2;
if(l<n && a[l]>a[largest])
largest=l;
if(r<n && a[r]>a[largest])
largest=r;

if(largest!=i)
{swap(a[largest],a[i]);
heapify(a,n,largest);
}

}
void heapsort(int a[],int n)
{
for(int i=n/2-1;i>=0;i--)
{
heapify(a,n,i);
}

for(int i=n-1;i>=0;i--)
{
swap(a[0],a[i]);
heapify(a,i,0);
}
}
int main()
{
int n=7;
int a[n]={3,2,6,5,4,9,8};
heapsort(a,n);

for(int i=0;i<n;i++)
cout<<a[i]<<" ";
return 0;
}


//not stable
/*complexity 0(nlogn) for all three cases
space complexity o(1)
int place sorting algorithm




swapping without third variable
x = x + y; // x now becomes 15
    y = x - y; // y becomes 10
    x = x - y; // x becomes 5
*/



