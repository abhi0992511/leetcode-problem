#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
	char s[50];
	cin>>s;
	for(int i=0;s[i]!='/0';i++)
	{
		if (s[0]-'0'<=9||s[0]=='_')
		{
			cout<<"false";
		}
		else
			cout<<"true";
		break;
	}
}
