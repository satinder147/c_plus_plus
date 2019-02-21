#include<iostream>
using namespace std;

int o(int a,int b)
{
if(a==1||b==1)
return 1;
else return 0;
}
int xo(int a,int b)
{
if(a==b)
return 1;
else
return 0;
}
int main()
{

string s;
cin>>s;
for(int i=0;i<s.length()-2;i=i+2)
{
int a=int(s[i])-48;
int b=int(s[i+2])-48;
char c=s[i+1];
//cout<<char(1);
if(c=='A')
{
if(a*b)
s[i+2]='1';
else s[i+2]='0';
}


else if(c=='B')
s[i+2]=char(o(a,b));

else if(c=='C')
s[i+2]=char(xo(a,b));
}
cout<<s;
return 0;
}
