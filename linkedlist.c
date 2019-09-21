#include<iostream>
#include<stdlib.h>

using namespace std;
class List;
class Node
{
    int data ;
    Node *next;
    Node()
    {
        next=NULL;
        data=0;
    }
    Node(int num)
    {
        data=num;
        next=NULL;
    }
    friend class List ;
};
class List
{
    Node * temp;
    Node *listptr;
    public :
    List()
    {
        listptr=temp=NULL;
    }
    int ask_num();
    int len();
    int display();
    Node * traverse(int pos);
    Node * insert_list(int pos,int num);
    Node * delete_list(int pos);
    Node * conc(List &l1,List &l2);
    Node * search_list(int num);
    Node * sort_list();
    Node * reverse_list();
    Node * copy_list(List l);
};
int List :: len()
{
    temp=listptr;
    int length=1;
    while(temp->next!=listptr)
    {
        length++;
        temp=temp->next;
    }
    return length;
}
Node * List:: traverse(int pos)
{
    temp=listptr;
if (pos==0)
{
    temp=listptr;
    while(temp->next!=listptr)
    {
        temp=temp->next;
    }
}
else
    {
      for(int i=1;i<pos;i++)  //transverse till given position
      temp=temp->next;
    }
    return temp;
}
int List :: ask_num()
{
    int num;

    cin>>num;
    return num;
}
Node * List::insert_list(int pos,int num)
{

    Node *newnode=new Node(num);
    if (pos==0)    // shortcut for create
    {
         if(this->listptr==NULL)
        {
           listptr=newnode;
           newnode->next=listptr;
        }
         else
        {
           temp=traverse(0);     //create in end or insert at end
           temp->next=newnode;
           temp=newnode;
           newnode->next=listptr;
        }
   }
   else if(pos==-1)  //inserting at beginning
   {
       temp= traverse(0);
       temp->next=newnode;
       newnode->next=listptr;
       listptr=newnode;

   }
   else     //insert a given position
   {
       temp=listptr;
       temp=traverse(pos-1);
       newnode->next=temp->next;
       temp->next=newnode;
   }
   return listptr;
}
int List :: display()
{
    temp=listptr;
    while(temp->next!=listptr)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data;
}
Node * List:: delete_list(int pos)
{
    Node *temp1=listptr;
    Node *temp2=listptr;
    Node *temp3=listptr;
    if(pos==0)  // delete from beginning
    {

        temp1=temp1->next;
        temp2=traverse(0);
        temp2->next=temp1;
        listptr=temp1;
        free(temp3);
    }
    else if(pos==-1)  // delete from end
    {

        if (temp1->next==NULL)
        {
           cout<<"list is empty\n";
        }
        else
        {

            temp1=traverse(len()-1);
            temp2=traverse(0);
            temp1->next=listptr;
            free(temp2);
         }
    }
   else            // delete from intermediate
   {
       temp1=traverse(pos-1);
       temp2=traverse(pos);
       temp1->next=temp2->next;
       free(temp2);

   }
   return listptr;
}

Node * List :: conc(List &l,List &l2)
{
    l.temp=l.traverse(0);
    l2.temp=l2.traverse(0);
    l.temp->next=l2.listptr;
    l2.temp->next=l.listptr;
    free(l2.listptr);
    return l.listptr;
}
Node * List :: search_list(int num)
{
    Node * temp1;
    int i=0;

        for(temp1=listptr;temp1->next!=listptr;temp1=temp1->next)
        {
            i++;
           if(num==temp1->data)
            {
            cout<<"number found at "<<i<<"\n";
            }
        }

    return listptr;
}
Node * List :: sort_list()
{
    Node *i,*j,*p;
int c=len();
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
	}
	temp=listptr;
	if((temp->next->data)<(temp->data))
			{
				int tem;
				tem=temp->next->data;
				temp->next->data=temp->data;
				temp->data=tem;
			}
    return listptr ;
}
Node * List :: reverse_list()
{
    if(listptr->next==listptr)
	cout<<"list not created";
	else{

	Node *forw,*curr,*bk;
	forw=listptr;
	curr=NULL;
	do
	{
		bk=curr;
		curr=forw;
		forw=forw->next;
		curr->next=bk;

	}   while (forw->next!=listptr);

	listptr=curr;

    }
    return listptr;
}
Node * List :: copy_list(List l)
{
int data;
    l.temp=l.listptr;
   do
    {
        data=l.temp->data;
        insert_list(0,data);
        l.temp=l.temp->next;
    }
    while(l.temp!=l.listptr);
    return listptr;
}
int main()
{
    List l;
    List l2;
    int n,num;
    int ch;
     while(1)
    {
    cout<<"\nEnter your choice:\n 1.create\n 2.display \n 3.insert from beginning\n 4.insert from intermediate position\n 5.insert from end \n 6.delete from beginning\n";
    cout<<" 7.delete from end\n 8.delete from intermediate\n 9.concatenate list\n 10.search from list\n 11.sort list\n 12.reverse the list\n 13.copy to list 2\n 14.length of the list\n";
    cin>>ch;

    switch(ch)
    {
    case 1:
    cout<<"Enter the number \n";
         num=l.ask_num();
         l.insert_list(0,num);
            break;
    case 2:
          l.display();
            break;
    case 3:
    cout<<"Enter the number \n";
         num=l.ask_num();
        l.insert_list(-1,num);
            break;
    case 4:
        int pos;
        cout<<"enter the position \n";
        pos=l.ask_num();
        num=l.ask_num();
        l.insert_list(pos,num);
            break;
    case 5:
    cout<<"Enter the number \n";
         num=l.ask_num();
        l.insert_list(0,num);
            break;
    case 6:
        l.delete_list(0);
            break;
    case 7:
        l.delete_list(-1);
        break;
    case 8:
        cout<<"enter the position \n";
        pos=l.ask_num();
        l.delete_list(pos);
        break;
    case 9:

        cout<<"enter the number of elements to be concatenated\n";
         n = l.ask_num();
        cout<<"enter the elements\n";
        for(int i=0;i<n;i++)
        {
           cout<<"Enter the number \n";
            num=l.ask_num();
            l2.insert_list(0,num);
        }
        l.conc(l,l2);
        break;

    case 10:
        cout<<"enter the number you want to search in the list\n";
        num=l.ask_num();
        l.search_list(num);
        break;
    case 11:
        l.sort_list();
        break;
    case 12:
        l.reverse_list();
        break;
   case 13:
        l2.copy_list(l);
        cout<<"the copied list is\n ";
        l2.display();
        break;
   case 14:
        cout<<"length of the string is "<<l.len();
    }
    }

}

