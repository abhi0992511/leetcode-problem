#include <bits/stdc++.h>
using namespace std;

class bus{
public:
	void print();
};
void test();



class truck
{
private:
	int x;
	protected:
		int y;
	public:
		int z;
	//defing the friend function
	friend void bus ::print();
	friend void test();	
};
void bus::print()
{
	truck t;
	t.x=20;
	t.y=30;
	t.z=50;
	cout<<t.x<<" "<<t.y<<" "<<t.z<<endl;
}
void test()
{
	truck a;
	a.x=5;
	cout<<a.x;
}

int main()
{
	bus b;
	b.print();
	test();
}