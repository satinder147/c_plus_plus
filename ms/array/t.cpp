#include<iostream>
using namespace std;

bool isvowel(char c1)
{
if(c1!='a'||c1!='e'||c1!='i'||c1!='o'||c1!='u')
return false;
}

int main()
{
string s1,s2;
cin>>s1>>s2;

int v1=0,v2=0,c1=0,c2=0;
for(int i=0;i<s1.length();i++)
if(s1[i]=='a' ||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u')
v1++;




for(int i=0;i<s2.length();i++)
if(s2[i]=='a' ||s2[i]=='e'||s2[i]=='i'||s2[i]=='o'||s2[i]=='u')
v2++;

c1=s1.length()-v1;
c2=s2.length()-v2;

if(v1==v2 &&c1==c2 &&s1.length()==s2.length())

{
bool flag=false;
for(int i=0;i<s1.length();i++)
{
if(isvowel(s1[i]) || isvowel(s2[i]))
flag=true;
}
if(flag)
cout<<"No";
else
cout<<"Yes";
}
else
cout<<"No";
return 0;
}
