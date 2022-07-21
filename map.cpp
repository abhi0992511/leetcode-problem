#include <bits/stdc++.h>
#include <string>
#include "ourmap.h"
using namespace std;
int main()
{
	ourmap<int>map;
	for (int i = 0; i < 10; i++)
	{
		char c='0'+i;
		string key="abc";
		key=key+c;
		int value=i+1;
		map.insert(key,value);
		cout<<key<<":"<<map.getloadfactor()<<endl;

	}
	cout<<map.size()<<endl;
	map.remove("abc2");
	map.remove("abc7");
	map.remove("abc5");
	cout<<map.size()<<endl;
	cout<<map.getvalue("abc4");
	

}