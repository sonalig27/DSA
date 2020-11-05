#include <iostream>
using namespace std;
int Partition(int *a, int low, int high)
{
	int x, i, temp1,temp2;
	x = a[high];
	i = low - 1;
	for (int j = low; j < high;j++)
	{
		if(a[j] <= x)
		{
			i++;
			swap(a[i], a[j]);
		}
			
	}
	swap(a[i+1], a[high]);
	return i+1;
	
}
void Quick_Sort(int *a, int low, int high)
{

	if(low < high)
	{
		int q = Partition(a,low,high);
		//cout<<endl<<q<<" "<<endl;
		//cout<<low<<"-"<<high<<"-";
		Quick_Sort(a,low,q-1);
		Quick_Sort(a,q+1,high);
		
	}
}

int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}	
 
	Quick_Sort(arr, 0, n-1);
	 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
 
	return 0;
}
