//Program to demonstrate : Data IO
#include <iostream>
#include<fstream>
using namespace std;

int main()
{
  int i1, i2;
  char c1, c2;
  double d1, d2;
  bool b1, b2;

  //file open for r/w
  fstream fio("d:\\a.txt", ios::binary|ios::in|ios::out|ios::trunc );

  if(fio)
  {
    i1  = 4532104;
    c1  = 'q';
    d1 = 7.00973;
    b1 = true;

    //write
    fio<<i1<<'\n';
    fio<<c1<<'\n';
    fio<<d1<<'\n';
    fio<<b1<<'\n';

    //read back
    fio.seekg(0, ios::beg);//position the file get pointer at 0 offset from BOF
    fio>>i2>>c2>>d2>>b2;

    fio.close();

    cout<<"\n"<<i1<<"  "<<i2;
    cout<<"\n"<<c1<<"  "<<c2;
    cout<<"\n"<<d1<<"  "<<d2;
    cout<<"\n"<<b1<<"  "<<b2;

  }
  else
    cerr<<"\n File Open Failed ";
  return 0;
}
