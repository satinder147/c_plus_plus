#include<iostream>
using namespace std;


bool isvowel(char s)
{

return s=='a'||s=='e'||s=='i'||s=='o'||s=='u';
}
bool hard(string s)
{
int v=0;
bool flag=false;
for(int i=0;i<s.length()-3;i++)
{

if((!isvowel(s[i])) && (!isvowel(s[i+1])) && (!isvowel(s[i+2])) && (!isvowel(s[i+3])))
flag=true;
}

int c=s.length()-v;

return flag || c>v;

}
int main()
{
string s;

cin>>s;
cout<<hard(s);
return 0;
}
