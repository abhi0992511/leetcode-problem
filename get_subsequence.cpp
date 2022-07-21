#include <bits/stdc++.h>
#include <string>
using namespace std;
//RECURSIVE:
void get_subsequence(string s,string output)
{
	if (s.length()==0)
	{
		cout<<output<<" ";
		return;
	}
	//include:
	get_subsequence(s.substr(1),output+s[0]);
	//not_include:
	get_subsequence(s.substr(1),output);

}
//using_vector;
vector<string>get_subsequence(string s)
{
	if(s.length()==0)
	{
		vector<string>empty;
		empty.push_back("");
		return empty;
	}
	char c=s[0];
	string sub=s.substr(1);
	vector<string>seq=get_subsequence(sub);
	vector<string>res;
	for(string i:seq)
	{
		res.push_back(i);
		res.push_back(c+i);
	}
	return res;

}
 vector<string>help(string s)
    {
        if(s.length()==0)
        {
            vector<string>empty;
            empty.push_back("");
            return empty;
        }
        char c=s[0];
        string sub=s.substr(1);
        vector<string>seq=help(sub);
        vector<string>ans;
        for(string i:seq)
        {
            ans.push_back(i);
            
        }
        for(string i:seq)
        	ans.push_back(c+i);
        return ans;
    }
int main()
{
	string s;
	cin>>s;
	string output="";
	vector<string>ans=help(s);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	get_subsequence(s,output);
}