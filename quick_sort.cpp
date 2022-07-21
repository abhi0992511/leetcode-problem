#include<bits/stdc++.h>
using namespace std;
int partition(int *,int ,int);
void quick_sort(int a[],int start,int last)
{
	if(start>=last)
	{
		return;
	}
	int part=partition(a,start,last);
	// cout<<part;
	quick_sort(a,start,part-1);
	quick_sort(a,part+1,last);
}
int partition(int a[],int start,int last){
	int i =start,j=last;
	int count=0;
	int temp=a[start];
	while(start<last)
	{
		if (a[start]>a[start+1])
		{
			count++;
			start++;
		}
		else{
			start++;
		} 

	}
	a[start]=a[count];
		a[start+count]=temp;
		while(i<start+count&&j>start+count)
		{
			if(a[i]<temp)
			{
				i++;
			}
			else if (a[j]>temp)
			{
				j--;
			}
			else{
				int s=a[i];
				a[i]=a[j];
				a[j]=s;
			i++,j--;
			}
		}
		return start+count;


}
int main()
{
	int n;
	cout<<"enter the size of array";
	cin>>n;
	int * arr=new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	quick_sort(arr,0,n-1);
	for (int i = 0; i < n; i++)
	{
		cout<<arr[i];
	}

}