# include<stack>
# include<iostream>
using namespace std;
# define MAX 1000
# define initial 1
stack<int> s1;
# define visited 2
int n,a[MAX][MAX],state[MAX];
void create_graph();
void df_traversal();
void dfs(int v);
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
	s1.push(v);
	while(s1.empty()==0)
	{
		if(state[s1.top()]==initial)
		{
			cout<<s1.top()<<endl;
			state[s1.top()]=visited;
		}
		s1.pop();
		for(i=n-1;i>=0;i--)
			if(a[v][i]==1 && state[i]==initial)
				s1.push(i);
	}
}
