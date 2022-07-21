#include <bits/stdc++.h>
#include<vector>
using namespace std;
vector<int>NSL(vector<int>heights)
    {
        vector<int>left;
        stack<pair<int,int>>s;
        for(int i=0;i<heights.size();i++)
        {
            if(s.size()==0)
            {
                left.push_back(-1);
            }
            else if(s.size()>0&&s.top().first<heights[i])
            {
                left.push_back(s.top().second);
            }
            else if(s.size()>0&&s.top().first>=heights[i])
            {
                while(s.size()>0&&s.top().first>=heights[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    left.push_back(-1);
                }
                else
                    left.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        return left;

        }
    vector<int>NSR(vector<int>heights)
    {
        vector<int>right;
        stack<pair<int,int>>s;
        for(int i=heights.size()-1;i>=0;i--)
        {
            if(s.size()==0)
            {
                right.push_back(heights.size());
            }
            else if(s.size()>0&&s.top().first<heights[i])
            {
                right.push_back(s.top().second);
            }
            else if(s.size()>0&&s.top().first>=heights[i])
            {
                while(s.size()>0&&s.top().first>=heights[i])
                {
                    s.pop();
                }
                if(s.size()==0)
                {
                    right.push_back(heights.size());
                }
                else
                    right.push_back(s.top().second);
            }
            s.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        return right;

        }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> l=NSL(heights);
        vector<int> r=NSR(heights);
        vector<int>width;
        vector<int>ans;
        for(int i=0;i<l.size();i++)
            width.push_back(r[i]-l[i]-1);
        for(int j=0;j<heights.size();j++)
        {
            ans.push_back(width[j]*heights[j]);
        }
        
        int res=INT_MIN;
        for(int i=0;i<ans.size();i++)
        {
            res=max(res,ans[i]);
        }
        return res;
        
    }
int main()
{
	int n;
	cin>>n;
	vector<int>heights;
	for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			heights.push_back(x);
		}
	cout<<largestRectangleArea(heights)<<endl;
		vector<int>a=NSL(heights);
		vector<int>b=NSR(heights);
		for (int i = 0; i < a.size(); ++i)
		{
			cout<<a[i]<<" ";

		}
		cout<<endl;
		for (int i = 0; i < b.size(); ++i)
		{
			cout<<b[i]<<" ";

		}
		cout<<endl;
		
}