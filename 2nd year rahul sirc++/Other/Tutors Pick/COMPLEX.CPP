#include<iostream>
using namespace std;

//complex number

/*
Design a Class Complex  with
data members for real and
imaginary part.

Provide default and
parameterized constructors.

Write a program to perform
arithmetic operations of two
complex numbers using operator
overloading

(using either member functions
or friend functions).

*/


class Complex
{
 private:
	float real,imaginary;
 public:
	Complex();
	Complex(float, float);

	void set();

	Complex operator +(Complex &o);
	Complex operator -(Complex &o);
	Complex operator *(Complex &o);
	Complex operator /(Complex &o);

	friend ostream& operator <<(ostream & out, Complex & c);
};

Complex :: Complex()
{
	real = 0;
	imaginary = 0;
}

Complex :: Complex(float r, float i)
{
	real = r;
	imaginary = i;
}

void Complex :: set()
{
	cout<<"\n enter real part ";
	cin>>real;
	cout<<"\n enter imaginary part ";
	cin>>imaginary;
}

Complex Complex :: operator +(Complex &o)
{
	Complex temp;
	temp.real = real + o.real;
	temp.imaginary = imaginary + o.imaginary;

	return temp;
}

Complex Complex :: operator -(Complex &o)
{
	Complex temp;
	temp.real = real - o.real;
	temp.imaginary = imaginary - o.imaginary;

	return temp;
}

Complex Complex :: operator *(Complex &o)
{
	//r3 = r1 * r2 - i1 * i2
	//i3 = r1 * i2 + r2 *i1

	Complex temp;
	temp.real = real * o.real - imaginary * o.imaginary;
	temp.imaginary = real * o.imaginary + o.real * imaginary;
	return temp;
}

Complex Complex :: operator /(Complex &o)
{
	//r3 = (r1*r2 + i1*i2) / (r2*r2 + i2*i2)
	//i3 = (-r1*i2 + i1*r2) / (r2*r2 + i2*i2)

	Complex temp;

	temp.real = ( real * o.real + imaginary * o.imaginary) / (o.real *o.real + o.imaginary * o.imaginary );
	temp.imaginary = (-1 * real * o.imaginary + imaginary * o.real)/ (o.real *o.real + o.imaginary * o.imaginary );

	return temp;
}

ostream& operator <<(ostream & out, Complex & c)
{
	if(c.imaginary >= 0)
		out<<"\n"<<c.real<<"+i"<<c.imaginary;
	else
		out<<"\n"<<c.real<<"-i"<<c.imaginary * -1;
	return out;
}

int main()
{
	int ch;
	Complex c1(5, 3), c2(7,1), c3;

	do
	{
		cout<<"\n 1. set complex number 1 ";
		cout<<"\n 2. set complex number 2 ";
		cout<<"\n 3. Add ";
		cout<<"\n 4. Subtract ";
		cout<<"\n 5. Multiply ";
		cout<<"\n 6. Divide ";
		cout<<"\n 7. Exit ";
		cout<<"\n enter choice : ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				c1.set();
				break;
			case 2:
				c2.set();
				break;
			case 3:
				c3 = c1 + c2;
				cout<<c1<<c2<<c3;
				break;
			case 4:
				c3 = c1 - c2;
				cout<<c1<<c2<<c3;
				break;
			case 5:
				c3 = c1 * c2;
				cout<<c1<<c2<<c3;
				break;
			case 6:
				c3 = c1 / c2;
				cout<<c1<<c2<<c3;
				break;
		}

	}while(ch != 7);

}
