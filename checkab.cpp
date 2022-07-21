#include <bits/stdc++.h>
#include <string>
#include <iostream>
using namespace std;
 bool checkab(string input)
{
	if (input.length()==0)
	{
		return false;
	}
	else
		return true;
}
int main()
{
string input;
cin>>input;
//cout<<input;
bool res=checkab(input);
cout<<res;

}