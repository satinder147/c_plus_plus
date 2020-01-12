#include<bits/stdc++.h>
using namespace std;
int main()

{

//first way of iterating
/*
vector <int> a;
for(int i=0;i<5;i++)
a.push_back(i);
for(int i=0;i<a.size();i++)
cout<<a[i]<<" ";
*/
// Second way //works in c++ 11 and above
/*
vector <int> g1;
for(int j=0;j<5;j++)
g1.push_back(j);

    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";
        */

//Begin from the end
/*
vector <int> c;
for(int i=0;i<5;i++)
c.push_back(i);
for(auto i=c.rbegin();i!=c.rend();i++)
cout<< *i<<" ";
*/
//cbegin,cend,crbegin,crend returns constant pointers
//vector <int> d;
//cout<<d.max_size();
//cout<<d.size();
//cout<<d.empty(); returns true of false;
//cout<<d.capacity();          the difference between capacity and size is that capacity is the size of the array which the vector is currently using under the hood. The size of this array is the next multiple of 2 for eg if size-17 then cap=32
                                //where as the size of the vector is the number of elements in the vector


// Capacity: how many items can be fit in the vector before it is "full". Once full, adding new items will result in a new, larger block of memory being allocated and the existing items being copied to it
/*
for(int i=0;i<129;i++)
d.push_back(i);

d.resize(4); // resizes the vector to size 4 leaving all other elements
d.shrink_to_fit();  // in the above case size was 129 and capacity 256 after resizing size becomes 4 but capacity is still 256 but when shrink to fit is called capacity is reduced to 4


cout<<endl;
cout<<d.size()<<endl;
cout<<d.capacity();
reverse(d.begin(),d.end());        //will reverese the vecto
for(auto i=d.begin();i!=d.end();i++)
cout<< *i<<" ";

*/

//ways to print data
//vector <int> g;
//for(int i=0;i<5;i++)
//g.push_back(i);

//for(int i=0;i<g.size();i++)
//cout<<g[i];   //g[i],g.at(i) are similar. g.front(), g.back() returns front and back elements.
//cout<<g.back();


/*
vector <int> s;
for(int i=0;i<5;i++)
s.push_back(i);

int *pos=s.data();
cout<<*(pos+1); //data can be printed in this manner using s.data(). S->data() returns a pointer to the first location

*/

vector <int> s;
for(int i=0;i<5;i++)
s.push_back(i);
vector <int> s1;
for(int i=5;i<15;i++)
s1.push_back(i);

//s.assign(1,10);  //--> will remove all the elements of the vector and add "10" one time.
//s.pop_back(); //removes last element;
//s.insert(s.begin()+3,6);  // this can be used to insert element at 4th position . element is 6
//s.erase(s.begin()+3); // it is used to erase the element at third index
//s.clear();  //used to remove all the elements from the vector
//s.swap(s1); // it swaps the elements of the vectors given data type is same.
//s.emplace(s.begin(), 5);  //inserts element in the beginning
//s.emplace_back(6);       //inserts element in the end.
for(int i=0;i<s.size();i++)
cout<<s[i]<<" ";




return 0;
}
