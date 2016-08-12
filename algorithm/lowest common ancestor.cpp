#include<bits/stdc++.h>

int par[1001],vis[1001];

int lca(int x, int y, int n){

	int i;
	for(i=1;i<=n;i++) vis[i] = 0;

	vis[x] = 1;

	while(par[x]!=x){
		vis[x] = 1;
		x = par[x];
	}

	vis[x] = 1;

	while(vis[y]!=1) y = par[y];

	return y;
}

int main(void){
	int t,q1=1;

	scanf("%d",&t);
while(t--){
		int n,m,q,x,y,i,j,k;
		printf("Case %u:\n",q1++);
		scanf("%d",&n);
		for(k=1;k<=n;k++) par[k] = k;
		for(i=1;i<=n;i++){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&k);
				par[k] = i;
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&x,&y);
			printf("%d\n",lca(x,y,n));
		}
	}
	return 0;
}