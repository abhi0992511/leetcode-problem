template <typename T>
class node{
	public:

T data;
node <T> *next;

	node(T data)
	{
		this->data=data;
		next=NULL;
	}

};
template <typename T>
class stackusingLL{
private:
	node<T>*head;
	int size;
public:
	stackusingLL()
	{
		head=NULL;
		size=0;
	}
	int length()
	{
		return size;

	}
	bool isEmpty()
	{
		if (head==NULL)
		{
			return true;
		}
		else
			return false;
	}
	void push(T data)
	{
		node <T>*newnode=new node<T>(data);
			newnode->next=head;
			head=newnode;
			size++;
			
	}
	T pop()
	{
		if (head==NULL)
		{
			return 0;
		}
		else
			{
				T ans=head->data;
				node<T> *temp=head;
				head=head->next;
				delete temp;
				size--;
				return ans;
			}
	}
	T top()
	{
		if (head==NULL)
		{
			return 0;
		}
		else{
			return head->data;
		}
	}



};