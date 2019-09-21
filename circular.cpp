#include<iostream>
#include<stdlib.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
         Node(){
        next=NULL;
    }

        Node(int n)
        {
            data=n;
            next=NULL;
        }

};
class List : Node
{
    Node *listptr;
    Node *temp;
public:
    List()
    {
        listptr=NULL;
        temp=NULL;
    }
   void create(int);
   void insert_beg();
   void insert_end();
   void insert_mid();
   void delete_beg();
   void delete_mid(int);
   void delete_end();
   void display();
   int length();
   void rev();
   void conc();
   void uni(List &l1,List &l2);
   void in(List &l1,List &l2);
   void copy_list(List &l1);
   void search_list(int);
   void split(List &l1, int);
};
void List:: create(int num){
    Node *newnode= new Node(num);

    if(listptr==NULL){
        listptr=newnode;

        newnode->next=listptr;
        temp=newnode;
    }
    else
    {
        while(temp->next!=listptr)
        {temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=listptr;

    }

}
void List::display()
{
    Node *temp=listptr;
    if (listptr==NULL)
        cout<<"List is empty";
    else
    {
    while(temp->next!=listptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
    }
}
void List::insert_beg()
{
    if (listptr==NULL)
        cout<<"List is empty";

    else{int n;
    cout<<"Enter data: ";
    cin>>n;
    Node *newnode= new Node(n);
    while(temp->next!=listptr)
    {
        temp=temp->next;
    }
    newnode->next=listptr;
    listptr=newnode;
    temp->next=newnode;

    }
}
void List::insert_end()
{
    if (listptr==NULL)
        cout<<"List is empty";

    else{int n;
    cout<<"Enter data: ";
    cin>>n;
    Node *newnode= new Node(n);
    while(temp->next!=listptr)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    }
}
void List:: insert_mid()
{
    int num,pos,i;
    Node *temp=listptr;
    cout<<"Enter number to add: ";
    cin>>num;
    Node *newnode= new Node(num);
    cout<<"Enter position to enter: ";
    cin>>pos;
    for(i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    display();
}
void List::delete_beg()
{
    Node *temp=listptr;
    Node *temp1=listptr;
    Node *temp3=listptr;
    if(listptr==NULL)
        cout<<"No list present";
    else
        {
        temp=temp->next;
        while(temp3->next!=listptr)
            temp3=temp3->next;
        temp3->next=temp;
        listptr=temp;
        free(temp1);
        }

}
void List ::delete_end()
{
    Node *temp=listptr;
    Node *temp1=listptr;

    if(listptr==NULL)
        cout<<"No list present";
    else
    {
        while(temp->next->next!=listptr)
            temp=temp->next;
        temp1=temp->next;
        temp->next=listptr;
        free(temp1);
    }
}
void List::delete_mid(int p)
{
    Node *temp=listptr;
    Node *temp1=listptr;

    if(listptr==NULL)
        cout<<"No list present";
    else
    {
        int i;
        for(i=1;i<p-1;i++)
            temp=temp->next;
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        display();
    }
}
int List::length()
{
    int cnt=1;
    Node *temp=listptr;
    while(temp->next!=listptr)
        {temp=temp->next;
        cnt++;}
        //cout<<"Length is "<<cnt;
    return cnt;
}
void List::rev()
{
    Node *forw, *curr, *bk;

    forw=listptr;
    curr=NULL;
    do
    {
        bk=curr;
        curr=forw;
        forw=forw->next;
        curr->next=bk;
    }while(forw!=listptr);
    listptr=curr;
    temp=listptr;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=listptr;

    display();
}
void List::conc()
{
    List l2;
    int num;
    cout<<"Enter number of element in list 2:";
    cin>>num;
    for(int i=0;i<num;i++)
    {
        int n;
        cout<<"Enter data: ";
        cin>>n;
        l2.create(n);
    }
    Node *temp2=l2.listptr;
    while(temp2->next!=l2.listptr)
        temp2=temp2->next;

    Node *temp=listptr;

    while(temp->next!=listptr)
        temp=temp->next;

    temp->next=l2.listptr;
    cout<<"Concatnated list is\n";
    temp2->next=listptr;
    temp=listptr;
          display();
    int c=1;
    while(temp->next!=listptr)
    {
        temp=temp->next;
        c++;
    }
    Node *i,*p,*j;
    for(i=listptr;i->next->next!=listptr;i=i->next)
    {
        p=listptr;
        j=p->next;
        c--;

            for(int k=0;k<c;k++)
            {
                if(j->data<p->data)
                {
                    int tem;
                    tem=j->data;
                    j->data=p->data;
                    p->data=tem;
                }
                p=j;
                j=j->next;
            }
        }temp=listptr;
        cout<<"\nSorted list:\n";
        display();
    }
void List::in(List &l1, List &l2)
{
    int flag;
    List l3;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1->next!=l1.listptr;temp1=temp1->next)
    {
        for(temp2=l2.listptr;temp2->next!=l2.listptr;temp2=temp2->next)
        {
            if(temp1->data==temp2->data)
            {
                 l3.create(temp1->data);
                 break;
            }
        }
    }

    l3.display();
}
void List::uni(List &l1, List &l2)
{
    int flag;
    List l3;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1->next!=l1.listptr;temp1=temp1->next)
    {flag=0;
        for(temp2=l2.listptr;temp2->next!=l2.listptr;temp2=temp2->next)
        {
            if(temp1->data==temp2->data)
            {
            flag=1;

            break;
            }
        }
        if(flag==0)
            l3.create(temp1->data);
    }

    temp3=l2.listptr;
    do
    {
     l3.create(temp3->data);
       temp3=temp3->next;
       cout<<"r";
    }while(temp3!=l2.listptr);

    temp3=l3.listptr;
    l3.display();
}
void List::copy_list(List &l1)
{
    int data;
    l1.temp=l1.listptr;
   do
    {
        data=l1.temp->data;
        create(data);
        l1.temp=l1.temp->next;
    }
    while(l1.temp!=l1.listptr);
    display();
    //return listptr;
}
void List::search_list(int s)
{
    Node *temp ;
    int i=1;
    int flag=0;
    for(temp=listptr;temp->next!=listptr;temp=temp->next)
    {
       if(temp->data==s)
        {
            cout<<s<<" Present at \n"<<i<<"\n";
            flag=1;
        }
        i++;
    }
    if (flag==0)
        cout<<"not present";
    }
void List::split(List &l1, int p)
{
    int len;
    len=l1.length();

    if(len%p!=0 || len<p)
    {
        cout<<"Split cannot be made";
    }
    else
    {
        Node *temp=l1.listptr;
        int m,f=1,i;
        m=len/p;
        do{
        cout<<"\nList "<<f<< " is ";
        for(i=0;i<m;i++)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        f++;
        }while(temp!=l1.listptr);
    }
}
main()
{
    int ch;
    List l;
    List l2;
    while(1){
    cout<<"\nEnter your choice:\n 1.create\n 2.insert from beginning\n 3.insert from end\n 4.insert from intermediate position\n 5.display\n 6.delete from beginning\n";
    cout<<" 7.delete from intermediate\n 8.delete from end\n 9.length of list\n 10.Reverse the list\n 11.Concatenate two lists\n 12.intersection\n 13.union\n14.search\n15.copy\n16.splitting list";
    cin>>ch;
    switch(ch)
        {
    case 1:int num;
            cout<<"Enter data: ";
            cin>>num;
            l.create(num);
            break;
    case 2:
            l.insert_beg();
            break;
    case 3:
            l.insert_end();
            cout<<"a";
            break;
    case 4:
            l.insert_mid();
            break;
    case 5:
            l.display();
            break;
    case 6:
            l.delete_beg();
            break;
    case 7:
        int pos;
          cout<<"What is the position of the node you want to delete?\n";
          cin>>pos;
          l.delete_mid(pos);
            break;
    case 8:
            l.delete_end();
            break;
    case 9:
            l.length();
            break;
    case 10:
            l.rev();
            break;
    case 11:
           l.conc();
            break;
    case 12:
           int n;
            cout<<"How many elements to take intersection of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                        int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
                l2.create(num);
            }
            l.in(l,l2);
            break;
    case 13:
            cout<<"How many elements to take union of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {   int num;
                cout<<"Enter the value to insert \n";
                cin>>num;
                l2.create(num);
            }
            l.uni(l,l2);
            break;
    case 14:
            int number;
            cout<<"Enter number to be searched \n";
            cin>>number;
            l.search_list(number);
            break;
    case 15:
        l2.copy_list(l);
        break;
    case 16:
        int o;
        cout<<"Enter number of splits you want to make";
        cin>>o;
        l.split(l,o);
    }}
    return 0;
}

