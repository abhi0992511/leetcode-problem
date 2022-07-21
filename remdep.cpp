#include <bits/stdc++.h>
using namespace std;
void dupli(char s[])
{
	if(s[0]=='\0')
	{
		return;
	}
	if(s[0]==s[1])
	{
		int i=1;
		for(;s[i]!='\0';i++)
		{
			s[i-1]=s[i];
		}
		s[i-1]=s[i];
		dupli(s);
	}
	dupli(s+1);
}
int main()
{
	char str[100];
	cout<<"enter the the string";
	cin>>str;
	dupli(str);
	cout<<str;
}