#include <bits/stdc++.h>
using namespace std;
#include "stackclass1.cpp"
int main()
{
	stackusingLL <char> s;
	s.push(100);
	s.push(101);
	s.push(102);
	s.push(103);
	s.push(104);
	s.push(105);
	s.push(106);
	s.push(107);
	s.push(108);
	s.push(109);
	s.push(110);
	s.push(111);
	cout<<s.pop()<<endl;
	cout<<s.top()<<endl;
	cout<<s.length()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.length()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.length()<<endl;
	cout<<s.isEmpty()<<endl;
}