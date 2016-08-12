# include<iostream>
# include<queue>
# include<vector>
using namespace std;
vector<int> g[100];
int s[100],a[100002],dis[100002];
void bfs(int beg,int end)
{
	queue<int> q;int i;
	for(i=0;i<100002;i++)
	dis[i]=-1;
	for(i=0;i<100;i++)
	s[i]=0;
	q.push(beg);
	dis[beg]=0;
	while(!q.empty())
	{
		int rr=q.front();
		q.pop();
		if(rr==end)
		break;
		int u=a[rr],sz=g[u].size();
		if(s[u]==0)
		{
			for(i=0;i<sz;i++)
			{
				int v=g[u][i];
				if(dis[v]==-1)
				{
					dis[v]=dis[rr]+1;
					q.push(v);
				}
			}
			s[u]=1;
		}
     /*   {
            if(dis[rr-1]==-1)
            {
                dis[rr-1]=dis[rr]+1;
                q.push(rr-1);
            }
        }*/
	}
}
int main()
{
	int n;
	cin>>n;
	int i,x,beg,end,mid;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		g[a[i]].push_back(i);
	}
	cin>>x;
	while(x--)
	{
		cin>>beg>>mid>>end;
		bfs(beg,mid);
		if(dis[mid]==-1)
		cout<<-1<<"\n";
		else
		{
			int z=dis[mid];
			bfs(mid,end);
			if(dis[end]==-1)
			cout<<-1<<"\n";
			else
			cout<<dis[end]+z<<endl;
		}
	}
}
