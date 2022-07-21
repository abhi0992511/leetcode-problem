#include <bits/stdc++.h>
#include<string>
#include <vector>
using namespace std;
vector<string>key={".,","abc","cde","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void keypard(string s,string output)
{
	if (s.length()==0)
	{
		cout<<output<<" ";
		return;
	}
	char a=s[0];
	string code=key[a-'0'];
	for (int i = 0; i < code.length(); ++i)
	{
		keypard(s.substr(1),output+code[i]);
	}
	return;
}
int main()
{
	string s;
	cin>>s;
	keypard(s,"");
}