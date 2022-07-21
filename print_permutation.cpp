#include <bits/stdc++.h>
#include <string>
using namespace std;
void print_permutation(string s,string ans,int &count)
{
	if (s.length()==0)
	{  count++;
		cout<<ans<<" ";
	}
	for (int i = 0; i < s.length(); ++i)
	{
		char ex=s[i];
		string l=s.substr(0,i);
		string r=s.substr(i+1);
		string com=l+r;
		print_permutation(com,ans+ex,count);
	}
	return;
}
int main()
{
	string s;
	cin>>s;
	int count=0;
	print_permutation(s,"",count);
	cout<<count<<" ";
}