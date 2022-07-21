template<typename T>
class node{
public:
	T data;
	node <T>*next;
	node(T val)
	{
		data=val;
		next=NULL;
	}
};
template<typename T>
class queueUsingLL{
private:
	node<T>*head;
	node<T> *tail;
	int size;
public:
	queueUsingLL()
	{
		head=NULL;
		tail=NULL;
		size=0;
	}
	int getsize()
	{
		return size;

	}
	bool isEmpty()
	{
		return size==0;
	}
	void enqueue(T val)
	{
		node <T>*newnode=new node<T>(val);
		if (head==NULL)
		{
			head=newnode;
			tail=newnode;
		}
		else
		{
			tail->next=newnode;
        tail=newnode;
        size++;
		}
	}
	T dequeue()
	{
		if (!getsize())
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}

		T ans=head->data;
		node <T>* temp=head;
		head=head->next;
		delete temp;
		size--;n
		return ans;


	}
	T front()
	{
		if (!getsize())
		{
			cout<<"Queue is empty !!"<<endl;
			return 0;
		}
		else{
			return head->data;
		}
	}

};