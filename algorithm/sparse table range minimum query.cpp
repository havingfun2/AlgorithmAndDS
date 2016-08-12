    #include <iostream>
    # include<cmath>
    # include<cstdio>
    # include<algorithm>
    using namespace std;
    long long T[10][1000007],fl[10000007];
    void build(long long n){
     
    	for(long long j=1;(1<<j)<=n;j++){
    		for(long long i=0;i+(1<<j)-1<n;i++){
    			T[j][i]=min(T[j-1][i],T[j-1][i+(1<<(j-1))]);
    		}
    	}
    }
     
                    int main() {
                    	long long n,q,x,y,i;cin>>n;long long ans;
                    	for(i=0;i<n;i++)
                    			cin>>T[0][i];
                    		build(n);
    						fl[0]=fl[1]=0;
    						for(long long i = 2; i <= n; ++i)
    					    fl[i] = fl[i/2] + 1;
    					    
    					    cin>>q;
    					    
                    	for(i=1;i<=q;i++){
                    		cin>>x>>y;
                    		if(x>y){
                    			long long temp=x;
                    			x=y;
                    			y=temp;
                    		}
                    		
                    	long long k=fl[y-x+1];
    					ans=min(T[k][x],T[k][y-(1<<k)+1]);
    					printf("%lld \n",ans);
                    	}
                    	return 0;
                    }     
