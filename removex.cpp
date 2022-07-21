#include<bits/stdc++.h>
using namespace std;
void remove(char s[])
{  if (s[0]=='\0')

{
	return;
}

if (s[0]=='x')
	{ int i=1;
		for( ;s[i]!='\0';i++)
		{
			s[i-1]=s[i];
			
		}
		s[i-1]=s[i];
		remove(s);

	}
	else
	remove(s+1);
}

	int len(char s[])
{
	if(s[0]=='\0')
	{
		return 0;

	}
	int small=len(s+1);
	return 1+small;
}
int main()
{
	char str[100];
	cout<<"enter a string";
	cin>>str;
	int length=len(str);
	cout<<length<<endl;
	remove(str);
	length=len(str);
	cout<<length<<endl;
	cout<<str;
}
