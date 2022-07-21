#include <bits/stdc++.h>
#include <vector>
using namespace std;
    vector<int>NSL(vector<int>&height)
    {
        vector<int>left;
        stack<pair<int,int>>s;
        for(int i=0;i<height.size();i++)
        {
            if(s.size()==0)
            {
                left.push_back(-1);
            }
            else if(s.size()>0&&s.top().first<height[i])
            {
                left.push_back(s.top().second);
            }
            else if(s.size()>0&&s.top().first>=height[i])
            {
                while(s.size()>0&&s.top().first>=height[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                    left.push_back(-1);
                else
                    left.push_back(s.top().second);
            }
            s.push({height[i],i});
        }
        return left;
    }
    vector<int>NSR(vector<int>&height)
    {
        vector<int>right;
        stack<pair<int,int>>s;
        for(int i=height.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                right.push_back(height.size());
            }
            else if(s.size()>0&&s.top().first<height[i])
            {
            right.push_back(s.top().second);
            }
            else if(s.size()>0&&s.top().first>=height[i])
            {
                while(s.size()>0&&s.top().first>=height[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                    right.push_back(height.size());
                else
                    right.push_back(s.top().second);
            }
            s.push({height[i],i});
        }
        reverse(right.begin(),right.end());
        return right;
    }
    int maximalRectangle(vector<int>height) {
        // vector<int>height(matrix[0].size(),0);
        // for(int i=0;i<matrix.size();i++)
        // { 
        //     int sum=0;
        //     for(int j=0;j<matrix[0].size();j++)
        //     {
        //         if(matrix[j][i]=='0')
        //         {
        //             sum=sum;
        //         }
        //         else
        //             sum=sum+1;
        //     }
        //     height.push_back(sum);
        // }
        vector<int>l=NSL(height);
        vector<int> r=NSR(height);
        vector<int>width;
        vector<int>ans;
        for(int i=0;i<height.size();i++)
        {
            width.push_back(r[i]-l[i]-1);
        }
        for(int i=0;i<height.size();i++)
        {
            ans.push_back(width[i]*height[i]);
        }
        int res=INT_MIN;
        for(int i=0;i<height.size();i++)
        {
            res=max(res,ans[i]);
        }
        return res;
            
        
    }
int main()
{
	int n,m;
	cin>>m>>n;
	vector<vector<char>>matrix(m,vector<char>(n));
	for(int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
	vector<int>height(n,0);
	int mx=0;
	for (int i = 0; i < m; ++i)
	{  
		
		for(int j=0;j<n;j++)
		{
           if (matrix[i][j]=='0')
           {
           height[j]=0;
           }
           else
           	height[j]=height[j]+1;
		}
		mx=max(mx,maximalRectangle(height));
		
	}
	cout<<mx;

}