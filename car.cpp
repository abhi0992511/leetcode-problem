//#include "vech.cpp"
class car: virtual public vechicle
{
public:
	int numGear;
	car():vechicle(4)
	{
		cout<<"car constructor"<<endl;


	}
	~car()
	{
		cout<<"car destructor"<<endl;
	}
};