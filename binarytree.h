template<typename T>
class binaryNode{
	public:
	T data;
	binaryNode* right;
	binaryNode *left;

	binaryNode(T data)
	{
		this->data=data;
		right=NULL;
		left=NULL;	
	}
	~binaryNode()
	{
		delete left;
		delete right;
	}
};
