//The problem is not actually to find the critical floor, but merely to decide floors from which eggs should be dropped so that total number of trials are minimized.
#include <iostream>
# include<cmath>
using namespace std;
int arr[5000][5000];
int dp(int n,int k){
	if(arr[n][k]);
	else if(n==1)
		arr[n][k]=k;
	else if(k==0)
		arr[n][k]=0;
	else if(k==1)
		arr[n][k]=1;
	else{
		arr[n][k]=999999999;
		for(int i=1;i<=k;i++)
			arr[n][k]=min(arr[n][k],1+max(dp(n-1,i-1),dp(n,k-i)));
	}
	return arr[n][k];
}
int main() {
	// your code goes here
	int n,k;
	cin>>n>>k;
	cout<<dp(n,k);
	return 0;
}
