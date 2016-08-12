# include<iostream>
using namespace std;
# define mx 1000007
int top=-1;
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
	if(top==mx-1)
	cout<<"\n Stack Full";
	else
	//	top++;
		a[++top]=x;
}
void pop()
{
	if(top==-1)
	cout<<"\n Stack Empty";
	else
		cout<<"\n Deleted Element Is = "<<a[top--];
}
void traverse()
{
	if(top==-1)
	cout<<"\n Stack Empty";
	else
	{
		for(int i=top;i>=0;--i)
		cout<<a[i]<<endl;
	}
}
