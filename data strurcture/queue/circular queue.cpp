// why it is giving 0??
# include<iostream>
using namespace std;
# define mx 6
int front=-1,rear=-1;
int a[mx];
void push(int x);
void pop();
void traverse();
int main()
{
	int x,y;
	do
	{
		cout<<"\n1. Push\n";
		cout<<"\n2. POP\n";
		cout<<"\n3. TRAVERSE\n";
		cout<<"\n4. EXIT\n";
		cin>>y;
		switch(y)
		{
			case 1:
				cin>>x;
				push(x);
				break;
			case 2:
				pop();
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
void push(int x)
{
	if(front==(rear+1)%mx)
	cout<<"\n Circular Queue Full";
	else
	{
		if(front==-1)
		{
			front=rear=0;
			a[rear]=x;
		}
		else
		{
			rear=(rear+1)%mx;
			a[rear]=x;
		}
	}
}
void pop()
{
	if(front==-1)
	cout<<"\n Circular Queue Empty";
	else
	{
		cout<<"\n Deleted Element Is = "<<a[front];
		if(front==rear)
		front=rear=-1;
		else
		front=(front+1)%mx;
	}
}
void traverse()
{
	if(front==-1)
	cout<<"\n Circular Queue Empty";
	else
	{
		if(rear>front)
		{
			for(int i=front;i<=rear;++i)
			cout<<a[i]<<endl;
		}
		else
		{
			for(int i=front;i<mx;++i)
			cout<<a[i]<<endl;
			for(int i=0;i<=rear;++i)
			cout<<a[i]<<endl;
		}
	/*	for(int i=front;(i-1)!=rear;i=(i)%mx)
		{
		cout<<a[i]<<endl;++i;}*/
	}
}
