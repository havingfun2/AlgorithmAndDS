# include<bits/stdc++.h>
#define INF 1000000000
#define MAXN 100000

using namespace std;

int main()
{
     int n,m,a,b,c;
     cin>>n>>m;
     
    int i,j,k,g[101][101];
    for(i=0;i<101;i++){
        for(j=0;j<101;j++){
            if(i==j)g[i][j]=0;
            else g[i][j]=INF;
        }
    }
    for(i=0;i<m;i++){
        cin>>a>>b>>c;
        g[a][b]=g[b][a]=c;
    }
    for(i=0;i<101;i++)g[i][i]=0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(g[i][k]+g[k][j]<g[i][j])
                    g[i][j]=g[i][k]+g[k][j];
            }
        }
    }
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == INF)
                printf("%7s", "INF");
            else
                printf ("%7d", g[i][j]);
        }
        printf("\n");
    }
}