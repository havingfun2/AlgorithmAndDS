# include<iostream>
using namespace std;
class stack
{
	int data;
	stack *next;
	public:
		void ins_end(int x);
		void del_end();
		void traverse();
};
stack *root=NULL,*top=NULL;
void stack :: ins_end(int x)
{
	stack *p =new stack;
	p->data=x;
	p->next=NULL;
	if(top==NULL)
	root=top=p;
	else
	{
		top->next=p;
		top=p;
	}
}
void stack :: del_end()
{
	if(top==NULL)
	cout<<"\nStack Empty";
	else
	{
		stack *temp=root,*p=top;
		cout<<"deleted element is= "<<p->data;
		if(root==top)
		{
			root=top=NULL;
			delete temp;
		}
		else
		{
			while(temp->next!=top)
				temp=temp->next;
			temp->next=NULL;
			top=temp;
			delete p;
		}
	}
}
void stack :: traverse()
{
	if(root==NULL)
	cout<<"\n Stack Empty";
	else
	{
		stack *temp=root;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
int main()
{
	stack n;
	int x,y,p;
	do
	{
		cout<<"\n1. INSERT AT END\n";
		cout<<"\n2. DELETE AT END\n";
		cout<<"\n3. TRAVERSE\n";
		cout<<"\n4. EXIT\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cin>>y;
				n.ins_end(y);
				break;
			case 2:
				n.del_end();
				break;
			case 3:
				n.traverse();
				break;
			case 4:
				break;
			default: 
				cout<<"\n Enter Correct Choice\n";
				break;
		}
	}while(x!=4);
	return 0;
}
