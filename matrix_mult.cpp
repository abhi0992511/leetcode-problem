#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r,c,r1,c1;
	cin>>r>>c>>r1>>c1;
	int **m1=new int *[r];
	int **m2=new int *[r1];
	//FIRST_MATRIX:
	for (int i = 0; i < r; ++i)
	{
		m1[i]=new int [c];

	}
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin>>m1[i][j];
		}
	}
	//SECOND_MATRIX:
	for (int i = 0; i < r1; ++i)
	{
		m2[i]=new int [c1];

	}
	for (int i = 0; i < r1; ++i)
	{
		for (int j = 0; j < c1; ++j)
		{
			cin>>m2[i][j];
		}
	}
	//1ST_TRAVERSAL:
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
	//2ND_TRAVERSAL:
	for (int i = 0; i < r1; ++i)
	{
		for (int j = 0; j < c1; ++j)
		{
			cout<<m2[i][j]<<" ";
		}
		cout<<endl;
	}
//MULTIPLICATION:
	if(c!=r1)
	{
		cout<<"INVALID INPUT";
	}
	else
	{
		int **m3=new int* [r];

		for (int i = 0; i < r; ++i)
		{
			m3[i]=new int [c1];
		}
		for (int i = 0; i < r; ++i)
		{
			for(int j=0;j<c1;j++)
			{
				for(int k=0;k<c;j++)
				{
					m3[i][j]+=m1[i][k]+m2[k][j];
				}
			}
		}
		for (int i = 0; i < r; ++i)
	{
		for(int j=0;j<c1;j++)
		{
			cout<<m3[i][j]<<" ";
		}
		cout<<endl;
	}
	}















}