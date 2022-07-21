#include<bits/stdc++.h>
#include <vector>
using namespace std;
//TARGET_SUM AS WELL AS COUNT_SUBSET_WITH_DIIFERENCE:
//RECURSION:
int helper(int *nums,int x,int n)
    {
        if(n==0&&x==0)
            return 1;
        if(n==0)
            return 0;
        if(nums[0]<=x)
        {
            return helper(nums+1,x-nums[0],n-1)+helper(nums+1,x,n-1);
        }
        else
            return helper(nums+1,x,n-1);
    }
    int findTargetSumWays(int * nums, int target,int n) {
        int sum=0;
        for(int i=0;i<n;i++)
            sum=sum+nums[i];
        int x=(target+sum)/2;
        return helper(nums,x,n);
        
    }
    //MEMOIZASTION:
    int helper(int *a,int x,int n,int **dp)
    {
    	if(x==0)
    		return 1;
    	if (n==0)
    	{
    		return 0;
    	}
    	if (dp[n][x]!=-1)
    	{
    		return dp[n][x];
    	}
    	if (a[0]>x)
    	{
    		dp[n][x]=helper(a+1,x,n-1,dp);
    	}
    	else
    	{
    		dp[n][x]=helper(a+1,x-a[0],n-1,dp)+helper(a+1,x,n-1,dp);
    		return dp[n][x];
    	}
    }
    int target(int *a,int target,int n)
    {
    	int sum=0;
    	for (int i = 0; i < n; ++i)
    	{
    		sum=sum+a[i];
    	}
    	int x=(sum-target)/2;
    	int **dp=new int *[n+1];
    	for (int i = 0; i < n+1; ++i)
    	{
    		dp[i]=new int  [x+1];
    	}
    	for (int i = 0; i < n+1; ++i)
    	{
    		for(int j=0;j<x+1;j++)
    			dp[i][j]=-1;
    	}
    	return helper(a,x,n,dp);
    }
 int main()
 {
 	int n;
 	 cin>>n;
 	 int *nums=new int[n];
 	 for (int i = 0; i < n; ++i)
 	 {
 	 	cin>>nums[i];
 	 }
 	 int target1;
 	 cin>>target1;
     cout<<findTargetSumWays(nums,target1,n)<<endl;
     cout<<target(nums,target1,n);
 }