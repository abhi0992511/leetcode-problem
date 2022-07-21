
class student
{

public:
	int rollNo;
	private:
	int age;
	char *name;
public:
		student()
	{
		cout<<"default destructor"<<endl;
	}
	student(int x)
	{
		age=x;
	}
	student(int c,int y)
	{
		age=c;
		rollNo=y;

	}
	student(student const &s)
	{
		this->age=age;
		this->rollNo=rollNo;
		this->name=new char[strlen(s.name)+1];
		strcpy(this->name,s.name);

	}
	student(int age,char *name,int rollNo)
	{
		this->age=age;
		this->rollNo=rollNo;
		this->name=new char[strlen(name)+1];
		strcpy(this->name,name);
	}
	
	void display1()
	{
		cout<<age<<" "<<name<<" "<<rollNo<<endl;
	}
	~student()
	{
		cout<<"destructor"<<endl;
	}
	void display()
	{
		cout<<age<<" "<<rollNo<<endl;
	}
	void setAge(int a)
	{
		age=a;
	}
	void setRollno(int r)
	{
		rollNo=r;
	}
	
};