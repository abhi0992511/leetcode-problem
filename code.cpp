#include <bits/stdc++.h>
using namespace std;
vector<int> Solution::solve(vector<int> &A) {
    vector<int>ans;
    for(int i=0;i<A.size();i++)
    {
        ans[i]=-1;
        for(int j=0;j<A.size();j++)
        {
            if(A[i]!=0 && A[j]!=0)
            {
                if(A[i]%A[j]==0 ||A[j]%A[i]==0)
                ans[i]++;
            }
        }
    }
    return ans;
}
