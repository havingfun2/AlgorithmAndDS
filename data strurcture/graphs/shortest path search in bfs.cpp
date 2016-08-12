# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
# define MAX 1000
# define infinity 9999
# define NIL -1
# define initial 1
# define waiting 2
# define visited 3
int n,a[MAX][MAX],s[MAX],d[MAX],predecessor[MAX];
void create_graph();
void bf_traversal();
void bfs(int v);
int q[MAX],front=-1,rear=-1;
void ins_queue(int ver);
int del_queue();
int isempty_queue();
int main()
{
	int temp,v,i,count,path[MAX];
	create_graph();
	bf_traversal();
	while(1)
	{
		printf("Enter Destination Vertex(-1 to quit) : ");
		cin>>v;
		if(v<-1||v>=n)
		{
			printf("\nDestination don't Exist\n");
			continue;
		}
		if(v==-1)
		break;
		count=0;
		if(d[v]==infinity)
		{
			printf("\nNo Path From Start Vertex To Destination Vertex\n");
			continue;
		}
		else
		printf("\nShortest Distance is: %d\n",d[v]);
		while(v!=NIL)
		{
			count++;
			path[count]=v;
			temp=predecessor[v];
			v=temp;
		}
		printf("\nShortest Path is: ");
		for(i=count;i>1;--i)
		printf("%d->",path[i]);
		printf("%d",path[i]);
		cout<<endl;
	}
}
void create_graph()
{
	int o,des,edg,i;
	printf("\nEnter No. Of Vertices\n");
	cin>>n;
	edg=n*(n-1);
	for(i=1;i<=edg;++i)
	{
		printf("\nEnter Edge %d(-1 -1)to quit :\n",i);
		cin>>o>>des;
		if(o==-1 && des==-1)
		break;
		if(o>=n||des>=n||o<0||des<0)
		{
			printf("\nNot Valid\n");
			--i;
		}
		else
		a[o][des]=1;
	}
}
void bf_traversal()
{
	int v;
	for(v=0;v<n;++v)
	{
		s[v]=initial;
		d[v]=infinity;
		predecessor[v]=NIL;
	}
	cout<<"Enter Vertice For BFS\n";
	cin>>v;
	bfs(v);
}
void bfs(int v)
{
	int i;
	ins_queue(v);
	s[v]=waiting;
	d[v]=0;
	predecessor[v]=NIL;
	while(!isempty_queue())
	{
		v=del_queue();
		s[v]=visited;
		for(i=0;i<n;++i)
		{
			if(a[v][i]==1 && s[i]==initial)
			{
				ins_queue(i);
				s[i]=waiting;
				predecessor[i]=v;
				d[i]=d[v]+1;
			}
		}
	}
}
void ins_queue(int ver)
{
	if(rear==MAX-1)
		cout<<"Queue Overflow\n";
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
