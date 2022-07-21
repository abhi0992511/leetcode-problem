#include<bits/stdc++.h>
#include <string>
using namespace std;
 int firstUniqChar(string s) {
        unordered_map<char, int>seen;
        for(int i=0;i<s.length();i++)
        {
           
            seen[s[i]]++;
        }
          int count=0; 
        for(int i=0;i<s.length();i++)
        {
            if(seen[s[i]]==1)
                count++;
        }
        return count;
    
        
        
    }
int main()
{
	string s;
	cin>>s;
	int count1=firstUniqChar(s);
	
	cout<<count1;

}