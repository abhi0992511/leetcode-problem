#include <bits/stdc++.h>
#include <string>
using namespace std;
string binary_represent(long long int n)
{
 string s="";
 while(n>0)
 {
 	if(n%2==0)
 	{
 		s=s+'0';
 		n=n/2;
 	}
 	else
 	{
       s=s+'1';
       n=n/2;
 	}
 }
 reverse(s.begin(),s.end());
 return s;
}
int main()
{
	long long int n;
	cin>>n;
	cout<<binary_represent(n);
}