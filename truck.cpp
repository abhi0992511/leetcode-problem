class truck: virtual public vechicle{
public:
	truck():vechicle(3)
	{
		cout<<"truck constructor"<<endl;
	}
	~truck()
	{
		cout<<"truck destructor"<<endl;
	}
};