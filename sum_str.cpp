#include <bits/stdc++.h>
#include <string>
using namespace std;

int sum_str(string s)
{   
	int x=s[0]-'0';
	int ans=0;
	int res=0;
	for(int i=0;i<s.length();i++)
	{
        int y=s[i]-'0';
        ans=ans*10+y*(i+1);
        res=res+ans;
	}
	return res;
}
int main()
{
	string s;
	cin>>s;
	cout<<sum_str(s);
}