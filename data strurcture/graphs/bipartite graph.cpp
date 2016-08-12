# include<iostream>
# include<cstdio>
using namespace std;
# include<vector>
vector<int>v[21000];
int s[21000];
int dfs(int u){
	bool res=true;
	int i;
	for(i=0;i<v[u].size();i++){
		if(s[v[u][i]]==s[u])return false;
		if(!s[v[u][i]]){
			s[v[u][i]]=-s[u];
			res=res&dfs(v[u][i]);
		}
	}
	return res;
}
int main(){
	int t,q=1;
	cin>>t;
	while(t--){
		int i;
		for(i=0;i<21000;i++){
			v[i].clear();
			s[i]=0;
		}
		int n,m,x,y;
		cin>>n>>m;
		for(i=0;i<m;i++){
			cin>>x>>y;
			
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bool result = true;
		for(i=0;i<n;i++){
			if(!s[i]){
				s[i]=1;
				result=result&dfs(i);
			}
		}
		printf("Scenario #%d:\n",q++);
		 if(result)
            printf("isbipartite\n");
        else
            printf("not bipartite graph\n");
	}
}
