#include <bits/stdc++.h>
#include <string>
using namespace std;
int to_number(string s)
{
	 int sum=0;
        int n=s.length();
        if(s[n-1]=='1')
            sum=sum+1;
        else
            sum=sum+0;
        int res=1;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='1')
            {
                res=2*res;
                sum=sum+res;    
            }
            else
            {
                res=2*res;
                sum=sum+0;
            }
        }
        return sum;
}
int main()
{
	string s;
	cin>>s;
	cout<<to_number(s);
}