#include<bits/stdc++.h>
using namespace std;
#include <vector>
int main()
{
  
  priority_queue<int>p;
  int testcase;
  cin>>testcase;
  while(testcase)
  {
    int n;
     cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
      {
        p.push(a[i]);
      }
    testcase--;
  }
  while(!p.empty())
  {
    cout<<p.top()<<" ";
    p.pop();
  }

  


}