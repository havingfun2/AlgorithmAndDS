# include<iostream>w
# include<cstdio>
using namespace std;
void create_graph();
void insert(int o,int des);
void del(int o,int des);
void display();
int n;
int a[100][100];
int main()
{
	int c,o,des;
	create_graph();
	do
	{
		cout<<"\n1. Insert Edge";
		cout<<"\n2. Delete Edge";
		cout<<"\n3. Display";
		cout<<"\n4. Exit\n";
		cin>>c;
		switch(c)
		{
			case 1:
				cout<<"\nEnter edge to be inserted\n";
				cin>>o>>des;
				insert(o,des);
				break;
			case 2:
				cout<<"\nEnter edge to be deleted\n";
				cin>>o>>des;
				del(o,des);
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default :
				cout<<"\nEnter correct choice \n";
				break;
		}
	}while(c!=4);
	return 0;
}
void create_graph()
{
	int i,edg,o,des;
	cout<<"Enter number of vertices\n";
	cin>>n;
	edg=n*(n-1);
	for(i=1;i<=edg;++i)
	{
		printf("\nEnter edge %d(-1 -1)to quit : ",i);
		cin>>o>>des;
		if(o==-1 && des==-1)
		break;
		if(o>=n || o<0 || des>=n || des<0)
		{
			printf("\nNot Valid\n");
			--i;
		}
		else
		a[o][des]=1;
	}
}
void insert(int o,int des)
{
	if(o<0||o>=n)
	{
		cout<<"\n Origin not exist\n";
		return ;
	}
	if(des<0||des>=n)
	{
		cout<<"\n Destination not exist\n";
		return ;
	}
	a[o][des]=1;
}
void del(int o,int des)
{
	if(o<0||des<0||des>=n||o>=n||a[o][des]==0)
	{
		cout<<"Edge Not Exist\n";
		return ;
	}
	a[o][des]=0;
}
void display()
{
	int i,j;
	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		printf("%4d",a[i][j]);
		cout<<endl;
	}
}
