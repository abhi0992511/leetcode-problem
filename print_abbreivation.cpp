#include <bits/stdc++.h>
#include<string>
using namespace std;
void print_abrev(string s,string output,int count)
{
	if (s.length()==0)
	{
		if (count==0)
		{
			cout<<output<<" ";
		}
		else
			cout<<output<<to_string(count)<<" ";
		return;
	}
	if (count>0)
	{
		print_abrev(s.substr(1),output+to_string(count)+s[0],0);
	}else
	print_abrev(s.substr(1),output+s[0],0);
	print_abrev(s.substr(1),output,count+1);

}
int main()
{
	string s;
	cin>>s;
   print_abrev(s,"",0);

}