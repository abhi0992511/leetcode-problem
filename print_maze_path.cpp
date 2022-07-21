#include <bits/stdc++.h>
#include <string>
using namespace std;
void path_maze(int sr,int sc,int m,int n,string path)
{
	if(sr>m||sc>n)
		return;
	if(sc==n&&sr==m)
	{
		cout<<path<<" ";
		return;
	}
	path_maze(sr+1,sc,m,n,path+"v");
	path_maze(sr,sc+1,m,n,path+"h");
	return;

}
int main()
{
	int m,n;
	cin>>m>>n;
	path_maze(1,1,m,n,"");
}