#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
}*TOP;

void push(int item)
{
	struct node *ptr;
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=item;
	if(TOP==NULL)
	{
		TOP=ptr;
		TOP->next=NULL;
	}
	else
	{
		ptr->next=TOP;
		TOP=ptr;
	}
}

void pop()
{
	struct node *ptr;
	ptr=TOP;
	if(TOP==NULL)
	{
		cout<<"Stack is empty!!"<<endl;
	}
	else
	{
		TOP=TOP->next;
		free(ptr);
	}
}

void display()
{
	int i;
	struct node *ptr;
	ptr=TOP;
	if(TOP==NULL)
	{
		cout<<"Stack is empty!!"<<endl;
	}
	else
	{
		cout<<"Stack elements are: ";
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"\t";
			ptr=ptr->next;
		}
		cout<<endl;
	}
}

int main()
{
	int item,ch;
	TOP=NULL;
	cout<<"1.PUSH\n";
	cout<<"2.POP\n";
	cout<<"3.DISPLAY\n";
	cout<<"4.EXIT\n";
	while(1)
	{
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Enter element to be pushed: ";
					cin>>item;
					push(item);
					display();
					break;
				}
			case 2:
				{
					pop();
					cout<<"After popping"<<endl;
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
		}
	}
}
