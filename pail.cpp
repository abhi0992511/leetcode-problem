#include <bits/stdc++.h>
using namespace std;
int palid(string s,int start,int last)
{
	if(start==0||last==1)
	{
		return 1;
	}
	else
	{
		if(s[start]==s[last])
	{
		//return 0;
		 return palid(s,start+1,last-1);

	}
	else
	
	return  0;
	}
	  // if(last==1 || start==0)
   //  {
   //      return 1;
   //  }
   //  else
   //  {
   //      if(s[start]==s[last])
   //      {
   //          return palid(s,start+1,last-1); 
   //      }
   //      else
   //      {
   //          return 0;
   //      }
   //  }
}
int main()
{
	string s;
	cin>> s;
	int start=0;
	int last=s.length();
	//cout<<s;
	int x =palid(s,start,last);
	if(x==1)
	{
		cout<<"true";
	}
	else
		cout<<"false";
}