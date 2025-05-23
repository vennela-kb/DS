#include<iostream>
#include<stdio.h>
using namespace std;
struct doublylist
{
    int no;
    struct doublylist *next;
    struct doublylist *prev;
};
void display(struct doublylist *head);
struct doublylist* deletevalue(struct doublylist *head);
struct doublylist* insertmiddle(struct doublylist *head);
struct doublylist* insertfirst(struct doublylist *head);
struct doublylist* deletefirst(struct doublylist *head);
struct doublylist* insertfirst_copy(struct doublylist *head,int key);
main()
{
    struct doublylist *first=NULL,*trav=NULL,*temp=NULL;
    char choice;
    first=new doublylist;
    trav=first;
    while(1)
    {
        cout<<"Enter the no : ";
        cin>>trav->no;
        cout<<"Do you continue [n/N] : ";
        cin>>choice;
        if(choice == 'n' || choice =='N')
            break;
        temp=new doublylist;
        trav->next=temp;
        temp->prev    =trav;
        temp->next=NULL;
        trav=trav->next;
    }
    first->prev=trav;
    trav->next=first;
    while(1)
    {
        
        cout<<endl<<"1. Delete first";
        cout<<endl<<"2. Insert first";
        cout<<endl<<"3. Insert middle";
        cout<<endl<<"4. Delete by value";
      
        cout<<endl<<"5.    Display";
        cout<<endl<<"6. Exit";
        cout<<endl<<"Enter the choice : ";
        cin>>choice;
        switch(choice)
        {
            
            case'1':
                first=deletefirst(first);
            break;
            case'2':
                first=insertfirst(first);
            break;
            case'3':
                first=insertmiddle(first);
            break;
            case'4':
                first=deletevalue(first);
            break;
            
           
            case'5':
                display(first);
            break;
            case'6':
                return(0);

        }
    }
}

struct doublylist* deletefirst(struct doublylist *head)
{
    struct doublylist *temp;
    if(head==NULL)
    {
        cout<<"empty list";
        return(NULL);
    }
    if(head->next==NULL)
    {
        delete head;
        return(NULL);
    }
    temp=head;
    struct doublylist *trav;
    for(trav=head;trav->next!=head;trav=trav->next);

    head=head->next;
    head->prev=trav;
    trav->next=head;
    delete temp;
    return(head);
}
struct doublylist* insertfirst(struct doublylist *head)
{
    if(head==NULL)
    {
        head=new doublylist;
        cout<<"Enter the no : ";
        cin>>head->no;
        head->next=head;
        head->prev=head;
        return (head);
    }
    struct doublylist *temp;
    struct doublylist *trav;
    for(trav=head;trav->next!=head;trav=trav->next);
    temp=new doublylist;
    cout<<"Enter the no : ";
    cin>>temp->no;
    temp->next=head;
    temp->prev=trav;
    head->prev=temp;
    trav->next=temp;
    return(temp);
}
struct doublylist* insertmiddle(struct doublylist *head)
{
    struct doublylist *temp;
    cout<<"Enter the position : ";
    int pos;
    cin>>pos;
    if(pos==1)
    {
        head=insertfirst(head);
        return(head);
    }
    int counter=1;
    struct doublylist*trav;
    for(trav=head;counter!=pos-1&&trav->next!=head;trav=trav->next,counter++);
    if(trav->next==head && counter!=pos)
    {
        cout<<"invalid postion";
        return(head);
    }
    if(trav->next==head && counter==pos)
    {
        temp=new doublylist;
        trav->next=temp;
        temp->next=head;
        temp->prev=trav;
        cout<<"Enter the no : ";
        cin>>temp->no;
        return(head);
    }
    temp=new doublylist;
    cout<<"Enter the no : ";
    cin>>temp->no;
    temp->next=trav->next;
    temp->prev=trav;
    temp->next->prev=temp;
    trav->next=temp;
    return(head);
}
struct doublylist* deletevalue(struct doublylist*head)
{
    cout<<"enter the value to be deleted : ";
    int key;
    cin>>key;
    if(head==NULL)
    {
        return(NULL);
    }
    if(head->no==key)
    {
        head=deletefirst(head);
        return(head);
    }
    struct doublylist *trav;
    for(trav=head;trav->next->no!=key&&trav->next!=head;trav=trav->next);
    if(trav->next==head)
    {
        cout<<"search key not found:";
        return(head);
    }
    struct doublylist *temp;
    temp=trav->next;
    temp->next->prev=trav;
    trav->next=temp->next;
    delete temp;
    return(head);
}
void display(struct doublylist*head)
{
    if(head==NULL)
    {
        cout<<"empty list";
        return;
    }
    struct doublylist *trav;
    trav=head;
    while(1)
    {
        cout<<endl<<"The element is : "<<trav->no;
        if(trav->next==NULL)
            break;
        trav=trav->next;
    }
}

struct doublylist* append_copy(struct doublylist *head,int key)
{
    if(head==NULL)
    {
        head=new doublylist;
        head->no=key;
        head->next=head;
        head->prev=head;
        return (head);
    }
    struct doublylist *trav=NULL,*temp=NULL;
    for(trav=head;trav->next!=head;trav=trav->next);
    temp=new doublylist;
    temp->next=head;
    trav->next=temp;
    temp->prev=trav;
    head->prev=temp;
    temp->no=key;
    return(head);
}
