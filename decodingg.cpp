#include <bits/stdc++.h>
#include <string>
using namespace std;
//RECURSIVE+MEMOISATION:
int dp[101];
int decode(string s)
{
	int m=s.length();
	if(m==0)
		return 1;
	if(m==1)
		return 1;
	if (dp[m]>0)
	{
		return dp[m];
	}
	if(s[0]-'0'>0)
	{
    
    int ans=decode(s.substr(1));
      if(s[0]-'0'>0)
      {
           if((s[0]-'0')*10+(s[1]-'0')<=26)
           	ans=ans+decode(s.substr(2));
      }
      else
      ans=0;
       dp[m]=ans;
      return ans;
	}
	return 0;
}
//DP
int decode1(string s)
{
	int m=s.size();
	int *res=new int[m+1];
	res[0]=1;
	res[1]=1;
	for (int i = 2; i < m+1; ++i)
	{
		 int first=s[i]-'0';
		 int second= s[i-1]-'0';
		 res[i]=res[i-1];
		 if(second*10+first<=26)
		 	res[i]=res[i]+res[i-2];
	}
	return res[m];
}
int main()
{
	string s;
	cin>>s;
	memset(dp,0,sizeof(dp));
	cout<<decode1(s)<<endl;
	cout<<decode(s);
}