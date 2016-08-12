# include<iostream>
# include<vector>
# include<queue>
using namespace std;
int s[100000],d[100000];
int n,m;
char vet[150][150];
void bfs(int u)
{
	queue<int> q;
	int i;
	q.push(u);
	s[u]=1;
	int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
	while(!q.empty())
	{
		int rr=q.front();
//		cout<<rr<<endl;
		int x=rr/m,y=rr%m;
		q.pop();
		for(int i=0;i<4;i++){
			if(x+xx[i]>=0&&x+xx[i]<n&&y+yy[i]>=0&&y+yy[i]<m)
			if(s[(x+xx[i])*m+(y+yy[i])]==0&&(vet[x+xx[i]][y+yy[i]]=='O'||vet[x+xx[i]][y+yy[i]]=='#')){
				q.push((x+xx[i])*m+(y+yy[i]));
				s[(x+xx[i])*m+(y+yy[i])]=1;
				d[(x+xx[i])*m+(y+yy[i])]=d[rr]+1;
			}
		}
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
	int i,j,u,v,start,end;
	cin>>n>>m;
	for(i=0;i<100000;i++){d[i]=-1;s[i]=0;}
	for(i=0;i<150;++i)
		for(j=0;j<150;j++)
			vet[i][j]='0';
	for(i=0;i<n;++i)
		for(j=0;j<m;j++)
		{
			cin>>vet[i][j];
			if(vet[i][j]=='$')start=i*m+j;
			if(vet[i][j]=='#')end=i*m+j;
		}
		d[start]=0
		bfs(start);
		if(d[end]==-1)cout<<-1<<endl;
		else
		cout<<d[end]<<endl;
	}
}
