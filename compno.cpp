
#include <iostream>
using namespace std;
#include "complex.cpp"
int main()
{
	// int r1,r2,i1,i2;
	// cin>>i1>>i2>>r1>>r2;
	complex c1(10,5);
	complex c2(65,3);
	c1.print();
	c2.print();
	int choice;
	cin>>choice;
	if (choice==1)
	{
		c1.add(c2);
		c1.print();
	}
	else if (choice==2)
	{
		c1.sub(c2);
		c1.print();
	}
	else if (choice==3)
	{
		c1.multiply(c2);
		c1.print();
	}
	else
		return 0;
}