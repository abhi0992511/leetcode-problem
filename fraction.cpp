class fraction
{
   private:
   	int num;
   	int den;
   public:
   	void print()const
   	{
        cout<<this->num<<"/"<<this->den<<endl;
   	}
      fraction()
      {

      }
   	fraction(int num,int den)
   	{
   		this->num=num;
   		this->den=den;

   	}
      ~fraction()
      {

      }
      fraction & operator++()
      {
         int x=den*1;
         num=num+x;
         simplfy();
         return *this;

      }
   	int simplfy()
   	{
   		int gcd=1;
   		int j=min(num,den);
   		for(int i=1;i<=j;i++)
   		{
   			if(num%i==0&&den%i==0)
   			{
   				gcd=i;
   			}
   		}
   		num=num/gcd;
   		den=den/gcd;
   	}
      fraction operator+(fraction const&f)
      {
         int lcm=den*f.den;
         int x=lcm/num;
         int y=lcm/f.num;
         int num=x*num+y*f.num;
         fraction fnew(num,lcm);
         
         fnew.simplfy();
         return fnew;

      }
      fraction operator*(fraction const&f)const
      {
         int x=num*f.num;
         int y=den*f.den;
         fraction fnew(x,y);
         fnew.simplfy();
         return fnew;

      }
      bool operator==(fraction const&f)const
      {
         return(num==f.num&&den==f.den);
      }
      fraction operator-(fraction const&f)const 
      {
         int lcm=den*f.den;
         int x=lcm/num;
         int y=lcm/f.num;
         int num=x*num-y*f.num;
         fraction fnew(num,lcm);
         fnew.simplfy();
         return fnew;
      }
      fraction operator/(fraction const &f)const
      {
         int x=num/f.num;
         int y=den/f.den;
         fraction fnew(x,y);
         fnew.simplfy();
         return fnew;
      }
      int getnum()const
      {
         return num;
      }
      int getden() const
      {
         return den;

      }
      void stenum(int n)
      {
         num=n;
      }
      void setden(int d)
      {
         den=d;
      }
   	void multiply(fraction const &f2)
   	{
   		this->num=this->num*f2.num;
   		this->num=this->num*f2.num;
   		simplfy();

   	}
   	void add(fraction const &f2)
   	{
   		int lcm,x,y;
   		lcm=den*f2.den;
   		x=lcm/den;
   		y=lcm/f2.den;
   		int n=num*x+(y*f2.num);
   		num=n;
   		den=lcm;
   		simplfy();




   	}
      fraction &operator++(int)
      {
         fraction fnew(num,den);
         num=num+den;
         simplfy();
         fnew.simplfy();
         return fnew;
      }
      fraction & operator+=(fraction const&f2)
      {
         int lcm,x,y;
         lcm=den*f2.den;
         x=lcm/den;
         y=lcm/f2.den;
         int n=num*x+(y*f2.num);
         num=n;
         den=lcm;
         simplfy();
         return *this;
      }

};