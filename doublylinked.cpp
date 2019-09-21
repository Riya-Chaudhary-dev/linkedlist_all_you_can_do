#include<iostream>
#include<stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev, *next;
public:
    Node(){
        prev=next=NULL;
    }
    Node(int n)
    {
        data=n;
        next=NULL;
    }
};
class List:Node
{
    public:
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
   void delete_mid();
   void delete_end();
   void display();
   void length();
   void rev();
   void copy_list(List &l1);
   void conc();
   void search_list();
   void merge_list(List &l1,List &l2);
   void sort_list();
   void in(List &l1,List &l2);
   void uni(List &l1,List &l2);
};
void List::create(int n)
{
    Node *newnode = new Node(n);
    Node *temp=listptr;
    //newnode->data=n;
    newnode->next=NULL;
    if(listptr==NULL)
        {listptr=newnode;
        temp=newnode;
        newnode->prev=NULL;}
    else
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;

    }
}
void List::display()
{
    if(listptr==NULL)
        cout<<"No list present";
    else{
            Node *temp= listptr;
   while(temp->next!=NULL)
   {
       cout<<temp->data<<"->";
       temp=temp->next;
   }
   cout<<temp->data<<"\n";}
}
void List::insert_beg()
{

    if(listptr==NULL)
        cout<<"No list";
    else{
            int t;
    cout<<"Enter data: ";
    cin>>t;
    Node *newnode= new Node(t);
    newnode->prev=NULL;
    newnode->next=listptr;
    listptr=newnode;}
}
void List::insert_end()
{
    if(listptr==NULL)
    cout<<"No list";
    else{
            int t;
            Node *temp=listptr;
    cout<<"Enter data: ";
    cin>>t;
    Node *newnode= new Node(t);
    while(temp->next!=NULL)
        temp=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next=NULL;}

}
void List::insert_mid()
{
    if(listptr==NULL)
        cout<<"No list";
    else{
    int num,pos,i;
       cout<<"Enter the value to insert \n";
       cin>>num;
       cout<<"Enter position";
       cin>>pos;
       Node *newnode=new Node(num);
       Node *temp=listptr;
       for(i=1;i<pos-1;i++)
       {
           temp=temp->next;
       }
       newnode->prev=temp;
       newnode->next=temp->next;
       temp->next=newnode;
    }
}
void List::delete_beg()
{
    if(listptr==NULL)
        cout<<"No list";
    else
        {
            Node *temp=listptr;
            Node *temp1=listptr;
            temp=temp->next;
            temp->prev=NULL;
            listptr=temp;
            free(temp1);
        }

}
void List::delete_end()
{
    if(listptr==NULL)
        cout<<"No list";
    else
    {
        Node *temp=listptr;
        Node *temp1=listptr;
        while (temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        temp1=temp->next;
        temp->next=NULL;
        free(temp1);
    }
}
void List::delete_mid()
{
    if(listptr==NULL)
        cout<<"No list";
    else
    {
        int pos,i;
        cout<<"Enter position to delete";
        cin>>pos;
        Node *temp=listptr;
        Node *temp1=listptr;
        for(i=1;i<pos-1;i++)
            temp=temp->next;
        temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);

}}
void List::length()
{
    int l=1;
    if(listptr==NULL)
        cout<<"Length is 0";
    else
    {
        temp=listptr;
        while(temp->next!=NULL)
            {temp=temp->next;
            l++;}
            cout<<"Length is "<<l;
    }
}
void List::rev()
{
     if(listptr->next==NULL)
	cout<<"list not created";
	else{
    Node * tempo;
    Node * forw;
    Node * curr;
    forw=listptr;
    curr=NULL;
    do
    {
        curr=forw;
        forw=forw->next;
        tempo=curr->next;
        curr->next=curr->prev;
        curr->prev=tempo;

    }while(forw!=NULL);
    listptr=curr;
	}
    display();
}
void List::search_list()
{
    int num,i=1,flag=0;
    cout<<"Enter number to search ";
    cin>>num;

   for(temp=listptr;temp->next!=NULL;temp=temp->next)
    {
       if(temp->data==num)
        {
            cout<<num<<" Present at "<<i<<"\n";
            flag=1;
        }
        i++;
    }
    if (flag==0)
        cout<<"not present";
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
    while(l1.temp!=NULL);
    display();
}
void List::merge_list(List &l,List &l2)
{

    l.temp=l.listptr;
    l2.temp=l2.listptr;
    for(l.temp=l.listptr;l.temp!=NULL;l.temp=l.temp->next)
    {
        int n;
        cout<<"Enter the value to merge :";
        cin>>n;
        l2.create(n);
        l2.create(l.temp->data);

    }
    l2.display();
}
void List::conc()
{
    List l2;
    int n,num;
    cout<<"Enter number of elements to concatnate";
    cin>>n;
    int i;
    for(i=0;i<n;i++)
    {
        cout<<"Enter elements";
        cin>>num;
        l2.create(num);
    }
    Node *temp=listptr;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=l2.listptr;
    cout<<"Concatnated list is";

    display();
}
void List:: sort_list()
{
    Node *i,*j,*p;
    int k,c=1;
    Node *temp=listptr;
    while(temp->next!=NULL)
        {temp=temp->next;
        c++;}
        for(i=listptr;i->next->next!=NULL;i=i->next)
        {
            p=listptr;
            j=p->next;
            c--;
            for(k=0;k<c;k++)
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
        display();

}
void List::in(List &l1, List &l2)
{
    int flag;
    List l3;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=l2.listptr;temp2!=NULL;temp2=temp2->next)
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
void List:: uni(List &l1,List &l2)
{
    int flag=0;
    List l3;
    Node *temp1, *temp2, *temp3;
    temp1=l1.listptr;
    temp2=l2.listptr;
    for(temp1=l1.listptr;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=l2.listptr;temp2!=NULL;temp2=temp2->next)
        {
            if(temp1->data==temp2->data)
            {
                flag=1;
                break;
            }
        }

        if(flag==0)
        {
            l3.create(temp1->data);
        }

    }
    temp3=l2.listptr;
    while(temp3!=NULL)
    {
     l3.create(temp3->data);
       temp3=temp3->next;
    }
    l3.display();
}

main()
{
    int ch;
    List l;
    List l1;
    while(1)
    {
        cout<<"\nEnter your choice:\n 1.create\n 2.display\n3.insert in beginning\n4.insert at end\n5.insert mid\n6.delete from start\n";
        cout<<"7.delete from end\n8.delete from mid\n9.length\n10.reverse\n11.search\n12.copy\n13.merge\n14.sort\n15.concatnate\n16.intersection\n17.union\n";
    cin>>ch;
    switch(ch)
    {
        case 1: int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
            l.create(num);
            break;
        case 2: l.display();
            break;
        case 3:
            l.insert_beg();
            break;
        case 4:
            l.insert_end();
            break;
        case 5:
            l.insert_mid();
            break;
        case 6:
            l.delete_beg();
            break;
        case 7:
            l.delete_end();
            break;
        case 8:
            l.delete_mid();
            break;
        case 9:
            l.length();
            break;
        case 10:
            l.rev();
            break;
        case 11:
            l.search_list();
            break;
        case 12:
            l1.copy_list(l);
            break;
        case 13:
            l.merge_list(l,l1);
            break;
        case 14:
            l.sort_list();
            break;
        case 15:
            l.conc();
            break;
        case 16:
            int n;
            cout<<"How many elements to take intersection of?\n ";
            cin>>n;
            for(int i=0;i<n;i++)
            {
                        int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
                l1.create(num);
            }
            l.in(l,l1);
            break;
        case 17:
            int p;
            cout<<"How many elements to take union of?\n ";
            cin>>p;
            for(int i=0;i<p;i++)
            {
                        int num;
       cout<<"Enter the value to insert \n";
       cin>>num;
                l1.create(num);
            }
            l.uni(l,l1);
            break;

    }
    }
}
