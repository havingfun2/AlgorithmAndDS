#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000001], w[1000001];
set<int> sett;
set <int> :: iterator it;
#define pb push_back
int d[1000001]={}, comp[1000001]={}, in[1000001]={};
stack<int> st;
void dfs(int u){
	d[u]=1;
	for (int i = 0; i < v[u].size(); ++i)
	{
		if(!d[v[u][i]])
			dfs(v[u][i]);
	}
	st.push(u);
}
void dfs2(int u,int a){
	d[u]=0;
	comp[u]=a;
	for (int i = 0; i < w[u].size(); ++i)
	{
		if(d[w[u][i]])
			dfs2(w[u][i],a);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,i,a,b,k,com=0,lim=0,j,tot=0;
		scanf("%d%d",&n,&m);
		for(i=0;i<=n;i++){
			d[i]=0;
			v[i].clear();
			w[i].clear();
			comp[i]=0;
			in[i]=0;
		}
		for(i=0;i<m;i++){
			scanf("%d %d", &a, &b);
			w[a].pb(b);
			v[b].pb(a);
		}
		for (int i = 1; i <=n ; ++i)
			if(!d[i])
			dfs(i);
		while(!st.empty()){
			k=st.top();
			if(d[k])
				dfs2(k,com++);
			st.pop();
		}
		cout<<com<<endl;
		
	}
}