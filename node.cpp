template<typename T>
class node{
public:
	int data;
	node <T> *next;
node(int n)
{
	this->data=n;
	this->next=NULL;
}
};