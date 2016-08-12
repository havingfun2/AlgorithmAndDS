# include<iostream>
# include<cmath>
using namespace std;
int q(int wt[],int v[],int n,int w){
	int dp[n+1][w+1],i,j;
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			if(!i||!j)dp[i][j]=0;
			else {
				if(j-wt[i-1]<0)dp[i][j]=dp[i-1][j];
				else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+v[i-1]);
			}
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=w;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n][w];
}
int main(){
	int n,w;
	cin>>n>>w;
	int wt[n],v[n],i;
	for(i=0;i<n;i++)cin>>wt[i]>>v[i];
	int ans=q(wt,v,n,w);
	cout<<ans<<endl;
}
