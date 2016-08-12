# include<iostream>
using namespace std;
class clink
{
	int data;
	clink *next;
	public:
		void ins_beg(int x);
		void ins_end(int x);
		void ins_pos(int x, int pos);
		void del_beg();
		void del_end();
		void del_pos(int pos);
		void traverse();
};
clink *first=NULL,*last=NULL;
void clink :: ins_beg(int x)
{
	clink *p=new clink;
	p->data=x;
	if(first==NULL)
	{
		p->next=p;
		first=last=p;
	}
	else
	{
		p->next=first;
		first=p;
		last->next=first;
	}
}
void clink :: del_beg()
{
	if(first==NULL)
	cout<<"Circular Linked List Empty";
	else
	{
		clink *temp=first;
		cout<<"Deleted Element Is = "<<temp->data;
		if(first==last)
		{
			first=last=NULL;
			delete temp;
		}
		else
		{
			first=first->next;
			last->next=first;
			delete temp;
		}
	}
}
void clink :: ins_end(int x)
{
	clink *p=new clink;
	p->data=x;
	if(last==NULL)
	{
		first=last=p;
		p->next=p;
	}
	else
	{
		last->next=p;
		last=p;
		last->next=first;
	}
}
void clink :: del_end()
{
	if(last==NULL)
	cout<<"Circular Linked List Empty";
	else
	{
		clink *temp=last;
		cout<<"Deleted Element is= "<<temp->data;
		if(first==last)
		{
			first=last=NULL;
			delete temp;
		}
		else
		{
			clink *p=first;
			while(p->next!=last)
			p=p->next;
			last=p;
			last->next=first;
			delete temp;
			
		}
	}
}
void clink :: ins_pos(int x,int pos)
{
	clink *temp=first;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"Item Can't Be Inserted\n";
			return ;
		}
		temp=temp->next;
	}
	clink *p=new clink;
	p->data=x;
	p->next=temp->next;
	temp->next=p;
}
void clink :: del_pos(int pos)
{
	clink *temp=first;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"Item Can't Be Inserted\n";
			return ;
		}
		temp=temp->next;
	}
	clink *p=temp->next;
	cout<<"Deleted Element Is = "<<p->data;
	temp->next=p->next;
	delete p;
}
void clink :: traverse()
{
	if(first==NULL)
	cout<<"Circular Linked List Empty";
	else
	{
		clink *temp=first;
		while(temp->next!=first)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<last->data<<endl;
	}
}
int main()
{
	clink n;
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
