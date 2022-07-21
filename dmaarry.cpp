#include <bits/stdc++.h>
using namespace std;
#include "DMAarray.cpp"
int main()
{
	dynamicArray d;
	d.add(5);
	d.add(6);
	d.add(55);
	d.add(98);
	d.add(101);
	d.add(5);
	d.add(6);
	d.add(55);
	d.add(98);
	d.add(101);
	d.print();
	d.add(4,52);
	d.print();
	// d.positionadd(2,5);
	// d.print();
}