#include<iostream>
using namespace std;
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int front=-1;
int rear=-1;

void insert()
{
int element;
 if(rear==(MAX-1))
 {
   cout<<"Queue full!"<<endl;
 }
 
 else
 {
   if(front==-1)
   { front=0; }
   cout<<"Enter element: ";
   cin>>element;
   queue[++rear]=element;
 }
}

void remove()
{
 int element;
 if(front==-1)
   cout<<"Queue is empty!"<<endl;
 else
 {
   cout<<"Element "<<queue[front]<<" is deleted!\n\n";
   ++front;
   if(front>rear)
   {
    front=-1;
    rear=-1;
   }
 }
}

void display()
{
 int i;
 if(front==-1)
  cout<<"Queue is empty!\n";
 else
 {
  cout<<"Queue elements are: ";
  for(i=front;i<=rear;i++)
    cout<<queue[i]<<"\t";
 }
 cout<<endl<<endl;
}

int main()
{
 int ch;
 while(1)
 {
  cout<<"1.Insert"<<endl;
  cout<<"2.Delete"<<endl;
  cout<<"3.Display"<<endl;
  cout<<"4.Exit"<<endl;
  cout<<"\nEnter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1:
    {
      insert();
      display();
    }  break;
   case 2:
    {
      remove();
      display();
      break;
    }
   case 3:
    {
      display();
      break;
    }
   case 4:
   {
      exit(0);
      break;
   }
   default:
     cout<<"Invalid choice!"<<endl;
  }
 }
}
   
