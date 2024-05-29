#include<iostream>
using namespace std;
#define MAX 5
int TOP,status;
int stack[MAX];

void add(int stack[],int number)
{
   if(TOP==(MAX-1))
     status=0;
   else
     {
       status=1;
       ++TOP;
       stack[TOP]=number;
     }
}

int remove(int stack[])
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

int contains(int stack[],int number)
{
	for(int i=0;i<5;i++)
	{
		if( stack[i]==number)
		{
			return 1;
			break;
		}
	}
	return(0);
}                    

void clear(int stack)
{
	for(int i=0;i<5;i++)
	{
		stack[i]=0;
	}
}
                   
int main()
{
 int ch;
 int number;
 TOP=-1;
 do 
  {
   do
    {
       cout<<"MAIN MENU"<<endl;
       cout<<"1.ADD"<<endl;
       cout<<"2.REMOVE"<<endl;
       cout<<"3.DISPLAY"<<endl;
       cout<<"4.CONTAINS"<<endl;
       cout<<"5.CLEAR"<<endl;
       cout<<"Enter your choice: ";
       cin>>ch;
     
       if(ch<1 || ch>5)
            exit();
    }while(ch<1 || ch>3);
     
     switch(ch)
     {
       case 1:
            cout<<"Enter the element to be added: ";
            cin>>number;
            add(stack,number);
            if(status)
            {
                display(stack);
                if(TOP==(MAX-1))
                    cout<<"Stack is full";
            }
            else
                cout<<"Stack is overflow";
       break;
       
       case 2:
           number=remove(stack);
           if(status)
            {
               cout<<endl<<"The number deleted = "<<number;
            }
           else
               cout<<endl<<"Stack is underflow"<<endl;
       break;
       
	   case 3:
            display(stack);
       break; 
        
        case 4:
        	cout<<"Enter number to be searched: ";
        	cin>>search;
        	status_contain=contains(stack,search);
        	if(status_contain)
        	{
        		cout<<"Found!!"<<endl
			}
			else
			{
				cout<<"Not Found!!"<<endl;
			}
		break;
		
		case 5:
			clear(stack);
			display(stack);
    }
  }while(ch<=5);
}    
              
 
