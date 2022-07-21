#include <bits/stdc++.h>
#include <string>
using namespace std;
string next_higher(string s)
{
next_permutation(s.begin(),s.end());
return s;
}
int main()
{
	string s;
	cin>>s;
	cout<<next_higher(s);
}