#include<bits/stdc++.h>
#include<string>
using namespace std;
void pairstar(string &input,string &output,int i=0)
{   
	output=output+input[i];
	if (i==input.length()-1)
	{
		
		return;
	}
	if (input[i]==input[i+1])
	{
		output=output+"*";
	}
	pairstar(input,output,i+1);
}
int main()
{
	string input;
	cout<<"enter the string";
	cin>>input;
	string output="";
	pairstar(input,output);
	cout<<output;

}
