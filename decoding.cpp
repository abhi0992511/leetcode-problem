#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	string nums;
	cin>>nums;
	int *dp=new int[nums.length()];
	dp[0]=1;
	if (nums[0]=='1'||nums[0]=='2')
	{
		if (nums[1]=='0'||nums[1]=='1'||nums[0]=='2'||nums[1]=='3'||nums[1]=='4'||nums[1]=='5'||nums[1]=='6')
		{
			dp[1]=2;
		}
		else
			dp[1]=1;
	}
	else
		dp[1]=1;

    for (int i = 2; i <nums.length() ; ++i)
    {
    	if (nums[i]=='0'&&dp[i-1]=='0')
    	{
    		dp[i]=0;
    	}
    	else if (nums[i-1]=='0'&&dp[i]!='0')
    	{
    		dp[i]=dp[i-1];
    	}
    	else if (nums[i-1]!='0'&&nums[i]=='0')
    	{
    		 if (nums[i-1]=='1'||nums[i-1]=='2')
    		 {
    		 	dp[i]=dp[i-2];
    		 }
    		 else
    		 	dp[i]=0;
    	}
    	else
    	{  
    		int x=atoi(nums[i-1]);
    		int y=atoi(nums[i]);
    		if(x+y<=26)
    		{
    			dp[i]=dp[i-1]+dp[i-2];
    		}
    		else
    			dp[i]=dp[i-1];
    	}
    }







}