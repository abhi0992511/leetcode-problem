#include <bits/stdc++.h>
using namespace std;
int pali(string s,int i,int j)
{

   if(i==1&&j==1)
   	return 1;
   while(i<j)
   {
   	if(s[i]==s[j])
   	{
   		i++;
   		j--;
   	}
   	else
   	{
   		return 0;
   	}
   }
   return 1;

}
int main()
{
	string s;
	cin>>s;
	int m=s.length();
	cout<<pali(s,0,m-1);
}