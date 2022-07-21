#include <bits/stdc++.h>
#include <stack>
using namespace std;
//MIN_ELEMENT_IN_WITHOUT_SPACE:
class mystack{
private:
	stack<int>s;
	int min_element;
public:
	int min_ele()
	{
		if (s.size()==0)
		{
			return -1;
		}
		return min_element;
	}
	void push(int x)
	{
		if (s.size()==0)
		{
			s.push(x);
			min_element=x;
		}
		else if(x>=min_element)
		{
			s.push(x);
		}
		else{
			s.push(2*x-min_element);
			min_element=x;
		}
	}
	void pop()
	{
		if (s.size()==0)
		{
		return;
		}
		else
		{
			if(s.top()>min_element)
			{
				s.pop();
			}
			else{
				min_element=2*min_element-s.top();
			}
		}
	}
	int top()
	{
		if (s.top()==0)
		{
			return -1;
		}
		return s.top();
	}
};
int main()
{
   mystack s;
   s.push(5);
   s.push(1);
   s.push(3);
   s.push(6);
   s.push(7);
   s.push(10);
   s.push(12);
   cout<<s.min_ele()<<endl;
   cout<<s.top()<<endl;
   s.pop();
   s.pop();
   cout<<s.min_ele()<<endl;
   cout<<s.top();
}