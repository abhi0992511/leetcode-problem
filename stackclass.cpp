#include<climits>
template <typename T>
class stackusingArray{
private:
	T *data;
	int nextindex;
	int capacity;
public:
	stackusingArray()
	{
		data=new T [2];
		nextindex=0;
		capacity=2;
	}
	int size()
	{
		return nextindex;

	}
	bool isEmpty()
	{
		if(nextindex==0)
		{
			return true;		
		}
		else
			return false;
	}
   void push(int value)
   {
   	if (nextindex==capacity)
   	{   //STATIC STACK:
   		// cout<<"Stack is Full!!"<<endl;
   		// return;
   	//	DYANAMIC STACK:
       T *newData=new T [2*capacity];
       for (int i = 0; i < nextindex; i++)
       {
       	newData[i]=data[i];
       }
       delete []data;
       data=newData;
       capacity=2*capacity;
       data[nextindex]=value;
       nextindex++;
   	}
   	else
   	{
   		data[nextindex]=value;
   		nextindex++;
   	}
   }
   T pop()
   {
   	if (!size())

   	{
   		cout<<"Stack is Empty !!"<<endl;
   		return 0;
   	}
   	else{
   		nextindex--;
   		return data[nextindex];
   	}

   }
  T top()
   {
   	if(isEmpty())
   	{
   		cout<<"Stack is empty !!"<<endl;
   		return 0;
   	}
   	else{
   		return data[nextindex-1];
   	}
   }

};