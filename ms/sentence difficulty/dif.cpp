#include<bits/stdc++.h>
using namespace std;

int main()

{
string s;
int c=0;
getline(cin,s);
string m[20];
string k="";
int j=0;
for(int i=0;i<s.length();i++)
{
if(s[i]==' ')
{
m[j]=k;
k="";
j++;
}
else
k=k+s[i];

}
m[j]=k;
cout<<m[1];
/*
char v[]={'a','e','i','o','u'};
string s[20];
for(int )
int k=0;
for(int a=0;a<s.length();a++){
for(int i=0;i<s[a].length();i++)
{
for(int j=0;j<5;j++)
{
if(s[a][i]==v[j])
k++;
}
}
int vs,cs;
vs=k;
cs=s.length()-vs;
cout<<vs<<" "<<cs<<endl;;
}
*/
return 0;
}
