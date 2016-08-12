#include <iostream>
using namespace std;
# include<vector>
vector<int>v[10000];
int d[10000],ct,ans=99999;
void dfs(int u){
	d[u]=1;
	int i;
	for(i=0;i<v[u].size();i++){
		if(!d[v[u][i]]){
			ct++;
			dfs(v[u][i]);
		}
	}
}
int main() {
	// your code goes here
	int n,m,i,j,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(i=1;i<=n;i++){
		for(j=0;j<10000;j++)d[j]=0;
		ct=1;
		dfs(i);
		ans=min(ans,ct);
	}
	cout<<ans;
	return 0;
}
