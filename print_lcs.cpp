#include <bits/stdc++.h>
using namespace std;
string p_lcs(string s,string a,int m,int n)
{

	string ans="";
	int **dp=new int *[m+1];
	for (int i = 0; i < m+1; ++i)
	{
		dp[i]=new int [n+1];
	}
	for (int i = 0; i < m+1; ++i)
	{
		dp[i][0]=0;
	}
	for (int i = 0; i < n+1; ++i)
	{
		dp[0][i]=0;
	}
	for (int i = 1; i < m+1; ++i)
	{
		for(int j=1;j<n+1;j++)
		{
			if (s[i-1]==a[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				int x=dp[i-1][j];
				int y=dp[i][j-1];
				dp[i][j]=max(x,y);
			}
		}
	}
	int i=m;
	int j=n;
	while(i>0&&j>0)
	{
		if (s[i-1]==a[j-1])
		{
			ans.push_back(s[i-1]);
			i--;
			j--;
		}
		else
		{

			if (dp[i-1][j]>dp[i][j-1])
			{
				i--;
			}
			else
				j--;
		}
	}
reverse(ans.begin(),ans.end());
return ans;
}

// string lcs(string a,string b)
// { 
//     int n=a.length();
//     int m=b.length();
//     int **dp=new int *[n+1];
//   for(int i=0;i<n+1;i++)
//    dp[i]=new int[m+1];
//    for(int i=0;i<m+1;i++)
//    {
//        dp[0][i]=0;
//    }
//    for(int i=0;i<n+1;i++)
//       dp[i][0]=0;
//    for(int i=1;i<n+1;i++)
//    {
//        for(int j=1;j<m+1;j++)
//        {
//              if(a[i-1]==b[j-1])
//               {
//                   dp[i][j]=dp[i-1][j-1]+1;
//               }
//               else
//               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//        }
//    }
//    int i=m;
//    int j=n;
//    string s="";
//    while(i>0&&j>0)
//    {
//        if(a[i-1]==b[j-1])
//        {
//            s.push_back(a[i-1]);
//            i--;
//            j--;
//        }
//        else
//        {
//            if(dp[i-1][j]>dp[i][j-1])
//            {
//                i--;
//            }
//            else
//            j--;
//        }
//    }
//    reverse(s.begin(),s.end());
//    return s;
// }
int main()
{
	string s,a,b;
	cin>>s>>a;
	b=s;
	//reverse(s.begin(),s.end());

	//a=s;
	int m=s.length();
	int n=a.length();
	cout<<p_lcs(b,a,m,n);
	//cout<<lcs(a,b);
}