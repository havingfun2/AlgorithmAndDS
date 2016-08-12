#include <iostream>
using namespace std;
int a[105];
int dp[105][105]; 
int c(int x,int b)
{
	int i,s=0;
	for(i=x;i<=b;i++)
		s=(s+a[i])%100;
		return s;
}
int sol(int x,int b)
{
	if(x==b)
	return 0;
	int &j=dp[x][b],i,t;
	if(j!=-1)
	return j;
	for(i=x;i<b;i++)
	{
		t=sol(x,i)+sol(i+1,b)+c(x,i)*c(i+1,b);
		if(j==-1||j>t)
		j=t;
	}
	return j;
}
int main() {
	// your code goes here
	int n;
	while(cin>>n)
	{
		int i,j;
		for(i=1;i<=n;i++)
		cin>>a[i];
		for(i=0;i<105;i++)
		for(j=0;j<105;j++)
		dp[i][j]=-1;
		cout<<sol(1,n)<<endl;
	}
	return 0;
}
