# include<queue>
# include<iostream>
using namespace std;
# define MAX 1000
# define initial 1
# define waiting 2
# define visited 3
int n,a[MAX][MAX],s[MAX];
queue<int> q1;
void create_graph();
void bf_traversal();
void bfs(int v);
int main()
{
	create_graph();
	bf_traversal();
	return 0;
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
}
void bfs(int v)
{
	int i;
	q1.push(v);
	s[v]=waiting;
	while(q1.empty()==0)
	{
		cout<<q1.front()<<endl;
		q1.pop();
		s[v]=visited;
		for(i=0;i<=n;++i)
		{
			if(a[v][i]==1 && s[i]==initial)
			{
				q1.push(i);
				s[i]=waiting;
			}
		}
	}
}
