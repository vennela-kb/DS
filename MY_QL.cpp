#include<iostream>
using namespace std;
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*rear,*front;
typedef struct node NODE;
void insert(int value)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(NODE));
	temp->data=value;
	if(front==NULL)
	{
		front=temp;
		front->next=NULL;
		rear=front;
	}
	else
	{
		rear->next=temp;
		rear=temp;
		rear->next=NULL;
	}
}

void remove()
{
	NODE *temp;
	temp=front;
	if(front==NULL)
	{
		cout<<"EMPTY!!"<<endl;
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
	}
}

void display()
{
	NODE *temp;
	temp=front;
	if(front==NULL)
	{
		cout<<"EMPTY!!"<<endl;
	}
	else if(temp!=NULL)
	{
		cout<<"Elements are:  ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	int i=0;
	front=NULL;
	cout<<"1.Insert"<<endl;
	cout<<"2.Delete"<<endl;
	cout<<"3.Display"<<endl;
	cout<<"4.Exit"<<endl;
	while(1)
	{
		cout<<"Enter choice: ";
		cin>>i;
		switch(i)
		{
			case 1:
				int value;
				cout<<"Enter data: ";
				cin>>value;
				insert(value);
			    display();
				break;
				
		    case 2:
		    	remove();
		    	display();
		    	break;
		    	
		    case 3:
		    	display();
		    	break;
		    	
		    case 4:
		    	exit(0);
		    	break;
		    	
		    default:
		    	cout<<"Invalid choice!!"<<endl;
		}
	}
}
