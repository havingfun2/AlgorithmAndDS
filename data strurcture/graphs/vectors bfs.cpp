# include<iostream>
# include<vector>
# include<queue>
using namespace std;
int s[1000000];
int n;
vector<int>vet[1000000];
void bfs(int u)
{
	queue<int> q;
	int i;
	q.push(u);
	s[u]=1;
	while(!q.empty())
	{
		int rr=q.front();
		cout<<rr<<endl;
		q.pop();
		for(int j=0;j<vet[rr].size();j++){
			if(!(s[vet[rr][j]])){
				q.push(vet[rr][j]);
				s[vet[rr][j]]=1;
			}
		}
	}
}
int main()
{
	int i,j,u,v,edg;
	cin>>edg;
	for(i=0;i<edg;++i)
	{
		cin>>u>>v;
		vet[u].push_back(v);
	}
		cin>>i;
		bfs(i);
}
