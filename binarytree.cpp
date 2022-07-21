#include <bits/stdc++.h>
#include<vector>
#include <math.h>
#include <stack>
#include"node.cpp"
#include "binarytree.h"
using namespace std;
class bst{
public:
	int maxi;
	int mini;
	bool isbst;
};
class info{
public:
	int s;
	int l;
	bool y;
	int ans;
	int size;
};

//PRINT:
void printTree(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;

	}
	cout<<root->data<<":";
if (root->left)
{
	cout<<"L"<<root->left->data;
}
if (root->right)
{
	cout<<"R"<<root->right->data;
}
cout<<endl;





	printTree(root->left);
	printTree(root->right);


}//1 2 3 4 5  6 -1 -1 -1 -1 7 8 -1 -1 -1 -1 -1 -1 -1 
//TAKE_INPUT:
binaryNode<int>*takeinput()
{
	int rootdata;
	cout<<"enter the data"<<endl;
	cin>>rootdata;
	if (rootdata==-1)
	{
		return NULL;
	}
	binaryNode<int>*root=new binaryNode<int>(rootdata);
	binaryNode<int>*leftchild=takeinput();
	binaryNode<int>*rightchild=takeinput();
	root->left=leftchild;
	root->right=rightchild;
	return root;
}
//TAKEINPUT_LEVELWISE:
binaryNode<int>*takeinputLevelwise()
{
	int rootdata;
	cout<<"enter the rootdata"<<endl;
	cin>>rootdata;
	if (rootdata==-1)
	{
		return NULL;
	}
	binaryNode<int>*root=new binaryNode<int>(rootdata);
	queue<binaryNode<int>*>pending;
	pending.push(root);
	while(pending.size()!=0)
	{
		binaryNode<int>*front=pending.front();
		pending.pop();
		cout<<"Enter the left the child "<<front->data<<endl;
		int leftchild;
		cin>>leftchild;
		if (leftchild!=-1)
		{
			binaryNode<int>*childl=new binaryNode<int>(leftchild);
			front->left=childl;
			pending.push(childl);

		}
	
		cout<<"Enter the Right the child "<<front->data<<endl;
		int rightchild;
		cin>>rightchild;
		if (rightchild!=-1)
		{
			binaryNode<int>*childr=new binaryNode<int>(rightchild);
			front->right=childr;
			pending.push(childr);

		}
		

	}
	return root;


}
//PRINT_LEVELWISE:
void printLevelwise(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	queue<binaryNode<int>*>node;
	node.push(root);
	while(node.size()!=0)
	{
		binaryNode<int>*front=node.front();
		node.pop();
		cout<<front->data<<":";
			if (front->left)
		{
			cout<<front->left->data<<",";
			node.push(front->left);
		}
	
		if (front->right)
		{
			cout<<front->right->data<<",";
			node.push(front->right);
		}

		cout<<endl;
	}
}
//NUM_NODES:
int count_nodes(binaryNode<int>*root)
{
  if (root==NULL)
  {
  	return 0;
  }
  int ans=1;
 int x= count_nodes(root->left);
 int y=count_nodes(root->right);
 return ans+x+y;

}
//FIND_X:
bool find_x(binaryNode<int>*root,int k)
{
	if (root->data==k)
	{
		return true;
	}
	if (root->left==NULL||root->right==NULL)
	{
       return false;
	}
   bool x=find_x(root->left,k);
	 bool y=find_x(root->right,k);
 if(x==true)
	return true;
if (y==true)
{
	return true;
}
return false;
}
//HEIGHT_BINARY_TREE:
int height(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return 0;
	}
	int ans=-1;
	int x=height(root->left);
	int y=height(root->right);
	return max(x,y)+1;
}
//MIRROR_IMAGE:
void mirror(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	queue<binaryNode<int>*>node;
	node.push(root);
	while(node.size()!=0)
	{
		binaryNode<int>*front=node.front();
		node.pop();
		cout<<front->data<<":";
			if (front->right)
		{
			cout<<front->right->data<<",";
			node.push(front->right);
		}
	
		if (front->left)
		{
			cout<<front->left->data<<",";
			node.push(front->left);
		}

		cout<<endl;
	}
}
//PREODER:
void inorder(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
//POST_ORDER:
void postorder(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
//IN_ORDER:
void preorder(binaryNode<int>*root)
{
	if (root==NULL)
	{
	return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right); 
}
binaryNode<int>*buildhelper1(int *in,int*pos,int inS,int inE,int posS,int posE)
{ 
	if (inS>inE)
	{
		return NULL;
	}
	int rootdata=pos[posE];
	int rootindex=-1;
	for(int i=inS;i<=inE;i++)
	{
		if (rootdata==in[i])
		{
			rootindex=i;
			break;
		}
	}
	binaryNode<int>*root=new binaryNode<int>(rootdata);
	int linS=inS;
	int linE=rootindex-1;
	int rinS=rootindex+1;
	int rinE=inE;
	int lposS=posE-1;
	int lposE=linE-linS+lposS;
	int rposS=lposE+1;
	int rposE=posE;
	root->left=buildhelper1(in,pos,linS,linE,lposS,lposE);
	root->right=buildhelper1(in,pos,rinS,rinE,rposS,rposE);
	return root;


}
binaryNode<int>*buildhelper(int *in,int*pre,int inS,int inE,int preS,int preE)
{ 
	if (inS>inE)
	{
		return NULL;
	}
	int rootdata=pre[preS];
	int rootindex=-1;
	for(int i=inS;i<=inE;i++)
	{
		if (rootdata==in[i])
		{
			rootindex=i;
			break;
		}
	}
	binaryNode<int>*root=new binaryNode<int>(rootdata);
	int linS=inS;
	int linE=rootindex-1;
	int rinS=rootindex+1;
	int rinE=inE;
	int lpreS=preS+1;
	int lpreE=linE-linS+lpreS;
	int rpreS=lpreE+1;
	int rpreE=preE;
	root->left=buildhelper(in,pre,linS,linE,lpreS,lpreE);
	root->right=buildhelper(in,pre,rinS,rinE,rpreS,rpreE);
	return root;


}
//CONSTRUCT_TREE_FROM_INODER_&_PREORDER:
binaryNode<int>*buildtree(int *in,int*pre,int size)
{
	return buildhelper(in,pre,0,size-1,0,size-1);
}
binaryNode<int>*buildtree1(int *in,int*pos,int size)
{
	return buildhelper1(in,pos,0,size-1,0,size-1);
}
//DIAMETER:
int diameter(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return 0;
	}
	int opt1=height(root->left)+height(root->right);
	int opt2=diameter(root->left);
	int opt3=diameter(root->right);
	return max(opt1,max(opt2,opt3));
}
//DIAMETER_USING_PAIR_CLASS:
  pair<int ,int>heightdiameter(binaryNode<int>*root)
{
	if (root==NULL)
	{
		pair<int,int>p;
		p.first=0;
		p.second=0;
		return p;
	}
	 pair<int,int>leftans=heightdiameter(root->left);
	 pair<int,int>rightans=heightdiameter(root->right);
	int lh=leftans.first;
	int ld=leftans.second;
	int rh=rightans.first;
	int rd=rightans.second;
	int height=1+max(lh,rh);
	int diameter=max(lh+rh,max(ld,rd));
 pair<int,int>x;
	x.first=height;
	x.second=diameter;
	return x;
}
//MINIMUM_MAXIMUM_USING_PAIR_CLASS:
pair<int,int>min_max(binaryNode<int>*root)
{
	if (root==NULL)
	{
		pair<int,int>p;
		p.first=INT_MAX;
		p.second=INT_MIN;
		return p;
	}
	pair<int,int>leftans=min_max(root->left);
	pair<int,int>rightans=min_max(root->right);
	int lm=leftans.second;
	int lmi=leftans.first;
	int rm=rightans.second;
	int rmi=rightans.first;
	int maximum=max(lm,max(root->data,rm));
	int minimum=min(lmi,min(root->data,rmi));
	pair<int,int>a;
	a.first=minimum;
	a.second=maximum;
	return a;





}
//SUM:
int sum(binaryNode<int>*root)
{
	// if (root==NULL)
	// {
	// 	return 0;
	// }
	// int ans =root->data;
	// int x=sum(root->left);
		// int y=sum(root->right);
	// return x+y+ans;

        if(root==NULL)
        return 0;
        int ans=+root->data;
        return ans+sum(root->left)+sum(root->right);
    
}
//BOTH_IDENTICAL_TREE:
bool identical(binaryNode<int>*root1,binaryNode<int>*root2)
{  


if(root1==NULL&&root2==NULL)
{
	return true;
}
if (root1==NULL||root2==NULL)
{
	return false;
}
if (root1->data!=root2->data)
{
	return false;
}

	return identical(root1->left,root2->left)&&identical(root1->right,root2->right);

	

	
	
}


//BALANCED_TREE_1:
bool balanced2(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return true;
	}
	int x=height(root->left);
	int y=height(root->right);
	if (abs(x-y)<=1&&balanced2(root->right)&&balanced2(root->left))
	{
		return true;
	}
	else return false;

}
//BALANCED_TREE_2:
bool balanced3(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return true;
	}
	int x=height(root->left);
	int y=height(root->right);
	if (abs(x-y)<=1)
	{
		bool a=balanced3(root->left);
		bool b=balanced3(root->right);
		if (a==true&&b==true)
		{
			return true;
		}
		else return false;
	}
	else return false;
}
//BALANCED_TREE_USING_PAIR_CLASS:
pair<int,bool>balance(binaryNode<int>*root)
{ 
	if (root==NULL)
	{  
		int height=0;
		bool bal=true;
		pair<int,bool>p;
		p.first=height;
		p.second=bal;
		return p;

	}
	pair<int,bool>x=balance(root->left);
	pair<int,bool>y=balance(root->right);
	

	
}
//LEVELWISE:
void levelwise(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	queue<binaryNode<int>*>level;
	level.push(root);
	level.push(NULL);
	
	while(level.size()!=0)
	{
		binaryNode<int>*front=level.front();
		level.pop();
		if (front!=NULL)
	{
			cout<<front->data<<" ";
			if (front->left)
		{
			//cout<<front->left->data<<" ";
			level.push(front->left);
		
		}
		
			if (front->right)
		{
			//cout<<front->right->data<<" ";
			level.push(front->right);
			
		}
		
		}
		else
		{
			cout<<endl;
			if(level.size()!=0)
			level.push(NULL);
		 else break;
		}
		}
}
//REMOVE_LEAF_NODE:
binaryNode<int>*remove_leaf(binaryNode<int>*root)
{

	if (root==NULL)
	{
		return NULL;
	}
	if (root->left==NULL&&root->right==NULL)
	{
		delete root;
   
   return NULL;	
	}
	 root->left=remove_leaf(root->left);
	 root->right=remove_leaf(root->right);
	 return root;
}

//ZIG_ZACK_TREE:
void zigzack(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	stack<binaryNode<int>*>s1;
	stack<binaryNode<int>*>s2;
	s1.push(root);
	while(s1.size()!=0||s2.size()!=0)
	{
		while(s1.size()!=0)
		{
			binaryNode<int>*front=s1.top();
				s1.pop();
			cout<<front->data<<" ";
			if (front->left)
			{
				s2.push(front->left);
			}
			if (front->right)
			{
				s2.push(front->right);
			}
			
			 }
		  cout<<endl;
		while (s2.size()!=0)
		{
			binaryNode<int>*front1=s2.top();
				s2.pop();
				cout<<front1->data<<" ";
				if (front1->right)
				{
					s1.push(front1->right);

				}
				if (front1->left)
				{
					s1.push(front1->left);
				}

		}
		cout<<endl;
	}
}
//NODE_LINKLIST:
vector<node<int>*>tree_linklist(binaryNode<int>*root)
{
	vector<node<int>*>ans;
	if (root==NULL)
	{
		return ans;

	}
	queue<binaryNode<int>*>son;
	son.push(root);
	son.push(NULL);
	node<int> *head=NULL;
	node <int>*tail=NULL;
	while(son.size()!=0)
	{
		binaryNode<int>*front=son.front();
		son.pop();
		if (front!=NULL)
		{
			node <int>*newnode=new node<int>(front->data);
			if (head==NULL&&tail==NULL)
			{
			   head=newnode;
			   tail=newnode;
			}
			if (head!=NULL)
			{
         tail->next=newnode;
         tail=newnode;
			}
			if (front->left)
			{
				son.push(front->left);
			}
			if (front->right)
			{
				son.push(front->right);
			}
		}
		else
		{ 
			if (son.size()!=0)
			{
				son.push(NULL);
				ans.push_back(head);
				head=NULL;
				tail=NULL;

			}
			
			else
			{
				ans.push_back(head);
				break;
			}
		}
	}
}
//NODE_WITHOUT_SIBLINGS:
void without_sibling(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return ;
	}
	if (root->left!=NULL&&root->right==NULL)
	{
		cout<<root->left->data<<" ";
	}
	if (root->left==NULL&&root->right!=NULL)
	{
		cout<<root->right->data<<" ";
	}
	without_sibling(root->left);
	without_sibling(root->right);

}
//SEARCH_IN_BST:
bool search_bst1(binaryNode<int>*root,int k)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==k)
	{
		return true;
	}
	bool x;
	if (root->data>k)
	{
		x=search_bst1(root->left,k);
		if (x==true)
		{
			return true;
		}
	}
	else
		x=search_bst1(root->right,k);
	  if (x==true)
	  {
	  	return true;
	  }
}
binaryNode<int>* search_bst(binaryNode<int>*root,int k)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==k)
	{
		return root;
	}
	binaryNode<int>* x=NULL;
	if (root->data>k)
	{
		x=search_bst(root->left,k);
		// if (x==true)
		// {
		// 	return true;
		// }
	}
	else
		x=search_bst(root->right,k);
	  // if (x==true)
	  // {
	  // 	return true;
	  // }
	return x;
}
//CHECK_BST:
bool check_bst(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return true;
	}
	if ((root->data<root->left->data)||(root->data>=root->right->data))
	{
		return false;
	}
	bool x=check_bst(root->left)&&check_bst(root->right);
	if (x==true)
	{
		return x;
	}
	return x;
}
//ELEMENT_IN_RANGE:
void element_range(binaryNode<int>*root,int k1,int k2)
{
	if (root==NULL)
	{
		return;
	}

	if (root->data>=k1)
		{
			element_range(root->left,k1,k2);
		}
			if (k1<=root->data&&root->data<=k2)
	{
		cout<<root->data<<" ";
	}
		
		if (root->data<=k2)
		{
			element_range(root->right,k1,k2);
		}
		

	
	


}
//MINIMUM_IN_R_BST:
int minimum(binaryNode<int>*root)
{
	int ans=INT_MAX;
	if (root==NULL)
	{
	  return INT_MAX;
	}
	int x=minimum(root->left);
	int y=minimum(root->right);
	ans=min(root->data,min(x,y));
	return ans;
}

//MAXIMUM_IN_L_BST:
int maximum(binaryNode<int>*root)
{
	int ans=INT_MIN;
	if (root==NULL)
	{
		return INT_MIN;
	}
	int x=maximum(root->left);
	int y=maximum(root->right);
	ans=max(root->data,max(x,y));
	return ans;
}
//IS_BST:
bst isbst(binaryNode<int>*root)
{
	if (root==NULL)
	{
		bst p;
		p.maxi=INT_MIN;
		p.mini=INT_MAX;
		p.isbst=true;
		return p;
	}
	bst left=isbst(root->left);
	bst right=isbst(root->right);
	bst ans;
	int maximum=max(root->data,max(left.maxi,right.maxi));
	int minimum=min(root->data,min(left.mini,right.mini));
	bool isbt=(left.maxi<root->data)&&(right.mini>=root->data)&&(left.isbst)&&(right.isbst);
	ans.mini=minimum;
	ans.maxi=maximum;
	ans.isbst=isbt;
	return ans;

}
//CONSTRUCT_A_BINARY_TREE_SORTED_ARRAY:
binaryNode<int>*tree(int a[],int s,int l)
{
	   if (s>l)
	   {
	   	return NULL;
	   }
	 
	   int mid=s+(l-s)/2;
	  int data=a[mid];
	   binaryNode<int>*root=new binaryNode<int>(data);
	 
	  root->left=tree(a,s,mid-1);
	  root->right=tree(a,mid+1,l);
	   return root;
	  
	 
	 
}
// //BST_TO_LINKLIST:
// node<int>*helper(binaryNode<int>*root,node<int>**head,node<int>**tail)
// {
//     if (root==NULL)
//     {
//     	return tail;
//     }
    


// }
// node<int>*ll(binaryNode<int>*root)
// {
// 	if (root==NULL)
// 	{
// 		return NULL;
// 	}
// 	node<int>*head=NULL;
// 	node<int>*tail=NULL;
// 	return helper(root, head,tail);
// }
//PATH_ IN_BST:
// void path(binaryNode<int>*root,int k)
// {
// 	if (root==NULL)
// 	{
// 		return;
// 	}
// 	if (root->data==k)
// 	{
// 		cout<<root->data<<" ";
// 	}
// 	if (root->data>k)
// 	{
// 		path(root->left);
// 	}
// 	else
// 		path(root->right);
// 	cout<<root->data<<" ";
// }
vector<int>*get(binaryNode<int>*root,int k)
{
	if (root==NULL)
	{
		return NULL;
	}
	if(root->data==k)
	{
		vector<int>*res=new vector<int>();
		res->push_back(root->data);
		return res;
	}
	vector<int>*out;
	if (root->data>k)
	{
		out=get(root->left,k);
		if(!out)
			out->push_back(root->data);
		return out;
	
	}
	else
	{
		out=get(root->left,k);
		if(!out)
			out->push_back(root->data);
		return out;
	}
	return NULL;

}
//ADD_DUPLICATE:
binaryNode<int>*add_duplicate(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return NULL;
	}
	// if (root->left==NULL&&root->right==NULL)
	// {
	// 	binaryNode<int >*dupli=new binaryNode<int>(root->data);
	// 	root->left= dupli;
	// 	return root;
	// }
	// if (root->left)
	// {
	// 	binaryNode<int>*dupli=new binaryNode<int>(root->data);
	// 	dupli->left=root->left;
	// 	root->left=dupli;
	// 	add_duplicate(dupli->left);
		
 //     add_duplicate(root->right);
 //    //dupli->right=root->right;

		
	// }
		binaryNode<int>*dupli=new binaryNode<int>(root->data);
		dupli->left=root->left;
		root->left=dupli;
		add_duplicate(dupli->left);
		// dupli->right=root->right;
		add_duplicate(root->right);

	return root;
}
//PAIR_SUM_BINARY_TREE:
vector<int>helper(binaryNode<int>*root,vector<int>&ans)
{
	if (root==NULL)
	{
		return ans;
	}
 
 helper(root->left,ans);
 helper(root->right,ans);
 ans.push_back(root->data);

return ans;
}
void pair_sum(binaryNode<int>*root,int k)
{ 
	if (root==NULL)
	{
		return;
	}
	vector<int>ans;
	helper(root,ans);
	sort(ans.begin(),ans.end());
	// for (int i = 0; i < ans.size(); i++)
	// {
	// 	cout<<ans[i]<<" ";
	// }
	int i=0,j=ans.size()-1;
	while(i<j)
	{
		if (ans[i]+ans[j]==k)
		{
			cout<<ans[i]<<" "<<ans[j]<<" "<<endl;
			i++,j--;
		}
		else if (ans[i]+ans[j]>k)
		{
			j--;
		}
		else
			i++;
	}


}//LCA_IN_BINARY_TREE:
binaryNode<int>* lca_bt(binaryNode<int>*root,int s,int l)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==s||root->data==l)
	{
		return root;
	}
	binaryNode<int>* x=lca_bt(root->left,s,l);
	binaryNode<int>* y=lca_bt(root->right,s,l);
	if (x&&y)
	{
	 return root;
	}
	if(x)
		return x;
	else
		return y;
}
//LCA_BST:
binaryNode<int>*lca_bst(binaryNode<int>*root,int s,int l)
{
	if (root==NULL)
	{
		return NULL;
	}
	if (root->data==s||root->data==l)
	{
		return root;
	}
	binaryNode<int>*left;
	binaryNode<int>*right;
	if (root->data>s)
	{
		left=lca_bst(root->left,s,l);
	}
	else
	left=lca_bst(root->right,s,l);
if (root->data<l)
	{
		right=lca_bst(root->right,s,l);
	}
	else
	right=lca_bst(root->left,s,l);
if (left&&right)
{
	return root;
}
if (left)
{
	return left;
}
else
return right;

}
//PAIR_SUM_SIMPLE_APROARCH:
bool bstfind(binaryNode<int>*root,int val)
{
	if (root==NULL)
	{
	 return false;
	}
	if (root->data==val)
	{ 
		root->data=INT_MIN;
		return true;
	}
	bool a= bstfind(root->left,val);
	bool b=bstfind(root->right,val);
	if (a==true||b==true)
	{
		return true;
	}
	else
	return false;
}
void pair_sum(binaryNode<int>*root,binaryNode<int>*curr,int k)
{
	if (root==NULL)
	{
		return;
	}
	if (curr==NULL)
	{
		return;
	}
		int element=k-curr->data;
		if (bstfind(root,element))
		{
			cout<<curr->data<<" "<<element<<" ";
		}
	
	pair_sum(root,curr->left,k);
	pair_sum(root,curr->right,k);

}
//LARGEST_BST_NORMAL_APROACH:
int largest_bst(binaryNode<int>*root)
{
	if (root==NULL)
	{
		return 0;
	}
	if (isbst(root).isbst)
	{
		return count_nodes(root);
	}
	else
	return	max(largest_bst(root->left),largest_bst(root->right));
}
//LARGEST_BST_EFFICENT_APROACH:
// public:
// 	int s;
// 	int l;
// 	bool y;
// 	int ans;
// 	int size;
info largest_bst1(binaryNode<int>*root)
{
	if (root==NULL)
	{
		info p;
		p.s=INT_MAX;
		p.l=INT_MIN;
		p.y=true;
		p.ans=0;
		p.size=0;
		return p;


	}
	if (root->left==NULL&&root->right==NULL)
	{
		info a;
		a.s=root->data;
		a.l=root->data;
		a.y=true;
		a.ans=1;
		a.size=1;
		return a;
	}
info left=largest_bst1(root->left);
info right=largest_bst1(root->right);

info res;
res.size=(left.size+right.size+1);
if (left.y==true&&right.y==true&&left.l<root->data&&right.s>root->data)
{
	res.s=min(root->data,min(left.s,right.s));
	res.l=max(root->data,max(left.l,right.l));
	res.ans=res.size;
	res.y=true;
	return res;

}
else{
		res.ans=max(left.ans,right.ans);
	res.y=false;
	return res;

}

}
//REPLACE_WITH-MAXIMUM_SUM:
int sum(binaryNode<int>*root,vector<int>&ans)
{
	int res=0;
	for (int i = 0; i <ans.size() ;i++)
	{
		if (ans[i]>=root->data)
		{
			res=res+ans[i];
		}
	}
	return res;
}
void helper2(binaryNode<int>*root,vector<int>&ans)
{
      if (root==NULL)
      {
      	return;
      }
      if (root)
      {
      	root->data=sum(root,ans);
      	//cout<<root->data<<" ";

      }
      helper2(root->left,ans);
      helper2(root->right,ans);

}
void replace_sum(binaryNode<int>*root)
{
	vector<int>ans;
	helper(root,ans);
	sort(ans.begin(),ans.end());
	helper2(root,ans);


}
//Path Sum Root to Leaf:
void helper(binaryNode<int>*root,int currsum,int sum,vector<int>v,vector<vector<int>>ans)
{
	if (root==NULL)
	{
		return;
	}
	v.push_back(root->data);
	currsum=currsum+root->data;
	if (currsum==sum&&root->left==NULL&&root->right==NULL)
	{
		ans.push_back(v);
		return;
	}
	else
	{
		helper(root->left,currsum,sum,v,ans);
		helper(root->right,currsum,sum,v,ans);
	}
	v.pop_back();
}
 void sum_path(binaryNode<int>*root,int sum)
{
	vector<vector<int>>ans;
	vector<int>v;
	if (root==NULL)
	{
		return ;
	}
	int currsum=0;
	helper(root,currsum,sum,v,ans);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	

}


int main()
 {
// 	binaryNode <int>*root=new binaryNode<int>(5);
// 	binaryNode<int>*root1=new binaryNode<int>(8);
// 	binaryNode<int>*root2=new binaryNode<int>(10);
// 	root->right=root2;
// 	root->left=root1;
binaryNode<int>*root=takeinputLevelwise();
vector<node<int>*>link=tree_linklist(root);
for(int i=0;i<link.size();i++)
 {
    cout<<link[i]->data<<" ";
	
 }
 cout<<endl;
	printLevelwise(root);
	cout<<largest_bst1(root).ans<<endl;
	cout<<endl;
	sum_path(root,13);
	cout<<endl;
	replace_sum(root);
	levelwise(root);
	cout<<endl;
	element_range(root,6,10);
	cout<<endl;
	mirror(root);
	cout<<endl;
	int d;
	cout<<"enter the data"<<endl;
	cin>>d;
	cout<<search_bst1(root,d)<<endl;
	binaryNode<int>*r= search_bst(root,d);
	if (r!=0)
	{
		cout<<r->data<<endl;
	}
	cout<<"no data found !!"<<endl;

	postorder(root);
	cout<<endl;
	preorder(root);
cout<<endl;
	inorder(root);
	cout<<endl;
	cout<<count_nodes(root);
	cout<<endl;
	zigzack(root);
	cout<<endl;
	// cout<<check_bst(root);
 cout<<endl;
	cout<<height(root)<<endl;
	cout<<sum(root)<<endl;
	pair_sum(root,root,12);
	cout<<endl; 
binaryNode<int>*t=lca_bst(root,2,6);
if(t!=NULL)
cout<<t->data<<endl;
else
cout<<"-1"<<endl;
 
	
	int x;
	cout<<"enter element to be find"<<endl;
	cin>>x; 
	cout<<find_x(root,x);
	cout<<endl;
	cout<<balanced3(root)<<endl;
	without_sibling(root);
	cout<<endl;
	binaryNode<int>*ad=add_duplicate(root);
	levelwise(ad);
	cout<<endl;

	// int in[]={4,2,5,1,6,3,7};
	// int pre[]={1,2,4,5,3,6,7};
	// int pos[]={4,5,2,6,7,3,1};
	// binaryNode<int>*root1=buildtree(in,pre,7);
	// binaryNode<int>*root2=buildtree(in,pos,7);
	// printLevelwise(root1);
	// cout<<endl;
	// printLevelwise(root2);
	pair<int,int>p= heightdiameter(root);
	cout<<p.first<<endl;
	cout<<p.second<<endl;
	pair<int,int>s=min_max(root);
	cout<<s.first<<endl;
	cout<<s.second<<endl;
	levelwise(root);
	//vector<binaryNode<int>*>link=levelwise_linklist(root);
	cout<<endl;
	//pair_sum(root,15);
//binaryNode<int>*root1=remove_leaf(root);	
 //levelwise(root1);

 cout<<endl;
 int n;

 cout<<"enter the size of array"<<endl;
 cin>>n;
 int *a=new int[n];
 for (int i = 0; i < n; i++)
 {
 	cin>>a[i];

 }
 binaryNode<int>*z=tree(a,0,n-1);
 levelwise(z);
 vector<int>*answer=get(root,2);
 for (int i = 0; i < answer->size(); i++)
 {
 	cout<<answer->at(i)<<endl;
 }



 
 	delete root;

}