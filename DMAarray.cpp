class dynamicArray{
private:
	int *data;
	int lastIdex;
	int capacity;
public:
	dynamicArray()
	{
		data=new int[5];
	 lastIdex=0;
		capacity=5;
	}
	void add(int n)
	{
		if (lastIdex==0)
		{
			data[lastIdex]=n;
			lastIdex++;
		}
		else if (lastIdex<capacity)
		{
			data[lastIdex]=n;
			lastIdex++;
		}
		else{
			int *newdata=new int[2*capacity];
			for (int i = 0; i < capacity; i++)
			{
				newdata[i]=data[i];
			}
			newdata[lastIdex]=n;
			delete []data;  
			data=newdata;
			capacity=2*capacity;
			lastIdex++;

		}

	}
	 void add(int n,int index)
		{
			if (lastIdex>index)
			{
				data[index]=n;
			}
			else if(lastIdex==index)
			{
				add(n);
				
			}
			else return;

		}
		void print()
		{
			for (int i = 0; i < lastIdex; i++)
			{
				cout<<data[i]<<" ";
			}
			cout<<endl;
		}
};