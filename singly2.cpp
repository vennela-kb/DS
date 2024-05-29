#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
  int num;
  struct node *next;
};

typedef struct node NODE;

NODE *start,*news;

void insert_at_beg(int item)
{
  NODE *news;
  news=(NODE*)malloc(sizeof(NODE));
  news->num=item;
  if(start==NULL)
    news->next=NULL;
  else
    news->next=start;
    start=news;
}

void insert_at_anywhere(int value,int loc)
{
  struct node *var,*temp;
  news=(NODE*)malloc(sizeof(NODE));
  news->num=value;
  temp=start;
  if(start==NULL)
  {
    start=news;
    start->next=NULL;
  }
  else
   while(temp->num!=loc)
   {
    temp=temp->next;
   }
   var=temp->next;
   temp->next=news;
   news->next=var;
}

void insert_at_end(int item)
{
  NODE *news,*temp;
  news=(NODE*)malloc(sizeof(NODE));
  news->num=item;
  news->next=NULL;
  if(start==NULL)
    start=news;
  else
    temp=start;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=news;
}

void remove()
{
  struct node *temp;
  if(start==NULL)
    cout<<"List is empty!\n";
  else
  {
    temp=start;
    start=start->next;
    free(temp);
    cout<<"\nElement deleted successfully!\n";
  }
}

void display()
{
  struct node *temp;
  if(start==NULL)
  {
    cout<<"\nList is empty!\n";
    return;
  }
  temp=start;
  cout<<"List of elements:\n";
  while(temp!=NULL)
  {
    cout<<temp->num<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

int main()
{
  int ch,item;
  do
  {
    cout<<"\n 1.insert_at_beg";
    cout<<"\n 2.insert_anywhere";
    cout<<"\n 3.insert_at_end";
    cout<<"\n 4.delete";
    cout<<"\n 5.display";
    cout<<"\n 6.exit";
    cout<<"\n Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
      {
        cout<<"\nEnter element: \n";
        cin>>item;
        insert_at_beg(item);
        display(); 
        break;
      }
      case 2:
      {
        int value,loc;
        cout<<"\n After which data item you want to insert: ";
        cin>>loc;
        cout<<"\n Enter value to insert: ";
        cin>>value;
        insert_at_anywhere(value,loc);
        display();
        break;
      }
      case 3:
      {
		cout<<"\nEnter element: ";
        cin>>item;
        insert_at_end(item);
        display();
        break;
      }
      case 4:
      {
      	remove();
        display();
        break;
      }
      case 5:
        display();
        break;
      case 6:
        exit(0);
    } 
  }
  while(ch!=6);
}
