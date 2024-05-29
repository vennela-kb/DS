#include <iostream>
using namespace std;

void merge(int a[], int p, int q, int r)
{
    int b[5]; 
    int i, j, k;
    k = 0;
    i = p;
    j = q + 1;
    while(i <= q && j <= r)
    {
        if(a[i] < a[j])
        {
            b[k++] = a[i++]; 
        }
        else
        {
            b[k++] = a[j++];
        }
    }
 
    while(i <= q)
    {
        b[k++] = a[i++];
    }
 
    while(j <= r)
    {
        b[k++] = a[j++];
    }
 
    for(i=r; i >= p; i--)
    {
        a[i] = b[--k]; 
    }
}
void mergeSort(int a[], int p, int r)
{
    int q;
    if(p < r)
    {
        q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
 
int main()
{
    int arr[50],n,i;
    cout<<"Enter size of array: ";
    cin>>n;
    
    cout<<"Enter Elements:\n";
    for(i=0;i<n;i++)
    { cin>>arr[i]; }

    mergeSort(arr, 0, n - 1);
 
    cout<<"Sorted array: \n";
    printArray(arr, n);
    return 0;
}
