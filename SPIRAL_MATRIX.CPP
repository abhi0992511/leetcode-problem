#include <bits/stdc++.h>
using namespace std;
int main()
{
	int r,c;
	cin>>r>>c;
	int **a=new int*[r];
	for (int i = 0; i < r; ++i)
	{
		a[i]=new int[c];
	}
	for (int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	int minr=0,minc=0,maxr=r-1,maxc=c-1;
	int te=r*c;
	int cn=0;
	//SPIRAL:
	while(cn<=te)
	{
		//LEFT:
		for(int i=minr,j=minc;i<=maxr&&cn<=te;i++)
		{
			cout<<a[i][j]<<" ";
			cn++;
		}
		minc++;
		//BOTTOM:
		for(int i=maxr,j=minc;j<=maxc&&cn<=te;j++)
		{
			cout<<a[j][i]<<" ";
			cn++;
		}
		maxr--;
        //RIGHT:
		for(int i=maxc,j=maxr;j>=minr&&cn<=te;j--)
		{
			cout<<a[j][i]<<" ";
			cn++;
		}
		maxc--;
		//TOP:
		for(int i=maxc,j=minr;j>=minc&&cn<=te;j--)
		{
			cout<<a[j][i]<<" ";
			cn++;
		}
		minr++;
	}
	// while(cn<te)
	// {
	// 	//LEFT:
	// 	for(int i=minr,j=minc;i<maxr&&cn<te;i++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 		cn++;
	// 	}
	// 	minc++;
	// 	// BOTTOM:
	// 	for(int i=maxr,j=minc;j<maxc&&cn<te;i++)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 		cn++;
	// 	}
	// 	maxr--;
	// 	//RIGHT:
	// 	for(int i=maxr,j=maxc;i>minr&&cn<te;i--)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 		cn++;
	// 	}
	// 	maxc--;
	// 	//TOP:
	// 	for(int i=minr,j=maxc;j>maxc&&cn<te;j--)
	// 	{
	// 		cout<<a[i][j]<<" ";
	// 		cn++;
	// 	}
	// 	minr++;
	//}

}