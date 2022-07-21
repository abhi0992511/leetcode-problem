#include <bits/stdc++.h>
using namespace std;
#include "fraction.cpp"
int main()
{
	fraction f1(10,5);
	f1.simplfy();
	f1.print();
	fraction f2(2,5);
	f1.add(f2);
	f1.print();
	f1.multiply(f2);
	f1.print();
	fraction const f3;
	f3.getnum();
	f3.print();
	fraction f5=f1+f2;
	f5.print();
	f5=f1-f2;
	f5.print();
	if (f1==f1)
	{
		cout<<"equal";

	}
	else
		cout<<"not equal";
	f2=f5/f1;
	f2.print();
	f1=f2*f5;
	f1.print();
	++f1;
	f1.print();
	++(++f1);
	f1.print();
	fraction f6(4,5);
	fraction f7(3,7);
	f7++;
	f7.print();
	f6+=f7;
	f6.print();
	


}