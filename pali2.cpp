#include <bits/stdc++.h>
#include <string>
using namespace std;
string without_any_spec_char(string s)
{
	for(int i=0;i<s.length();i++)
        s[i]=tolower(s[i]);
    string b;
    int j=0;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>='a'&&s[i]<='z')||(s[i]>=1-'0'&&s[i]<=9-'0'))
        {
             b.push_back(s[i]);
            
        }
        
    }
    return b;
}
int main()
{
	string s;
	cin>>s;
	cout<<without_any_spec_char(s);
}