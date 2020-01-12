//Program to copy a file
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
  char src[20], trgt[20];

  cout<<"\n Enter source file name ";
  cin>>src;
  cout<<"\n Enter target file name ";
  cin>>trgt;

  //open this file for reading (file must exist and there must be a read permission)
  ifstream fin(src, ios::binary);

  //open this file for writing (file would be created or overwritten provided the path is valid and has write permission )
  ofstream fout(trgt, ios::binary | ios::trunc);

  //test
  if(fin && fout)
  {
      //copy
      int x;
      while((x = fin.get()) != -1)
        fout.put(x);

      fin.close();
      fout.close();
      cout<<"\n File Copied";
  }
  else
    cerr<<"\n Copy Failed ";

  return 0;
}
