#include <iostream>
 
using namespace std;
//int inv_count = 0;
// A function to merge the two half into a sorted data.
int Merge(int *a, int low, int high, int mid)
{
	int inv_count = 0;
//	cout<<endl;
//	for(int i = low; i <= mid;i++)
//	{
//		cout <<a[i]<<" ";
//	}
//	cout<<endl<<endl<<endl<<endl;
//	for(int i = mid+1; i <= high;i++)
//	{
//		cout <<a[i]<<" ";
//	}
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
			inv_count += (mid+1)-i;
		}
	}
 
	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 
	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
 
 
	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
	return inv_count;
}
 
// A function to split array into two parts.
int MergeSort(int *a, int low, int high)
{
	//cout<<endl;
	//for(int i = low; i <= high;i++)
	///{
	//	cout <<a[i]<<" ";
	//}
	int mid;
	int inv_count = 0;
	if (low < high)
	{
		//int inv_count = 0;
		mid=(low+high)/2;
		// Split the data into two half.
		inv_count += MergeSort(a, low, mid);
		inv_count += MergeSort(a, mid+1, high);
		// Merge them to get sorted output.
		inv_count += Merge(a, low, high, mid);
	//	return inv_count;
	}
	return inv_count;
}
 
int main()
{
	int n, i, count;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	count = MergeSort(arr, 0, n-1);
	 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
        
    cout <<endl<<"The number of inversions for the given set = "<<count;
 
	return 0;
}
