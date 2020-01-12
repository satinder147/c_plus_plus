/*
General C++ Program
*/

#include <iostream>//preprocessor directive
using namespace std;

int x = 10;//global variable x, belongs to global namespace. It has no name.
int main()//program starts here
{
    int x ;//local variable x
    int no;// a local variable

    do
    {
        cout << "\n Enter a  positive number ";
        cin >> no;

        if(no > 0)
        {
            x = no*no;//local x gets the square
            ::x = no * no * no;//global x gets the cube

            //note : direct use of x would map with local definition
            //and would shadow (hide) the global definition

            //The binary operator << is cascaded to output multiple values
            cout<<"\n Square of "<<no<< " : "<<x;
            cout<<"\n Cube of "<<no<< " : "<<::x;
        }
        else
            cerr<<"\n Negative data or Zero"<<no;

    }while(no <= 0);

    return 0;
}//program ends here
