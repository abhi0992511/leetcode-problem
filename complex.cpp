class complex
{
 private:
 	int real;
 	int img;
 public:
 	void print()
 {
 	cout<<real<<"+"<<"i"<<img<<endl;

 }
 complex(int real,int img)
 {
 	this->real=real;
 	this->img=img;
 }
 void add(complex &x)
 {
 	this->real=this->real+x.real;
 	this->img=this->img+x.img;
 }
 void multiply(complex  const &x)
 {
 	real=real*x.real;
 	img=img*x.img;

 }
 void sub(complex const&x)
 {
 	real=real-x.real;
 	img=img-x.img;
 }

};