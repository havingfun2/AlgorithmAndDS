# include<iostream>
# include<cmath>
using namespace std;
int q(int wt[],int v[],int n,int w,int sum){
	int dp[n+1][sum+1],i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=sum;j++){
			if(!i||!j)dp[i][j]=0;
			else {
				if(j-wt[i-1]<0)dp[i][j]=dp[i-1][j];
				else{
					if(j-wt[i-1]&&!dp[i-1][j-wt[i-1]])
					dp[i][j]=dp[i-1][j];
					else
					dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+v[i-1]);
				}
				
			}
		}
	}
	while(dp[n][w]==0)w++;
	return dp[n][w];
}
int main(){
	int n,w;
	cin>>n>>w;
	int wt[n],v[n],i,sum=0;
	for(i=0;i<n;i++){
		cin>>wt[i]>>v[i];
		sum+=wt[i];
	}
	int ans=q(wt,v,n,w,sum);
	cout<<ans<<endl;
}
