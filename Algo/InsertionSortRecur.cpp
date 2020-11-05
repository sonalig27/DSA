#include<iostream>
using namespace std;

void Insertion_Sort(int *a,int n)
{
	if(n <= 1)
		return;
	Insertion_Sort(a,n-1);
	
	int last = a[n-1];
	int j = n-2;
	while(j >= 0 && a[j]>last)
	{
		a[j+1] = a[j];
		j--;
	}
	a[j+1] = last;	
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
	Insertion_Sort(arr,n);
 		 
	// Printing the sorted data.

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
      
	return 0;  
}
