#include<iostream>
using namespace std;
#include<stdlib.h>
struct node
{
struct node *previous;
int data;
struct node *next;
}*start,*last;
void insert_beg(int value)
{
struct node *ptr,*temp;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
if(start==NULL)
{
start=ptr;
start->previous=NULL;
start->next=NULL;
last=start;
}
else
{

ptr->previous=NULL;
ptr->next=start;
start->previous=ptr;
start=ptr;
}
}
void insert_end(int value)
{
struct node *ptr,*temp;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
if(start==NULL)
{
start=ptr;
start->previous=NULL;
start->next=NULL;
last=start;
}
else
{
last=start;
while(last!=NULL)
{
temp=last;
last=last->next;
}
last=ptr;
temp->next=last;
last->previous=temp;
last->next=NULL;
}
}
void insert_after(int value,int loc)
{
struct node *temp,*ptr,*temp1;
ptr=(struct node*)malloc(sizeof(struct node));
ptr->data=value;
if(start==NULL)
{
start=ptr;
start->previous=NULL;
start->next=NULL;
}
{
temp=start;
while((temp!=NULL)&&(temp->data)!=loc)
{
temp=temp->next;
}
if(temp==NULL)
{
cout<<loc<<" not present in the list";
}
else
{
temp1=temp->next;
temp->next=ptr;
ptr->previous=temp;
ptr->next=temp1;
temp1->previous=ptr;
}
}
last=start;
while(last->next!=NULL)
{
last=last->next;
}
}
void delet()
{
struct node *temp;
temp=start;
start=start->next;
free(temp);
cout<<"\nElement deleted successfully";
}
void display()
{
struct node *temp;
temp=start;
if(temp==NULL)
{
cout<<"list is empty"<<endl;
}
while(temp!=NULL)
{
cout<<temp->data;
temp=temp->next;
}
}
int main()
{
int value,i,loc;
start=NULL;
cout<<"select your choice:"<<endl;
cout<<"\n1.insert at beginning";
cout<<"\n2.insert at end";
cout<<"\n3.insert anywhere";
cout<<"\n4.delete";
cout<<"\n5.display";
cout<<"\n6.exit";
while(1)
{
cout<<"\n\nEnter your choice:";
cin>>i;
switch(i)
{
case 1:
{
cout<<"\nEnter data to insert:";
cin>>value;
insert_beg(value);
display();
break;
}
case 2:
{
cout<<"\nEnter value:";
cin>>value;
insert_end(value);
display();
break;
}
case 3:
{
cout<<"\nAfter which data item you want to insert:";
cin>>loc;
cout<<"\nenter data to insert";
cin>>value;
insert_after(value,loc);
display();
break;
}
case 4:
{
delet();
display();
break;
}
case 5:
{
display();
break;
}
case 6:
exit(0);
break;
}
}
}
