# include<bits/stdc++.h>
using namespace std;
vector< vector< int > > st;
vector<int>v;
int log2(int x)
{
    int i=0;
    while (x){
        x>>=1;
        i++;
    }
    return i;
}
void constructsparsetable(int n)
{
    int c = log2(n);
    st = vector< vector< int > >(n, vector< int >(c));
 
    //Initialize
    for (int i = 0; i < n; i++){
        st[i][0] = v[i];
    }
    for (int i = 1; i < c; i++){
        for (int j = 0; j < (n - (1<<(i-1))); j++){
            st[j][i] = max(st[j][i-1], st[j+(1<<(i-1))][i-1]);
        }
    }
}
 
int querysparsetable(int a, int b)
{
    int l = log2(b - a + 1);
    return max(st[a][l-1], st[b-(1<<(l-1))][l-1]);
}
int main(){
	int n, m, x, a, b,i;
    scanf("%d %d", &n, &m);
    for(i=0;i<n;i++){
    	scanf("%d",&x);
    	v.push_back(x);
    }
    constructsparsetable(n);
    int c = 0;
    for(i=0;i<m;i++){
    	scanf("%d %d", &a, &b);
    	c=querysparsetable(a-1,b-1);
    printf("%d\n", c);	
    }
    
}
