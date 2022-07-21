#include <bits/stdc++.h>
#include <string.h>
using namespace std;

 void sub(string input,string output)
 {
 	if(input.length()==0)
 	{
 		cout<<output<<endl;
 		return;
 	}
 	sub(input.substr(1),output);
 	sub(input.substr(1),output+input[0]);
 }
int main()
{
	string input;
	cout<<"enter the string";
	cin>>input;
	string output=" ";
	sub(input,output);
	return 0;
}