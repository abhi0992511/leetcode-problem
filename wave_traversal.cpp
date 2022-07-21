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
	for (int i = 0; i < r; ++i)
	{
		for (int j=0;j<c;j++)
		{
		    cin>>a[i][j];
		}
	}
	for (int i = 0; i < r; ++i)
	{
	  for(int j=0;j<c;j++)
	  {
	  	cout<<a[i][j]<<" ";
	  }
	  cout<<endl;
	}
	//WAVE_TRAVESRSAL:
	for (int i=0;i<c; i++)
	{
		if (i%2==0)
		{
			for (int j=0;j<r;j++)
			{
				cout<<a[i][j];
				
			}
		}
		else{
			for(int j=r-1;j>=0;j--)
			{
				cout<<a[i][j];

			}
			
		}
		cout<<endl;
		
	}
}