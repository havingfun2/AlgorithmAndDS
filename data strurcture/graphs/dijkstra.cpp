# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
# define MAX 100
# define infinity 9999
# define NIL -1
# define TEMP 0
# define PREM 1
int n,a[MAX][MAX],state[MAX],pre[MAX],path_length[MAX];
void create_graph();
void find_path(int s,int v);
void dijkstra(int s);
int min_temp();
int main()
{
	int s,v;
	create_graph();
	cout<<"\nEnter Source Vertex\n";
	cin>>s;
	dijkstra(s);
	while(1)
	{
		printf("Enter Destination Vertex(-1 to quit): ");
		cin>>v;
		if(v==-1)
		break;
		if(v<0||v>=n)
		printf("\nVertex Not Exist");
		else if(v==s)
		printf("\nSource And Destination Vertex Same\n");
		else if(path_length[v]==infinity)
		printf("No Path\n");
		else
		find_path(s,v);
	}
}
void create_graph()
{
	int o,des,edg,i,w;
	cout<<"\nEnter No. Of Vertices To Be Added\n";
	cin>>n;
	edg=n*(n-1);
	for(i=1;i<=edg;++i)
	{
		printf("\nEnter Edge %d(-1 -1)to quit : \n",i);
		cin>>o>>des;
		if(o==-1 && des==-1)
		break;
		cout<<"\nEnter Weight For this Edge\n";
		cin>>w;
		if(o<0||des<0||o>=n||des>=n)
		{
			cout<<"\nNot Valid\n";
			--i;
		}
		else
		a[o][des]=w;
	}
}
void dijkstra(int s)
{
	int i,curr;
	for(i=0;i<n;++i)
	{
		pre[i]=NIL;
		path_length[i]=infinity;
		state[i]=TEMP;
	}
	path_length[s]=0;
	while(1)
	{
		curr=min_temp();
		if(curr==NIL)
		return;
		state[curr]=PREM;
		for(i=0;i<n;++i)
			if(a[curr][i]!=0&&state[i]==TEMP)
			if(path_length[curr]+a[curr][i]<path_length[i])
			{
				pre[i]=curr;
				path_length[i]=path_length[curr]+a[curr][i];
			}
	}
}
int min_temp()
{
	int i,min=infinity,k=NIL;
	for(i=0;i<n;++i)
	if(state[i]==TEMP&&path_length[i]<min)
	{
		min=path_length[i];
		k=i;
	}
	return k;
}
void find_path(int s,int v)
{
	int i,temp;
	int path[MAX],shortdis=0,count=0;
	while(v!=s)
	{
		count++;
		path[count]=v;
		temp=pre[v];
		shortdis+=a[temp][v];
		v=temp;
	}
	count++;
	path[count]=s;
	printf("\nShortest path is: ");
	for(i=count;i>=1;--i)
	cout<<path[i]<<endl;
	cout<<"Shortest Distance is: "<<shortdis<<endl;
}
