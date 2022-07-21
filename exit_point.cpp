#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,c;
	cin>>r>>c;
	int **a=new int*[r];
	for(int i=0;i<r;i++)
	{
		a[i]=new int [c];
	}
	for (int i = 0; i < r; i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	int dir=0;
	int i=0,j=0;
	//EXIT_POINT_MATRIX:
	while(true)
	{
		dir=(dir+a[i][j])%4;
		if (dir==0)
		{
			j++;
		}
	   else if (dir==1)
		{
		      i++;
		}
		else if (dir==2)
		{
			j--;
		}
		else if (dir==3)
		{
			i--;
		}
		 



		 if (i<0)
		{
			i++;
			break;
		}
		else if (i==r)
		{
			i--;
			break;
		}
		else if(j<0)
		{
			j++;
			break;
		}
		else if (j==c)
		{
			j--;
			break;
		}
	}
	cout<<i<<" "<<j; 
}