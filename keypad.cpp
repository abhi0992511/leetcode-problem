#include <bits/stdc++.h>
#include <unordered_map>
#include <string.h>
using namespace std;
string dail(int n)
{
	unordered_map<int,string>m;
	m[0]=' ';
	m[1]=' ';
	m[2]="abc";
	m[3]="def";
	m[4]="ghi";
	m[5]="jkl";
	m[6]="mno";
	m[7]="pqrs";
	m[8]="tuv";
	m[9]="wxyz";
	return m[n];
}
void pk(int n,string output)
{
	if(n==0)
	{
		cout<<output<<endl;
		return;
	}
	string pd=dail(n%10);
	for(int i=0;i<pd.length();i++)
	{
      pk(n/10,output+pd[i]);
	}
}
void keypad(int n)
{
	pk(n,"");
}

int main()
{
	int n;
	cin>>n;
	keypad(n);

}