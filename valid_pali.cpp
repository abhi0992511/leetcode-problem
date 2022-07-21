#include <bits/stdc++.h>
using namespace std;
string solve(string s)
{
	 transform(s.begin(),s.end(),s.begin(),::tolower);
        string a="";
        for(int i=0;i<s.length();i++)
        {
           if(s[i]>64&&s[i]<92)
           	 a+=tolower(s[i]);
           	else if(s[i]>96&&s[i]<123)
           		a+=s[i];
           	
        }
        return a;
}
int main()
{
	string s;
	cin>>s;
	cout<<solve(s);

}