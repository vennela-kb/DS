#include<iostream>
using namespace std;
#include<stdlib.h>
struct node
{
 int data;
  struct node *next;
}*rear,*front;

void remove()
{
 struct node *temp,*var=rear;
 if(var==rear)
 {
  rear=rear->next;
  free(var);
 }
 else
 {
  cout<<"\nQueue is empty!\n";
  }
}

void insert(int value)
{
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->data=value;
 if(front==NULL)
  {
   front=temp;
   front->next=NULL;
   rear=front;
  }
 else
  {
   front->next=temp;
   front=temp;
   front->next=NULL;
  }
}

void display()
{
 struct node *var;
 var=rear;
  if(rear==NULL)
  cout<<"\nQueue is empty!\n";
 else
 {
  cout<<"\nElements are: ";
  while(var!=NULL)
  {
   cout<<var->data<<"\t";
   var=var->next;
  }
  cout<<"\n";
 }

}

int main()
{
 int i=0;
 front=NULL;
 cout<<"\n1.Insert";
 cout<<"\n2.Delete";
 cout<<"\n3.Display";
 cout<<"\n4.Exit";
 while(1)
 {
  cout<<"\nEnter choice: ";
  cin>>i;
  switch(i)
  {
   case 1:
    int value;
    cout<<"\nEnter value";
    cin>>value;
    insert(value);
    display();
    break;
   
   case 2:
    {
     remove();
     display();
     break;
    }
   
   case 3:
    display();
    break;
   
   case 4:
    exit(0);
    break;
    
   default:
    cout<<"\nInvalid choice";
  }
 }
}
