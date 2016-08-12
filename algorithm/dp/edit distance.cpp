#include <iostream>
using namespace std;
# include<cmath>
int dp[3010][3010];
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int la=a.size(),lb=b.size();
		int i,j;
		for(i=0;i<3010;i++)
		for(j=0;j<3010;j++)
		dp[i][j]=0;
		for(i=0;i<=la;i++)
		{
			for(j=0;j<=lb;j++)
			{
				if(i==0)
				dp[i][j]=j;
				if(j==0)
				dp[i][j]=i;
				if(i-1>=0&&i-1<la&&j-1>=0&&j-1<lb)
				{
					if(a[i-1]==b[j-1])
					dp[i][j]=dp[i-1][j-1];
					else
					dp[i][j]=1+(min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])));
				}
			}
		}
		cout<<dp[la][lb]<<endl;
	}
	return 0;
}

