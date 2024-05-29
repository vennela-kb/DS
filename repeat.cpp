#include<iostream>
using namespace std;
int main()
{
int arr[20], i, j, n, x, temp;
cout<<"Total number of elements in array: ";
cin>>n;
cout<<"Enter Numbers: \n";
for(i=0;i<n;i++)
{ cin>>arr[i]; }
for(i=0;i<n;i++)
{
  for(j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
        {
          temp=arr[i];
          arr[i]=arr[j];
          arr[j]=temp;
        }
    }
}

cout<<"After Sorting \n";
for(i=0;i<n;i++)
{ cout<<arr[i]<<" \t"; }

cout<<"\nRepeated Elements\n";
i=0;
j=1;
 while(i<n)
   {
     if(arr[i]==arr[j])
       { cout<<arr[i]<<" \t"; }
    i++;
    j++;
   }

i=0;
j=1;
while(i<n)
  {
     if(arr[i]==arr[j])
       {
          for(x=i;x<n-1;x++)
             {arr[x]=arr[x+1];}
          n--;
       }
    else
      {
        i++;
        j++;
     }
  }
cout<<"\nElements of array after removing repeated elements:\n";
for(i=0;i<=n;i++)
  { cout<<arr[i]<<"\t"; }
cout<<endl;
return 0;
}


