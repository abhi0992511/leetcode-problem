#include <bits/stdc++.h>
#include <string>
using namespace std;
void path_maze(int sc,int sr,int m,int n,string path)
{
	if (sc>n||sr>m)
	{
		return;
	}
	if (sc==n&&sr==m)
	{
		cout<<path<<" ";
		return;
	}
	for (int ms=1;ms<=m-sr;ms++)
	{    
		  char a=ms;
		path_maze(sc,sr+ms,m,n,path+a+"v");
	}
	for (int ms=1;ms<=m-sr&&ms<=n-sc;ms++)
	{
		path_maze(sc+ms,sr+ms,m,n,path+"h");
	}
	for (int ms=1;ms<=n-sc;ms++)
	{
		path_maze(sc+ms,sr,m,n,path+"d");
	}
	return;
}
int main()
{
	int m,n;
	cin>>m>>n;
	path_maze(1,1,m,n,"");
}
