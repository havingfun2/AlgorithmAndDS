# include<iostream>
using namespace std;
class dnode
{
	int data;
	dnode *next;
	dnode *prev;
	public:
		void ins_beg(int x);
		void ins_end(int x);
		void ins_pos(int x, int pos);
		void del_beg();
		void del_end();
		void del_pos(int pos);
		void traverse();
		void count();
};
dnode *head=NULL , *tail=NULL;
void dnode :: count()
{
	int count=0;
	dnode *temp=head;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	if(count)
	cout<<"NUMBER OF ELEMENTS IN DOUBLY LINKED LIST IS : "<<count<<endl;
	else
	cout<<"DOUBLY LINKED LIST IS EMPTY\n";
}
void dnode :: ins_beg(int x)
{
	dnode *p=new dnode;
	p->data=x;
	p->prev=NULL;
	if(head==NULL)
	{
		head=tail=p;
		p->next=NULL;
	}
	else
	{
		p->next=head;
		head->prev=p;
		head=p;
	}
}
void dnode :: ins_end(int x)
{
	dnode *p=new dnode;
	p->data=x;
	p->next=NULL;
	if(tail==NULL)
	{
		tail=head=p;
		p->prev=NULL;
	}
	else
	{
		p->prev=tail;
		tail->next=p;
		tail=p;
	}
}
void dnode :: del_beg()
{
	if(head==NULL)
	cout<<"Doubly Linked List Empty\n";
	else
	{
		cout<<"Deleted Item Is = "<<head->data<<endl;
		dnode *temp=head;
		if(head==tail)
		{
			head=tail=NULL;
			delete temp;
		}
		else
		{
			head=head->next;
			head->prev=NULL;
			delete temp;
		}
	}
}
void dnode :: del_end()
{
	if(tail==NULL)
	cout<<"Doubly Linked List Empty\n";
	else
	{
		cout<<"Deleted Item Is = "<<tail->data<<endl;
		dnode *temp=tail;
		if(head==tail)
		{
			head=tail=NULL;
			delete temp;
		}
		else
		{
			tail=tail->prev;
			tail->next=NULL;
			delete temp;
		}
	}
}
void dnode :: traverse()
{
	if(head==NULL)
	cout<<"Doubly Linked List Empty\n";
	else
	{
		dnode *temp=head;
		cout<<"ELEMENTS OF DOUBLY LINKED LIST ARE :\n";
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
void dnode :: ins_pos(int x, int pos)
{
	dnode *temp=head;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"Can't Be Inserted"<<endl;
			return ;
		}
		temp=temp->next;
	}
	dnode *p=new dnode;
	p->data=x;
	p->next=temp->next;
	temp->next->prev=p;
	temp->next=p;
	p->prev=temp;
}
void dnode :: del_pos(int pos)
{
	dnode *temp=head;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"Can't Be Inserted"<<endl;
			return ;
		}
		temp=temp->next;
	}
	dnode *p=temp->next;
	cout<<"\n Deleted Element Is = "<<p->data<<endl;
	temp->next=p->next;
	p->next->prev=temp;
	delete p;
}
int main()
{
	dnode n;
	int x,y,p,i;
	do
	{
		cout<<"\n\n\n         ------------------------DOUBLY LINKED LIST---------------------\n\n";
		cout<<"\n\t\t\t1. CREATE DOUBLY LINKED LIST\n";
		cout<<"\n\t\t\t2. INSERT AT BEGINNING\n";
		cout<<"\n\t\t\t3. INSERT AT END\n";
		cout<<"\n\t\t\t4. INSERT AT POSITION\n";
		cout<<"\n\t\t\t5. DELETE AT BEGINNING\n";
		cout<<"\n\t\t\t6. DELETE AT END\n";
		cout<<"\n\t\t\t7. DELETE AT POSITION\n";
		cout<<"\n\t\t\t8. TRAVERSE\n";
		cout<<"\n\t\t\t9. NUMBER OF ELEMENTS IN DOUBLY LINKED LIST\n";
		cout<<"\n\t\t\t10. EXIT\n";
		cout<<"\nENTER YOUR CHOICE : ";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"ENTER THE NUMBER OF ELEMENT TO BE INSERTED : ";
				cin>>y;
				cout<<endl;
				for(i=0;i<y;i++)
				{
					cout<<"ENTER THE ELEMENT TO BE INSERTED : ";
					cin>>p;
					n.ins_end(p);
				}
				break;
			case 2:
				cout<<"ENTER THE ELEMENT TO BE INSERTED : ";
				cin>>y;
				n.ins_beg(y);
				break;
			case 3:
				cout<<"ENTER THE ELEMENT TO BE INSERTED : ";
				cin>>y;
				n.ins_end(y);
				break;
			case 4:
				cout<<"ENTER THE ELEMENT TO BE INSERTED AND THE POSITION WHERE TO BE INSERTED : ";
				cin>>y>>p;
				n.ins_pos(y,p);
				break;
			case 5:
				n.del_beg();
				break;
			case 6:
				n.del_end();
				break;
			case 7:
				cin>>p;
				n.del_pos(p);
				break;
			case 8:
				n.traverse();
				break;
			case 9:
				n.count();
				break;
			case 10:
				break;
			default: 
				cout<<"\n Enter Correct Choice\n";
				break;
		}
	}while(x!=10);
	return 0;
}
