#include <bits/stdc++.h>
using namespace std;
bool check_pali(string s,int i, int j)
{
	if (i==1&&j==1)
	{
		return true;
	}
	while(i<j)
	{
		if (s[i]==s[j])
		{
			i++;
			j--;
		}
		else
			return false;
	}
	return true;
}
//RECURSIVE:
int pali_part(string s,int i,int j)
{
	if (i>j)
	{
		return 0;
	}
	if (check_pali(s,i,j)==true)
	{
		return 0;
	}
	int ans=INT_MAX;
	for (int k=i;k<j;k++)
	{
		int temp=pali_part(s,i,k)+pali_part(s,k+1,j)+1;
		ans=min(ans,temp);
	}
	return ans;
}
//MEMOISATION:
int pali_part1(string s,int i,int j ,int**dp)
{
	if (i>j)
	{
		return 0;
	}
	if (dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if (check_pali(s,i,j)==true)
	{
		return 0;
	}
	int ans=INT_MAX;
	for(int k=i;k<j;k++)
	{
		int temp=pali_part1(s,i,k,dp)+pali_part1(s,k+1,j,dp)+1;
		ans=min(ans,temp);
	}
	dp[i][j]=ans;
	return dp[i][j];
}
//OPTIMISED:
int pali_part2(string s,int i,int j ,int**dp)
{
	if (i>j)
	{
		return 0;
	}
	if (dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	if (check_pali(s,i,j)==true)
	{
		return 0;
	}
	int ans=INT_MAX;
	for(int k=i;k<j;k++)
	{  

		int l,r;
		if(dp[i][k]!=-1)
			l=dp[i][k];
		else
			{
				l=pali_part2(s,i,k,dp);
				dp[i][k]=l;
			}

		if(dp[k+1][j]!=-1)
			r=dp[k+1][j];
		else
			{
				r=pali_part2(s,k+1,j,dp);
				dp[k+1][j]=r;
			}
		int temp=l+r+1;
		ans=min(ans,temp);
	}
	dp[i][j]=ans;
	return dp[i][j];
}

int main()
{
	string s;
	cin>>s;
	int j=s.length();
	int **dp=new int *[j+1];
	for (int i = 0; i <j+1; ++i)
	{
		dp[i]= new int[j+1];
	}
	for (int i = 0; i < j+1; ++i)
	{
		for(int s=0;s<j+1;s++)
			dp[i][s]=-1;
	}
	cout<<pali_part1(s,0,j-1,dp)<<endl;
	cout<<pali_part(s,0,j-1)<<endl;
	cout<<pali_part2(s,0,j-1,dp);
}