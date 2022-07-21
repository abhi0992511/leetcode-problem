#include <bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;
 void keypad(vector <char> cha[],int input[],string output,int index)
{
  if (index==-1)
  {
  	cout<<output<<endl;
  	return;
  }
  int digit=input[index];
  int len=cha[digit].size();
  for (int i = 0; i < len; i++)
  {
  	keypad( cha,input,cha[digit][i]+output,index-1);
  }
}

int main()
{
	int n;
 vector<char>key[]={
 	{},
 	{},
 	{'a','b','c'},
 	{'d','e','f'},
 	{'g','h','i'},
 	{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}
 };
 
 cout<<"enter the size";
 cin>>n;
 int *input=new int [n];
 for (int i = 0; i < n; i++)
 {
 	cin>>input[i];
 }
  keypad(key,input," ",n-1);

}
