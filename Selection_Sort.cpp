#include<iostream>
using namespace std;
int main()
{
	int n, i, a[50], j, temp;
	cout<<"Enter total number of elements:";
	cin>>n;
	cout<<"Enter numbers:";
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	cout<<"Sorted list:"<<endl;
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
}


