#include<iostream>
#include<stdlib.h>
 using namespace std;
 struct node
    {
     int data;
     struct node *next;
    }*last=NULL,*start=NULL;
 void insert_at_first(int value)
 {
 struct node *temp;
 temp=(struct node*)malloc(sizeof(struct node));
 temp->data=value;
 if(start==NULL)
     {
       temp->next=NULL;
       start=temp;
       last=start;
      }
  else
     {
       temp->next=start;
       start=temp;

     }
 }
 void insert_at_middle(int value,int loc)
 {
 struct node *temp2=start,*new1,*var;
 new1=(struct node*)malloc(sizeof(struct node));
 new1->data=value;
 if(start==NULL)
   {
     cout<<"IT IS THE FIRST ELEMENT\n";
    insert_at_first(value);
   }
  else
   {
    while(temp2->data!=loc)
         temp2=temp2->next;
    var=temp2->next;
    temp2->next=new1;
    new1->next=var;
   }}
void insert_end(int value)
{
struct node *temp3;
temp3=(struct node*)malloc(sizeof(struct node));
temp3->data=value;
   if(start==NULL)
     {
      cout<<"NO ELEMENT IS PRESENT ENTERING DATA IN FIRST NODE\n";
      insert_at_first(value);
     }
     else
     {
     last->next=temp3;
     last=temp3;
     last->next=NULL;
     }
  }
void remove()
{
  struct node *temp;
  temp=start;
  if(temp==NULL)
  cout<<"EMPTY\n";
  else
   {
    start=start->next;
    free(temp);
    cout<<"element deleted"<<endl;
   }
}
void display()
 {
   struct node *temp5;
   temp5=start;
   if (temp5==NULL)
   cout<<"it is empty\n";
   else
   {
   cout<<"ELEMENTS IN NODES ARE=";
   while(temp5!=NULL)
     {
        cout<<temp5->data<<"\t";
        temp5=temp5->next;
     }
    }
}
int main()
{
int choice,loc,value;
cout<<"1.insert at beg\n2.insert at middle\n3.inseert at end\n4.delete\n5.display\n6.exit\n";
while(choice!=6)
{
cout<<"enter choice\n";
cin>>choice;
switch(choice)
   {
     case 1 :
          {
          cout<<"ENTER DATA\n";
          cin>>value;
           insert_at_first(value);
           display();
           break;
          }
     case 2 :
          { cout<<"AFTER WHICH ELEMENT U WANT TO ENTER\n";
            cin>>loc;
            cout<<"enter data\n";
            cin>>value;
            insert_at_middle(value,loc);
            display();
            break;
          }
     case 3 :
         {
           cout<<"ENTER DATA\n";
           cin>>value;
           insert_end(value);
           display();
           break;
         }
     case 4 :
         {
         remove();
         display();
         break;
         }
     case 5:
         {
          display();
          break;
         }
     case 6 :
         {
           exit(0);
           break;
         }
   }
   }
   }
