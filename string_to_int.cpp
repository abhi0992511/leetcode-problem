#include <bits/stdc++.h>
#include <string>
using namespace std;
int help(string s,int k)
{
	 string a="";
        for(int i=0;i<s.length();i++)
        {
            int x=s[i]%96;
             a=a+to_string(x);
        }
        //return a;
        int n=0;
        for(int i=0;i<a.length();i++)
        {
            int x=(a[i])%48;
            n=n+x;
        }
        return n;
       //  int sum=0;
       // while(k>0)
       // {
       //      while(n>0)
       //  { 
       //      int x=n%10;
       //      n=n/10;
       //      sum=sum+x;
        
       //  }
       //     k--;
       // }
       //  return sum;
    
}
int main()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	cout<<help(s,k);
}
