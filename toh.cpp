#include<bits/stdc++.h>
using namespace std;
void toh(int n,char source,char desti,char axu)
{
	if(n==1)
	{
		cout<<"from "<<source<<" "<<"to"<<desti<<endl;
		return;
	}
	toh(n-1,source,axu,desti);
	cout<<"from "<<" "<<source<<" "<<"to "<<desti<<endl;
	toh(n-1,axu,desti,source);
}
int main()
{
	int n;
	cout<<"enter the no disk";
	cin>>n;
	// ';char source ='A';
	// char desti='C';
	// char axu='B
	toh(n,'A','C','B');
	return 0;
}