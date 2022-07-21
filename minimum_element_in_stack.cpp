#include <bits/stdc++.h>
#include <stack>
using namespace std;
//MINIMUM_ELEMENT_WITH_EXTRA_SPACE:
class mystack{
private:
		stack<int>s;
 stack<int>ss;
public:
	mystack()
	{

	}

int min_element()
{
	if(ss.size()==0)
		return -1;
	return ss.top();
}
void push(int x)
{
	if(s.size()==0)
	{
		s.push(x);
		ss.push(x);
	}
	else if(x<=ss.top())
	{
		s.push(x);
		ss.push(x);
	}
	else
		s.push(x);
}
int pop()
{
	if(s.size()==0)
		return -1;
	 int ans=s.top();
	 s.pop();
	 if(ans==ss.top())
	 	ss.pop();
	 return ans;
}
int top()
{
	if(s.size()==0)
		return -1;
	return s.top();
}
~mystack()
{
 
}
};

int main()
{ 
	mystack s;
  s.push(15);
  s.push(25);
  s.push(35);
  s.push(45);
  s.push(55);
  s.push(65);
  s.push(75);
  s.push(85);
  s.push(95);
  s.push(125);
  s.push(255);
  s.push(235);
  s.push(12);
  cout<<s.top()<<endl;
  s.pop();
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.min_element()<<endl;
   s.pop();
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.min_element()<<endl;
   s.pop();
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.min_element()<<endl; s.pop();
  s.pop();
  cout<<s.top()<<endl;
  cout<<s.min_element()<<endl;


}