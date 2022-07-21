#include <bits/stdc++.h>
#include<math.h>
using namespace std;
int subs(string s,string output[])
{
	if(s.size() ==0)
	{
		output[0]=" ";
		return 1;
	}
	string small=s.substr(1);
	int size=subs(small,output);
	for (int i = 0; i < size; i++)

	{
	   output[i+size]=s[0]+output[i];
	}
	return 2*size;
}
int main()
{
	string s;
	cout<<"enter the string";
	cin>>s;
	int len=s.size();
	int outputsize=pow(2,len);
	string *output=new string[outputsize];
	int count=subs(s,output);
	for (int i = 0; i < count; i++)
	{
		cout<<output[i]<<endl;
	}
}