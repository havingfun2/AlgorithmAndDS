# include<iostream>
using namespace std;
class node
{
	int data;
	node *next;
	public:
		void ins_beg(int x);
		void ins_end(int x);
		void ins_pos(int x, int pos);
		void del_beg();
		void del_end();
		void del_pos(int pos);
		void traverse();
};
node *root = NULL;
void node :: ins_beg(int x)
{
	node *p=new node;
	p->data=x;
	p->next=root;
	root=p;
}
void node :: ins_end(int x)
{
	node *p=new node;
	p->data=x;
	p->next=NULL;
	if(root==NULL)
		root=p;
	else
	{
		node *temp=root;
		while(temp->next!=NULL)
		temp=temp->next;
		temp->next=p;
	}
}
void node :: del_beg()
{
	if(root==NULL)
	cout<<"\n Linked List Empty";
	else
	{
		cout<<"Deleted Item Is = "<<root->data;
		node *temp=root;
		if(temp->next==NULL)
		{
			root=NULL;
			delete temp;
		}
		else
		{
			root=temp->next;
			delete temp;
		}
	}
}
void node :: del_end()
{
	if(root==NULL)
	cout<<"\n Linked List Empty";
	else
	{
		node *temp=root,*p=root->next;
		if(temp->next==NULL)
		{
			cout<<"Deleted Item Is = "<<root->data;
			root=NULL;
			delete temp;
		}
		else
		{
			while(p->next!=NULL)
			{
				p=p->next;
				temp=temp->next;
			}
			cout<<"Deleted Item Is = "<<p->data;
			temp->next=NULL;
			delete p;
		}
	}
}
void node :: traverse()
{
	if(root==NULL)
	cout<<"\n Linked List Empty";
	else
	{
		node *temp=root;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
void node :: ins_pos(int x,int pos)
{
	node *temp=root;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"\n Element Can't Be Inserted\n";
			return ;
		}
		temp=temp->next;
	}
	node *p=new node;
	p->data=x;
	p->next=temp->next;
	temp->next=p;	
}
void node :: del_pos(int pos)
{
	node *temp=root;
	for(int i=1;i<pos;++i)
	{
		if(temp==NULL)
		{
			cout<<"\n Element Can't Be Inserted\n";
			return ;
		}
		temp=temp->next;
	}
	node *p=temp->next;
	cout<<"Deleted Item Is = "<<p->data;
	temp->next=p->next;
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
