//Program to demonstrate : RMS
#include <iostream>
#include<fstream>
#include<cstring>
#include<cstdlib>
using namespace std;

//to clear the stdin
void flush(istream & in)
{
    if(in.fail())
      in.clear();//reset the failed bits
    in.ignore(1000, '\n');////Discard from the stdin : 1000 characters or until '\n' is encountered, whichever first.

}

class RMS; //forward declaration

class Student
{
  int rno;
  char name[20];
  float percentage;
public:
  Student();
  void setData();
  void displayData();
  friend class RMS;
};

Student :: Student()
{
  rno = 0;
  strcpy(name, "");
  percentage = 0;
}

void Student :: setData()
{
  cout<<"\n Enter rno : ";
  cin>> rno;
  cout<<"\n Enter Name : ";
  flush(cin);
  cin.getline(name, 20, '\n');
  cout<<"\n Enter percentage: ";
  cin>> percentage;

}

void Student :: displayData()
{
  cout<<"\n "<<rno<<"  "<<name<<"  "<<percentage;
}

class RMS
{
    fstream fio;
    char fname[20];

  public:
    RMS(const char []);
    void addRecord();
    void viewAllRecords();
    void searchRecord();
    void modifyRecord();
    void deleteRecord();
  ~RMS();
};

RMS :: RMS(const char fn[])
{
  strcpy(fname, fn);
  int cnt = 0;
  do
  {
    fio.open(fname, ios::binary|ios::out|ios::in);
    if(!fio )
    {
      if(cnt == 0)
      {
        fio.open(fname, ios::binary|ios::out|ios::trunc);
        fio.close();
      }
      else
      {
        cout<<"\n File Open Failed ";
        exit(1);
      }
    }//if
    else
      cnt++;
    cnt++;
  }while(cnt < 2);
}//RMS

RMS :: ~RMS()
{
  fio.close();
}

void RMS :: addRecord()
{
    //create an object
    Student s;
    //set data
    s.setData();

    //append the record

    fio.seekp(0, ios::end);//position the file put pointer at 0 offset from EOF

    //Write the object
    //Address of object is converted into char pointer form and size of object are passed as parameters to the write function.
    //The function dereferences the object byte by byte and writes it into the file.
    fio.write((char*)&s, sizeof(s));
}

void RMS :: viewAllRecords()
{
    //dummy object
    Student s;

    //display records from BOF until EOF
    fio.seekg(0, ios::beg);//position the file read pointer at 0 offset from BOF

    //Read into the object
    //Address of object is converted into char pointer form and size of object are passed as parameters to the read function.
    //The function reads data from the file and writes into the object byte by byte.
    //The function returns the caller objects reference or NULL (@ eof).

    while(fio.read((char*)&s, sizeof(s)))
    {
        s.displayData();
    }
    //files eofbit is set, clear it otherwise all i/o operations would cease
    fio.clear();

}


void RMS :: searchRecord()
{
  Student s; //empty object
  int r;
  int flag ;
  cout<<"\n Enter the rno to search : ";
  cin>> r;

  //position the file get pointer at bof
  fio.seekg(0, ios::beg);
  flag = 0;
  //start reading
  while(fio.read((char*)&s, sizeof(s)))
  {
      if(s.rno == r)
      {
          s.displayData();
          flag = 1;
          break;
      }
  }//while

  if(flag == 0)
    cout<<"\n Rno : "<<r<<" not found ";

  fio.clear();
}

void RMS :: modifyRecord()
{
  Student s; //empty object
  int r;
  int flag ;
  cout<<"\n Enter the rno to modify : ";
  cin>> r;

  //position the file get pointer at bof
  fio.seekg(0, ios::beg);
  flag = 0;
  //start reading
  while(fio.read((char*)&s, sizeof(s)))
  {
      if(s.rno == r)
      {
        //display current data
          s.displayData();
        //fetch new data
          s.setData();
        //write back into the file
          int pos = fio.tellg();//get the current position of get pointer
          pos -= sizeof(s);//because the record had been read
          fio.seekp(pos, ios::beg);//position the put pointer
          fio.write((char*)&s, sizeof(s));

          flag = 1;
          cout<<"\n Record Modified ";
          break;
      }
  }//while

  if(flag == 0)
    cout<<"\n Rno : "<<r<<" not found ";

  fio.clear();
}

void RMS :: deleteRecord()
{//transfer all records other than the record to be deleted, into another file.
 //delete this file
 //rename the target file as this file

  ofstream fout("d:\\temp.txt", ios::out|ios::trunc|ios::binary);
  if(fout)
  {
    Student s;//empty object
    int flag = 0;
    int r;
    cout<<"\n Enter the rno to delete : ";
    cin>> r;

    fio.seekg(0, ios::beg);
    while(fio.read((char*)&s, sizeof(s)))
    {
        if(s.rno != r)
        {//transfer
          fout.write((char*)&s, sizeof(s));
        }
        else
          flag = 1;
    }//while
    fio.clear();
    fout.close();//close the target file (copy)

    if(flag == 0)
    {
      cout<<"\n Rno "<<r<<" not found ";
      //delete the copy
      remove("d:\\temp.txt");//stdio
    }
    else
    {//rno to be deleted was found and not copied
      fio.close();
      remove(fname);
      rename("d:\\temp.txt", fname);
      fio.open(fname, ios::binary | ios::out| ios::in);

      cout<<"\n Record Deleted";
    }

  }
  else
    cout<<"\n Delete Operation Failed ";

}

int main()
{
    int ch;
    RMS rms("d:\\student.txt");
    do
    {
        cout<<"\n 1. Add Record ";
        cout<<"\n 2. Modify Record ";
        cout<<"\n 3. Delete Record ";
        cout<<"\n 4. Search Record ";
        cout<<"\n 5. View All Records ";
        cout<<"\n 6. Exit ";
        cout<<"\n Enter Choice : ";
        cin>>ch;

        switch(ch)
        {
        case 1:
            rms.addRecord();
            break;
        case 2:
            rms.modifyRecord();
            break;
        case 3:
            rms.deleteRecord();
            break;
        case 4:
            rms.searchRecord();
            break;
        case 5:
            rms.viewAllRecords();
            break;
        case 6://exit
            break;
        default:
            cout<<"\n Wrong Choice ";
            break;
        }//switch
    }while(ch != 6);

    return 0;
}
