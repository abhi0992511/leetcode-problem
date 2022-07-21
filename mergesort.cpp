#include<bits/stdc++.h>
using namespace std;

 void Merge(int *,int,int,int);
void merge_sort(int arr[],int start,int last)
{
	// if(start>=last)
	// {
	// 	return;
	// }
	 if(last>start)
	 {
	 	int mid =start+ (last-start)/2;
	 merge_sort(arr,start,mid);
	 merge_sort(arr,mid,last);
	 Merge(arr,start,mid,last);

	 }
}
void Merge(int arr[], int start, int mid, int high)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-start+1];
	i = start;
	k = 0;
	j = mid + 1;
 
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (arr[i] < arr[j])
		{
			temp[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = arr[j];
			k++;
			j++;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = arr[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = start; i <= high; i++)
	{
		arr[i] = temp[i-start];
	}
	// for (int i = 0; i < high; ++i)
	// {
	// 	cout<<arr[i]<<"";
	// }
	return;
}

// A function to split array into two parts.
// void MergeSort(int *a, int low, int high)
// {
// 	int mid;
// 	if (low < high)
// 	{
// 		mid=(low+high)/2;
// 		// Split the data into two half.
// 		MergeSort(a, low, mid);
// 		MergeSort(a, mid+1, high);
 
// 		// Merge them to get sorted output.
// 		Merge(a, low, high, mid);
// 	}
// }
int main()
{
	int n;
	cout<<"enter the size";
	cin>>n;
	int *arr=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<arr[i];
	// }
	merge_sort(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<endl;
	}
return 0;


}