# include<iostream>
using namespace std;
int q(int wt[],int n,int val){
	int dp[n][val+1],i,j;
	for(i=0;i<n;i++){
		for(j=0;j<=val;j++){
			if(!j)dp[i][j]=1;
			else{
				if(!i&&j-wt[i]<0)dp[i][j]=0;
				else if(!i&&j-wt[i]>=0)dp[i][j]=dp[i][j-wt[i]];
				else if(i&&j-wt[i]<0)dp[i][j]=dp[i-1][j];
				else dp[i][j]=dp[i-1][j]+dp[i][j-wt[i]];
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<=val;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[n-1][val];
}
int main(){
	int n,val;
	cin>>n>>val;
	int i,wt[n];
	for(i=0;i<n;i++)cin>>wt[i];
	int ans=q(wt,n,val);
	cout<<ans<<endl;
}
