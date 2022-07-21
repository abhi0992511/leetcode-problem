class dynamicarray{
private:
	int *data;
	int nextindex;
	int capacity;
public:
	dynamicarray()
	{
		 data=new int[5];
		 nextindex=0;
		 capacity=5;
	}
	void add(int n)
	{
		if (nextindex==capacity)
		{
			int *newdata=new int[2*capacity];
			for (int i = 0; i < capacity; i++)
			{
				newdata[i]=data[i];
			}
			delete []data;
			data= newdata;
			capacity*=2;
			data[nextindex]=n;
		nextindex++;
		}
		else
		{
			data[nextindex]=n;
			nextindex++;
		}
		

	}//copy constructor
	dynamicarray(dynamicarray const &d)	{
		this->data=new int[d.capacity];
		for(int i=0;i<d.capacity;i++)
		{
			this->data[i]=d.data[i];
		}
		this->nextindex=d.nextindex;
		this->capacity=d.capacity;
	}
	//operator overloading
	void operator=(dynamicarray const&d)
	{
		this->data=new int[d.capacity];
		for(int i=0;i<d.capacity;i++)
		{
			this->data[i]=d.data[i];
		}
		this->nextindex=d.nextindex;
		this->capacity=d.capacity;
	}
	int get(int i)
	{
		if(nextindex>i)
			return data[i];
	else return -1;	
	}
	void add(int n ,int index)
	{
		if (nextindex>index)
		{
			data[index]=n;
		}
		else if (nextindex==index)
		{
			add(n);
		}
		else return;
	}
	void Print()
	{
		for (int i = 0; i <capacity; i++)
		{
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
};