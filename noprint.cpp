#include<bits/stdc++.h>
using namespace std;
int print(int n)
{
	if(n==0)
	{
		return n;

	}
	print(n-1);
	  cout<< n<<" ";
	 // x=0;
}
int main()
{
	int n;
	cin>> n;
	print(n);

}