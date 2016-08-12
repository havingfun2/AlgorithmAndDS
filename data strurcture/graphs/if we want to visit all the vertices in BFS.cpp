# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
# define MAX 1000
# define initial 1
# define waiting 2
# define visited 3
int n,a[MAX][MAX],s[MAX];
void create_graph();
void bf_traversal();
void bfs(int v);
int q[MAX],front=-1,rear=-1;
void ins_queue(int ver);
int del_queue();
int isempty_queue();
int main()
{
	create_graph();
	bf_traversal();
}
void create_graph()
{
	int o,des,edg,i;
	cout<<"\n Enter no. Of Vertices to be Inserted\n";
	cin>>n;
	edg=n*(n-1);
	for(i=1;i<=edg;++i)
	{
		printf("Enter edge %d(-1 -1)to quit : \n",i);
		cin>>o>>des;
		if(o==-1 && des==-1)
		break;
		if(o<0||o>=n||des<0||des>=n)
		{
			printf("\nNot Valid\n");
			--i;
		}
		else
		a[o][des]=1;
	}
	for(i=0;i<n;++i)
	{
	for(int j=0;j<n;++j)
	cout<<a[i][j]<<"\t";
	cout<<endl;
}
}
void bf_traversal()
{
	int v;
	for(v=0;v<n;++v)
	s[v]=initial;
	cout<<"\n Enter starting vertex of BFS\n";
	cin>>v;
	bfs(v);
	for(v=0;v<n;++v)
	if(s[v]==initial)
	bfs(v);
}
void bfs(int v)
{
	int i;
	ins_queue(v);
	s[v]=waiting;
	while(isempty_queue()==0)
	{
		v=del_queue();
		cout<<v<<endl;
		s[v]=visited;
		for(i=0;i<=n;++i)
		{
			if(a[v][i]==1 && s[i]==initial)
			{
				ins_queue(i);
				s[i]=waiting;
			}
		}
	}
}
void ins_queue(int ver)
{
	if(rear==MAX-1)
	cout<<"\nQueue Overflow\n";
	else
	{
		if(front==-1)
		front=0;
		rear+=1;
		q[rear]=ver;
	}
}
int isempty_queue()
{
	if(front==-1||front>rear)
	return 1;
	else
	return 0;
}
int del_queue()
{
	int d;
	if(front==-1||front>rear)
	{
		cout<<"\nQueue Underflow\n";
		exit(1);
	}
	d=q[front];
	front+=1;
	return d;
}
