#include <bits/stdc++.h>
using namespace std;
const int inf = 999999999;
int d[1000000],n,m,gg,hh;

#define mp(b,c) make_pair(b,c)
int  dij(){
	priority_queue< pair<int, int> , vector<pair<int, int>  >, greater<pair<int, int>  > > q;
    int dx[]={2,2,1,-1,1,-1,-2,-2},i;
    int dy[]={-1,1,2,2,-2,-2,1,-1};
    int vis[10000];
    memset(vis, 0, sizeof vis);
    q.push(mp(0,n*8+m));
    while(!q.empty()){
        pair<int, int>  p=q.top();
        q.pop();
        int xx=p.second/8,yy=p.second%8;
        if(vis[xx*8+yy]) continue;
        if(xx==gg&&yy==hh) return p.first;
        vis[xx*8+yy]=1;
        for(i=0;i<8;i++){
            int nx = xx+dx[i], ny = yy+dy[i];
            if (nx>=0&&ny>=0&&nx<8&&ny<8&&!vis[nx*8+ny])
                q.push(mp(p.first+xx*nx+yy*ny,nx*8+ny));
        }
    }
    return -1;
    
}
int main() {
	while( cin>>n>>m>>gg>>hh){
	  
	    
	   cout<<dij()<<endl;
	}
	return 0;
}
