#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include"class.cpp"
int main()
{ char name[]="abhi";
	student s1;
	s1.setAge(10);
	s1.setRollno(24);
	s1.display();
	 student s2(10,20);
	 
	  s2.display();
	  student *s3=new student(s2);
	  student s4;
	  s4=*s3;
	  s4.display();
	  student s6(2,name,101);
	  s6.display1();
	  name[1]='v';
	  student s7(5,name,55);
	  s7.display1();
	  delete s3;

}