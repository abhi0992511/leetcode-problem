#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<string>s;
	for (int i = 0; i < 6; ++i)
	{  
		string x;
		cin>>x;
		s.push_back(x);
	}
	for (int i = 0; i < s.size(); ++i)
	{
		string a=s[i];
		sort(a.begin(),a.end());
		s[i]=a;
	}
	for (int i = 0; i < s.size(); ++i)
	{
		cout<<s[i]<<endl;
	}
}