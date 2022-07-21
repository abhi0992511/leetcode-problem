#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace  std;

vector<string>keyboard(string s,vector<string>&mp)
{
	if(s.length()==0)
	{
		vector<string>empty;
		empty.push_back("");
		return empty;
	}
	char a=s[0];
	string sub=s.substr(1);
	vector<string>res=keyboard(sub,mp);
	vector<string>ans;
	string code=mp[a-'0'];
	for(int i=0;i<code.length();i++)
	{
		char x=code[i];
		for(string i:res)
		{
			ans.push_back(i+x);
		}
	}
	return ans;
}
int main()
{
	string s;
	cin>>s;
	vector<string>mp={".,","abc","def","ghi","jkl","mno","pqrs","tuv","xyz","#*"};
	vector<string>ans=keyboard(s,mp);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
}