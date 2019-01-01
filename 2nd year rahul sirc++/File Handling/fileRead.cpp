//Program to read a file

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  //open a file
  char fname[20] = "d:\\a.txt";
  ifstream fin(fname);//defaults to text mode
  //file must exist for the stream to establish

  if(fin)//open success test
  {
      //data transfer
      int x;
      //int get()
      //fetches a byte from the input stream 
      //returns the ASCII value of the read byte
      //returns -1 at EOF
      //blocks the program control if data is not available in the stream.   

      //put(int)
      //gets ASCII value of a byte as parameter
      //writes it to the output stream 

      while( (x =  fin.get()) != -1)
        cout.put(x);//write a byte

      //close
      fin.close();

  }
  else
    cerr<<"\n File Open Failed";

  return 0;
}
