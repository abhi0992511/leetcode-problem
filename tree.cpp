#include <bits/stdc++.h>
#include <queue>
#include <climits>
#include <algorithm>
#include "treeclass.h"
using namespace std;
//PRINT_LEVEL_WISE:
void printLevelwise(treeNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	queue<treeNode<int>*>children;
	children.push(root);
	while(children.size()!=0)
	{
		treeNode<int >*front=children.front();
		children.pop();
		cout<<front->data<<":";
		for (int i = 0; i < front->child.size(); i++)
		{
			cout<<front->child[i]->data<<",";
			children.push(front->child[i]);
		}
		cout<<endl;
	}


}
//NUM_NODE:
int count(treeNode<int>*root)
{
	int ans=1;
	for (int i = 0; i < root->child.size(); i++)
	{
	   ans+=count(root->child[i]);
	}
	return ans;
}
//SUM_OF_TREE:
int sum(treeNode<int>*root)
{
	int ans=root->data;
	for (int i = 0; i < root->child.size(); i++)
	{   
	 
	 ans+=sum(root->child[i]); 
		
		
	}
	return ans;
}
//MAXIMUM_IN_TREE:
int maximum(treeNode<int>*root)
{
	int maxi=INT_MIN;
	for (int i = 0; i < root->child.size(); i++)
	{
	    int c=maximum(root->child[i]);
	    if (c>maxi)
	    {
	    	maxi=c;
	    }
	}
	maxi=max(root->data,maxi);
	return maxi;

}
//HEIGHT OF GENERIC TREE1:
int height0(treeNode<int>*root)
{
	int len=-1;
	for(int i=0;i<root->child.size();i++)
	{
		int c =+height0(root->child[i]);
		if (c>len)
		{
			len=c;
		}
	}
	return len+1;
}
//NUM_LEAF_NODE:
int num_leaf(treeNode<int>*root)
{ 
	int c=0;
	if (root->child.size()==0)
	{
		return 1;
	}
	for(int i=0;i<root->child.size();i++)
	{
	 c = c + num_leaf(root->child[i]);
	}
	return c;
}
//HEIGHT OF GENERIC TREE2:
int height1(treeNode<int>*root)
{
	int len=0;
	for(int i=0;i<root->child.size();i++)
	{
		int c =+height1(root->child[i]);
		if (c>len)
		{
			len=c;
		}
	}
	return len+1;
}
//PRINT_TREE:
void print(treeNode<int>*root)
{ 
	if (root==NULL)
	{
		return;
	}
	cout<<root->data<<':';
	for (int i = 0; i < root->child.size(); i++)
	{
		cout<<root->child[i]->data<<',';
	}
	cout<<endl;
	for(int i=0;i<root->child.size();i++)
	{
		print(root->child[i]);
	}
}
//TAKE_INPUT_LEVEL_WISE: 
treeNode<int>*takeinputLevelwise()
{
	int rootdata;
	cout<<"enter the rootdata"<<endl;
	cin>>rootdata;
	treeNode <int>*root=new treeNode<int>(rootdata);
	queue<treeNode<int>*>restnode;
	restnode.push(root);
	while(restnode.size()!=0)
	{
		treeNode<int >*front=restnode.front();
		restnode.pop();
		int numchild;
		cout<<"enter the no child for "<<front->data<<endl;
		cin>>numchild;
		for (int i = 0; i < numchild; i++)
		{
			int childdata;
			cout<<"enter the "<<i<<" th child of "<<front->data<<endl;
			cin>>childdata;
			treeNode<int>*baby=new treeNode<int>(childdata);
			front->child.push_back(baby);
			restnode.push(baby);

		}
		

	}
	return root;


}
//PRINT_DEPTH_AT_K:
void depth_at_k(treeNode<int>*root,int k)
{
	if (root==NULL)
	{
		return;
	}
	if (k==0)
	{
		cout<<root->data<<endl;
		return;

	}
	for (int i = 0; i < root->child.size(); i++)
	{
		depth_at_k(root->child[i],k-1);
	}
}
//TAKE_INPUT:
treeNode<int>*takeinput()
{ 
	// if (root==NULL)
	// {
	// 	return root;
	// }
	int data;
	cout<<"enter the data"<<endl;
	cin>>data;
	treeNode <int>*root=new treeNode<int>(data);
	int child;
	cout<<"enter the child of "<<data<<endl;
	cin>>child;
	for (int i = 0; i < child; i++)
	{
		treeNode<int>*child=takeinput();
		root->child.push_back(child);
	}
	return root;

}
// PREORDER_TRAVERSAL:
void preoder(treeNode<int>*root)
{
	cout<<root->data<<" ";
	for (int i = 0; i < root->child.size(); i++)
	{
	     preoder(root->child[i]);
	}
}
//POSTODER_TRAVERSAL:
void postorder(treeNode<int>*root)
{
	if (root==NULL)
	{
		return;
	}
	for(int i=0;i<root->child.size();i++)
	{
		postorder(root->child[i]);

	}
	cout<<root->data<<" ";
}
//FIND_X:
bool find(treeNode<int>*root,int value)
{
	if (root==NULL)
	{
		return false;
	}
	if (root->data==value)
	{
	return true;
	}
	

	
	
	for (int i = 0; i < root->child.size(); i++)
	{
		 bool x=find(root->child[i],value);
		 if (x==true)
		 {
		 	return true;
		 }
		  
		
	}

	return false;
	
	


}
//FIND_COUNT_NODES:

int count_nodes(treeNode<int>*root,int value)
{    
	int ans;
	if (root==NULL)
	{
		return 0;
	}
	if (root->data>value)
	{
		ans=1;
	}
	else
	{
		ans=0;
	}
		

	for (int i = 0; i < root->child.size(); i++)
	{ 
		 ans+=count_nodes(root->child[i],value);
		
	}
	return ans;
	

	
}
//  int msn=0;
//  int ms=INT_MIN;
//   int maximum_node(treeNode<int>*root)
// {  
// 	// if (root==NULL)
// 	// {
// 	// 	return 0;
// 	// }
// 	int sum=0;
// 	for (int i = 0; i < root->child.size(); i++)
// 	{
// 		int csum=maximum_node(root->child[i]);
// 		sum +=csum;
// 	}
// 	sum+=root->data;
// 	if (sum>ms)
// 	{
// 		ms=sum;
// 		msn=root->data;

// 	}

// 	return sum;
// }
//CHECK SYMMETRY:
bool check_symmetry(treeNode<int>*root,treeNode<int>*root1)
{
	if (root==NULL&&root1==NULL)
	{
		return true;
	}
	else if (root==NULL||root1==NULL)
	{
		return false;
	}
	else if (root->data==root1->data)
	{
		int i=0;
		int j=0;
		while((i<root->child.size())&&(j<root1->child.size()))
			{
				if (!check_symmetry(root->child[i],root1->child[j]))
				{
				 break;
				}
				i++,j++;
			}
			if((i<root->child.size())||(j<root1->child.size()))
			{
				return false;
			}
			else
				return true;
	}
	return false;
}
//NEXT_LARGER:
// int sec=0;
// int next_larger(treeNode<int>*root,int ele)
// {
// 	int lar=INT_MIN;
// 	for (int i = 0; i < root->child.size(); i++)
// 	{
// 		int c=next_larger(root->child[i],ele);
	
//     }
//     lar=root->data;
//     if (ele<lar)
//     {
//     	sec=lar;


    
//     }
	 
	
   
//     return lar;

// }
//NEXT_LARGER:
void next_larger1util(treeNode<int>*root,int key,treeNode<int>**res)
{
	if (root==NULL)
	{
		return;
	}
	if (root->data>key)
		if (!(*res)||(*res)->data>root->data)
			*res=root;

		for(int i=0;i<root->child.size();i++)
		{
			next_larger1util(root->child[i],key,res);
		}
		return;
}
treeNode<int>*nextLarger2(treeNode<int>*root,int data)
{
	treeNode<int>*res=NULL;
	next_larger1util(root,data,&res);
	return res;
}
int next_larger1(treeNode<int>*root,int k)
{
	int ans=0;
	if (root->data>k)
	{
		ans=root->data;
	}
	for (int i = 0; i < root->child.size(); i++)
	{
		int temp=next_larger1(root->child[i],k);
		if (ans==0)
		{
		ans =temp;
		}
		if (temp>ans)
		{
			return ans;
		}


	}
	if (root->data>k)
	{
		return root->data;
	}
	return 0;
}
//REPLACE_DEPTH:
void replace_depth(treeNode<int>*root,int depth)
{   
	if (root==NULL)
	{
		return;
	}
	if (root)
	{
		root->data=depth;
		
	}
	for (int i = 0; i < root->child.size(); i++)
	{
		replace_depth(root->child[i],depth+1);
		
	}
	

}
//2ND_LARGEST:
void second_greatest(treeNode<int>*root,treeNode<int>**first,treeNode<int>**sec)
{
	if (root==NULL)
	{
		return;
	}
	if (!(*first))
	{
		*first=root;
	}
	else if (root->data>(*first)->data)
	{
		*sec=*first;
		*first=root;
	}
	else if (!(*sec))
	{
		if (root->data<(*first)->data)
		{
			*sec=root;
		}
	}
	else if (root->data<(*first)->data&&root->data>(*sec)->data)
	{
		*sec=root;
	}
	for (int i = 0; i < root->child.size(); i++)
	{
	     second_greatest(root->child[i],first,sec);
	}
}
treeNode<int>*sec_greatest(treeNode<int>*root)
{
	treeNode<int>*first=NULL;
	treeNode<int>*sec=NULL;
	second_greatest(root,&first,&sec);
	if (sec==NULL)
	{
		return NULL;
	}


	return sec;
}


int main()

{
	// treeNode<int>*root=new treeNode<int>(12);
	// treeNode<int>*node1=new treeNode<int>(13);
	// treeNode<int>*node2=new treeNode<int>(14);
	// root->child.push_back(node1);
	// root->child.push_back(node2);
	treeNode<int>*root=takeinputLevelwise();
	//treeNode<int>*root1=takeinputLevelwise();
	printLevelwise(root);
	//printLevelwise(root1);
	cout<<endl;
	cout<<count(root)<<endl;
	cout<<sum(root)<<endl;
	cout<<maximum(root)<<endl;
	cout<<height0(root)<<endl;
	cout<<num_leaf(root)<<endl;
	depth_at_k(root,2);
	cout<<endl;
	preoder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	int x;
	cout<<"enter value to be find"<<endl;
	cin>>x;
	cout<<find(root,x)<<endl;
    cout<<count_nodes(root,6)<<endl;

// 	cout<<maximum_node(root)<<endl;
// 	cout<<msn<<endl;
 	int element;
 	cout<<"enter the element"<<endl;
cin>>element;
treeNode<int>*root1=  nextLarger2(root,element);
	cout<<root1->data<<endl;
// 	//cout<<check_symmetry(root,root1);
	treeNode<int>*y=sec_greatest(root);
	cout<<y->data;

	replace_depth(root,0);
	printLevelwise(root);
	



}