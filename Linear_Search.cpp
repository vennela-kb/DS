#include<iostream>
using namespace std;

int a[500],maxs,key;

int linearsearch(int a[],int maxs,int key)
{
   int i,temp;
   for(i=0;i<maxs;i++)
   {
      if(key==a[i])
	  {
        return i;
        break;
	  }
	  else
	  {
        return i=-1;
        break;
	  }
   }
}

 
int main()
{
   int i,pos;
   cout<<"ENTER NUMBER OF ELEMENTS IN THE LIST"<<endl;
   cin>>maxs;
   cout<<"ENTER THE KEY TO BE SEARCHED"<<endl;
   cin>>key;
   cout<<"ENTER THE ELEMENTS ONE BY ONE"<<endl;
   for(i=0;i<maxs;i++)
   {
     cin>>a[i];
   }
   pos=-1;
   pos=linearsearch(a,maxs,key);
   if(pos!=-1)
      cout<<"ELEMENT IS IN POSITION "<<pos<<endl;
   else
      cout<<"ELEMENT IS NOT IN THE LIST "<<endl;
}

