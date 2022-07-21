#include <bits/stdc++.h>

#include <string>
using namespace std;
int length(char str[])
{
	if(str[0]=='\0')
	{
		return 0;
	}
	int small=length(str+1);
	return 1+small;
}
void pairstar(char str[],int start)
{
	if(str[start]=='\0')
	{
		return;
	}
	pairstar(str,start+1);
	if (str[start]==str[start+1])
	{
		int l=length(str);
		for (int i = l; i >=start+1; i--)
		{
			str[i+1]=str[i];

		}
		str[start+1]='*';
	}
	
	// if(str[0]==str[1])
	// {
	// 	int i=1;
	// 	int count=0;
	// 	for ( ; str[0]!='\0'; i++)
	// 	{
	// 		count++;	
	// 	}
	// 	// str[1]="*";
	// 	// pairstar(str+1);
	// 	for (int i = count+2; i >1; i--)
	// 	{
	// 		str[i]=str[i-1];
	// 	}
	// 	str[1]='*';
		
		
	// }
	// pairstar(str+1);
	
}
int main()
{
char  str[100];
cout<<"enter the string";
cin>>str;
 pairstar(str,0);
cout<<str;
}