#include<bits/stdc++.h>
using namespace std;
#include "queueclass1.cpp"
int main()
{
	queueUsingLL<char> q;
	q.enqueue(100);
	q.enqueue(101); 
	q.enqueue(102);
	q.enqueue(103);
	q.enqueue(104); 
	q.enqueue(105);
	q.enqueue(106);
	q.enqueue(107); 
	q.enqueue(108);
	cout<<q.front()<<endl;
	cout<<q.getsize()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	q.enqueue(109);
	q.enqueue(111);
	cout<<q.front()<<endl;
	cout<<q.getsize()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.front()<<endl;
	cout<<q.getsize();

}