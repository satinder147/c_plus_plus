//Program to demonstrate : String IO
#include <iostream>
using namespace std;

int main()
{
  char str[100];
  cout<<"\n Enter a string ";

  //getline fetches a string from the input stream
  //its 3 parameters are : string, maxQuantity, delimiter
  //it fetches input puts the content into string, 
  //it fetches maxQuantity -1 characters or until delimiter is found
  //the dilimiter is removed from the stream but not put into the string
  //on failure it set the failbit to true due to which further input operations on stream cease until reset.

  cout<<"\n Enter a string ";
  cin.getline(str, 100, '\n');
  if(cin.fail())//input failed
    cin.clear();//reset
  cin.ignore(1000, '\n');//skip from cin next 1000 bytes or until '\n' is found
  cout<<str;

  cout<<"\n Enter a string ";
  cin.getline(str, 100, '\n');
  if(cin.fail())//input failed
    cin.clear();//reset
  cin.ignore(1000, '\n');//skip from cin next 1000 bytes or until '\n' is found
  cout<<str;

  cout<<"\n Enter a string ";
  cin.getline(str, 100, '\n');
  if(cin.fail())//input failed
    cin.clear();//reset
  cin.ignore(1000, '\n');//skip from cin next 1000 bytes or until '\n' is found
  cout<<str;

  return 0;
}
