#include <bits/stdc++.h>
#include <string>
using namespace std;
//MIN_DEL_OF_A_&_B:
int st(string s)
{
   int a=0,b=0,ca=0,cb=0;
   for(auto c:s)
   {
   	if(c=='a')ca++;
   	else
   		cb++;

   }
   int ans;
   for(int i=0;i<s.length();i++)
   {
   	if(s[i]=='a')
   		a++;
   	else
   		b++;
   	ans=min(ans,ca-a+b);
   }
   return ans;   
}
int main()
{
	string a;
	cin>>a;
	cout<<st(a);
}