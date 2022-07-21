class polynomial{
private:
	int *deg;
	int capacity;
	public:
		polynomial()
		{
			deg=new int[5];
			capacity=5;
			for (int i = 0; i < capacity; i++)
			{
				deg[i]=0;
			}

		}
		void set()
		{
			cout<<"enter the size of polynomial";
			cin>>n;
			if (n==capacity)
			{
				int *newdeg=new int [2*capacity];
				for (int i = 0; i < capacity; i++)
				{
					newdeg[i]=deg[i];

				}
				delete []deg;
				deg=newdeg;
				for(int i=0 i<n;;i++)
				{
					cin>>deg[i];
				}


			}
		}
};