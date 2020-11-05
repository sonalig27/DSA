# include<iostream>
using namespace std;
Selection_Sort(int *a, int n)
{
	int temp,index;
	for (int i = 0; i < n-1 ; i++)
	{
		index = i;
		for(int j = i+1 ; j < n ; j++)
		{
			if(a[index] > a[j])
			{
				index = j;
			}
		
		}
		temp = a[index];
		a[index] = a[i];
		a[i]= temp;
	
		//cout <<"a[ "<<i<<" ]"<<a[i] <<endl;
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
	Selection_Sort(arr,n);
 		 
	// Printing the sorted data.

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
        cout<<arr[i]<<" ";
      
	return 0;  
}
