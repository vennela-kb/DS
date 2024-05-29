#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX 5
int TOP=-1;

void push(int stack[],int item)
{
	if(TOP==(MAX-1))
	{
		cout<<"Stack is full!!"<<endl;
	}
	else
	{
		TOP++;
		stack[TOP]=item;
	}
}

void pop(int stack[])
{ 
	if(TOP==-1)
	{
		cout<<"Stack is empty!!"<<endl;
	}
	else
	{
		cout<<"The popped element is "<<stack[TOP]<<endl;
		TOP--;
	}
}

void display(int stack[])
{
	int i;
	if(TOP==-1)
	{
		cout<<"Stack is underflow!"<<endl;
	}
	else
	{
		cout<<"Stack elemnets are: ";
		for(i=0;i<=TOP;i++)
		{
			cout<<stack[i]<<"\t";
		}
		cout<<endl;
	}
}

int main()
{
	int ch,stack[MAX],item;
	cout<<"1.PUSH"<<endl;
	cout<<"2.POP"<<endl;
	cout<<"3.EXIT"<<endl;
	do
	{
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"Enter element to be pushed: ";
					cin>>item;
					push(stack,item);
					display(stack);
					break;
				}
			
			case 2:
				{
					pop(stack);
					display(stack);
					break;
				}
				
			case 3:
				{
					exit(0);
					break;
				}
		}
	}while(ch>=1 && ch<=3);
	
}
