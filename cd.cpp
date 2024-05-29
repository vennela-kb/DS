#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int data;
  struct node *previous;
  struct node *next;
};
typedef struct node NODE;
NODE *start,*last;

void insert_beg(int value)
{
  NODE *ptr,*temp;
  ptr=(NODE*)malloc(sizeof(NODE));
  ptr->data=value;
  if(start==NULL)
  {
    start=ptr;
    start->previous=start;
    start->next=start;
  }
  else
  {
    temp=ptr;
    while(temp->next!=start)
    {
      temp=temp->next;
      temp=temp->previous;
    }
    temp->next=start;
    temp->previous=start;
    start=temp;
  }
}

void insert_end(int value)
{
  NODE *ptr,*temp;
  ptr=(NODE*)malloc(sizeof(NODE));
  ptr->data=value;
  if(start==NULL)
  {
    start=ptr;
    start->previous=start;
    start->next=start;
  }
  else
  {
    last=start;
    while(last->next!=start)
    {
      temp=last;
      last=last->next;
    }
    last->next=ptr;
    ptr->previous=last;
    ptr->next=start;
    start->previous=ptr;
    last=ptr;
  }
}

void insert_mid(int value,int loc)
{
  NODE *temp,*ptr,*temp1;
  ptr=(NODE*)malloc(sizeof(NODE));
  ptr->data=value;
  if(start==NULL)
  { cout<<"List is empty!"<<endl; }
  
  if(loc==start->data)
  { insert_beg(value); }
  
  else
  {
    temp=start;
    while(temp!=start && temp->data!=loc)
    { temp=temp->next; }
    if(temp==start)
    { cout<<loc<<" does not exist!"<<endl; }
    else
    {
      temp1=temp->next;
      temp->next=ptr;
      ptr->previous=temp;
      ptr->next=temp1;
      temp1->previous=ptr;
      cout<<value<<" inserted"<<endl;
    }
  }
}

void deletion(int loc)
{
  NODE *temp;
  temp=start;
  if(start==NULL)
  { cout<<"List is empty!"<<endl; }
  else
  {
    temp=start;
    while(temp->data!=loc)
    {
      temp=temp->next;
      temp=temp->previous;
      free(temp);
    }
  }
}

void display()
{
  NODE *temp;
  temp=start;
  if(temp==NULL)
  { cout<<"List is empty!"<<endl; }
  else
  {
    cout<<temp->data;
    while(temp->next!=start)
    {
      temp=temp->next;
      cout<<temp->data<<"\t";
    }
    cout<<endl;
  }
}

int main()
{
  int value,i,loc;
  start=NULL;
  do
  {
    cout<<"Select your choice"<<endl;
    cout<<"1.Insert at Beginning"<<endl;
    cout<<"2.Insert at End"<<endl;
    cout<<"3.Insert in Middle"<<endl;
    cout<<"4.Delete"<<endl;
    cout<<"5.Display"<<endl;
    cout<<"6.Exit"<<endl;
    
    while(1)
    {
      cout<<"Enter your choice: ";
      cin>>i;
      switch(i)
      {
        case 1:
        {
          cout<<"Enter data to insert: ";
          cin>>value;
          insert_beg(value);
          display();
          break;
        }
        case 2:
        {
          cout<<"Enter the value: ";
          cin>>value;
          insert_end(value);
          display();
          break;
        }
        case 3:
        {
          cout<<"After which value you want to insert: ";
          cin>>loc;
          cout<<"Enter data to insert: ";
          cin>>value;
          insert_mid(value,loc);
          display();
          break;
        }
        case 4:
        {
          cout<<"Enter the value you want to delete: ";
          cin>>loc;
          deletion(loc);
          display();
          break;
        }
        case 5:
        {
          display();
          break;
        }
        case 6:
        {
          exit(0);
          break;
        }
        default:
        {
          cout<<"Invalid choice!"<<endl;
          break;
        }
      }
    }
  }while(i!=6);
}
          
  
