# include<stdio.h>
# include<stdlib.h>
# include<iostream>
using namespace std;
# define MAX 1000
# define initial 1
# define visited 2
int n,a[MAX][MAX],state[MAX];
void create_graph();
void df_traversal();
void dfs(int v);
int stack[MAX],top=-1;
void push(int v);
int pop();
int isempty_stack();
int main()
{
	create_graph();
	df_traversal();
}
void create_graph()
{
	int o,des,edg,i;
	cout<<"\nEnter No. Of Vertices To Be Added\n";
	cin>>n;
	edg=n*(n-1);
	for(i=1;i<=edg;++i)
	{
		printf("\nEnter Edge %d(-1 -1)to quit : \n",i);
		cin>>o>>des;
		if(o==-1 && des==-1)
		break;
		if(o<0||des<0||o>=n||des>=n)
		{
			cout<<"\nNot Valid\n";
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
void df_traversal()
{
	int v;
	for(v=0;v<n;++v)
	state[v]=initial;
	cout<<"\nEnter Starting Node For DFS\n";
	cin>>v;
	dfs(v);
}
void dfs(int v)
{
	int i;
	push(v);
	while(isempty_stack()==0)
	{
		v=pop();
		if(state[v]==initial)
		{
			cout<<v<<endl;
			state[v]=visited;
		}
		for(i=n-1;i>=0;i--)
		{
			if(a[v][i]==1 && state[i]==initial)
			{
				push(i);
				//dfs(i);
			}
		}
	}
}
void push(int v)
{
	if(top==MAX-1)
	{
		cout<<"\nStack Overflow\n";
		return ;
	}
	top+=1;
	stack[top]=v;
}
int isempty_stack()
{
	if(top==-1)
	return 1;
	else
	return 0;
}
int pop()
{
	int d;
	if(top==-1)
	{
		cout<<"\nStack Underflow\n";
		exit(1);
	}
	else
	{
		d=stack[top];
		top-=1;
		return d;
	}
}
