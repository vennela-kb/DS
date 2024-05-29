#include<iostream>
using namespace std;
int e[500],maxs,key;

int linearsearch(int e[],int maxs,int key)
{
int i,temp;
for(i=0;i<maxs;i++)
  {
     if(key==e[i])
    {
     return i;
    }
     else
    {
     return -1;
    }
  }
}
 
int main()
{
 int i,pos;
 cout<<"ENTER NUMBER OF ELEMENTS IN THE LIST: ";
 cin>>maxs;
 cout<<"ENTER THE KEY TO BE SEARCHED: ";
 cin>>key;
 cout<<"ENTER THE ELEMENTS ONE BY ONE: "<<endl;
 for(i=0;i<maxs;i++)
    {
       cin>>e[i];
    }

 pos=linearsearch(e,maxs,key);
 if(pos!=-1)
    cout<<"ELEMENT IS IN THE POSITION - "<<pos<<endl;
 else
    cout<<"ELEMENT IS NOT FOUND IN THE LIST!"<<endl;
}

