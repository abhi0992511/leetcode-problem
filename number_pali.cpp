#include <bits/stdc++.h>
using namespace std;
int ispali(int a)
{     
	string s="";
	s=to_string(a);

	for(int i=0;i<s.length();i++)
	{
		if(s[i]!=s[s.length()-1-i])
			return false;
	}
	return true;

}
int pali(int n)
{
   
  int k=n;

 int sum=0;
 while(n>0)
 {
 	int res=n%10;
 	n=n/10;
 	sum=sum*10+res;
 }
 if(ispali(sum+k))
 	return sum+k;
 else
   return pali(sum+k);




}
int main()
{
	int n;
	cin>>n;
	cout<<pali(n);
}