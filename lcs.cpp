#include <bits/stdc++.h>
using namespace std;
//RECURSIVE:
int lcs(string s,string t)
{   
    if (s.size()==0||t.size()==0)
    {
    	return 0;
    }


	if (s[0]==t[0])
	{
		return 1+lcs(s.substr(1),t.substr(1));
	}
	int x=lcs(s.substr(1),t);
	int y=lcs(s,t.substr(1));
	//int z=lcs(s.substr(1),t.substr(1));
	return max(x,y);

}
//MEMOSIATION:
int helper(string s,string t,int **dp)
{
   int m=s.length();
   int n= t.length();
   int ans;
	if (m==0||n==0)
	{
		return 0;
	}
	if (dp[m][n]!=-1)
	{
		return dp[m][n];
	}
	if (s[0]==t[0])
	{
	   ans=1+helper(s.substr(1),t.substr(1),dp);
	   dp[m][n]=ans;
	}
	else
	{
		int a=helper(s.substr(1),t,dp);
		int b=helper(s,t.substr(1),dp);
		//int c=helper(s.substr(1),t.substr(1),dp);
		ans=max(a,b);
	}
	
	dp[m][n]=ans;
	return ans;
}
int lcs1(string s,string t)
{
   

   int m=s.length();
   int n=t.length();
   int **op=new int *[m+1];
   for (int i = 0; i < m+1; ++i)
   {
    op[i]=new int [n+1];
   }
   for (int i = 0; i < m+1; ++i)
   {
   	for (int j=0;j<n+1;j++)
   	{
   		op[i][j]=-1;
   	}
   }




	return helper(s,t,op);
}
//DP:
void lcs2(string s,string t)
{
	 int m= s.length();
	 int n=t.length();
	int **op=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		op[i]=new int[n+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		op[i][0]=0;
	}
	for (int i = 0; i < n+1; ++i)
	{
         op[0][i]=0;
	}
	for (int i=1;i< m+1; ++i)
	{
	for(int j=1;j<n+1;j++)
	{
		if (s[m-i]==t[n-j])
		{
			op[i][j]=1+op[i-1][j-1];
		}
		else
		{
			int a=op[i-1][j-1];
			int b=op[i-1][j];
			int c=op[i][j-1];
			op[i][j]=max(a,max(b,c));
		}

	}
	
	}
     for (int i = 0; i < m+1; ++i)
     {
     	for (int j=0;j<n+1;j++)
     	{
     		cout<<op[i][j]<<" ";
     	}
     	cout<<endl;
     }
     cout<<op[m][n];
}
int main()
{
	string s,t;
	cin>>s>>t;
 cout<<lcs(s,t)<<endl;
	cout<<lcs1(s,t)<<endl;
	lcs2(s,t);

}