# include<iostream>
using namespace std;
class queue
{
	int data;
	queue *next;
	public:
		void ins_end(int x);
		void del_beg();
		void traverse();
};
queue *front=NULL,*rear=NULL;
void queue :: ins_end(int x)
{
	queue *p =new queue;
	p->data=x;
	p->next=NULL;
	if(rear==NULL)
	front=rear=p;
	else
	{
		rear->next=p;
		rear=p;
	}
}
void queue :: del_beg()
{
	if(rear==NULL)
	cout<<"\nqueue Empty";
	else
	{
		queue *temp=front;
		cout<<"deleted element is= "<<temp->data;
		if(front==rear)
		{
			front=rear=NULL;
			delete temp;
		}
		else
		{
			front=temp->next;
			delete temp;
		}
	}
}
void queue :: traverse()
{
	if(front==NULL)
	cout<<"\n queue Empty";
	else
	{
		queue *temp=front;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
}
int main()
{
	queue n;
	int x,y,p;
	do
	{
		cout<<"\n1. INSERT AT END\n";
		cout<<"\n2. DELETE AT BEGINNING\n";
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
				n.del_beg();
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
