#include <bits/stdc++.h>
using namespace std;
long long solve(int N, vector<long long> A) {
       long long ans=INT_MIN;
       int index=0;
       int k=1;
       while(k<=N)
       {  
           long long sum=0;
          for(int i=k;i<A.size();i=i+k)
          {
              sum=sum+A[i-1];
          }
          if(sum>ans)
          {
              ans=sum;
              index=k;
          }
           k++;
       }
       return index;
    }
int main()
{
int n;
cin>>n;
vector<long long>a;
for(int i=0;i<n;i++)
   {
   	long long x;
   	cin>>x;
   	a.push_back(x);
   }
   cout<<solve(n,a);
}