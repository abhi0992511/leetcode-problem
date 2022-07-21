class bus:public car,public truck{
public:
	bus():vechicle(5)
	{
		cout<<"bus constructor"<<endl;

	}
	~bus()
	{
		cout<<"bus destructor"<<endl;
	}
	void print()
	{
		cout<<"bus"<<endl;
	}
};