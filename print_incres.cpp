#include <bits/stdc++.h>
using namespace std;
void print_increse(int n)
{
  if(n<0)
  	return;
  print_increse(n-1);
  cout<<n<<" ";
}
int main()
{
	int n;
	cin>>n;
	print_increse(n);
}