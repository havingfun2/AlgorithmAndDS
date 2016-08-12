# include<iostream>
using namespace std;
# define mx 1000007
int front=-1,rear=-1;
int a[mx];
void qinsert(int x);
void qdelete();
void traverse();
int main()
{
	int x,y;
	do
	{
		cout<<"\n1. qinsert\n";
		cout<<"\n2. qdelete\n";
		cout<<"\n3. TRAVERSE\n";
		cout<<"\n4. EXIT\n";
		cin>>y;
		switch(y)
		{
			case 1:
				cin>>x;
				qinsert(x);
				break;
			case 2:
				qdelete();
				break;
			case 3:
				traverse();
				break;
			case 4:
				break;
			default:
				cout<<"\n Enter Correct Choice";
				break;	
		}
	}while(y!=4);
	return 0;
}
void qinsert(int x)
{
	if(rear==mx-1)
	cout<<"\n Queue Full";
	else
	{
		rear++;
		a[rear]=x;
		if(front==-1)
		front=0;
	}
}
void qdelete()
{
	if(front==-1)
	cout<<"\n Queue Empty";
	else
	{
		cout<<"\n Deleted Element is = "<<a[front];
		if(front==rear)
		front=rear=-1;
		else
		front++;
	}
}
void traverse()
{
	if(front==-1)
	cout<<"\n Queue Empty";
	else
	{
		for(int i=front;i<=rear;++i)
		cout<<a[i]<<endl;
	}
}
