    #include <cstring>
    #include <cstdio>
    #include <vector>
    # include<iostream>
    #include <queue>
    using namespace std;
     
    typedef pair< int, int > pii;
    const int MAX = 100010;
    const int INF = 0x3f3f3f3f;
    vector< pii > G[MAX];
    int d[MAX];
    void dijkstra(int start) {
        int u, v, i, c, w;
        priority_queue< pii, vector< pii >, greater< pii > > Q;
        memset(d, 0x3f, sizeof d);
        Q.push(pii(0, start));
        d[start] = 0;
        while(!Q.empty()) {
            u = Q.top().second; // node
            c = Q.top().first; // node cost so far
            Q.pop(); 
            if(d[u] < c) continue;
            for(i = 0; i < G[u].size(); i++) {
                v = G[u][i].first;
                w = G[u][i].second; 
                if(d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    Q.push(pii(d[v], v));
                }
            }
        }
    }
     
    int main() {
        int n, e, i, u, v, w, start,end;
        int t;
        cin>>t;
        while(t--){
        scanf("%d %d", &n, &e) ;
     	scanf("%d %d", &start,&end);
            for(i = 0; i <=MAX ; i++) {
            G[i].clear();d[i]=INF;}
            for(i = 0; i < e; i++) {
                scanf("%d %d %d", &u, &v, &w);
                G[u].push_back(pii(v, w));
                G[v].push_back(pii(u, w)); 
            }
            dijkstra(start);
                if(d[end] >= INF) printf("NONE\n");
                else printf("%d\n",d[end]);
        }
        return 0;
    }
