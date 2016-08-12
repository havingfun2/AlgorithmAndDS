//ASSIGNMENT (3) PROBLEM 1: Implement minimum spanning tree using Prim algorithm
//****DONE USING ADJACENCY MATRIX# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
# define MAX 100
# define infinity 9999
# define NIL -1
# define TEMP 0
# define PREM 1
struct edge
{
	int u,v;
};
int n,a[MAX][MAX],state[MAX],pre[MAX],path_length[MAX];
void create_graph();
void maketree(int r,struct edge tree[MAX]);
int min_temp();
int main()
{
	int wt=0,i,root;
	struct edge tree[MAX];
	create_graph();
	printf("\nEnter Root Vertex: ");
	cin>>root;
	maketree(root,tree);
	printf("\nEdges in Minimum Spanning Tree Are: \n");
	for(i=1;i<n;++i)
	{
		printf("%d->",tree[i].u);
		printf("%d\n",tree[i].v);
		wt+=a[tree[i].u][tree[i].v];
	}
	cout<<"\nWeight of the Spanning Tree is : "<<wt;
}
void create_graph()
{
	int o,des,edg,i,w;
	cout<<"\nEnter No. Of Vertices To Be Added\n";
	cin>>n;
	edg=(n*(n-1))/2;
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
		{
			a[o][des]=w;
			a[des][o]=w;
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
void maketree(int r,struct edge tree[MAX])
{
	int curr,i,count=0;
	for(i=0;i<n;++i)
	{
		state[i]=TEMP;
		pre[i]=NIL;
		path_length[i]=infinity;
	}
	path_length[r]=0;
	while(1)
	{
		curr=min_temp();
		if(curr==NIL)
		{
			if(count==n-1)
			return;
			else
			{
				printf("\nGraph Not Connected\n");
				exit(1);
			}
		}
		state[curr]=PREM;
		if(curr!=r)
		{
			count++;
			tree[count].u=pre[curr];
			tree[count].v=curr;
		}
		for(i=0;i<n;++i)
		{
			if(a[curr][i]>0&& state[i]==TEMP)
			if(a[curr][i]<path_length[i])
			{
				pre[i]=curr;
				path_length[i]=a[curr][i];
			}
		}
	}
}
