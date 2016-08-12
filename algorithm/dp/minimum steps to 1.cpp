#  include<iostream>
#include<cmath>
using namespace std;
int dp[1000000];
int rec(int n)
{
	if(n==1)
	return 0;
	if(dp[n])
	return dp[n];
		int r;
		r=1+rec(n-1);
		if(n%2==0)
		r=min(r,1+rec(n/2));
		if(n%3==0)
		r=min(r,1+rec(n/3));
		dp[n]=r;
	//	cout<<r<<" ";
		return r;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<1000000;i++)
	dp[i]=0;
	cout<<rec(n);
}
