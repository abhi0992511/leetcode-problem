#include <bits/stdc++.h>
using namespace std;
string break_pali(string s)
{
	string a="";
	if(s.length()==1)
		return a;
	for (int i = 0; i < s.length()/2; ++i)
	{
		if (s[i]!='a')
		{
			s[i]='a';
			return s;
		}

	}
	if(s[s.length()-1]=='a')
		return "IMPOSSIBLE";
	s[s.length()-1]='b';
	return s;

}
int main()
{
	string s;
	cin>>s;
	cout<<break_pali(s);
}