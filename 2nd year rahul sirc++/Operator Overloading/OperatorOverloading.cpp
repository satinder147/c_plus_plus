/*
Study of Operator Overloading

System provides a rich set of operators that can act on primary datatypes.
But for the secondary datatypes, system by default allows use of operator:

= (assignment)
. (member access)
& (referencing)
sizeof (know the size in bytes)
new (memory allocation)
delete (memory deallocation)
* -> (on pointers, for dereferencing)

Use of the rest of the operators on objects of secondary types is prohibited.

The reason being, logic of the operator action on object is not known.

The class or the program is allowed to define the logic of operator action on objects.
Doing so is termed as "Operator Overloading".
By this the use of operators on object becomes legal.


"Operator Overloading is defining operator functions that provide
the logic of operator action on objects of the class."

Refer the cases and code below
*/


#include<iostream>
using namespace std;

class Time
{
private:
  int h,m,s;
public:
  Time();
  Time(int,int,int);
  void display();

  Time operator +(Time &r);
  Time operator -(Time &r);
  Time operator +(int x);

  Time & operator =(int x);
  Time & operator ++();//pre
  Time operator ++(int q);//post
  int operator [](int q);
  bool operator == (Time &r);
  Time* operator ->();
  void operator ()(int x, int y, int z );
  Time & operator ()(Time &r);

  operator int();
  operator double();


  friend Time operator +(int q, Time &r);
  friend ostream & operator <<(ostream &o, Time &r);
  friend istream & operator >>(istream &in, Time &r);

};

Time :: Time()
{
  h = m = s = 0;
}

Time :: Time(int a, int b, int c)
{
  h = a;
  m = b;
  s = c;
}

void Time ::display()
{
  cout<<"\n"<<h<<":"<<m<<":"<<s;
}

//t1 + t2
Time Time :: operator +(Time &r)
{
  Time temp;
  temp.h = h + r.h;
  temp.m = m + r.m;
  temp.s = s + r.s;

  return temp;
}

//t2 -t1

Time Time :: operator -(Time &r)
{
  Time temp;
  temp.h = h - r.h;
  temp.m = m - r.m;
  temp.s = s - r.s;

  return temp;
}

//t1 + 5
Time Time :: operator +(int x)
{
  Time temp;
  temp.h = h +x;
  temp.m = m +x;
  temp.s = s +x;

   return temp;
}

//t3 = 9
Time & Time :: operator =(int x)
{
    h = m = s = x;
    return *this;//returning the caller object for cascading support
}

Time & Time :: operator ++()
{
  //increment
  ++h;
  ++m;
  ++s;

  //return the incremented value
  return *this;
}

//t1++
Time Time :: operator ++(int q)
{
    q = q;//to show that q is used

    //copy of caller object
    Time temp;
    temp.h = h;
    temp.m = m;
    temp.s = s;

    //increment
    h++;
    m++;
    s++;

    return temp;//original value
}

Time operator +(int q, Time &r)
{
 Time temp;
 temp.h = q + r.h;
 temp.m = q + r.m;
 temp.s = q + r.s;

 return temp;
}

ostream & operator <<(ostream &o, Time &r)
{
    o<<"\n"<<r.h<<":"<<r.m<<":"<<r.s;
    return o;
}

istream & operator >>(istream &in, Time &r)
{
  cout<<"\n Enter hours : ";
  in>>r.h;
  cout<<"\n Enter minutes : ";
  in>>r.m;
  cout<<"\n Enter seconds : ";
  in>>r.s;
  return in;
}

//t1[0]
int Time :: operator [](int q)
{
    if(q == 0)
      return h;
    else if(q == 1)
      return m;
    else if(q == 2)
      return s;
    else
    {
      cout<<"\n Invalid Index ";
      return 0;
    }
}

//t1 == t2
bool Time :: operator == (Time &r)
{
  return h == r.h && m== r.m && s == r.s;
}

//t1->display()
Time* Time :: operator ->()
{
    h++;//any logic
    return this;
}

//t1(10,11,12)
void Time :: operator ()(int x, int y, int z )
{
  h = x;
  m = y;
  s = z;
}

//t1(t2)
Time & Time :: operator ()(Time &r)
{
  h = r.h;
  m = r.m;
  s = r.s;
  return r;
}

//x = t1;
Time :: operator int()
{
 int sum = h*60*60 + m*60 +s;
 return sum;
}

//d = t1
Time :: operator double()
{
 double sum = h + m/60.0 + s/(60.0*60.0);
 return sum;
}

int main()
{
  Time t1(1,2,3);
  Time t2(10,20,30);
  Time t3;

  t1->display();

  t1(6,7,8);
  t3(t1);

  int q;
  double w;
  q = t1;
  w = t3;

  cout<<"\n t1 : "<<t1;
  cout<<"\n t3 : "<<t3;
  cout<<"\n q : "<<q;
  cout<<"\n w : "<<w;


  //t3 = t1 + t2;
  //t3 = t2 - t1;
  //t3 = t1 - t2 + 5;

  //t2 = t3 = 9;

  //t3 = t1++;
  //t3 = ++t1;

  //t3 = 5 + t1;
  //t1.display();
  //t2.display();
  //t3.display();
  //cin>>t1>>t2>>t3;

 // int i;
 // for(i = 0; i < 4; i++)
//  cout<<"\n"<<t1[i];

  if(t1 == t2 )
    cout<<"\n t1 == t2";
  else
    cout<<"\n t1 != t2";

  cout<<t1<<t2<<t3;

  return 0;
}


/*
Learn By Case Study
------------------------------------------
Case 1:   t1 + t2
Here operator + acts on 2 Time objects.
For the user it is an addition expression.

For the system it is a function call.
function : operator + is called using
t1 as caller object and t2 as the parameter.

For implementation, see the code.

------------------------------------------
Case 2:   t2 - t1
Here operator - acts on 2 Time objects.
For the user it is a subtraction expression.

For the system it is a function call.
function : operator - is called using
t2 as caller object and t1 as the parameter.

For implementation, see the code.

------------------------------------------
Case 3:   t1 + 5
Here operator + acts on 1 Time object
and 1 int.
For the user it is a addition expression.

For the system it is a function call.
function : operator + is called using
t1 as caller object and 5 (int) as the parameter.

For implementation, see the code.

------------------------------------------
Case 4:   t3  = 9
Here operator = acts on 1 Time object
and 1 int.
For the user it is an assignment statement.

For the system it is a function call.
function : operator = is called using
t3 as caller object and 9 (int) as the
parameter.

For implementation, see the code.

------------------------------------------
Case 5 and Case 6 :
t3 = t1++
t3 = ++t1

t1++ :
Here operator ++ is applied on 1 Time object.
For the user it is a unit increment expression.
For C++ system it is a call to function : operator ++
The function uses :
 t1 as the caller object
 It doesnt take any parameter as the operator is unary.

By the above understanding implement the operation.

++t1:
Here operator ++ is applied on 1 Time object.
For the user it is a unit increment expression.
For C++ system it is a call to function : operator ++
The function uses :
 t1 as the caller object
 It doesnt take any parameter as the operator is unary.

By the above understanding implement the operation.

Bug :
It is observed that the two overloads result in the same signature.
Ultimately it would cause redeclaration error.
Solution :
The bug was identified by the developers of C++ and they
introduced a compiler level fix.

It specifies that the postfix overload of operator ++ must
declare an int as a formal parameter.
No actual parameter be passed.
i.e.  usage would be unary but the definition would be binary.

Q) Why the parameter ?
A) So that the signatures dont conflict.

Q) Then why the parameter to the postfix?
A) Internally the call t1++ would convert into t1++0
If it was applied to prefix then call ++t1 would convert to 0++t1
But as 0 cannot be the caller object, hence the postfix was
selected to take the parameter.

For implementation, see the code.

------------------------------------------
Case 7: 5 + t1

Here operator + is applied on one int and one Time object.
Observe that operand int is on the LHS of the operator +.
It tends to be the caller object for the operator function.
It is not possible as data types of caller object and member function mismatch.
Conclusion : A caller object for function invokation is not available.
So the operator function needs to be invoked without any caller object.
Hence the operator function needs to be defined as a non member function.
(Recollect that non member function donot require a caller object for invokation.)

When an operator function is overloaded as a non member function then :
The LHS operand is the first parameter.
The RHS operand is the second parameter.
The operator function invokes on itself (without any caller object).

------------------------------------------
case 8 : cout<<t1
Here operator << (insertion) is applied on cout and a Time object.
for C++ system it is a call to function : operator <<

Observe that operand "cout" is on the LHS of the operator <<.
It tends to be the caller object for the operator function.
It is not possible as data types of caller object and member function mismatch.
Conclusion : A caller object for function invokation is not available.
So the operator function needs to be invoked without any caller object.
Hence the operator function needs to be defined as a non member function.
(Recollect that non member function donot require a caller object for invokation.)

When an operator function is overloaded as a non member function then :
The LHS operand is the first parameter.
The RHS operand is the second parameter.
The operator function invokes on itself (without any caller object).

------------------------------------------
case 9 : cin>>t1
Here operator >> (extraction) is applied on cin and a Time object.
for C++ system it is a call to function : operator >>

Observe that operand "cin" is on the LHS of the operator >>.
It tends to be the caller object for the operator function.
But it is not possible as data types of caller object and member function mismatch.
Conclusion : A caller object for function invokation is not available.
So the operator function needs to be invoked without any caller object.
Hence the operator function needs to be defined as a non member function.
(Recollect that non member function do not require a caller object for invokation.)

When an operator function is overloaded as a non member function then :
The LHS operand is the first parameter.
The RHS operand is the second parameter.
The operator function invokes on itself (without any caller object).
------------------------------------------
case 10: t1[0]
Here operator [ ] acts on 1 Time object
and 1 int.
For the user it is an array element access statement.

For the system it is a function call.
function : operator [] is called using
t1 as caller object and 0 (int) as the parameter.

For implementation, see the code.

------------------------------------------
case 11 : t1 == t2
Here operator == is applied on 2 Time objects.
For the user it is a comparison statement.
For the system it is a call to operator function ==.

In this case :
t1 : is the caller object
== : is the operator function being called.
t2 : is the parameter.

Learn by implementation.
------------------------------------------
Case 12 and 13 : Overloading new and delete
Refer : OverloadingNewDel.cpp

------------------------------------------
Case 14 : t1->display()
Operator -> (infix dereferencing) is applied on one Time object and one member of the Time class.
Certain restrictions apply for overloading of the operator ->
1) It is a unary operator, i.e. it acts on one operand and it is the caller object.
2) Its return type must be Time * (It should return address of a Time object).
3) It can only be overloaded as a member function.

Developer is free to put up any logic against its invokation.
Refer the implementation.

case 15 : t1(1,2,3) and t1(t2)
Here operator () is applied on 1 Time object and arbitrary parameters.
For the user it seems a function call.
But for the C++ system, it is call to operator ()
with arbitrary set of parameters.

System treats:
 t1 as the caller object
 () as the operator function
 parameters as parameters.

case 16: x = t1
Here operator = is applied on 1 int and 1 Time object
For the user it is an assignment expression
but for the C++ system it is a case of
type-conversion of Time object into int.

System doesn't treat the expression as
a case of operator call because:
1) On the LHS of the operator there is an int,
which cannot act as the caller object.
2) Operator = cannot be overloaded as a
non member function.

Type Conversion / Conversion Functions :
is defining operator functions that
convert object of a secondary type
into a value of a primary type.

Type Conversion function take special
signature:
 operator <primary type>()
 {
    conversion logic
    return value primary type
 }
 Refer : 2 examples

--------------------------------------------
Operator Overloading Rules and Restrictions
--------------------------------------------
There are some rules and restrictions that
apply to operator overloading.

* New operators cannot be defined using operator overloading.
* Precedence/Associativity of an operator cannot be altered.
* Number of operands that an operator takes cannot be changed,
  except for the operator ().
* Operator functions cannot have default arguments.
* These operators cannot be overloaded :-
  . :: .* ?
* There are some restrictions that apply to
  friend operator functions.
  You cannot overload the
  = () [] –> operators
  by using a non member function.

*/
