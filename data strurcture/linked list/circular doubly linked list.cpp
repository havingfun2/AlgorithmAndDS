# include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	node *prev;
	public:
		void ins_beg(int x);
		void ins_end(int x);
		void ins_pos(int x, int pos);
		void del_beg();
		void del_end();
		void del_pos(int pos);
		void traverse();
};
node *head=NULL,*tail=NULL;
void node :: ins_beg(int x)
{
	node *p=new node;
	p->data=x;
	if(head==NULL)
	{
		head=tail=p;
		p->next=p;
		p->prev=p;
	}
	else
	{
		p->next=head;
		p->prev=tail;
		head=p;
		tail->next=head;
	}
}
void node :: ins_end(int x)
{
	node *p=new node;
	p->data=x;
	if(tail==NULL)
	{
		head=tail=p;
		p->next=p;
		p->prev=p;
	}
	else
	{
		tail->next=p;
		p->prev=tail;
		tail=p;
		head->prev=tail;
		tail->next=head;
	}
}
void node :: del_beg()
{
	if(head==NULL)
	cout<<"Circular Linked List Is Empty\n";
	else
	{
		node *temp=head;
		cout<<"\nDeleted Element IS = "<<temp->data;
		if(head==tail)
		{
			head=tail=NULL;
			delete temp;
		}
		else
		{
			head=temp->next;
			head->prev=tail;
			tail->next=head;
			delete temp;
		}
	}
}
void node :: del_end()
{
	if(tail==NULL)
	cout<<"Circular Linked List Is Empty\n";
	else
	{
		node *temp=tail;
		cout<<"\nDeleted Element IS = "<<temp->data;
		if(head==tail)
		{
			head=tail=NULL;
			delete temp;
		}
		else
		{
			tail=tail->prev;
			tail->next=head;
			head->prev=tail;
			delete temp;
		}
	}
}
void node :: traverse()
{
	if(head==NULL)
	cout<<"Circular Linked List Is Empty\n";
	else
	{
		node *temp=head;
		while(temp->next!=head)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<tail->data<<endl;
	}
}
void node :: ins_pos(int x,int pos)
{
	node *temp=head;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"\n Element Can't Be Inserted";
			return ;
		}
		temp=temp->next;
	}
	node *p=new node;
	p->data=x;
	p->next=temp->next;
	temp->next->prev=p;
	p->prev=temp;
	temp->next=p;
}
void node :: del_pos(int pos)
{
		node *temp=head;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"\n Element Can't Be Inserted";
			return ;
		}
		temp=temp->next;
	}
	node *p=temp->next;
	cout<<"\n Deleted Element Is = "<<p->data;
	temp->next=p->next;
	p->next->prev=temp;
	delete p;
}
int main()
{
	node n;
	int x,y,p;
	do
	{
		cout<<"\n1. INSERT AT BEGINNING\n";
		cout<<"\n2. INSERT AT END\n";
		cout<<"\n3. INSERT AT POSITION\n";
		cout<<"\n4. DELETE AT BEGINNING\n";
		cout<<"\n5. DELETE AT END\n";
		cout<<"\n6. DELETE AT POSITION\n";
		cout<<"\n7. TRAVERSE\n";
		cout<<"\n8. EXIT\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cin>>y;
				n.ins_beg(y);
				break;
			case 2:
				cin>>y;
				n.ins_end(y);
				break;
			case 3:
				cin>>y>>p;
				n.ins_pos(y,p);
				break;
			case 4:
				n.del_beg();
				break;
			case 5:
				n.del_end();
				break;
			case 6:
				cin>>p;
				n.del_pos(p);
				break;
			case 7:
				n.traverse();
				break;
			case 8:
				break;
			default: 
				cout<<"\n Enter Correct Choice\n";
				break;
		}
	}while(x!=8);
	return 0;
}
