#include <bits/stdc++.h>
using namespace std;
#include "node.cpp"
// class pair{
// public:
// 	node*head;
// 	node*tail;

// };


// pair reverse_linklist_better(node*);
//INSERT AT Ith POSITION:
node * insert(node*head,int pos,int data)
{
	node*newnode=new node(data);
	newnode->next=NULL;
	node*prev=NULL;
	node*curr=head;
	int count=0;
	if (pos==0)
	{
		newnode->next=head;
		head =newnode;
		return head;
	}
	while(curr!=0&&count<pos-1)
	{
       curr=curr->next;
       pos--;
	}
	// prev=curr->next;
	// curr->next=newnode;
	// newnode->next=prev;
	if (curr!=0)
	{
		newnode->next=curr->next;
	curr->next=newnode;
	
	
	}
	return head;

}
//DELETE THE NODE AT Ith POSITION:

node* delete1(node *head,int pos)
{     node*temp= head;
	int count=0;
	if (pos==0)
	{
		head=head->next;
		delete temp;
		return head;
	}
	while(temp!=0&&count<pos-1)
	{
     temp=temp->next;
     count++;
	}
	if (temp!=0)
	{
		node*del=temp->next;
	temp->next=temp->next->next;
	delete del;
	
	}

	return head;

}
//TAKE INPUT:
node* takeinput()
{
	int data;
	cin>>data;
	node*head=NULL;
	while(data!=-1)
	{
		node *newnode=new node(data);
		if(head==	NULL)
		{
		head=newnode;
		}
		else{
	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
		}
		cin>>data;
	}
	return head;
}//TAKE INPUT (BETTER TIME COMPLEXITY)
node* takeinput_better()
{
	int data;
	cin>>data;
	node*head=NULL;
	node*tail=NULL;
	while(data!=-1)
	{
		node *newnode=new node(data);
		if(head==	NULL)
		{
		head=newnode;
		tail=newnode;
		}
		else{
			tail->next=newnode;
			tail=newnode;
		}
	
	
		cin>>data;
	}
	return head;
}
//PRINT THE LINKLIST
void print(node *head)
{
	node*temp=head;

	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
//LENGTH RECURSIVELY
int length(node*head)
{
	if (head==NULL)
	{
          return 0;
	}
	else{
		return 1+length(head->next);
	}
}
//INSERT RECURIVELY
node *insert_Recursive(node *head,int i,int data)
{
	if (head==NULL)
	{
		return head;
	}
	if (i==0)
	{
		node*newnode=new node(data);
		newnode->next=head;
		//head->next=newnode;
		head=newnode;
	}

	node*x=insert_Recursive(head->next,i-1,data);
	head->next=x;
	return (head);
}
//DELETE_NODE_RECURSIVELY:
node* delete_recursive(node *head,int index)
{
	if (head==NULL)
	{
		return head;
	}
	  else if (index==0)
	{
		node *temp1;
		temp1=head;
		head=head->next;
		delete temp1;
	

	}
	  node*x=delete_recursive(head->next,index-1);
	  head->next=x;
	  return head;
       
}
//FIND_DATA:
int find_data(node * head,int data)
{
	if (head==NULL)
	{
		return -1;
	}
	int index=0;
	node* temp=head;
	while(temp!=0)
	{
      if (data==temp->data)
      {
         return index;
      }
      else 
      {
      	index++;
      	temp=temp->next;
      }
	}
	return -1;
}
node * append_Last(node *head,int n)
{
	int len=length(head);
	node *temp =head;
	node*head1=NULL;
	node*x=NULL;
	
	int append=len-n;
	int i=0;
	while(i<=append)
	{
     temp=temp->next;
     i++;
	}
	head1=temp->next;
	x=head1;
	temp->next=NULL;
	while(head1->next!=NULL)
	{
		head1=head1->next;
	}
	head1->next=head;
	head=x;
return head;

}
//REMOVE_SORTED_DUPLICATES:
node *remove_duplicate(node *head)
{
	node*t1=head;
	node*t2=head->next;
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	while(t1!=NULL&&t2!=NULL)
	{
		if (t1->data==t2->data)
		{
			t2=t2->next;
		}
		else{
			//node *n=t2;
			t1->next=t2;
			t2=t2->next;
			t1=t1->next;
			//delete n;
		}
	}
	t1->next=t2;
	return head;
}
//REVERSE_LINKLIST:
// pair reverse_linklist_better(node*head)
// {
// 	if (head==NULL||head->next==NULL)
// 	{
// 		pair ans;
// 		ans.head=head;
// 		ans.tail=head;
// 	}
// 	pair small=reverse_linklist_better(head->next);
// 	small.head->next=head;
// 	head->next=NULL;
// 	pair ans;
// 	ans.head=small.head;
// 	ans.tail=head;
// 	return ans;
// }

node *reverse(node*head)
{
	node*curr=head;
	node *prev=NULL;
	node* next=head;
	if (head==NULL||head->next==NULL)
	{
	   return head;
	}
	while(next!=NULL)
	{
       next=curr->next;
       curr->next=prev;
       prev=curr;
       curr=next;
	}
	head=prev;
	return head;
}
//REVERSE_BY_USING_RECURSION:
node *reverse_recursion(node *head)
{
   
   if (head->next=NULL)
   {
   	return head;
   }
   node*x=reverse_recursion(head->next);
   x->next=head;
   head->next=NULL;
   return x;
   
}
// REVERSE_RECURSION:
node * reverse_recursion1(node *head)
{
   
   if (head==NULL||head->next==NULL)
   {  
 
   	return head;
   }
    node *small=reverse_recursion1(head->next);
    node*temp=small;
  while(temp->next!=NULL)
  {
  	temp=temp->next;
  }
  temp->next=head;
  head->next=NULL;
  return small;

   
   
}
//MID-POINT_LINKLIST:
node* mid_point(node*head)
{
	if (head==NULL||head->next==NULL)
	{
		return head;
	}
	node *slow=head;
	node*fast=head->next;
	while(slow!=NULL&&fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if (fast==NULL)
		{
			break;
		}
	}
	return slow;
}
//MERGE_SORTED_LINKLIST:
node* megre_sorted_linklist(node*head,node*head1)
{
   node*final_head=NULL;
   node*final_tail=NULL;
   if (head==NULL)
   {
   	return head1;

   }
   if(head1==NULL)
   {
   	return head;
   }
   if (head->data<=head1->data)
   {
   	final_head=head1;
   	final_tail=head1;
   	head1=head1->next;
   }
   else{
   	final_head=head;
   	final_tail=head;
   	head=head->next;
   }
   while(head!=NULL&&head1!=NULL)
   {
   	if (head->data<=head1->data)
   	{
   		final_tail->next=head1;
   		final_tail=head1;
   		head1=head1->next;

   	}
   	final_tail->next=head;
   	final_tail=head;
   	head=head->next;
   }
   if (head==NULL&&head1!=NULL)
   {
   	final_tail->next=head1;
   }
   else if(head1==NULL&&head!=NULL)
   	final_tail->next=head;
   return final_head;

}
// FIND_DATA_RECURSIVE:

int find_data_recursive(node*head,int data)
{ 
	if (head==NULL)
	{
		return-1;
	}
	else if (head->data==data)
	{
		return head->data;
	}

		int x=find_data_recursive(head->next,data);
		return x;
	


	
}
//FIND_POSITION_USING_RECURSION:
int find_postion(node*head,int val,int count)
{
	if (head==NULL)
	{ 
		count=-1;
		return count;
	}
	else if(head->data==val)
	{
		count++;
		return count;
	}


	int x=find_postion(head->next,val,++count);
	return x;
}
//SEPRATE_EVEN_OOD:
node* even_odd(node*head)
{
	node*odd_head=NULL;
	node*odd_tail=NULL;
	node *even_head=NULL;
	node*even_tail=NULL;
	if (head==NULL)
	{
		return head;
	}
	if (head->data%2==0)
	{
		even_head=head;
		even_tail=head;
	}
	else
	{
		odd_head=head;
		odd_tail=head;
	}
	head=head->next;
	while(head!=NULL)
	{
		if ((head->data)%2!=0)
        {
				odd_tail->next=head;
				odd_tail=head;

			}
		
		else{
	    
				even_tail->next=head;
				even_tail=head;
			}
		
		head=head->next;
	}
	odd_tail->next=NULL;
	even_tail->next=NULL;
	odd_tail->next=even_head;
	return odd_head;


}
//DELETE_EVERY_NODE:
node* delete_every_node(node*head,int start,int last)
{
 if (start==0&&last==0)
 {
 	return head;
 }
 node *temp=head;
 node*temp1=NULL;
 while(start)
 {
 	temp=temp->next;
 	start--;
 }
 temp1=temp;
 int x=start-last;
 while(x)
 {
 	temp=temp->next;
 	x--;
 }
 temp=temp->next;
 temp1->next=temp;
 return head;


}
//SWAP_LINKLIST:
// node *swap(node*head,int st,int lt)
// {
// 	node*temp=head;
// 	node*t1=head;
// 	node*t2=head;
// 	node*p1=NULL;
// 	node*p2=NULL;
// 	int i=0;
// 	int j=0;
// 	while(temp!=NULL)
// 	{
// 		if (i<st)
// 		{
// 			t1=temp->next;
// 			p1=temp;
// 			i++;
// 		}
// 		if (j<lt)
// 		{
// 			t2=temp->next
// 			p2=temp;
// 			j++;
// 		}

// 		temp=temp->next;
// 		if (j==lt)
// 		{
// 			break;
// 		}
// 	}
	
// }
//REVERSE_RECURSION2:
node *reverse_recursion2(node*head)
{ 
if (head==NULL||head->next==NULL)
{
	return head;
}
node* small=reverse_recursion2(head->next);
node*tail=head->next;
tail->next=head;
head->next=NULL;
return small;
}
//MERGE_SORT:
// node *merge_sort(node *head,node *mid)
// {
// 	node *mid=mid_point(head);
// 	merge_sort(head->next)
// }
//REVERSE_LINKLIST_BETTER:

int main()
{
	// node a(3);
	// node *head=&a;

	// node *n=new node(5);
	// a.next=&(*n);
	
	node *head=takeinput_better();
	node*head1=takeinput_better();
	//int n,data;
	//cin>>n>>data;
	//head=insert_Recursive(head,n,data);
	print(head);
	cout<<endl;
	print(head1);
	cout<<endl;
	//head=reverse_recursion1(head);
	//print(head);
	node*y=megre_sorted_linklist(head,head1);
	//head=reverse_recursion2(head);
	print(y);
	cout<<endl;


	//head=reverse_linklist_better(y);
	int data;
	cin>>data;
	int x=find_data_recursive(head,data);
	cout<<x;
	cout<<endl;
	// head=even_odd(head);
	// print(head);
	head=delete_every_node(head,1,3);
	print(head);
	

	int val;
	cin>>val;
	int z=find_postion(head,val,-1);
	cout<<z<<endl;
	
	
	//cout<<endl;
	//head=delete1(head,45); 
	//int y=length(head);
	//cout<<y<<endl;
//	head=delete_recursive(head,0);
	//print(head);
	//y=length(head);
	//cout<<endl;
	//cout<<y<<endl;
	//int data1;
	//cin>>data1;
//	int z=find_data(head,data1);
	//cout<<z<<endl;
	//head=append_Last(head,3);
	//head=remove_duplicate(head);
//	print(head);
	//cout<<endl;//
	//head=reverse_recursion(head);
	//reverse_recursion1(head);

	//print(head);
	//node *x=mid_point(head);
	//cout<<x->data;
	
	
}