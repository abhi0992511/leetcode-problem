#include<bits/stdc++.h>
using namespace std;
void replace(char s[],char a,char b)
{
	if(s[0]=='\0')
		{
			return;
		}
		if(s[0]==a)
		{
			s[0]=b;
			replace(s+1,a,b);
		}
		else
			replace(s+1,a,b);
}
int main()
{
	char str[100];
	cout<<"enter the string";
	cin>>str;
	char a='\0',b='\0';
	cout<<"enter the replace char with that char";
	cin>>a>>b;
	replace(str,a,b);
	//cout<<a<<b;
	cout<<str;

}