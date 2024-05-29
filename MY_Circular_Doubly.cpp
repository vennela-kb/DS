#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *previous;
	struct node *next;
}*start,*last;
typedef struct node NODE;

void insert_beg(int value)
{
	NODE *temp,*ptr;
	ptr=(NODE*)malloc(sizeof(NODE));
	ptr->data=value;
	if(start==NULL)
	{
		start=ptr;
		start->next=start;
		start->previous=start;
		last=start;
	}
	else
	{
		temp=ptr;
		last->next=temp;
		temp->previous=last;
		start->previous=temp;
		start=temp;
	}
}

void display()
{
	struct node *temp;
	temp=start;
	if(temp==NULL)
	{
		cout<<"List is empty!"<<endl;
	}
	else
	{
		cout<<"Elements are: "<<temp->data;
		temp=temp->next;
		while(temp!=start)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
		cout<<endl<<endl;
	}
}

int main()
{
	int value;
	start=NULL;
	while(1)
	{
	cout<<"Enter data: ";
	cin>>value;
	insert_beg(value);
 	display();
    }
}
