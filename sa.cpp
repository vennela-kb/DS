#include<iostream>
using namespace std;
#define MAX 5
int TOP,status;

void push(int stack[],int item)
{
   if(TOP==(MAX-1))
     status=0;
   else
     {
       status=1;
       ++TOP;
       stack[TOP]=item;
     }
}

int pop(int stack[])
{
   int ret;
   if(TOP==-1)
     {
       ret=0;
       status=0;
     }
   else
    {
      status=1;
      ret=stack[TOP];
      --TOP;
    }
  return ret;
}

void display(int stack[])
{
  int i;
  cout<<"\nThe stack is:"<<endl;
  if(TOP==-1)
    cout<<"Stack is empty"<<endl;
  else
    {
      for(i=TOP;i>=0;i--)
        {
          cout<<stack[i]<<"\t";
        }
      cout<<endl;
    }
  cout<<endl;
}                        
                   
int main()
{
 int ch;
 int stack[MAX],item;
 TOP=-1;
 do 
  {
   do
    {
       cout<<"MAIN MENU"<<endl;
       cout<<"1.PUSH"<<endl;
       cout<<"2.POP"<<endl;
       cout<<"3.EXIT"<<endl;
       cout<<"Enter your choice: ";
       cin>>ch;
     
       if(ch<1 || ch>3)
        cout<<"Invalid choice, try again!"<<endl;
    }while(ch<1 || ch>3);
     
     switch(ch)
     {
       case 1:
            cout<<"Enter the element to be pushed: ";
            cin>>item;
            cout<<"Item="<<item<<endl;
            push(stack,item);
            if(status)
             {
               cout<<endl<<"After pushing";
               display(stack);
               if(TOP==(MAX-1))
                    cout<<"Stack is full";
            }
          else
             cout<<"Stack is overflow";
       break;
       
       case 2:
           item=pop(stack);
           if(status)
            {
               cout<<endl<<"The popped item= "<<item;
               display(stack);
            }
           else
               cout<<endl<<"Stack is underflow"<<endl;
       break;
        
       default:
           cout<<endl<<"END OF PROGRAM"<<endl;
     }
  }while(ch!=3);
}    
              
 
