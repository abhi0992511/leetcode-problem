#include <bits/stdc++.h>
using namespace std;
int friend_pair(int n)
{
	if (n<=0)
	{
		return 0;
	}
	if(n<=2)
		return n;
	return friend_pair(n-1)+(n-1)*friend_pair(n-2);
}
int main()
{
	int n;
	cin>>n;
	cout<<friend_pair(n);
}