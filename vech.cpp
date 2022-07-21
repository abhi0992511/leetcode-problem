class vechicle{
private:
	int maxSpeed;
protected:
	int numTyre;
public:
	string color;
	vechicle()
	{
		cout<<"vech constructor"<<endl;
	}
	vechicle(int z)
	{
		cout<<"constructor"<<z<<endl;
	}
	~vechicle()
	{
		cout<<"vechicle destuctor"<<endl;
	}
	void print(){
		cout<<"vechicle"<<endl;
	}
};