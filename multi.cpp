#include<bits/stdc++.h>
using namespace std;
int multi(int n,int m)
{
     if(m==1)
     {
     	return n;

     }
     return n+multi(n,m-1);

}
int main()
{
 int n,m;
 cout<<"enter the no";
 cin>>n>>m;
 int x=multi(n,m);
 cout<<x;

}