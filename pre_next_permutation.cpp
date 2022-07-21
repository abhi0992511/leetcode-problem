#include <bits/stdc++.h>
#include <string>
using namespace std;
void nex_permutation(string s)
{
	sort(s.begin(),s.end());
	cout<<s<<" ";
	while(next_permutation(s.begin(),s.end()))
	{
		cout<<s<<" ";
	}
}
void pre_permutation(string s)
{
	sort(s.begin(),s.end());
	reverse(s.begin(),s.end());
	cout<<s<<" ";
	while(prev_permutation(s.begin(),s.end()))
	{
		cout<<s<<" ";
	}
}

int main()
{
	string s;
	cin>>s;
	nex_permutation(s);
	cout<<endl;
	pre_permutation(s);
}