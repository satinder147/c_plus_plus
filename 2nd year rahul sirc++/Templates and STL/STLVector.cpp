#include <iostream>
#include <string>
#include <vector>//from stl library
#include<algorithm>//from stl library

using namespace std;

class PersonDB;

class Person
{
    string name;
    int age;
    char gender;
  public:
    void set();
    void display();
    bool operator <(Person & r)
    {
      return name < r.name;
    }
    friend class PersonDB;
};

void Person :: set()
{
  cout<<"\n Enter name : ";
  cin>>name;
  cout<<"\n Enter age : ";
  cin>> age;
  cout<<"\n Enter gender : ";
  cin>> gender;
}

void Person :: display()
{
  cout<<"\n { "<<name <<", "<<age<<", "<<gender<< " }";
}

class PersonDB
{
  vector<Person> all;//a dynamic array.
public:
  void addPerson();
  void displayAll();
  void deletePerson();
  void arrangeByName();
};

void PersonDB :: addPerson()
{//add a new Person into the vector
  Person p;
  p.set();
  all.push_back(p);//append an object to the vector

}

void PersonDB :: displayAll()
{
  //iterator to the vector
  vector<Person>::iterator itr;
  //initialize it with the address of first element
  itr = all.begin();

  while(itr != all.end())
  {
    //primary cout<< *itr;
    itr->display();//pointer to person object se person method call kar rahe hai
    itr++;
  }
}
void PersonDB :: deletePerson()
{
  string n;
  cout<<"\n Enter the name of person to delete ";
  cin>> n;

  //sequential search
  int flag = 0;
  vector<Person>:: iterator itr = all.begin();

  while(itr != all.end())
  {
    if(itr->name == n)
    {//this element to be deleted
      all.erase(itr);
      flag = 1;
      break;
    }
    itr++;
  }//while

  if(flag == 0)
    cout<<"\n"<<n<<" not found";
  else
    cout<<"\n"<<n<<" deleted";
}

void PersonDB :: arrangeByName()
{
    sort(all.begin(), all.end());//uses operator <
}

int main()
{
    PersonDB pdb;
    int ch;
    do
    {
        cout<<"\n 1. Add Person ";
        cout<<"\n 2. Delete Person ";
        cout<<"\n 3. Display ALL ";
        cout<<"\n 4. Arrange By Name ";
        cout<<"\n 5. Exit";
        cout<<"\n enter choice ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                pdb.addPerson();
                break;
            case 2:
                pdb.deletePerson();
                break;
            case 3:
                pdb.displayAll();
                break;
            case 4:
                pdb.arrangeByName();
                break;
            case 5:
                break;
            default:
                cout<<"\n Wrong Choice ";
                break;
        }//switch
    }while(ch != 5);
    return 0;
}
