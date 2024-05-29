#include<iostream>
using namespace std;
int e[500],k,n;

int linearsearch(int e[],int n,int k)
{
  int i;
  for(i=0;i<n;i++)
    {
      if(k==e[i])
        {
           return i;
           break;
        }
     }
    for(i=0;i<n;i++)
     {
        if(k!=e[i])
          { return -1; }
     }
}

int main()
{
  int i,pos;
  cout<<"ENTER NUMBER OF ELEMENTS IN THE LIST: ";
  cin>>n;
  cout<<"ENTER THE ELEMENTS ONE BY ONE: "<<endl;
  for(i=0;i<n;i++)
    {
      cin>>e[i];
    }
  cout<<"ENTER THE KEY TO BE SEARCHED: ";
  cin>>k;
  pos=-1;
  pos=linearsearch(e,n,k);
  if(pos!=-1)
    {  cout<<"ELEMENT IS IN THE POSITION - "<<pos+1<<endl;  }
  else
    {  cout<<"ELEMENT IS NOT FOUND IN THE LIST!"<<endl;  }
}
