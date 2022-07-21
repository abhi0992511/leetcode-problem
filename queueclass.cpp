template<typename T>
class queueUsingArray{
private:
	T * data;
	int nextindex;
	int size;
	int capacity;
	int frontIndex;
public:
	queueUsingArray(int s)
	{
		data=new T[s];
		nextindex=0;
		size=0;
		frontIndex=-1;
		capacity=s;
	}
	void enqueue(T val)
	{
		if (size==capacity)
		{
			// cout<<"Queue is Empty !!.."<<endl;
			// return;
				T*newdata=new T[2*capacity];
				int j=0;
				for (int i = frontIndex; i < capacity; i++)
				{
					newdata[j]=data[i];
					j++;
				}
				for (int i = 0; i < frontIndex; i++)
				{
					newdata[j]=data[i];
					j++;
				}
				frontIndex=0;
				nextindex=capacity;
				delete []data;
				data=newdata;
				capacity=2*capacity;


		}
		data[nextindex]=val;
		nextindex=(nextindex+1)%capacity;
		if (frontIndex==-1)
		{
			frontIndex=0;
		}
		size++;
	}
	int getsize()
	{
		return size;
	}
	bool isEmpty()
	{
		return size==0;
	}
	T top()
	{
		if (isEmpty())
		{
		    cout<<"Queue is empty !!"<<endl;
		    return 0;
		}
		return data[frontIndex];
	}
	T dequeue()
	{
		if (isEmpty())
		{
		cout<<"Queue is Empty"<<endl;
		return 0;
		}
		T ans=data[frontIndex];
		frontIndex=(frontIndex+1)%capacity;
		size--;
		return ans;
	}
};