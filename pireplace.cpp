#include<bits/stdc++.h>
#include<string>
using namespace std;
string replace(string s)
{
	if(s.length()==0||s.length()==1){
	return s;


}
if(s[0]=='p'&&s[1]=='i')
{
	string small=replace(s.substr(2));
	return "3.14"+small;
}
else
	return s[0]+replace(s.substr(1));
}
int main()
{
	string s;
	cout<<"enter a string";
	string res=replace(s);
	cout<<res;
	return 0;

}