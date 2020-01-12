#include<iostream>
using namespace std;




int part(int a[],int s,int e)
{
int pIndex=s;
int pivot=a[e];

for(int i=s;i<e;i++)
{
if(a[i]<=pivot)
{
swap(a[i],a[pIndex]);
pIndex++;
}

}
swap(a[pIndex],a[e]);
return pIndex;
}

void quickSort(int a[],int s,int e)
{
if(s<e){
int pIndex=part(a,s,e);
quickSort(a,s,pIndex-1);
quickSort(a,pIndex+1,e);
}
}

void merg(int a[],int n,int l[],int ln,int r[],int rn)
{

int i=0,j=0,k=0;
while(j<ln && k<rn)
{
if(l[j]>r[k])
{
a[i]=r[k];
i++,k++;
}
else
{

a[i]=l[j];
i++,j++;
}
}
while(j<ln)
{
a[i]=l[j];
i++,j++;
}

while(k<rn)
{
a[i]=r[k];
i++,k++;
}

}

void mergesort(int a[],int n)
{

if(n<2)
return;


int mid=n/2;
//cout<<mid<<endl;
int l[mid];
int r[n-mid];
for(int i=0;i<mid;i++)
l[i]=a[i];
for(int i=mid;i<n;i++)
r[i-mid]=a[i];

mergesort(l,mid);
mergesort(r,n-mid);

merg(a,n,l,mid,r,n-mid);


}
void insertion(int a[],int n)
{
int pick,j;
for(int i=1;i<n;i++)
{
pick=a[i];
j=i-1;
while(j>=0 && a[j]>pick)
{
a[j+1]=a[j];
j--;
}
a[j+1]=pick;
}
}

void selection(int a[],int n)
{
for(int i=0;i<n;i++)
{
    int mi=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[mi])
        mi=j;
    }

    int temp=a[mi];
    a[mi]=a[i];
    a[i]=temp;
}

}

void bucket(int a[],int n)
{
int ma=a[0];
for(int i=0;i<n;i++)
if(a[i]>ma)
ma=a[i];

int b[ma+1]={0};

for(int i=0;i<n;i++)
b[a[i]]++;

for(int i=0;i<(ma+1);i++)
{
if(b[i]!=0)
{
while(b[i])
{cout<<i<<" ";
b[i]--;
}
}
}
}

int bubble(int a[],int n)
{
int c=0;
for(int i=n-1;i>0;i--)
    {
    bool flag=true;
    for(int j=0;j<i;j++)
        {
        c++;
        if(a[j]>a[j+1])
        {
            flag=false;
            int temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;

        }
        }
    if(flag)
    break;
    }
return c;
}
void print(int a[],int n)
{
for(int i=0;i<5;i++)
cout<<a[i]<<" ";
}
int main()
{
int n=5;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

//cout<<bubble(a,5)<<endl;
//selection(a,n);
//insertion(a,n);
//bucket(a,n);
//mergesort(a,5);

//int l[2]={1,6};
//int r[3]={2,3,9};
//merg(a,5,l,2,r,3);
//quickSort(a,0,4);
print(a,5);
return 0;
}
