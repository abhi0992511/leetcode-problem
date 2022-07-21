#include <bits/stdc++.h>
#include <string>
using namespace std;
vector<string> permutation(string s,vector<string>res)
{
	sort(s.begin(),s.end());
	res.push_back(s);
	while(next_permutation(s.begin(),s.end()))
	{
		res.push_back(s);
	}
	return res;
}
int main()
{
	string s;
	cin>>s;
	vector<string>res;
	vector<string>ans= permutation(s,res);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	 cout<<endl;
	 sort(ans.begin(),ans.end());
	 for (int i =0;i<ans.size() ;++i)
	 {
	 	cout<<ans[i]<<" ";
	 }
}