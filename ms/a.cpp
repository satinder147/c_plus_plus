#include<iostream>
using namespace std;
int main()
{
char s[100];
cin.getline(s,sizeof(s));
cout<<endl;
int i=0;
while(s[i]!='\0')
i++;

while(i>-1)
{
if(s[i]==' ')
{
int j=i+1;
while(s[j]!=' ' || s[j]=='\0')
{cout<<s[j];
j++;
}
}
cout<<" ";
i--;
}
}
