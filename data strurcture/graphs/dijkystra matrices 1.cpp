#include <bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int a[1000][1000]={}, d[1000000], m, n;
priority_queue< pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
#define mp make_pair
void  dij(){
    int i, x, y, j, k, u, v;
	int g[]={0, 0, 1, -1};
	int h[]={1, -1, 0, 0};
	q.push(mp(0,a[0][0]));
	d[0]=a[0][0];
	while(!q.empty()){
	    u=q.top().first;
	    v=q.top().second;
	    x=u/m;
	    y=u%m;
	    q.pop();
	    for(i=0;i<4;i++){
	        if(x+g[i]>=0&&x+g[i]<n&&y+h[i]>=0&&y+h[i]<m){
	            if(d[(x+g[i])*m+y+h[i]]>d[u]+a[x+g[i]][y+h[i]]){
	                d[(x+g[i])*m+y+h[i]]=d[u]+a[x+g[i]][y+h[i]];
				    q.push(mp((x+g[i])*m+y+h[i], d[u]+a[x+g[i]][y+h[i]]));
	        }
	    }
	}
}
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int i,j,g,h,T;
	    cin>>n>>m;
	    for(i=0;i<n;i++){
	        for(j=0;j<m;j++){
	            cin>>a[i][j];
	            d[i*m+j]=inf;
	        }
	    }
	    cin>>g>>h>>T;
	    g--;
	    h--;
	    dij();
	   if(d[g*m+h]>T)cout<<"NO\n";else {cout<<"YES\n"<<T-d[g*m+h]<<endl;}
	}
	return 0;
}
