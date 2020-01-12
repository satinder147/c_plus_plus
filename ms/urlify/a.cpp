#include<iostream>
using namespace std;
int main()
{
char a[100];
string s="";
cin.getline(a,sizeof(a));
//cin>>a;
cout<<endl;
int i=0;
while(a[i]!='\0')
{
if(a[i]!=' ')
s+=a[i];
else s+="%20";
i++;
}
cout<<endl;
cout<<s;
return 0;
}
