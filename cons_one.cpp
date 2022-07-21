#include <bits/stdc++.h>
#include<string>
using namespace std;
int count(string s)
{
	int res=0;
	int cou=0;
	for(int i=0;i<s.length()-1;i++)
	{
		if(s[i]=='1')
		{
			cou++;
			res=max(res,cou);
		}
		else
			cou=0;
	}
	return res;
}
int main()
{
	string s;
	cin>>s;
	cout<<count(s);
}